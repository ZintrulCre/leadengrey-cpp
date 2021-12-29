#include "include/std.h"

void ThreadTest()
{
    auto SleepFunc = []()
    {
        this_thread::sleep_for(chrono::seconds(1000));
    };

    auto EndlessLoopFunc = []()
    {
        while(true) {}
    };

    thread ts[4];
    for (int i = 0; i < 3; ++i)
        ts[i] = thread(SleepFunc);
    ts[3] = thread(EndlessLoopFunc);

    for (auto& t : ts)
        t.join();
}