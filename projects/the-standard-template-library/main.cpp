#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::cout << "Hello World!" << std::endl;

    std::vector<std::string> str_vector;

    str_vector.push_back("one");
    str_vector.push_back("two");
    str_vector.push_back("three");
    str_vector.push_back("four");
    str_vector.push_back("five");

    std::cout << "Vector size: " << str_vector.size() << std::endl;
    std::cout << "Vector capacity: " << str_vector.capacity() << std::endl;

    std::cout << "End!" << std::endl;
    return 0;
}
