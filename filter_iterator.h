#ifndef FILTER_ITERATOR
#define FILTER_ITERATOR

template<class Iterator, class Function>
class FilterIterator {
    Iterator iter;
    Iterator end;
    Function func;

    Iterator findNextMatch(int add) {
        iter += add;
        while ( iter < end && (!func(*iter)) )
            iter += add;
        return iter;
    }
    Iterator findPrevMatch(int add) {
        iter -= add;
        while ( iter < end && (!func(*iter)) )
            iter -= add;
        return iter;
    }

public:
    FilterIterator(Iterator iter, Iterator end)
        : iter(iter), end(end), func(func) {
            if (iter < end)
                findNextMatch(1);
            else
                findPrevMatch(1);
        }
   
    ~FilterIterator() {}

    typename Iterator::value_type operator*() { return *iter; } 

    Iterator operator++() { return findNextMatch(1); }
    Iterator operator++(typename Iterator::value_type) { return findNextMatch(1); }

    Iterator operator--() { return findPrevMatch(1); }
    Iterator operator--(typename Iterator::value_type) { return --this; }

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
I operator+(typename I::value_type num, FilterIterator<I, F> iterator) { 
    return num + iterator.iter;
}

template<class I, class F>
I operator-(typename I::value_type num, FilterIterator<I, F> iterator) { 
    return num - iterator.iter;
}

#endif
