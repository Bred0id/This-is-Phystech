#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<long long> a(n + 2, 0);
    std::vector<long long> diff(n + 2, 0);
    std::vector<long long> answers(n + 1, 0);
    std::vector<long long> pref(n + 1, 0);
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        long long l = 0;
        long long r = 0;
        long long b = 0;
        long long d = 0;
        std::cin >> l >> r >> b >> d;
        a[l] += b - l * d;
        a[r + 1] += -(b - l * d);
        diff[l] += d;
        diff[r + 1] += -d;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        diff[i] += diff[i - 1];
        answers[i] = a[i] + diff[i] * i;
    }
    pref[0] = answers[0];
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + answers[i];
    }
    int k = 0;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l = 0;
        int r = 0;
        std::cin >> l >> r;
        std::cout << pref[r] - pref[l - 1] << '\n';
    }
}