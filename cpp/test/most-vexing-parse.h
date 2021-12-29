#include "include/std.h"
#include "include/boost.h"

void MostVexingParseTest()
{
    class Foo {};

    Foo foo1;
    Foo foo2();

    cout << boost::typeindex::type_id_with_cvr<decltype(foo1)>().pretty_name() << endl;
    cout << boost::typeindex::type_id_with_cvr<decltype(foo2)>().pretty_name() << endl;
}
