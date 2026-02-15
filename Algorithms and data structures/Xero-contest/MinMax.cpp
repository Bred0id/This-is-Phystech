#include <iostream>
#include <vector>

int BinarySearch(std::vector<int> &a, std::vector<int> &b, int x)
{
    int l = 0;
    int mid = 0;
    int r = a.size();
    while (l < r)
    {
        mid = (l + r) / 2;
        if (b[mid] - a[mid] >= x)
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    int q = 0;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x = 0;
        std::cin >> x;
        int ind = BinarySearch(a, b, x);
        if (ind == 0)
        {
            std::cout << 1 << "\n";
        }
        else if (ind == n)
        {
            std::cout << n << "\n";
        }
        else
        {
            int first_max = std::max(a[ind] + x, b[ind]);
            int second_max = std::max(a[ind - 1] + x, b[ind - 1]);
            if (first_max > second_max)
            {
                std::cout << ind << "\n";
            }
            else
            {
                std::cout << ind + 1 << "\n";
            }
        }
    }
}