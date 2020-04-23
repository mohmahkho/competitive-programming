In order to binary search on integers, you only need one while loop. Assume you have predicate **P(n)**, you can search for 
the first place that **P(n)** is *false* or the last place that it is *true*.  
Here I'm assuming that **P(n) -> P(n + 1)** and I want to find the smallest **n** for which **P(n)** is *true*.  
```c++
int lo = 0, hi = 1000000000;
while(lo != hi) {
  int mid = (lo + hi) / 2;
  if(P(mid)) {
    hi = mid;
  } else {
    lo = mid + 1;
  }
}
```
But if wanted to find the largest **n** for which **P(n)** is false I should have done it this way:
```c++
while(lo != hi) {
  int mid = (lo + hi + 1) / 2;
  if(!P(mid)) {
    lo = mid;
  } else {
    hi = mid - 1;
  }
}
```
Notice the difference. In the first example, for the `mid` we are taking the floor of avg of `hi` and `lo`, however, for 
the second one we are taking the ceiling of avg.
