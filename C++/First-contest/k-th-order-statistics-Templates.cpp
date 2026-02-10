#ifndef SOLUTION_HPP
#define SOLUTION_HPP

template <typename T>
void KthElement(T *begin, T *kth, T *end)
{
    T *left = begin;
    T *right = end - 1;
    while (left < right)
    {
        T pivot = *(left + (right - left) / 2);
        T *i = left;
        T *j = right;
        T *mid = left;
        while (mid <= j)
        {
            if (*mid < pivot)
            {
                T temp = *i;
                *i = *mid;
                *mid = temp;
                i++;
                mid++;
            }
            else if (pivot < *mid)
            {
                T temp = *mid;
                *mid = *j;
                *j = temp;
                j--;
            }
            else
            {
                mid++;
            }
        }
        if (kth < i)
        {
            right = i - 1;
        }
        else if (kth <= j)
        {
            return;
        }
        else
        {
            left = j + 1;
        }
    }
}

#endif