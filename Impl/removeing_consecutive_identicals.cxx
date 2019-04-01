/*
suppose we have an array of elements in a way that some consecutive elements may be identical
and we want only one of them for example :
1, 2, 3, 3, 3, 3, 1, 1, 1, 5, 1, 1, 1
we want to have :
1, 2, 3, 1, 5, 1
we can use std::unique in c++ algorithms library.
*/

/*
std::unique works with iterators which means we should use iterators! :))
it takes two parameters a begin iterator and an end iterator which like all the other 
funtions in STL working with iterators the end iterator itself is not included.
eleminating consecutive identical elements is done by shifting so iterators to the array or vector
will not be affected.
at return value std::unique will return an iterator pointing to the physical end of the array.
elements after return value of unique (the iterator pointing to the end of the array) are still 
dereferencable but have non specific value.
*/

/*
for plain arrays we can use pointers instead of the iterators. works exactly as expected.
*/

/*
if we are using a vector and we want to delete the eliminated elements we can use a simple trick :
*/

vector<int> v;
// inserting some value to v
v.erase(unique(v.end(), v.begin()), v.end());

// after this there will be no consecutive elements in v and v's size will change.
