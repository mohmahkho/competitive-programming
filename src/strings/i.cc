#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& s, char sep) {
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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  char c;
  cin >> s >> c;
  for(auto x : split(s, c)) {
    cout << x << endl;
  }
}
