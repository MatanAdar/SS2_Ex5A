#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

namespace ariel{

    class MagicalContainer{

        public:

            MagicalContainer() = default; //defult constructor

            vector<int>& getContainer(){
                return container;
            }

            void setContainer(vector<int>& new_container){
              container = new_container;
            }

            void addElement(int element){
                container.push_back(element);
            }

            void removeElement(int element){
                for(auto i=container.begin(); i!=container.end();i++){
                    if(*i == element){
                        container.erase(i);
                        break;
                    }

                }
            }

            // return size of container
            int size(){
                return container.size();
            }

            // destructor
            ~MagicalContainer() = default;

            // copy constructor
            MagicalContainer(const MagicalContainer& other) = default;

            // Copy assignment operator
            MagicalContainer& operator=(const MagicalContainer& other) {
                if (this != &other) {
                    // Perform deep copy of the container
                    container = other.container;
                }
                return *this;
            }

            // Move constructor
            MagicalContainer(MagicalContainer&& other) noexcept = default;

            // Move assignment operator
            MagicalContainer& operator=(MagicalContainer&& other) noexcept {
                if (this != &other) {
                    // Move the container from the other object
                    container = std::move(other.container);
                }
                return *this;
            }


            
        private:

            vector<int> container;


        public:

            class AscendingIterator{

                private:

                    MagicalContainer& container;
                    int index;

                public:

                    //defult constructor
                    AscendingIterator(MagicalContainer& container) : container(container),index(0){

                        sortContainer();
                    }

                    //Copy constructor
                    AscendingIterator(const AscendingIterator& copy_container) : container(copy_container.container){}//Copy constructor


                    // Sort the container
                    void sortContainer() {
                        std::sort(container.getContainer().begin(), container.getContainer().end());
                    }

                    // Return a new iterator at the beginning
                    AscendingIterator begin() const{
                        AscendingIterator begin_iterator(container);
                        return begin_iterator;
                    }

                    // Return an iterator that point to the end of the container (one past the last element)
                    AscendingIterator end() const{
                        AscendingIterator iterator_end(container);
                        iterator_end.index = container.size();
                        return iterator_end;


                    }


                    int& operator*() const {
                        return container.getContainer()[static_cast<vector<int>::size_type>(index)];
                    }

                    //Destructor
                    ~AscendingIterator() = default;


                    AscendingIterator& operator++(){
                        // Increment the index
                        this->index = this->index + 1;

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

                    bool operator==(const AscendingIterator& other) const{
                        return index == other.index;
                    }

                    bool operator!=(const AscendingIterator& other) const{
                        return index != other.index;
                    }

                    bool operator>(const AscendingIterator& other) const{
                        return index > other.index;
                    }

                    bool operator<(const AscendingIterator& other) const{
                        return index < other.index;
                    }


            };


            class SideCrossIterator{
                
                private:

                    MagicalContainer& container;
                    int index = 0;

                public:

                    //defualt constructor
                    SideCrossIterator(MagicalContainer& container) : container(container){
                        
                        sortContainer();


                        // std::vector<int> sortedElements = container.getContainer();
                        // std::sort(sortedElements.begin(), sortedElements.end());
                        // size_t start = 0;
                        // size_t end = sortedElements.size() -1;
                        // std::vector<int> crossElements(sortedElements.size());
                        // for (size_t i = 0; i < crossElements.size() ; i+=2) {
                        //     crossElements[i] = sortedElements[start];
                        //     crossElements[i+1] = sortedElements[end];
                        //     start++;
                        //     end--;

                        // }
                        // this->container.setContainer(crossElements);

                    } 

                    //Copy constructor
                    SideCrossIterator(const SideCrossIterator& other_container) : container(other_container.container){} //Copy constructor

                    void sortContainer() {
                        size_t size = static_cast<size_t>(container.size());
                        vector<int> temp(size, 0);

                        vector<int>& temp2 = container.getContainer();
                        std::sort(temp2.begin(), temp2.end());

                        size_t start = 0;
                        size_t end = size - 1;
                        size_t j = 0;
                        
                        while (start <= end) {
                            if (start == end) {
                                temp[j] = temp2[start];
                                break;
                            }

                            //from first the container
                            temp[j] = temp2[start];
                            start++;

                            //from end the container
                            temp[j+1] = temp2[end];
                            end--;

                            //increase j by 2
                            j+=2;
                        }

                        //replace the new container in the old one
                        container.setContainer(temp);
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

                    bool isPrime(int element){
                        
                        if(element <= 1){
                            return false;
                        }

                        if(element == 2 || element == 3){
                            return true;
                        }

                        for(int i=2 ; i<=sqrt(element) ; i++){
                            if(element % i == 0){
                                return false;
                            }
                        }

                        return true;
                    }

                public:

                    //defualt constructor
                    PrimeIterator(MagicalContainer& container) : container(container) , index(0){
                        sortPrimeContainer();
                    } 

                    //Copy constructor
                    PrimeIterator(const PrimeIterator& other_container) : container(other_container.container){} //Copy constructor

                    void sortPrimeContainer(){
                        
                        // std::sort(container.getContainer().begin(), container.getContainer().end());
                        vector<int> temp = {};

                        for(size_t i = 0 ; i<container.size();i++){
                            bool check = isPrime(container.getContainer()[i]);
                            if(check){
                                temp.push_back(container.getContainer()[i]);
                            }
                        }

                        container.setContainer(temp);
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