/*
fibonacci sequence is f(1) = 1, f(2) = 2, f(n) = f(n - 1) + f(n - 2).
sum of first k terms of fibonacci sequence is equal to f(k + 2) - 1.
proof by induction:
let s(k) be equal to f(1) + f(2) + ... + f(k).
Base case:
    s(1) = f(1) = f(3) - 1 (true)
Inductive step:
    if s(k) = f(k + 2) - 1 then we will porve s(k + 1) = f(k + 3) - 1
    s(k) = f(k + 2) - 1
    s(k) + f(k + 1) = f(k + 1) + f(k + 2) - 1
    s(k + 1) = f(k + 1) + f(k + 2) - 1
    s(k + 1) = f(k + 3) - 1.
*/
