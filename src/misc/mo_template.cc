template<typename T, typename AnsType>
struct Window {
  int l, r;
  AnsType ans;
  vector<T>& a;
  Window(vector<T>& a_) : a(a_), l(), r(), ans() {
    // initialize l, r, ans
  }
  void inc_r() {
  }
  void dec_r() {
  }
  void inc_l() {
  }
  void dec_l() {
  }
};

template<typename T, typename AnsType, int S = 370>
struct Mo {
  struct Query {
    int l, r, idx;
  };
  Window<T, AnsType>& w;
  vector<Query> query;
  Mo(Window<T, AnsType>& w_) : w(w_)
  {
  }
  void add_query(int l, int r) {
    static int i = 0;
    query.push_back({l, r, i++});
  }
  vector<AnsType> calc() {
    sort(query.begin(), query.end(), [](const auto& q1, const auto& q2) {
      int b1 = q1.l / S, b2 = q2.l / S;
      if(b1 == b2) {
        if(b1 & 1) {
          return q1.r < q2.r;
        } else {
          return q1.r > q2.r;
        }
      }
      return b1 < b2;
    });
    vector<AnsType> ans(query.size());
    for(auto& q : query) {
      while(w.r < q.r) {
        w.inc_r();
      }
      while(w.r > q.r) {
        w.dec_r();
      }
      while(w.l < q.l) {
        w.inc_l();
      }
      while(w.l > q.l) {
        w.dec_l();
      }
      ans[q.idx] = w.ans; 
    }
    return ans;
  }
};

