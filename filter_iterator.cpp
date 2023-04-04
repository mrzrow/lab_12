#include "filter_iterator.h"

template<class I, class F>
void FilterIterator<I, F>::findNextMatch() {
    while ( iter != end && (!func(*iter)) )
        ++iter;
}

template<class I, class F>
void FilterIterator<I, F>::findPrevMatch() {
    while ( iter != end && (!func(*iter)) )
        --iter;
}

template<class I, class F>
I operator+(typename I::value_type num, FilterIterator<I, F> iterator) { 
    return num + iterator.iter;
}

template<class I, class F>
I operator-(typename I::value_type num, FilterIterator<I, F> iterator) { 
    return num - iterator.iter;
}

template<class Iterator>
Iterator operator-(typename Iterator::value_type num, Iterator iter)
    { return num - iter; }

template<class I, class F>
I FilterIterator<I, F>::operator++() {
    ++iter;
    findNextMatch();
    return iter;
}

template<class I, class F>
I FilterIterator<I, F>::operator++(typename I::value_type num) {
    ++iter;
    findNextMatch();
    return iter;
}

template<class I, class F>
I FilterIterator<I, F>::operator--() {
    --iter;
    findPrevMatch();
    return iter;
}

template<class I, class F>
void FilterIterator<I, F>::operator+=(typename I::value_type num) {
    iter += num;
    findNextMatch();
    return iter;
}

template<class I, class F>
void FilterIterator<I, F>::operator-=(typename I::value_type num) {
    iter -= num;
    findPrevMatch();
    return iter;
}
