#include <iostream>
#include <thread>

long long count = 0;
 // okk so here we have a global variable which is shared between the threads and gets
// modified by both threads simultaneously
// so not big deal aryan
// yes here is the deal if we run this code for the smaller values than it wll work fine 
// like uptill 10^5 that i have tasted again and again and  it works fine bt if we go beyond liek the moment we step in the 10^6 than
// it will give ys wrong ouput 
// and its not like a  same wrong output every time it will give us some random wrong output in each run
// so this is the concept of the 
// so ladies and gentlemen this is the race condition when two or more thread are trying to access 
// the same resources at the same time and they are trying to modify it at the same time and they are not able to do it properly
// and to fix this shit we use the 
// mutex = (to lock access so only one thread updates at a time)
// atomic = variable (which ensure safe access automatically)
// i bet u heard of it bt may be never implemented nd got ur hands dirty on it
void worker() {
    for (long long i = 0; i < 100000; i++) {  
        count++;
    }
    std::cout << "count == " << count << std::endl;
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker); 
    t1.join(); 
    t2.join();  

    return 0;
}
