#include <iostream>
#include <vector>

bool BinarySearch(std::vector<int> &v, int key)
{
    int l = 0;
    int r = v.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] == key)
        {
            return true;
        }
        if (v[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::vector<int> b(k, 1.0);
    for (int i = 0; i < k; i++)
    {
        std::cin >> b[i];
    }
    for (int i = 0; i < k; i++)
    {
        if (BinarySearch(a, b[i]))
        {
            std::cout << "YES" << "\n";
        }
        else
        {
            std::cout << "NO" << "\n";
        }
    }
}