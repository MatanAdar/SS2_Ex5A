#include "doctest.h"
#include "MagicalContainer.hpp"

#include <iostream>

using namespace ariel;
using namespace std;


TEST_SUITE("Adding elements to MagicalContainer") {
    MagicalContainer container;

    TEST_CASE("Adding a single element") {
        container.addElement(5);
        CHECK(container.size() == 1);
        CHECK(container.getContainer()[0] == 5);
    }

    TEST_CASE("Adding multiple elements") {
        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        CHECK(container.size() == 4);
        std::vector<int> expected = {5, 10, 20, 30};
        CHECK(container.getContainer() == expected);
    }
}

TEST_SUITE("Removing elements from MagicalContainer") {
    TEST_CASE("Removing an existing element") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);
        container.addElement(29);
        container.addElement(25);

        container.removeElement(10);
        CHECK(container.size() == 4);
        std::vector<int> expected = {5, 15, 29, 25};
        CHECK(container.getContainer() == expected);
    }

    TEST_CASE("Removing a non-existing element") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);
        container.addElement(29);
        container.addElement(25);

        container.removeElement(30); // Element does not exist
        CHECK(container.size() == 5); // Size should remain the same
        std::vector<int> expected = {5, 10, 15, 29, 25};
        CHECK(container.getContainer() == expected); // Container should remain unchanged
    }
}


TEST_SUITE("Copy and move operations") {
    TEST_CASE("Copy constructor") {
        MagicalContainer container1;
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(3);

        MagicalContainer container2(container1);
        CHECK(container2.size() == container1.size());
        CHECK(container2.getContainer() == container1.getContainer());
    }

    TEST_CASE("Copy assignment operator") {
        MagicalContainer container1;
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(3);

        MagicalContainer container2;
        container2 = container1;
        CHECK(container2.size() == container1.size());
        CHECK(container2.getContainer() == container1.getContainer());
    }

    TEST_CASE("Move constructor") {
        MagicalContainer container1;
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(3);

        MagicalContainer container2(std::move(container1));
        CHECK(container2.size() == 3);
        CHECK(container1.size() == 0); // container1 should be empty after move
        std::vector<int> expected = {1, 2, 3};
        CHECK(container2.getContainer() == expected);
    }

    TEST_CASE("Move assignment operator") {
        MagicalContainer container1;
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(3);

        MagicalContainer container2;
        container2 = std::move(container1);
        CHECK(container2.size() == 3);
        CHECK(container1.size() == 0); // container1 should be empty after move
        std::vector<int> expected = {1, 2, 3};
        CHECK(container2.getContainer() == expected);
    }

    }

    TEST_SUITE("AscendingIterator Test") {
    // Create a MagicalContainer and add elements
        MagicalContainer container;
        TEST_CASE("adding elements"){
            container.addElement(3);
            container.addElement(7);
            container.addElement(32);
            container.addElement(4);
            container.addElement(19);
        }
       
    // Create an AscendingIterator using the container
    TEST_SUITE("Iteration through the container") {

        TEST_CASE("Verify values using operator*") {
            MagicalContainer::AscendingIterator ascIter(container);
            // Test iterating through the container using the AscendingIterator
            auto iter = ascIter.begin();
            auto end = ascIter.end();

            CHECK(*iter == 3);
            ++iter;
            CHECK(*iter == 4);
            ++iter;
            CHECK(*iter == 7);
            ++iter;
            CHECK(*iter == 19);
            ++iter;
            CHECK(*iter == 32);
            ++iter;
            CHECK(iter == end);
        }


        TEST_CASE("Verify operators == and !=") {
            MagicalContainer::AscendingIterator ascIter(container);
            // Test iterating through the container using the AscendingIterator
            auto begin = ascIter.begin();
            auto end = ascIter.end();
            CHECK(begin != end);
            CHECK(begin == begin);
            CHECK(end == end);
        }

        
    TEST_CASE("Iteration through an empty container") {
        MagicalContainer container;
        MagicalContainer::AscendingIterator ascIter(container);
        auto begin = ascIter.begin();
        auto end = ascIter.end();
        CHECK(begin == end);  // The iterator range should be empty
    }

    TEST_CASE("Multiple iterators on the same container") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);
        container.addElement(7);
        MagicalContainer::AscendingIterator ascIter1(container);
        MagicalContainer::AscendingIterator ascIter2(container);
        // Verify that the iterators progress independently
        auto it1 = ascIter1.begin();
        auto it2 = ascIter2.begin();
        CHECK(*it1 == 3);
        CHECK(*it2 == 3);
        ++it1;
        CHECK(*it1 == 5);
        CHECK(*it2 == 3);
        ++it1;
        CHECK(*it1 == 7);
        CHECK(*it2 == 3);
        ++it2;
        CHECK(*it1 == 7);
        CHECK(*it2 == 5);
        ++it1;
        CHECK(*it1 == 10);
        CHECK(*it2 == 5);
        ++it1;
        CHECK(it1 == ascIter1.end());
        CHECK(*it2 == 5);
        ++it2;
        CHECK(*it2 == 10);
        ++it2;
        CHECK(it2 == ascIter2.end());
    }

    }

    TEST_SUITE("SideCrossIterator Test") {
        TEST_CASE("Adding elements to MagicalContainer") {
            MagicalContainer container;
            container.addElement(17);
            container.addElement(2);
            container.addElement(25);
            container.addElement(9);
            container.addElement(3);
        }

        TEST_CASE("Verify values using operator*") {
            MagicalContainer container;
            container.addElement(4);
            container.addElement(8);
            container.addElement(2);
            container.addElement(27);
            container.addElement(14);
            MagicalContainer::SideCrossIterator sideCrossIter(container);
            auto iter = sideCrossIter.begin();
            auto end = sideCrossIter.end();
            CHECK(*iter == 2);
            ++iter;
            CHECK(*iter == 27);
            ++iter;
            CHECK(*iter == 4);
            ++iter;
            CHECK(*iter == 14);
            ++iter;
            CHECK(*iter == 8);
            ++iter;
            CHECK(iter == end);
        }

        TEST_CASE("Verify operators < and >") {
            MagicalContainer container;
            container.addElement(17);
            container.addElement(2);
            container.addElement(25);
            container.addElement(9);
            container.addElement(3);
            MagicalContainer::SideCrossIterator sideCrossIter(container);
            auto begin = sideCrossIter.begin();
            auto end = sideCrossIter.end();
            CHECK(begin < end);
            CHECK(end > begin);
        }

        TEST_CASE("Verify operators == and !=") {
            MagicalContainer container;
            container.addElement(17);
            container.addElement(2);
            container.addElement(25);
            container.addElement(9);
            container.addElement(3);
            MagicalContainer::SideCrossIterator sideCrossIter(container);
            auto begin = sideCrossIter.begin();
            auto end = sideCrossIter.end();
            CHECK(begin != end);
            CHECK(begin == begin);
            CHECK(end == end);

            //removing all elements
            container.removeElement(17);
            container.removeElement(2);
            container.removeElement(25);
            container.removeElement(9);
            container.removeElement(3);

            CHECK(begin == end);

        }
    }


    TEST_CASE("Multiple iterators on the same container") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);
        container.addElement(7);
        MagicalContainer::SideCrossIterator sideCrossIter1(container);
        MagicalContainer::SideCrossIterator sideCrossIter2(container);
        // 3 5 7 10 -> 3 10 5 7 
        // Verify that the iterators progress independently
        auto it1 = sideCrossIter1.begin();
        auto it2 = sideCrossIter2.begin();
        CHECK(*it1 == 3);
        CHECK(*it2 == 3);
        ++it1;
        CHECK(*it1 == 10);
        CHECK(*it2 == 3);
        ++it1;
        CHECK(*it1 == 10);
        CHECK(*it2 == 3);
        ++it2;
        CHECK(*it1 == 10);
        CHECK(*it2 == 10);
        ++it1;
        CHECK(*it1 == 5);
        CHECK(*it2 == 10);
        
    }

}


