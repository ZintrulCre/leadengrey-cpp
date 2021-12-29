#include "include/std.h"
#include "include/boost.h"

// Function template std::mem_fn generates wrapper objects for pointers to members, 
// which can store, copy, and invoke a pointer to member. 
// Both references and pointers (including smart pointers) 
// to an object can be used when invoking a std::mem_fn.

class Foo
{
public:
    void Print() { cout << 0 << endl; }
    void PrintI(int i) { cout << i << endl; }
    int k = 5;
};

void MemFnTest()
{
    Foo foo;
    auto FooPrint = mem_fn(&Foo::Print);
    FooPrint(foo);
    auto FooPrintI = mem_fn(&Foo::PrintI);
    FooPrintI(foo, 2);
    auto FooK = mem_fn(&Foo::k);
    cout << FooK(foo) << endl;
    
    cout << boost::typeindex::type_id_with_cvr<decltype(FooPrint)>().pretty_name() << endl;
    cout << boost::typeindex::type_id_with_cvr<decltype(FooPrintI)>().pretty_name() << endl;
    cout << boost::typeindex::type_id_with_cvr<decltype(FooK)>().pretty_name() << endl;
}