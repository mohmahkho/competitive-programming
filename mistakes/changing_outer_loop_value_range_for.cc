/*
as you know range for without using references does not change the value inside vector/array
for example
*/
vector<int> v {1, 2, 3};
for(int x : v) x *= 2;

// after this : v = {1, 2, 3}

/*
if you want to use two for ranges inside each other and you think changing them does not changes the array itself
and you change the values. the value for the next element in the inner loop will be the new value but if you change
outer loop's element it will remain the same until the inner loop ends.
*/

// vectors A and B

for(int u : A) {
  for(int v : B) {
    u = max(u, v)
  }
}
// this will change u in the next iterations of the for(v:B)
