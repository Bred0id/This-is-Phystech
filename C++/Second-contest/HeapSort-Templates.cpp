#ifndef SOLUTION_HPP
#define SOLUTION_HPP

template <class T>
void MakeHeap(T *begin, T *end)
{
    int n = end - begin;
    if (n <= 1)
    {
        return;
    }
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        int parent = i;
        while (true)
        {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            if (left >= n)
            {
                break;
            }
            int biggest = parent;
            if (*(begin + biggest) < *(begin + left))
            {
                biggest = left;
            }
            if (right < n && *(begin + biggest) < *(begin + right))
            {
                biggest = right;
            }
            if (biggest != parent)
            {
                T tmp = *(begin + parent);
                *(begin + parent) = *(begin + biggest);
                *(begin + biggest) = tmp;
                parent = biggest;
            }
            else
            {
                break;
            }
        }
    }
}

template <class T>
void SortHeap(T *begin, T *end)
{
    int n = end - begin;
    if (n <= 1)
    {
        return;
    }
    for (int i = n - 1; i > 0; --i)
    {
        T tmp = *begin;
        *begin = *(begin + i);
        *(begin + i) = tmp;
        int parent = 0;
        while (true)
        {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            if (left >= i)
            {
                break;
            }
            int biggest = parent;
            if (*(begin + biggest) < *(begin + left))
            {
                biggest = left;
            }
            if (right < i && *(begin + biggest) < *(begin + right))
            {
                biggest = right;
            }
            if (biggest != parent)
            {
                T tmp = *(begin + parent);
                *(begin + parent) = *(begin + biggest);
                *(begin + biggest) = tmp;
                parent = biggest;
            }
            else
            {
                break;
            }
        }
    }
}

#endif