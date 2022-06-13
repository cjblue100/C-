#include <chrono>
#include <conio.h>
#include <iostream>
using sys_clock = std::chrono::system_clock;

double computeDelay()
{
    auto start_time = sys_clock::now();
    std::cout << "cosa";
    // Do something
    auto end_time = sys_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    _getch();
    return static_cast<double>(duration.count());
}
