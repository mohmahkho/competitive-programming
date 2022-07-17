vector<string> split(const string& s, char sep) {
  vector<string> res;
  string t {};
  for(char c : s) {
    if(c != sep) {
      t += c;
    } else {
      if(t.size()) {
        res.push_back(t);
        t.clear();
      }
    }
  }
  if(t.size()) {
    res.push_back(t);
  }
  return res;
}
