#ifndef SOLUTION_HPP
#define SOLUTION_HPP

template <class T>
bool BinarySearch(const T *begin, const T *end, const T &value)
{
    int left = 0;
    int right = end - begin;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (*(begin + mid) < value)
        {
            left = mid + 1;
        }
        else if (value < *(begin + mid))
        {
            right = mid;
        }
        else
        {
            return true;
        }
    }
    return false;
}

template <class T>
const T *LowerBound(const T *begin, const T *end, const T &value)
{
    int left = 0;
    int right = end - begin;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (*(begin + mid) < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return begin + left;
}

template <class T>
const T *UpperBound(const T *begin, const T *end, const T &value)
{
    int left = 0;
    int right = end - begin;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (value < *(begin + mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return begin + left;
}

#endif