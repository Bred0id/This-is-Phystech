#include <iostream>
#include <cstdint>

int64_t InputStr(char *str)
{
    int64_t i = 0;
    int64_t count = 0;
    while (count < 2)
    {
        std::cin.get(str[i]);
        if (str[i] == '\n')
        {
            count++;
        }
        i++;
    }
    return i;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t k = 0;
    std::cin >> k;
    char *str = new char[1000010]{};
    int64_t len = InputStr(str);
    int64_t count = 0;
    int64_t l = 0;
    for (int64_t i = 1; i < len - 1 - k; i++)
    {
        if (str[i] == str[i + k])
        {
            l++;
        }
        else
        {
            l = 0;
        }
        count += l;
    }
    delete[] str;
    std::cout << count;
}