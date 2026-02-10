#include <cstring>
#include <iostream>
#include <algorithm>

size_t Distance(char *str1, size_t len1, char *str2, size_t len2)
{
    auto dp = new size_t *[len1 + 1];
    for (size_t i = 0; i <= len1; ++i)
    {
        dp[i] = new size_t[len2 + 1];
    }
    for (size_t i = 0; i <= len1; ++i)
    {
        dp[i][0] = i;
    }
    for (size_t j = 0; j <= len2; ++j)
    {
        dp[0][j] = j;
    }
    for (size_t i = 1; i <= len1; ++i)
    {
        for (size_t j = 1; j <= len2; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }
    size_t ans = dp[len1][len2];
    for (size_t i = 0; i <= len1; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

char *Input()
{
    char *str = new char[5001];
    char symbol = '0';
    size_t i = 0;
    while (std::cin.get(symbol))
    {
        if (symbol == '\n' || symbol == '\0')
        {
            break;
        }
        str[i++] = symbol;
    }
    str[i] = '\0';
    return str;
}

int main()
{
    char *str1 = Input();
    char *str2 = Input();
    std::cout << Distance(str1, std::strlen(str1), str2, std::strlen(str2));
    delete[] str1;
    delete[] str2;
}