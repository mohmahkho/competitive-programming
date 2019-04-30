/* A permutation of elements of a set is sequence formed by elements in that set.
A set with n elements has n! different permutations.
Problem : find all permutations of {1, 2, ..., n}.
there is recursive approach to this problem.
we have n choices for the first element in the permutation.
then we have (n - 1) choices for the second elements in permutation.
and so on...
we should not use the same element twice.
thus we need a boolean array to keep track of what elements we currently have in our
permutation.
*/

int constexpr N = 1000;
int n;
bool chosen[N];
vector<int> p; // permutation

void search() {
    if(p.size() == n) {
        // p holds a permutation of numbers {1, 2, ..., n}.
    } else {
        for(int i = 1; i <= n; ++i) {
            if(chosen[i]) continue;
            chosen[i] = true;
            p.push_back(i);
            search();
            chosen[i] = false;
            p.pop_back();
        }
    }
}

int main() {
    cin >> n;
    search();
}

/*
at the very beginning there is nothing in p.
so the first element among {1, 2, ..., n} can be any of them.
we put chosen of each of this elements (separately) to true for the first element.
and run the search() recursively.
first of all chosen of 1 will be set to true.
then we push 1 in the permutation.
if search() follows a recursion tree in this path of tree 1 is the first element of the permutation.
after we are done with the path that 1 is  the first element of the permutation we pop_back 1
from the permutation and let 2 be the first element in the permutation.
because this is done in a recursive fashion the next first element (here the second element)
will be chosen recursively in this manner.
until we reach a point that our permutation has n elements in it. we can make sure this is a permutation.
*/
