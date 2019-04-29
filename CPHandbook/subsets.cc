/*
Problem : having a set of objects, we want to find all of its subsets.
in this particular example we have set of {1, 2, ..., n}.
*/

int n;
vector<int> subset;

void search(int k) {
    if(k == n + 1) {
        // now subset vector contains a subset of {1, 2, ..., n}.
    } else {
        search(k + 1); // k is not in the subset
        subset.push_back(k);
        search(k + 1); // k is in the subset
        subset.pop_back();
    }
}

// call search(1) and you can search on all subsets of {1, 2, ..., n}.
// in recursive calls this function finds a path to each leaf of a complete binary tree
// each path can be identified with a string of 0s and 1s which 0 mean going left in tree
// and 1 means going right in tree. the length of the string is n.
// similarly a string of 0s and 1s with lenght n identifies one of the subsets of a
// set with n elements in it where if the bit at position i is 1 means that object at
// position i is in the subset and if the bit is 0 means that object is not in the subset.
// so we can implement subsets in non-recursive fashion :

int n;
for(int subset = 0; subset < (1 << n); ++subset) {
    // subset in binary represents a subset of {0, 1, ..., n - 1}.
    for(int i = 0; i < n; ++i) {
        if((1 << i) & subset) { /* i is in the subset */ }
    }
}
