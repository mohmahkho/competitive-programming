int n = 5;

string bin(int x) {
  string ans = "";
  for(int j = n - 1; j >= 0; --j) {
    ans += ((x >> j & 1) ? '1' : '0');
  }
  return ans;
}

int main() {
  int mask;
  cin >> mask;
  cout << "Need : " << bin(mask) << '\n';
  for (int overmask = mask; overmask < (1 << n); overmask = (overmask + 1) | mask) {
    cout << bin(overmask) << endl;
  }
}

/*
5
Need : 00101
00101
00111
01101
01111
10101
10111
11101
11111
*/
