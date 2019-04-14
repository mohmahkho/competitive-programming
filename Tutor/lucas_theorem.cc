/*
Lucas's Theorem
consider integers n and m. we want to calculate C(m, n) (mod p) where C is bionomial coefficient function and p is a prime number.
if we write m in base p like :
(mk, mk-1, mk-2, ..., m0)
and n in base p:
(nk, nk-1, nk-2, ..., n0)
then 
C(m, n) % p = C(mk, nk) * C(mk-1, nk-1) * ... * C(m0, n0) % p

for small enough primes p this is a feasible approach to calculate C(m, n) in mod p.
*/
