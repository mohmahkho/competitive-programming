template <class ForwardIterator, class T>
ForwardIterator first_occurrence(ForwardIterator first, ForwardIterator last,
                                 const T& val)
{
    auto it = lower_bound(first, last, val);
    if(it == last or *it != val) {
        return last; // val not found!
    }
    return it;
}


template <class ForwardIterator, class T>
ForwardIterator last_occurrence(ForwardIterator first, ForwardIterator last,
                                const T& val)
{
    auto it = upper_bound(first, last, val);
    if(it == first or *(it - 1) != val) {
        return last; // val not found!
    }
    return (--it);
}
