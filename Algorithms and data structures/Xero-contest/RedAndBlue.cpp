#include <iostream>
#include <vector>

const int cInf = 2e9;

int BinarySearch(const std::vector<int> &arr, int x)
{
    int l = 0;
    int r = arr.size();
    while (l < r)
    {
        int mid = (l + r) / 2;
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

int Min(int a, int b) { return a < b ? a : b; }

int main()
{
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> b[i];
    }
    int min = cInf;
    int l = Min(n, m);
    if (l == n)
    {
        for (int i = 0; i < n; i++)
        {
            int j = BinarySearch(b, a[i]);
            int value = cInf;
            if (j < m)
            {
                value = b[j] - a[i];
            }
            if (j > 0)
            {
                int left_dist = a[i] - b[j - 1];
                value = Min(value, left_dist);
            }
            if (value < min)
            {
                min = value;
            }
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            int j = BinarySearch(a, b[i]);
            int value = cInf;
            if (j < n)
            {
                value = a[j] - b[i];
            }
            if (j > 0)
            {
                int left_dist = b[i] - a[j - 1];
                value = Min(value, left_dist);
            }
            if (value < min)
            {
                min = value;
            }
        }
    }
    std::cout << min;
}