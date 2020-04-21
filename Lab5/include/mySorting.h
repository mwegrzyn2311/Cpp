#include <iostream>

#ifndef MYLIST4STUDENTS_MYSORTING_H
#define MYLIST4STUDENTS_MYSORTING_H
using namespace std;

template<typename Container, typename Compare = greater<>>
void mySort(Container& container, Compare greater = Compare()) {
    bool sorted;
    do {
        sorted = true;
        auto it1 = begin(container);
        auto it2 = begin(container);
        it2++;
        while(it2 != end(container)) {
            if(greater(*it1, *it2)){
                iter_swap(it1, it2);
                sorted = false;
            }
            it1++;
            it2++;
        }
    } while(!sorted);
}

template<size_t count, size_t length, typename Compare = greater<>>
void mySort(char (&container)[count][length], Compare greater = Compare()) {
    bool sortedcharset[ch];;
    do {
        sorted = true;
        auto it1 = begin(container);
        auto it2 = begin(container);
        it2++;
        while(it2 != end(container)) {
            bool shouldSwap = false;
            for(size_t i = 0; i < length; i++) {
                if(greater(toupper((*it1)[i]), toupper((*it2)[i]))) {
                    shouldSwap = true;
                    break;
                } else if(greater(toupper((*it2)[i]), toupper((*it1)[i]))) {
                    break;
                }
            }
            if(shouldSwap) {
                iter_swap(it1, it2);
                sorted = false;
            }
            it1++;
            it2++;
        }
    } while(!sorted);
}

#endif //MYLIST4STUDENTS_MYSORTING_H