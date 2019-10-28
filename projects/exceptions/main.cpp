#include <iostream>

using namespace std;

void mightGoWrong()
{
    bool error_1 = true;
    bool error_2 = false;
    if (error_1)
    {
        throw bad_alloc();
    }
    if (error_2)
    {
        throw std::string("Something else went wrong!!!");
    }

}

void usesMightGoWrong()
{
    mightGoWrong();
}

class CanGoWrong {
public:
    CanGoWrong() {
        char* pMemory = new char[999999999999999999];
        //char* pMemory = new char[999999999];

        std::cout << "Successfully allocated" << std::endl;
        delete [] pMemory;
    }
};


class MyException : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Something bad happend!!!";
    }
};

class Test
{
public:
    void goesWrong()
    {
        throw MyException();
    }
};

int main()
{
    cout << "Hello World!" << endl;

    Test test;
    try
    {
        test.goesWrong();
    }
    catch (MyException& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        CanGoWrong tmp;
    }
    catch (std::bad_alloc& e)
    {
        std::cout << "exception in constructor!!!:" << e.what() << std::endl;
    }

    try
    {
        usesMightGoWrong();
    }
    catch (bad_alloc& e)
    {
        std::cout << "Derived bad_alloc exception: " << e.what() << std::endl;
    }
    catch (exception& e)
    {
        std::cout << "Base exception: " << e.what() << std::endl;
    }
    catch (const char* e)
    {
        std::cout << "Error msg: " << e << std::endl;
    }
    catch (std::string& e)
    {
        std::cout << "Error string: " << e << std::endl;
    }

    std::cout << "Still running" << std::endl;
    return 0;
}
