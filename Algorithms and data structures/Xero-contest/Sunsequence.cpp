#include <iostream>
#include <vector>

std::vector<char> Input()
{
    std::vector<char> str;
    char c = '0';
    while (std::cin.get(c) && c != '\n')
    {
        str.push_back(c);
    }
    return str;
}

int Answer(std::vector<char> &str, std::vector<char> &pstr,
           std::vector<size_t> &index)
{
    size_t l = 0;
    size_t r = str.size();
    while (l < r)
    {
        size_t mid = (r + l) / 2;
        std::vector<bool> del(str.size(), true);
        for (size_t i = 0; i < mid; i++)
        {
            del[index[i]] = false;
        }
        size_t i = 0;
        size_t j = 0;
        while (i < str.size() && j < pstr.size())
        {
            if (del[i] && str[i] == pstr[j])
            {
                j++;
            }
            i++;
            if (j == pstr.size() || i == str.size())
            {
                if (j == pstr.size())
                {
                    l = mid + 1;
                    break;
                }
                r = mid;
                break;
            }
        }
    }
    return l - 1;
}

int main()
{
    std::vector<char> str = Input();
    std::vector<char> pstr = Input();
    std::vector<size_t> index(str.size(), 0);
    for (size_t i = 0; i < index.size(); i++)
    {
        std::cin >> index[i];
        index[i] -= 1;
    }
    std::cout << Answer(str, pstr, index);
}