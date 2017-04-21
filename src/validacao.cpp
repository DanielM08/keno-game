#include <iostream>
#include <iterator>
#include <algorithm>

int *valida(int *first, int *last);
int *unique(int *first, int *last);
int *compact(int *first, int *last);

int main()
{
    int Vet[] = {-1, -7, -20, 0, 1, 4, 9, 13, 16, 21, 22, 25,27, 42, 47, 50, 63, 70, 71, 78, 80, 90, 100, 101};

    std::cout << ">>>Vetor \n";
    std::cout << ">>>Vet = [";
    for (auto i = std::begin(Vet); i != std::end(Vet); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "]\n";

    auto last = valida(std::begin(Vet), std::end(Vet));

    std::cout << ">>>Vetor de elementos únicos:  \n";
    std::cout << ">>>Vet = [";
    for (auto i = std::begin(Vet); i != last; ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "]\n";

    return (0);
}

int *unique(int *first, int *last)
{
    auto slow = first + 1;

    for (auto fast(first + 1); fast != last; fast++)
    {
        int k = 0;
        for (auto j(first); j != slow; j++)
        {
            if (*fast == *j)
            {
                k++;
            }
        }
        if (k == 0)
        {
            std::swap(*slow, *fast);
            slow++;
        }
    }
    return slow;
}

int *compact(int *first, int *last)
{
    while (first != last)
    {
        if (*first <= 0)
        {
            for (auto j(first); j != (last - 1); j++)
            {
                *j = *(j + 1);
            }
            last--;
        }
        else
        {
            first++;
        }
    }
    return first;
}

int *valida(int *first, int *last)
{
    auto compacted = compact(first, last);
    auto uniques = unique(first, compacted);

    while(first != first+15)
    {
        if( *(first) > 80 )
        {
            return first;
        }
        first++;

    }

    return first;
}