/*
suppose we have a dynamic sized container and we are looping through it
if we don't consider index (like we do in deque) we care about number of times the loop
is executed. so if we set the number of times the loop will execute to the size of container (like code below) :
*/

deque<int> dq;
// some initializations
for(int i = 0; i < dq.size(); ++i) {
    // if we change the size of dq so this for loop will/may act strangly
}

// --- example ---
/*
suppose we have k processors and we have n tasks to do. the ith task will take a[i] seconds to
be done. we want to know when all these tasks are done.
*/
// solution :
/*
a bruteforce solution will work fine.
so we want to simulate the second t. at the second t each of the processors that have a task to do
will work on that specific task. so we need to loop through all the active processors.
if we queue the processors and at time t for all processors deque that processors and make it work on task for a second
the natural thing to do is that active processors are queued so the number of times we want to make processors do their work
in a single second is equal to the number of active processors which is the size of our queue.
so we might make a mistake and write the for loop like the above code. which may cause problem because after a processor is 
done and there is no work to assign to it, we will not push that processor into queue. so this will cause the size of queue
change and we are likely to get a wrong answer.
so the right way to do it is like :
*/

int loop_cnt = Q.size();
for(int i = 0; i < loop_cnt; ++i) {
    // process tasks
}
