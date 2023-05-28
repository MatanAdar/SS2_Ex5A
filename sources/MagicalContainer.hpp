#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

namespace ariel{

    class MagicalContainer{

        public:

            MagicalContainer() = default; //defult constructor

            vector<int>& getContainer(){
                return container;
            }

            void addElement(int element){
                container.push_back(element);
            }

            void removeElement(int element){
                // for(auto i=container.begin(); i!=container.end();i++){
                //     if(*i == element){
                //         container.erase(i);
                //     }
                //     else{
                //         i++;
                //     }
                // }

                container.erase(std::find(container.begin(), container.end(), element));

            }

            int size(){
                return container.size();
            }

            ~MagicalContainer() = default; // destructor

            MagicalContainer(const MagicalContainer& other) = default; // copy constructor


            
        private:

            vector<int> container;


        public:

            class AscendingIterator{

                private:

                    MagicalContainer& container;
                    int index;

                public:

                    //defult constructor
                    AscendingIterator(MagicalContainer& container) : container(container){

                        std::sort(container.getContainer().begin(),container.getContainer().end());
                    }

                    //Copy constructor
                    AscendingIterator(const AscendingIterator& copy_container) : container(copy_container.container){}//Copy constructor

                    
                    int& operator*() const {
                        return container.getContainer()[static_cast<vector<int>::size_type>(index)];
                    }

                    //Destructor
                    ~AscendingIterator() = default;


                    AscendingIterator& operator++(){
                        // Increment the index
                        index++;
                        return *this;
                    }

                    // MagicalContainer& operator=(const MagicalContainer& other){
                    //     if (this != &other)
                    //     {
                    //         // Perform any necessary deep copying or assignment
                    //         // of data members and iterators

                    //         // Example:
                    //         // Copy the data members
                    //         // this->data = other.data;

                    //         // Copy the iterators
                    //         // this->iterator = other.iterator;
                    //     }

                    //     // Return the reference to the current object
                    //     return *this;
                    // }

                    bool operator==(const AscendingIterator& other_iterator) const {
                        return index == other_iterator.index;
                    }

                    bool operator!=(const AscendingIterator& other_iterator) const {
                        return index != other_iterator.index;
                    }


                    AscendingIterator begin() const{
                        // Return a new iterator at the beginning
                        return AscendingIterator(container);
                    }

                    AscendingIterator end() const{
                        // Return an iterator that point to the end of the container (one past the last element)
                        AscendingIterator iterator_end(container);
                        iterator_end.index = container.size();
                        return iterator_end;
                    }



            };


            class SideCrossIterator{
                
                private:

                    MagicalContainer& container;
                    int index;

                public:
                    //defualt constructor
                    SideCrossIterator(MagicalContainer& container) : container(container){} 

                    //Copy constructor
                    SideCrossIterator(const SideCrossIterator& other_container) : container(other_container.container){} //Copy constructor

                    int& operator*() const {
                        return container.getContainer()[static_cast<vector<int>::size_type>(index)];
                    }

                    //Destructor
                    ~SideCrossIterator() = default;

                    SideCrossIterator& operator++(){
                        // Increment the index
                        index++;
                        return *this;
                    }

                    // Return a new iterator at the beginning
                    SideCrossIterator begin() const{
                        return SideCrossIterator(container);
                    }

                    // Return an iterator that point to the end of the container (one past the last element)
                    SideCrossIterator end() const{
                        SideCrossIterator iterator_end(container);
                        iterator_end.index = container.size();
                        return iterator_end;
                    }

                    bool operator==(const SideCrossIterator& other) const{
                        return index == other.index;
                    }

                    bool operator!=(const SideCrossIterator& other) const{
                        return index != other.index;
                    }

                    bool operator>(const SideCrossIterator& other) const{
                        return index > other.index;
                    }

                    bool operator<(const SideCrossIterator& other) const{
                        return index < other.index;
                    }
            };


            class PrimeIterator{

                private:

                    MagicalContainer& container;
                    int index;

                public:

                    //defualt constructor
                    PrimeIterator(MagicalContainer& container) : container(container){} 

                    //Copy constructor
                    PrimeIterator(const PrimeIterator& other_container) : container(other_container.container){} //Copy constructor

                    int& operator*() const {
                        return container.getContainer()[static_cast<vector<int>::size_type>(index)];
                    }

                    //Destructor
                    ~PrimeIterator() = default;

                    PrimeIterator& operator++(){
                        // Increment the index
                        index++;
                        return *this;
                    }

                    // Return a new iterator at the beginning
                    PrimeIterator begin() const{
                        return PrimeIterator(container);
                    }

                    // Return an iterator that point to the end of the container (one past the last element)
                    PrimeIterator end() const{
                        PrimeIterator iterator_end(container);
                        iterator_end.index = container.size();
                        return iterator_end;
                    }

                    bool operator==(const PrimeIterator& other) const{
                        return index == other.index;
                    }

                    bool operator!=(const PrimeIterator& other) const{
                        return index != other.index;
                    }

                    bool operator>(const PrimeIterator& other) const{
                        return index > other.index;
                    }

                    bool operator<(const PrimeIterator& other) const{
                        return index < other.index;
                    }

            };

            


    };
}



#endif