#include <iostream>

int LowerBound(int *arr, int n, int x)
{
    int l = 0;
    int r = n;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int UpperBound(int *arr, int n, int x)
{
    int l = 0;
    int r = n;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int main()
{
    int n = 0;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int x = 0;
        std::cin >> x;
        std::cout << (UpperBound(arr, n, x) - LowerBound(arr, n, x)) << '\n';
    }
    delete[] arr;
}