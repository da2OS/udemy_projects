#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
auto test(T value) ->decltype(value)
{
    return value;
}

int main()
{
    std::string value;
    cout << typeid (value).name() << std::endl;

    decltype (value) name = "Bob";
    cout << typeid (name).name() << std::endl;

    cout << test("Hello World!") << endl;
    return 0;
}
