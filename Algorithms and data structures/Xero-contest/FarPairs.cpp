#include <iostream>
#include <vector>

int BinarySearch(const std::vector<int> &arr, long long x)
{
    int l = 0;
    int r = arr.size();
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    int x = 0;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long nearest = a[i] + x;
        int j = BinarySearch(a, nearest);
        ans += (n - j);
    }
    std::cout << ans;
}