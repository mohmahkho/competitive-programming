/*
Suppose we have a geometric serie a + a * q + a * q ^ 2 + a * q ^ 3 + ...
the formula for sum of first m elements is :
a * (1 - q ^ m) / (1 - q)
but we need to consider that this formula only works for q != 1
this is a corner case and should be handled :
*/
if(q != 1) sum = a * (1 - pow(q, m)) / (1 - q);
else       sum = a * m;
