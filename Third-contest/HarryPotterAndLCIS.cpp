#include <iostream>

int *LCIS(int *a, int n, int *b, int m, int &size)
{
    if (n == 0 || m == 0)
    {
        size = 0;
        return nullptr;
    }
    int **dp = new int *[n + 1];
    int **best_pos = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[m + 1]{};
        best_pos[i] = new int[m + 1]{};
    }
    int *prev = new int[(n + 1) * (m + 1)]{};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i][j - 1];
            best_pos[i][j] = best_pos[i][j - 1];
            if (a[i - 1] == b[j - 1])
            {
                int best = 1;
                int best_prev = 0;
                for (int k = 1; k <= i - 1; k++)
                {
                    if (a[k - 1] < a[i - 1] && best < dp[k][j] + 1)
                    {
                        best = dp[k][j] + 1;
                        best_prev = best_pos[k][j];
                    }
                }
                if (dp[i][j] < best)
                {
                    dp[i][j] = best;
                    best_pos[i][j] = i * (m + 1) + j;
                    prev[i * (m + 1) + j] = best_prev;
                }
            }
        }
    }
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[pos / (m + 1)][m] < dp[i][m])
        {
            pos = best_pos[i][m];
        }
    }
    size = 0;
    if (pos != 0)
    {
        int b_i = pos / (m + 1);
        size = dp[b_i][m];
    }
    if (size == 0)
    {
        for (int i = 0; i < n + 1; i++)
        {
            delete[] dp[i];
            delete[] best_pos[i];
        }
        delete[] dp;
        delete[] best_pos;
        delete[] prev;
        return nullptr;
    }
    int *answer = new int[size];
    int ind = size - 1;
    while (pos != 0)
    {
        int b_i = pos / (m + 1);
        answer[ind--] = a[b_i - 1];
        pos = prev[pos];
    }
    for (int i = 0; i < n + 1; i++)
    {
        delete[] dp[i];
        delete[] best_pos[i];
    }
    delete[] dp;
    delete[] best_pos;
    delete[] prev;
    return answer;
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
    std::cin >> n;
    int *a = Input(n);
    std::cin >> m;
    int *b = Input(m);
    int size = 0;
    int *result = LCIS(a, n, b, m, size);
    std::cout << size << '\n';
    for (int i = 0; i < size; i++)
    {
        std::cout << result[i] << " ";
    }
    delete[] a;
    delete[] b;
    delete[] result;
}