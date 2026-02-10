#include <iostream>

void Bag(int n, int m, int *masses, int *prices)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[m + 1]{};
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (masses[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - masses[i - 1]] + prices[i - 1]);
            }
        }
    }
    int i = n;
    int j = m;
    int *subjects = new int[n]{};
    int k = 0;
    while (i > 0 && j >= 0)
    {
        if (dp[i - 1][j] == dp[i][j])
        {
            i--;
        }
        else
        {
            subjects[k++] = i;
            j -= masses[i - 1];
            i--;
        }
    }
    for (int t = k - 1; t >= 0; t--)
    {
        std::cout << subjects[t] << " ";
    }
    for (int t = 0; t < n + 1; t++)
    {
        delete[] dp[t];
    }
    delete[] dp;
    delete[] subjects;
}

int *Input(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    return arr;
}

int main()
{
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    int *masses = Input(n);
    int *prices = Input(n);
    Bag(n, m, masses, prices);
    delete[] masses;
    delete[] prices;
}