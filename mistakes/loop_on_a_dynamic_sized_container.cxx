/*
suppose we have a dynamic sized container and we are looping through it
if we don't consider index (like we do in deque) we care about number of times the loop
is executed. so if we set number of times the loop will execute to the size of container (like code below) :
*/

deque<int> dq;
// some initializations
for(int i = 0; i < dq.size(); ++i) {
    // if we may change size of dq so this for loop will/may act strangly
}
