#include <iostream>
#include <string>
#include <limits>

int main()
{
    // std::string a = "0.12f";
    // std::size_t found = a.find_first_of("f");
    // std::cout << found << std::endl;

    // std::string b = "0.12";
    // int size = b.length();
    // std::cout << size << std::endl;
    // found = b.find_first_of("f");
    // std::cout << found << std::endl;
    // found = b.find_last_of("f");
    // std::cout << found << std::endl;

    std::string a = "-5";
    int b = std::stoi(a);
    std::cout << b << std::endl;

    std::cout << INT_MAX << std::endl;
    std::cout << INT_MIN << std::endl;
    // std::cout << FLOAT_MAX << std::endl;
    // std::cout << FLT_MIN << std::endl;
    std::cout << std::numeric_limits<float>::min() << std::endl;
    std::cout << std::numeric_limits<float>::max() << std::endl;


}