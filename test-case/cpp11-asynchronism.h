#include "universal/std-pch.h"

void PromiseFoo(int x, promise<int>& pms)
{
    ++x;
    pms.set_value(x); // set future
}

void PromiseTest()
{
    int x = 0;
    promise<int> p;
    future<int> f = p.get_future();
    thread t(PromiseFoo, x, ref(p));
    x = f.get();
    t.join();
    cout << x << endl;
}

int PackagedTaskFoo(int x)
{
    ++x;
    return x;
}

void PackagedTaskTest()
{
    int x = 1;
    packaged_task<int(int)> task(PackagedTaskFoo);
    future<int> f = task.get_future();
    // thread t(PackagedTaskFoo, x);
    thread t(std::ref(task), x); // packaged_task instead of function pointer
    x = f.get();
    t.join();
    cout << x << endl;
}

int AsyncFoo(int x)
{
    ++x;
    return x;
}

void AsyncTest()
{
    int x = 2;
    future<int> f = async(launch::async, AsyncFoo, x);
    x = f.get();
    cout << x << endl;
}
