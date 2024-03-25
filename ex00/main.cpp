#include "easyfind.hpp"
#include <array>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <set>

int main(void)
{
{
    /*  test for array */
    std::array<int, 5> test1 = {1, 2, 3, 4, 5};
    std::array<int, 5>::iterator i1;

    try
    {
        i1 = easyfind<std::array<int, 5>>(test1, 1);
        std::cout << "match found for array : " << *i1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "no match found for array" << std::endl;
    }
}

{
    /*  test for list */
    std::list<int> test2 = {1, 2, 3, 4, 5};
    std::list<int>::iterator i2;
    
    try
    {
        i2 = easyfind<std::list<int>>(test2, 2);
        std::cout << "match found for list : " << *i2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "no match found for list" << std::endl;
    }
}

{
    /*  test for vector */
    std::vector<int> test3 = {1, 2, 3, 4, 5};
    std::vector<int>::iterator i3;
    try
    {
        i3 = easyfind<std::vector<int>>(test3, 3);
        std::cout << "match found for vector : " << *i3 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "no match found for vector" << std::endl;
    }
}

{
    /*  test for deque */
    std::deque<int> test4 = {1, 2, 3, 4, 5};
    std::deque<int>::iterator i4;
    try
    {
        i4 = easyfind<std::deque<int>>(test4, 4);
        std::cout << "match found for deque : " << *i4 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "no match found for deque" << std::endl;
    }
}

{
    /*  test for forward_list */
    std::forward_list<int> test5 = {1, 2, 3, 4, 5};
    std::forward_list<int>::iterator i5;
    try
    {
        i5 = easyfind<std::forward_list<int>>(test5, 5);
        std::cout << "match found for forward_list : " << *i5 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "no match found for forward_list" << std::endl;
    }
}

{
    /*  test for set */
    std::set<int> test6 = {6, 1, 0, 2, 3, 4, 5};
    std::set<int>::iterator i6;

    try
    {
        i6 = easyfind<std::set<int>>(test6, 1);
        std::cout << "match found for forward_list : " << *i6 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "no match found for forward_list" << std::endl;
    }
}

{
    /*  test for multiset */
    std::multiset<int> test7 = {6, 2, 1, 0, 2, 3, 4, 5};
    std::multiset<int>::iterator i7;

    try
    {
        i7 = easyfind<std::multiset<int>>(test7, 2);
        std::cout << "match found for multiset : " << *i7 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "no match found for multiset" << std::endl;
    }
}



    return(0);
}