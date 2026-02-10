#ifndef SOLUTION_HPP
#define SOLUTION_HPP

template <class T>
void PushHeap(T *begin, T *end)
{
    int n = end - begin;
    if (n <= 1)
    {
        return;
    }
    T *element = begin + (n - 1);
    while (element > begin)
    {
        T *parent = begin + ((element - begin - 1) / 2);
        if (*parent < *element)
        {
            T tmp = *parent;
            *parent = *element;
            *element = tmp;
            element = parent;
        }
        else
        {
            break;
        }
    }
}

template <class T>
void PopHeap(T *begin, T *end)
{
    int n = end - begin;
    if (n <= 1)
    {
        return;
    }
    T tmp = *begin;
    *begin = *(end - 1);
    *(end - 1) = tmp;
    T *parent = begin;
    end -= 1;
    while (true)
    {
        T *left_child = begin + (2 * (parent - begin) + 1);
        if (left_child >= end)
        {
            break;
        }
        T *right_child = left_child + 1;
        T *best = left_child;
        if (right_child < end && *best < *right_child)
        {
            best = right_child;
        }
        if (*parent < *best)
        {
            tmp = *parent;
            *parent = *best;
            *best = tmp;
            parent = best;
        }
        else
        {
            break;
        }
    }
}

#endif