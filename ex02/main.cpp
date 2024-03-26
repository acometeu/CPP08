#include "MutantStack.hpp"
#include <array>
#include <vector>
#include <list>

int main(void)
{
{
    /*TEST SUBJECT */
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

std::cout << std::endl << std::endl;
{
    /*TEST SUBJECT to compare with list */
    std::list<int>  mstack;

    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << mstack.back() << std::endl;

    mstack.pop_back();

    std::cout << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> s(mstack);
}
std::cout << std::endl << std::endl;


{
    MutantStack<int> test;
    MutantStack<int>::iterator   it;

    std::cout << "test with INT" << std::endl;
    test.push(7);
    std::cout << "top of stack test = " << test.top() << std::endl;
    test.push(999);
    std::cout << "top of stack test = " << test.top() << std::endl;

    it = test.begin();
    std::cout << "iterator it from beningin = " << *it << std::endl;
    it++;
    std::cout << "iterator it from beningin = " << *it << std::endl;
    it --;
    std::cout << "iterator it from beningin = " << *it << std::endl;

    it = test.end();
    it--;
    std::cout << "iterator it from end = " << *it << std::endl << std::endl;
    
    {
        /*  test copy   */   
        MutantStack<int> copy(test);
        MutantStack<int> equal = test;
        MutantStack<int>::iterator   it;

        it = copy.begin();
        std::cout << "copy values :" << std::endl;
        std::cout << *it << std::endl;
        it++;
        std::cout << *it << std::endl << std::endl;

        it = equal.begin(); 
        std::cout << "equal values :" << std::endl;
        std::cout << *it << std::endl;
        it++;
        std::cout << *it << std::endl << std::endl;
    }
}

{
    MutantStack<std::string> test;
    MutantStack<std::string>::iterator   it;

    std::cout << "test with STRING" << std::endl;
    test.push("et vas-y");
    std::cout << "top of stack test = " << test.top() << std::endl;
    test.push("ouioui !");
    std::cout << "top of stack test = " << test.top() << std::endl;

    it = test.begin();
    std::cout << "iterator it from beningin = " << *it << std::endl;
    it++;
    std::cout << "iterator it from beningin = " << *it << std::endl;
    it --;
    std::cout << "iterator it from beningin = " << *it << std::endl;

    it = test.end();
    it--;
    std::cout << "iterator it from end = " << *it << std::endl << std::endl;
    
    {
        /*  test copy   */   
        MutantStack<std::string> copy(test);
        MutantStack<std::string> equal = test;
        MutantStack<std::string>::iterator   it;

        it = copy.begin();
        std::cout << "copy values :" << std::endl;
        std::cout << *it << std::endl;
        it++;
        std::cout << *it << std::endl << std::endl;

        it = equal.begin(); 
        std::cout << "equal values :" << std::endl;
        std::cout << *it << std::endl;
        it++;
        std::cout << *it << std::endl << std::endl;
    }
}
{
    /*  more iterator type  */
    MutantStack<long int> more;

    MutantStack<long int>::reverse_iterator reverse_it;
    MutantStack<long int>::reverse_iterator reverse_it2;
    MutantStack<long int>::const_iterator const_it;
    MutantStack<long int>::const_iterator const_it2;
    MutantStack<long int>::const_reverse_iterator const_reverse_it;
    MutantStack<long int>::const_reverse_iterator const_reverse_it2;

    more.push(1);
    more.push(2);
    more.push(3);
    more.push(4);
    more.push(5);
    more.push(6);
    more.push(7);

    reverse_it = more.rbegin();
    reverse_it2 = more.rend();
    std::cout << "boucle reverse" << std::endl;
    while (reverse_it != reverse_it2)
    {
        std::cout << "reverse_it = " << *reverse_it << std::endl;
        reverse_it++;
    }

    const_it = more.cbegin();
    const_it2 = more.cend();
    while (const_it != const_it2)
    {
        std::cout << "const_it = " << *const_it << std::endl;
        const_it++;
    }

    const_reverse_it = more.crbegin();
    const_reverse_it2 = more.crend();
    while (const_reverse_it != const_reverse_it2)
    {
        std::cout << "const_reverse_it = " << *const_reverse_it << std::endl;
        const_reverse_it++;
    }


}
    return(0);
}