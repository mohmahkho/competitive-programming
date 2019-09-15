/*
suppose you want to find attached segments in an array.
a segment is a contiguos subarray.
if there is a, b, a as sub sequence in the array then a and b are attached. 
array like [1, 2, 3, 1, 2, 5, 5, 5, 6, 6, 6] has three attached segments : [1, 2, 3, 1, 2] [5, 5, 5] [6, 6, 6]
array like [1, 1, 10, 10, 4, 4] has three segments as well.
*/

// approach 1 : two pointers O(n)
    int n;
    constexpr int N = 200009;
    vector<int> a(N), last(N), cnt(N);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        last[a[i]] = i;
        cnt[a[i]] += 1;
    }
 
    for(int st = 0; st < n; ) {
        int ed = last[a[st]];
        int mx = cnt[a[st]];
        for(int i = st; i <= ed; ++i) {
            ed = max(ed, last[a[i]]);
            mx = max(mx, cnt[a[i]]);
        }
        // here from st to ed is an attached segment
        st = ed + 1;
    }
    
// approach 2 : using stack
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(!min_i[a[i]]) min_i[a[i]] = i;
        cnt[a[i]] += 1;
    }
 
    stack<int> st;
    for(int i = 1; i <= n; ++i) {
        if(min_i[a[i]] == i) {
            st.push(a[i]);
        } else {
            while(st.size() && min_i[st.top()] > min_i[a[i]]) {
                unite(st.top(), a[i]); // a[i] and st.top() are attached to each other
                st.pop();
            }
        }
    }
