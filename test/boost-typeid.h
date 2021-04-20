#include "include/std.h"
#include "include/boost.h"

void Foo()
{
}

void TypeidTest()
{
    int i;

    auto A = [](int i) -> bool {return i == 0;};
    function<bool()> B = [&]() -> bool {return i == 0;};

    cout << boost::typeindex::type_id_with_cvr<decltype(A)>().pretty_name() << endl;
    cout << boost::typeindex::type_id_with_cvr<decltype(*A)>().pretty_name() << endl;

    cout << boost::typeindex::type_id_with_cvr<decltype(B)>().pretty_name() << endl;

    cout << boost::typeindex::type_id_with_cvr<decltype(Foo)>().pretty_name() << endl;
}
