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
in the normal case (1 - mpow(q, m)) / (1 - q) will be 0 / 0 and a RUNTIME ERROR verdict
will be shown. but when you are calculating it in inverse mod its not a division
it's a multiplication. hence you get a WRONG ANSWER verdict which makes it even harder to
spot the error.
*/
