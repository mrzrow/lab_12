#ifndef FILTER_ITERATOR
#define FILTER_ITERATOR

template<class Iterator, class Function>
class FilterIterator {
    Iterator iter;
    Iterator end;
    Function func;

    Iterator findNextMatch(int); 
    Iterator findPrevMatch(int);

public:
    FilterIterator(Iterator, Iterator); 
    ~FilterIterator() {}

    typename Iterator::value_type operator*() { return *iter; } 

    Iterator operator++()    { return findNextMatch(1); }
    Iterator operator++(int) { return findNextMatch(1); }

    Iterator operator--()    { return findPrevMatch(1); }
    Iterator operator--(int) { return findPrevMatch(1); }

    void operator+=(typename Iterator::value_type num)
        { findNextMatch(num); }
    void operator-=(typename Iterator::value_type num)
        { findPrevMatch(num); }

    Iterator operator+(typename Iterator::value_type num) 
        { return iter + num; }
    Iterator operator-(typename Iterator::value_type num) 
        { return iter - num; }
    
    friend Iterator operator+(typename Iterator::value_type, Iterator) {}
    friend Iterator operator-(typename Iterator::value_type, Iterator) {}

    bool operator> (Iterator a) { return iter >  a; }
    bool operator>=(Iterator a) { return iter >= a; }
    bool operator< (Iterator a) { return iter <  a; }
    bool operator<=(Iterator a) { return iter <= a; }

    bool operator==(Iterator a) { return iter == a; }
    bool operator!=(Iterator a) { return iter != a; }
};


template<class I, class F>
I FilterIterator<I, F>::findNextMatch(int add) {
    iter += add;
    while ( iter < end && (!func(*iter)) )
        iter += add;
    return iter;
}

template<class I, class F>
I FilterIterator<I, F>::findPrevMatch(int add) {
    iter -= add;
    while ( iter >= end && (!func(*iter)) )
        iter -= add;
    return iter;
}

template<class I, class F>
FilterIterator<I, F>::FilterIterator(I iter, I end)
    : iter(iter), end(end) {
        if (iter < end) findNextMatch(1);
        else findPrevMatch(1);
    }

template<class I, class F>
I operator+(typename I::value_type num, FilterIterator<I, F> iterator) { 
    return num + iterator.iter;
}

template<class I, class F>
I operator-(typename I::value_type num, FilterIterator<I, F> iterator) { 
    return num - iterator.iter;
}

#endif
