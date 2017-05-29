#include <iostream>
#include <vector>
template<class It, class Cmp>
void qsort(It first, It last, Cmp cmp)
{
    if (first != last)
    {
        It left = first;
        It right = last;
        It pivot = left++;
        while (left != right)
        {
            if (cmp(*left, *pivot))
            {
                ++left;
            }
            else
            {
                while ((left != --right) && cmp(*pivot, *right));
                std::swap(*left, *right);
            }
        }

        --left;
        std::swap(*first, *left);
        qsort(first, left, cmp);
        qsort(right, last, cmp);
    }
}

int main()
{
    std::vector<int> a = { 23, -1, 2, 1, 0, 0, 9, 7 };
    std::cout << "Before qsort" << std::endl;
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::less<int> l;
    qsort(a.begin(), a.end(), l);
    std::cout << std::endl << std::endl << "After qsort" << std::endl;
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}