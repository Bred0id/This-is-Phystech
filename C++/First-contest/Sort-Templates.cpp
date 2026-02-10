#ifndef SOLUTION_HPP
#define SOLUTION_HPP

template <class T1, class T2, class T3>
T3 *Merge(const T1 *first_begin, const T1 *first_end, const T2 *second_begin, const T2 *second_end, T3 *out)
{
    while ((first_begin - first_end < 0) && (second_begin - second_end < 0))
    {
        if (*first_begin < *second_begin)
        {
            *out = *first_begin;
            ++first_begin;
        }
        else
        {
            *out = *second_begin;
            ++second_begin;
        }
        ++out;
    }
    while (first_begin - first_end < 0)
    {
        *out = *first_begin;
        ++first_begin;
        ++out;
    }
    while (second_begin - second_end < 0)
    {
        *out = *second_begin;
        ++second_begin;
        ++out;
    }
    return out;
}

template <class T>
T *Sort(T *begin, T *end)
{
    if (end - begin < 2)
    {
        return begin;
    }
    int mid = (end - begin) / 2;
    T *left = new T[mid];
    T *right = new T[(end - begin) - mid];
    for (int i = 0; i < mid; ++i)
    {
        left[i] = *(begin + i);
    }
    for (int i = 0; i < (end - begin) - mid; ++i)
    {
        right[i] = *(begin + i + mid);
    }
    Sort(left, left + mid);
    Sort(right, right + (end - begin) - mid);
    Merge(left, left + mid, right, right + (end - begin) - mid, begin);
    delete[] left;
    delete[] right;
    return begin;
}

#endif