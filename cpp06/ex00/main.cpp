#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

const std::string red("\033[0;31m");
const std::string reset("\033[0m");

bool check_char(std::string a)
{
    int b = static_cast<int>(a[0]);
    if (a.length() == 1 && ((b > 31 && b<48) || (b>57 && b<129)))
        return true;
    else
        return false;
}

bool check_int(const std::string a, double &b)
{
    int size = a.length();
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if ((i == 0 && a[i] == '-') || isdigit(a[i]))
            count++;
    }
    if (count == size)
    {
        if (size > 11)
        {
            std::cout << "the input overflows" << std::endl;
            return false;
        }
        b = std::strtod(a.c_str(), nullptr);
        if (b > INT_MAX || b < INT_MIN)
        {
            std::cout << "the input overflows" << std::endl;
            return false;
        }
        return true;
    }
    else
        return false;
}

bool check_float(std::string a, double &b)
{
    int size = a.length();
    int count = 0;
    int i;
    if(a[size - 1] == 'f')
    {   
        std::size_t found = a.find_first_of(".");
        std::size_t found2 = a.find_last_of(".");
        if (found == found2 && static_cast<int>(found) < size)
        {
            for(i = 0; i < size; i++)
            {                
                if ((i == 0 && a[i] == '-') || isdigit(a[i]))
                    count++;
            }
            if (count == size - 2)
            {
                b = std::strtod(a.c_str(), nullptr);
                return true;
            }
        }
        if (found == found2)
        {
            count = 0;
            for(i = 0; i < size; i++)
            {                
                if ((i == 0 && a[i] == '-') || isdigit(a[i]))
                    count++;
            }
            if (count == size - 1)
            {
                b = std::stof(a);
                return true;
            }
        }
    }
    return false;
}

bool check_double(std::string a, double &b)
{
    int size = a.length();
    int count = 0;
    int i;
    std::size_t found = a.find_first_of(".");
    std::size_t found2 = a.find_last_of(".");
    if(found == found2 && static_cast<int>(found) < size)
    {
        for(i = 0; i < size; i++)
            {                
                if ((i == 0 && a[i] == '-') || isdigit(a[i]))
                    count++;
            }
            if (count == size - 1)
            {
                b = std::strtod(a.c_str(), nullptr);
                return true;
            }
    }
    return false;
}

void cast_char(int b)
{
    if ((b < 32 && b >= 0) || b == 128)
        std::cout << reset << "char: Non displayable" << std::endl;
    else if (b < 0 || b > 128)
        std::cout << reset << "char: impossible" << std::endl;
    else
        std::cout << reset << "char :'" << static_cast<char>(b) << "'" << std::endl;
}

int check_precision(std::string a)
{
    int dot_position = a.find_first_of(".");
    int size = a.length();
    if (dot_position >= size || dot_position < 0 )
        dot_position = size - 2;
    if (a[size - 1] == 'f')
    {    
        int f_position = size - 1;
        return f_position - dot_position - 1;
    }
    else
        return size - dot_position - 1;
}

bool check_science(std::string a)
{
    std::string f;
    std::string d;
    int len = a.length();
    if (a.compare("-inff") == 0 || a.compare("+inff") == 0 ||a.compare("nanf") == 0)
    {
        d = a.substr(0, len - 1);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float: " << a << std::endl;
        std::cout << "double: " << d << std::endl;
        return true;
    }
    if (a.compare("-inf") == 0 || a.compare("+inf") == 0 ||a.compare("nan") == 0)
    {
        f = a + "f";
        std::cout << "char: impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float: " << f << std::endl;
        std::cout << "double: " << a << std::endl;
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    double c;
    int precision = 0;
    if (check_science(argv[1]))
        return 0;
    if (check_char(argv[1]))
    {
        char a = argv[1][0];
        std::cout << red << "the input type is char" << std::endl;
        cast_char(static_cast<int>(a));
        std::cout << "int: " << static_cast<int>(a) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(a) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(a) << std::endl;
        return 0;
    }
    if (check_int(argv[1], c))
    {
        std::cout << red << "the input type is int" << std::endl;
        cast_char(static_cast<int>(c));
        std::cout << reset << "int: " << argv[1] << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
        return 0;
    }

    if (check_float(argv[1], c))
    {
        std::cout << red << "the input type is float" << std::endl;
        precision = check_precision(argv[1]);
        cast_char(static_cast<int>(c));
        if (c > INT_MAX || c < INT_MIN)
            std::cout << reset << "int: value overflows" << std::endl;
        else
            std::cout << reset << "int: " << static_cast<int>(c) << std::endl;
        if (precision == 0)
            precision = 1;
        std::cout << std::fixed << std::setprecision(precision) << "float: " << c << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(precision) << "double: " << static_cast<double>(c) << std::endl;
        return 0;
    }

    if (check_double(argv[1], c))
    {
        std::cout << red << "the input type is double" << std::endl;
        precision = check_precision(argv[1]);
        cast_char(static_cast<int>(c));
        if (c > INT_MAX || c < INT_MIN)
            std::cout << "int: value overflows" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(c) << std::endl;
        if (precision == 0)
            precision = 1;
        std::cout << std::fixed << std::setprecision(precision) << "float: " << static_cast<float>(c) <<  "f" << std::endl;
        std::cout << std::fixed << std::setprecision(precision) << "double: " << c << std::endl;
        return 0;
    }
    std::cout << red << "input does not make sense" << std::endl;
    std::cout << reset;
    return 0;
}