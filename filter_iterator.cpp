#include "filter_iterator.h"

template<class Iterator>
Iterator operator+(typename Iterator::value_type num, Iterator iter)
    { return num + iter; }

template<class Iterator>
Iterator operator-(typename Iterator::value_type num, Iterator iter)
    { return num - iter; }
