/*
we know that in C programming languange every non-zero number is treated as true and 0
is false.
so what happens to the code below ?
*/
bool res = true;
res &= 8;
// res should be true because it is (ANDED) with a non-zero number? NO!
// here we are bitwise anding the res and 8 which is (1 & 8) which is 0 which is false!
res &= (bool)8;
// now we get expected results
