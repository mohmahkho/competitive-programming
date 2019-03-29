/*
lower bound function which is in the STL uses a binary search to find the first object that does not match < (lower)
binary operator. it is gaurenteed that in a random access iterator it has a O(lg(size)) time complexity.
but for non random access iterators it is guarenteed that it has a linear time complexity.
for exmaple :
*/

set<int> st;
// .. some inserts
auto it = lower_bound(st.begin(), st.end(), x); // this is done in O(st.size())

/* the solution is to use lower bound and upper bound function of the set container itself */
auto it = st.lower_bound(x);
