/*
Suppose we have a geometric serie a + a * q + a * q ^ 2 + a * q ^ 3 + ...
the formula for sum of first m elements is :
a * (1 - q ^ m) / (1 - q)
but we need to consider that this formula only works for q != 1
this is a corner case and should be handled :
*/
if(q != 1) sum = a * (1 - pow(q, m)) / (1 - q);
if(q == 1) sum = a * m;

/* pitfall:
if you are calculating this sum normally (meaning without taking mod) you
are likely to get a runtime error.
but suppose our answer cannot be stored in a 64 bit signed integer and
problem asked us to take the sum of first m elements modula 10^9 + 7
so this formula can be written as :
*/
sum = a * (1 - mpow(q, m)) * inverse(1 - q);
/*
as you may know inverse of an integer modula a large prime is usually calculated as
mpow(x, MOD - 2).
the bad thing about mpow is that usually the answer is at least 1!
which means for the x = 0 it will return 1!!
the worst thing is that inverse of (1 - q) becomes 1 and you even don't get a 
runtime error verdict! you get WRONG ANSWER!! which makes it even harder to spot the error!
*/
