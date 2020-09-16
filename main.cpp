#include "base/pch.h"
#include "design-pattern/pch.h"
#include "online-judge/pch.h"

int main()
{
    // OjTest();
    int i;

    auto A = [](int i) -> bool {return i == 0;};
    function<bool()> B = [&]() -> bool {return i == 0;};

    cout << boost::typeindex::type_id_with_cvr<decltype(A)>().pretty_name() << endl;
    cout << boost::typeindex::type_id_with_cvr<decltype(*A)>().pretty_name() << endl;

    cout << boost::typeindex::type_id_with_cvr<decltype(B)>().pretty_name() << endl;

    return 0;
}
