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
