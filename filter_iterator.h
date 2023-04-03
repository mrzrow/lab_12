#ifndef FILTER_ITERATOR
#define FILTER_ITERATOR

template<class Iterator, class Function>
class FilterIterator {
    Iterator iter;
    Iterator end;
    Function func;
public:
    FilterIterator(Iterator iter, Iterator end)
        : iter(iter), end(end), func(func) {}
   
    ~FilterIterator() {}

    typename Iterator::value_type operator*() { return *iter; } 

    Iterator operator++() {
        ++iter;
        while ( iter != end && (!func(*iter)) )
            ++iter;
        return iter;
    }
    Iterator operator++(typename Iterator::value_type) { return ++iter; }

    void operator--() { --iter; }
    void operator--(typename Iterator::value_type) { iter--; }

    void operator+=(typename Iterator::value_type num) { iter += num; }
    void operator-=(typename Iterator::value_type num) { iter -= num; }

    Iterator operator+(typename Iterator::value_type num) { return iter + num; }
    Iterator operator-(typename Iterator::value_type num) { return iter - num; }
    
    friend Iterator operator+(typename Iterator::value_type, Iterator) {}
    friend Iterator operator-(typename Iterator::value_type, Iterator) {}

    bool operator> (Iterator a) { return iter >  a; }
    bool operator>=(Iterator a) { return iter >= a; }
    bool operator< (Iterator a) { return iter <  a; }
    bool operator<=(Iterator a) { return iter <= a; }

    bool operator==(Iterator a) { return iter == a; }
    bool operator!=(Iterator a) { return iter != a; }
};

#endif
