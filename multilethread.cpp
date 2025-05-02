#include <iostream>
#include <thread>

long long count = 0; 
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

    std::cout << "Second worker call\n";
    t2.join();  

    return 0;
}
