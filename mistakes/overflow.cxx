std::vector<int> vec {1}; // vector containing only value 1

for(int i = 0; i < vec.size() - 2; ++i) {
    std::cout << vec[i] << std::endl;
}

/*
this part of code seems to work because [vec.size() - 2 = -1] and 0 is not
less than -1 so it will not even enter the loop;
but since size() member function returns an unsigned value this is actually
an underflow.
*/

// the right way:
for(int i = 0; i < (int)vec.size() - 2; i++) {
    std::cout << vec[i] << std::endl;
}

// =======================================================================
/*
once I was trying to find vertex with maximul degree in a graph and
I wrote the code below:
*/
int max_deg = -1;
int max_deg_vertex;
for(int v = 1; v <= n; v++) {
  if(adjlist[v].size() > max_deg) {
    max_deg = adjlist[v].size();
    max_deg_vertex = v;
  }
}
/*
this super simple code intrestingly does not work. The reason may not be 
obvios at first glace but the thing that happening here is that
comparison between unsigned_integer and signed_integer caused the signed one
to be casted to unsigned so that the value of that would be maximum value of
unsigned integer. this mistake is basikly the previos one.
*/
// Solution 1:
int max_deg = -1;
int(adjlist[v].size()) > max_deg     
// Solution 2:
int max_deg = 0;
adjlist[v].size() > max_deg

