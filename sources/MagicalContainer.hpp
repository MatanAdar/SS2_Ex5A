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

            //defult constructor
            MagicalContainer() = default;

            // copy constructor
            MagicalContainer(const MagicalContainer& other) = default;

            vector<int>& getContainer(){
                return container;
            }

            void setContainer(vector<int>& new_container){
              container = new_container;
            }

            void addElement(int element){
                for(size_t i = 0; i<container.size();i++){
                    if(container[i] == element){
                        return;
                    }
                }

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
            size_t size(){
                return container.size();
            }

            // destructor
            ~MagicalContainer() = default;

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

            // class Iterator{

            //     private:

            //         MagicalContainer& container;
            //         int index = 0;
                    

            //     public:

            //         Iterator(MagicalContainer& container) : container(container){}


            //         // // Return a new iterator at the beginning
            //         // AscendingIterator begin() const{
            //         //     AscendingIterator begin_iterator(container);
            //         //     return begin_iterator;
            //         // }

            //         // // Return an iterator that point to the end of the container (one past the last element)
            //         // AscendingIterator end() const{
            //         //     AscendingIterator iterator_end(container);
            //         //     iterator_end.index = (int)container.size();
            //         //     return iterator_end;

            //         // }

                    


            // };

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
                    AscendingIterator(const AscendingIterator& copy_container) : container(copy_container.container) , index(copy_container.index){}


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
                        iterator_end.index = (int)container.size();
                        return iterator_end;

                    }


                    int& operator*() const {
                        return container.getContainer()[static_cast<vector<int>::size_type>(index)];
                    }

                    AscendingIterator& operator++(){
                        // Increment the index
                        this->index = this->index + 1;

                        return *this;

                    }

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


                    //Destructor
                    virtual ~AscendingIterator() = default;


                    // Copy assignment operator
                    AscendingIterator& operator=(const AscendingIterator& other) {
                        if (this != &other) {
                            container = other.container;
                            index = other.index;
                        }
                        return *this;
                    }

                    // Move constructor
                    AscendingIterator(AscendingIterator&& other) noexcept : container(other.container), index(other.index) {}

                    // Move assignment operator
                    AscendingIterator& operator=(AscendingIterator&& other) noexcept {
                        if (this != &other) {
                            container = std::move(other.container);
                            index = other.index;
                        }
                        return *this;
                    }

            };


            class SideCrossIterator{
                
                private:

                    MagicalContainer& container;
                    int index = 0;

                public:

                    //defualt constructor
                    SideCrossIterator(MagicalContainer& container) : container(container){
                        
                        sortSizeCrossContainer();

                    } 

                    //Copy constructor
                    SideCrossIterator(const SideCrossIterator& other_container) : container(other_container.container){} //Copy constructor


                    void sortSizeCrossContainer() {
                        size_t size = static_cast<size_t>(container.size());
                        vector<int> temp(size, 0);

                        vector<int>& temp2 = container.getContainer();
                        std::sort(temp2.begin(), temp2.end());

                        size_t start = 0;
                        size_t end = size - 1;
                        size_t idx = 0;
                        
                        while (start <= end) {
                            if (start == end) {
                                temp[idx] = temp2[start];
                                break;
                            }

                            //from first the container
                            temp[idx] = temp2[start];
                            start++;

                            //from end the container
                            temp[idx+1] = temp2[end];
                            end--;

                            //increase j by 2
                            idx+=2;
                        }

                        //replace the old container with the new one
                        container.setContainer(temp);
                    }


                    // Return a new iterator at the beginning
                    SideCrossIterator begin() const{
                        return SideCrossIterator(container);
                    }

                    // Return an iterator that point to the end of the container (one past the last element)
                    SideCrossIterator end() const{
                        SideCrossIterator iterator_end(container);
                        iterator_end.index = (int)container.size();
                        return iterator_end;
                    }


                    int& operator*() const {
                        return container.getContainer()[static_cast<vector<int>::size_type>(index)];
                    }

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


                    //Destructor
                    ~SideCrossIterator() = default;

                    // Copy assignment operator
                    SideCrossIterator& operator=(const SideCrossIterator& other) {
                        if (this != &other) {
                            container = other.container;
                            index = other.index;
                        }
                        return *this;
                    }

                    // Move constructor
                    SideCrossIterator(SideCrossIterator&& other) noexcept : container(other.container), index(other.index) {}

                    // Move assignment operator
                    SideCrossIterator& operator=(SideCrossIterator&& other) noexcept {
                        if (this != &other) {
                            container = std::move(other.container);
                            index = other.index;
                        }
                        return *this;
                    }
            };


            class PrimeIterator{

                private:

                    MagicalContainer& container;
                    int index;

                    bool static isPrime(int element){
                        
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
                    PrimeIterator(const PrimeIterator& other_container) : container(other_container.container) , index(other_container.index){} //Copy constructor

                    void sortPrimeContainer(){
                        
                        // std::sort(container.getContainer().begin(), container.getContainer().end());
                        vector<int> temp = {};

                        std::sort(container.getContainer().begin(),container.getContainer().end());

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
                        iterator_end.index = (int)container.size();
                        return iterator_end;
                    }


                    int& operator*() const {
                        return container.getContainer()[static_cast<vector<int>::size_type>(index)];
                    }


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

                    //Destructor
                    ~PrimeIterator() = default;


                    // Copy assignment operator
                    PrimeIterator& operator=(const PrimeIterator& other) {
                        if (this != &other) {
                            container = other.container;
                            index = other.index;
                        }
                        return *this;
                    }

                    // Move constructor
                    PrimeIterator(PrimeIterator&& other) noexcept : container(other.container), index(other.index) {}

                    // Move assignment operator
                    PrimeIterator& operator=(PrimeIterator&& other) noexcept {
                        if (this != &other) {
                            container = std::move(other.container);
                            index = other.index;
                        }
                        return *this;
                    }

            };

            


    };
}



#endif