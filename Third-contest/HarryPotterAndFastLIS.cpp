#include <iostream>

int BinarySearch(int *arr, int r, int x)
{
    int l = 0;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int LIS(int *arr, int n)
{
    int *dp = new int[n];
    int *parent = new int[n];
    int *pos = new int[n];
    int len = 0;
    dp[len++] = arr[0];
    parent[0] = -1;
    pos[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = BinarySearch(dp, len, arr[i]);
        if (j == len)
        {
            if (j > 0)
            {
                parent[i] = pos[j - 1];
            }
            else
            {
                parent[i] = -1;
            }
            pos[j] = i;
            dp[len++] = arr[i];
        }
        else
        {
            if (j > 0)
            {
                parent[i] = pos[j - 1];
            }
            else
            {
                parent[i] = -1;
            }
            dp[j] = arr[i];
            pos[j] = i;
        }
    }
    int *lis = new int[n];
    int k = pos[len - 1];
    int t = len - 1;
    while (k != -1)
    {
        lis[t] = arr[k];
        k = parent[k];
        t--;
    }
    delete[] lis;
    delete[] parent;
    delete[] dp;
    delete[] pos;
    return len;
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
    std::cout << LIS(arr, n);
    delete[] arr;
}