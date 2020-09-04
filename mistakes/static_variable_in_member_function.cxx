/*
Consider this example:
*/

struct s {
  void print() {
    static int x = 0;
    x += 1;
    cout << x << endl;
  }
};

int main() {
  s s1;
  s1.print();
  s s2;
  s2.print();
}

/*
Output:
1
2

[Probably] Expected output:
1
1

This is something that you generally want to avoid.
Basically you may expect that static variable x reset to 0 for every instance of struct s, but it is not the case.
Solution is so simple, declare x as a member variable!
*/
