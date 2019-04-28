/*
using tuples in c++ can possibly make you code more clear.
when you are working with object that consist of two ordered elements,
pairs are a great choice. but for more number of elements it is more convinient to use tuples :
*/
tuple<int, int, int> t;
get<0>(t) = 100;
get<1>(t) = 200;
get<2>(t) = 300;

cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
// output : 100 200 300

/*
if you have a container of tuples and you are using sort function on them
it first sorts based on first element, then second element, then ...
*/

/*
if syntax of get<i>(t) bothers you, you can define the function below for more ease of use:
*/
#define get(i, t) get<i>(t)
tuple<int, int, int> t;
get(0, t) = 100;
get(1, t) = 200;
get(2, t) = 300;

cout << get(0, t) << ' ' << get(1, t) << ' ' << get(2, t) << endl;
// output : 100 200 300
