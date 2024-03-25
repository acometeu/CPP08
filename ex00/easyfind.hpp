#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T  &target, int src)
{
    typename T::iterator    iter = std::find(target.begin(), target.end(), src);

    if (iter == target.end())
        throw std::exception();
    return(iter);
}

#endif