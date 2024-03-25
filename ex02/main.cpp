#include "Span.hpp"
#include <array>
#include <vector>

int main(void)
{
{
    /*  test du test  */
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "sp[0] = " << sp[0] << std::endl;
    std::cout << "sp[1] = " << sp[1] << std::endl;
    std::cout << "sp[2] = " << sp[2] << std::endl;
    std::cout << "sp[3] = " << sp[3] << std::endl;
    std::cout << "sp[4] = " << sp[4] << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    {
        /*  test copy and operator = */
        Span    copy(sp);
        Span    equal = sp;
        std::cout << "copy test" << std::endl;
        std::cout << "copy[0] = " << copy[0] << std::endl;
        std::cout << "copy[1] = " << copy[1] << std::endl;
        std::cout << "copy[2] = " << copy[2] << std::endl;
        std::cout << "copy[3] = " << copy[3] << std::endl;
        std::cout << "copy[4] = " << copy[4] << std::endl;
        std::cout << std::endl;
        std::cout << "equal test" << std::endl;
        std::cout << "equal[0] = " << equal[0] << std::endl;
        std::cout << "equal[1] = " << equal[1] << std::endl;
        std::cout << "equal[2] = " << equal[2] << std::endl;
        std::cout << "equal[3] = " << equal[3] << std::endl;
        std::cout << "equal[4] = " << equal[4] << std::endl;
    }
}
std::cout << std::endl << std::endl;
{
    /*  petit test  */
    Span    test;

    std::cout << "test max is : " << test.get_max() <<  std::endl;
    std::cout << "test number is : " << test.get_number() <<  std::endl;
    try
    {
        std::cout << "test[0] = " << test[0] <<  std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    test.addNumber(20);
    test.addNumber(30);
    test.addNumber(40);
    test.addNumber(-50);
    test.addNumber(-60);
    test.addNumber(70);
    test.addNumber(-80);
    test.addNumber(90);
    test.addNumber(32);
    test.addNumber(35);
    try
    {
        int i = 0;

        while (i < 10)
        {
            std::cout << "test[" << i << "] = " << test[i] <<  std::endl;
            i++;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "shortest_span = " << test.shortestSpan() <<  std::endl;
        std::cout << "longest_span = " << test.longestSpan() <<  std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
std::cout << std::endl << std::endl;

{
    /* 10001 numbers */
    Span    test(10001);
    int i = 0;

    while (i < 6000)
    {
        test.addNumber(i * 999 + 7);
        i++;
    }
    test.addNumber(3599 *999 + 677);
    while (i < 10000)
    {
        test.addNumber(i * 999 + 7);
        i++;
    }
    std::cout << "boucle 10000 longest Span = " << test.longestSpan() << std::endl;
    std::cout << "boucle 10000 shortest Span = " << test.shortestSpan() << std::endl;
}
std::cout << std::endl << std::endl;

{
    /* TUH-TUH-TES-TUH  */
    std::array<int, 5>  array = {-55555, 6236345, 49218743, -2147483648, 2147483647};
    std::vector<int>    biguh(10000, 7); 
    Span                for_harray(5);
    Span                for_biguh(10001);

    try
    {
        for_harray.addManyNumber(array);
        std::cout << "array[0] = " << for_harray[0] << std::endl;
        std::cout << "array[1] = " << for_harray[1] << std::endl;
        std::cout << "array[2] = " << for_harray[2] << std::endl;
        std::cout << "array[3] = " << for_harray[3] << std::endl;
        std::cout << "array[4] = " << for_harray[4] << std::endl;
        std::cout << "longest span for Harray : " << for_harray.longestSpan() << std::endl;
        std::cout << "shortest span for Harray : " << for_harray.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        for_biguh.addManyNumber(biguh);
        for_biguh.addNumber(999999999);
        std::cout << "longest span for biguh : " << for_biguh.longestSpan() << std::endl;
        std::cout << "shortest span for biguh : " << for_biguh.shortestSpan() << std::endl;
        /*  random valid number   */
        std::cout << "random valid number 1 : " << for_biguh[5555] << std::endl;
        std::cout << "random valid number 2 : " << for_biguh[55] << std::endl;
        // std::cout << "random valid number 3 : " << for_biguh[55555] << std::endl;
        std::cout << "random valid number 4 : " << for_biguh[10000] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

}
    return(0);
}