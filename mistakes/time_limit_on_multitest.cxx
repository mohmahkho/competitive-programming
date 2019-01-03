/* Question :
    given a graph check if it is bipartite or not.
    input:
        there will be multiple test cases T (300000).
        the first line of each test contains two integer n and m (n < 300000, m < 300000))
        then m line. on each u and v (1 <= u, v <= n)
        sum of all n <= 300000
        sum of all m <= 300000
*/
/* Algorithm :
    color the graph black and white (with dfs) if there was a contradiction print "NO"
    otherwise print "YES"
*/
/* Mistake :
    we know that for dfs we usually need an array of visited which demonstrates if a node has
    been visited or not.
    we usually consider this array as a global array and give it the size of maximum input.
    you can see how it lookes like:
*/
int constexpr MAXN = 300001;
int visited[MAXN];
/*
    because this problem is multi test case in each input file so for the next input
    we need to clear the visited array so it does not affects the next test.
    so we can make mistake like below:
*/
int tc;
cin >> tc;
while(tc--)
{
    for(int i = 0; i < MAXN; i++) visited[i] = false;
}
/*
    or even worse. if we have defined visited array as an std::array so the process of
    filling the array would be easier, it would be much harder to detect the problem.
*/
std::array<int, MAXN> visited;
int tc;
cin >> tc;
while(tc--)
{
    visited.fill(false);
}
/*
    both ways of clearing the visisted array would cause a Time Limit Exceeded
    if the number of test cases in a single input file be high clearing the visited array
    takes too much time.
    the order would be. O(tc * MAXN)
    which is clearly a TLE.
*/
/* Solution :
    clear the needed part of the array.
    this will lower the time complexity because it is guaranteed that sum of all n would not exceed 300001
    so the order of clearing visited array would be O(tc * n) which is much smaller and will hopefully pass
    all tests in proper time.
    you can see the code for solution :
*/
int tc;
cin >> tc;
while(tc--)
{
    for(int i = 0; i <= n; i++) visited[i] = false;
}
