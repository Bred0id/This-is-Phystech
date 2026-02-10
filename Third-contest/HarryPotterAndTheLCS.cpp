#include <iostream>

void LCS(int *arr1, int m, int *arr2, int n)
{
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; ++i)
    {
        dp[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (arr1[i - 1] == arr2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                int left = dp[i][j - 1];
                int top = dp[i - 1][j];
                dp[i][j] = (left > top) ? left : top;
            }
        }
    }
    int lcs_length = dp[m][n];
    if (lcs_length > 0)
    {
        int *lcs = new int[lcs_length];
        int i = m;
        int j = n;
        int index = lcs_length - 1;
        while (i > 0 && j > 0)
        {
            if (arr1[i - 1] == arr2[j - 1])
            {
                lcs[index] = arr1[i - 1];
                --index;
                --i;
                --j;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                --i;
            }
            else
            {
                --j;
            }
        }
        for (int k = 0; k < lcs_length; ++k)
        {
            std::cout << lcs[k] << " ";
        }
        delete[] lcs;
    }
    for (int i = 0; i <= m; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;
}

int main()
{
    int m = 0;
    int n = 0;
    std::cin >> m;
    int *arr1 = new int[m];
    for (int i = 0; i < m; ++i)
    {
        std::cin >> arr1[i];
    }
    std::cin >> n;
    int *arr2 = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr2[i];
    }
    LCS(arr1, m, arr2, n);
    delete[] arr1;
    delete[] arr2;
}