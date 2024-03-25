#include "Span.hpp"

Span::Span(void) : _max(10), _number(0), _member(new int[10])
{
    return;
}

Span::Span(unsigned int N) : _max(N), _number(0), _member(new int[N])
{
    return;
}

Span::Span(Span const &src) : _max(src.get_max()), _number(src.get_number()), _member(new int[src.get_number()])
{
    unsigned int i = 0;

    while (i < this->_number)
    {
        _member[i] = src[i];
        i++;
    }
    return;
}

Span::~Span(void)
{
    delete [] this->_member;
    return;
}

Span  &Span::operator=(Span const &src)
{
    unsigned int    i = 0;
    unsigned int    number = src.get_number();

    if (this->_max < number)
        throw NotEnoughSpaceException();
    while (i < number)
    {
        this->_member[i] = src[i];
        i++;
    }
    return (*this);
}

int    Span::operator[](unsigned int index) const
{
    if (index >= this->_number)
        throw OutOfBoundsException();
    return(this->_member[index]);
}

unsigned int	Span::get_max(void) const
{
    return(this->_max);
}

unsigned int	Span::get_number(void) const
{
    return(this->_number);
}

void 			Span::addNumber(int new_nbr)
{
    unsigned int    i = this->_number;

    if (i >= this->_max)
        throw NotEnoughSpaceException();
    this->_member[i] = new_nbr;
    this->_number++;
    return;
}

unsigned int             Span::shortestSpan(void) const
{
    unsigned int    i = 0;
    unsigned int    j;
    unsigned int    shortest_span;
    unsigned int    temp;

    if (this->_number < 2)
        throw NotEnoughNumberException();
    if (this->_member[0] > this->_member[1])
        shortest_span = this->_member[0] - this->_member[1];
    else
        shortest_span = this->_member[1] - this->_member[0];
    if (shortest_span == 0)
        return(0);
    while (i < this->_number - 1)
    {
        j = i + 1;
        while (j < this->_number)
        {
            if (this->_member[i] > this->_member[j])
            {
                temp = this->_member[i] - this->_member[j];
                if (temp < shortest_span)
                {
                    if (!temp)
                        return(0);
                    shortest_span = temp;
                }
            }
            else
            {
                temp = this->_member[j] - this->_member[i];
                if (temp < shortest_span)
                {
                    if (!temp)
                        return(0);
                    shortest_span = temp;
                }
            }
            j++;
        }
        i++;
    }
    return(shortest_span);
}

unsigned int				Span::longestSpan(void) const
{
    unsigned int    i = 2;
    int             min;
    int             max;

    if (this->_number < 2)
        throw NotEnoughNumberException();
    if (this->_member[0] < this->_member[1])
    {
        min = this->_member[0];
        max = this->_member[1];
    }
    else
    {
        min = this->_member[1];
        max = this->_member[0];
    }
    while (i < this->_number)
    {
        if (this->_member[i] < min)
            min = this->_member[i];
        if (this->_member[i] > max)
            max = this->_member[i];
        i++;
    }
    return (max - min);
}