#include <iostream>

int CountLIS(int *arr, int n)
{
    int *dp = new int[n]{};
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = (dp[i] + dp[j]) % 1000000;
            }
        }
        count += dp[i];
    }
    delete[] dp;
    return count % 1000000;
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
    std::cin >> n;
    int *arr = Input(n);
    std::cout << CountLIS(arr, n);
    delete[] arr;
}