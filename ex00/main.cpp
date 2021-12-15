#include <string>
#include <iostream>

bool check_char(std::string a)
{
    if (a.length() == 1)
    {
        if(a[0] > 31 && a[0] < 127)
            return true;
        else
        {
            std::cout << "the character is not displayable" << std::endl;
            return true;
        }
    }
    return false;
}

bool check_int(std::string a)
{
    int size = a.length();
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if ((i == 0 && a[i] == '-') || isdigit(a[i]))
            count++;
    }
    if (count == size)
        return true;
    else
        return false;
}
bool check_float(std::string a)
{

}
bool check_double(std::string a)
{

}


int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;

}