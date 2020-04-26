template<typename T>
T segulen(const vector<pair<T, T>>& a) {
  int n = (int) a.size();
  vector<pair<T, int>> ends(n << 1);
  for(int i = 0; i < n; ++i) {
    ends[i << 1] = {a[i].first, -1};
    ends[i << 1 | 1] = {a[i].second, 1};
  }
  sort(ends.begin(), ends.end());
  T ulen = 0;
  for(int i = 0, c = 0; i < (n << 1); ++i) {
    if(i) ulen += (c > 0) * (ends[i].first - ends[i - 1].first);
    c -= ends[i].second; 
  }
  return ulen;
}
