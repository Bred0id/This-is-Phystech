#include <iostream>

int LCS(char *arr1, int m, char *arr2, int n)
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
    for (int i = 0; i <= m; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return lcs_length;
}

int main()
{
    char *arr1 = new char[10001]{};
    int size = 0;
    while (size < 10001 && std::cin.get(arr1[size]) && arr1[size] != '\n')
    {
        ++size;
    }
    char *arr2 = new char[size];
    for (int i = 0; i < size; ++i)
    {
        arr2[i] = arr1[size - 1 - i];
    }
    std::cout << size - LCS(arr1, size, arr2, size);
    delete[] arr1;
    delete[] arr2;
}