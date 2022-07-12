template<typename T, typename Comp>
vector<int> left_first_match(const vector<T>& v, Comp cmp) { // return vector of indecies
  vector<int> ans(v.size(), -1);
  stack<int> s;
  s.push(0);
  for(int i = 1; i < v.size(); ++i) {
    while(s.size() && !cmp(v[s.top()], v[i])) s.pop();
    if(s.size()) ans[i] = s.top();
    s.push(i);
  }
  return ans;
}