TEST_SUITE("PrimeIterator Test") {
    TEST_CASE("Adding elements to MagicalContainer") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
    }

    TEST_SUITE("Iteration through the container") {


        TEST_CASE("Verify values using operator*") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
        MagicalContainer::PrimeIterator primeIter(container);
            auto iter = primeIter.begin();
            auto end = primeIter.end();
            CHECK(*iter == 2);
            ++iter;
            CHECK(*iter == 3);
            ++iter;
            CHECK(*iter == 17);
            ++iter;
            CHECK(iter == end);
        }

        TEST_CASE("Verify operators < and >") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
        MagicalContainer::PrimeIterator primeIter(container);
            auto begin = primeIter.begin();
            auto end = primeIter.end();
            CHECK(begin < end);
            CHECK(end > begin);
        }

        TEST_CASE("Verify operators == and !=") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
        MagicalContainer::PrimeIterator primeIter(container);
            auto begin = primeIter.begin();
            auto end = primeIter.end();
            CHECK(begin != end);
            CHECK(begin == begin);
            CHECK(end == end);
        }
    }

    TEST_CASE("Iteration through an empty container") {
        MagicalContainer container;
        MagicalContainer::PrimeIterator primeIter(container);
        auto begin = primeIter.begin();
        auto end = primeIter.end();
        CHECK(begin == end);  // The iterator range should be empty
    }

    TEST_CASE("Multiple iterators on the same container") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);
        container.addElement(7);
        MagicalContainer::PrimeIterator primeIter1(container);
        MagicalContainer::PrimeIterator primeIter2(container);

        // Verify that the iterators progress independently
        auto it1 = primeIter1.begin();
        auto it2 = primeIter2.begin();
        CHECK(*it1 == 2);
        CHECK(*it2 == 2);
        ++it1;
        CHECK(*it1 == 3);
        CHECK(*it2 == 2);
        ++it2;
        CHECK(*it1 == 3);
        CHECK(*it2 == 7);
        ++it1;
        CHECK(*it1 == 17);
        CHECK(*it2 == 7);
        ++it1;
        CHECK(it1 == primeIter1.end());
        CHECK(*it2 == 7);
        ++it2;
        CHECK(*it2 == 7);
        ++it2;
        CHECK(it2 == primeIter2.end());
    }
}

    