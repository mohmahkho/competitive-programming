/*
If you need some powers of 2 (or some constant) you can just pre calculate it
Typically because of overflow powers are needed in some mod.
*/

int constexpr MOD = 1000000007;
int maxn = 200009;
int p2[maxn];
p2[0] = 1;
for(int i = 1; i < maxn; i++) p2[i] = (p2[i - 1] * 2) % MOD;
