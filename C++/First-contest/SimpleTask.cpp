#include <iostream>

struct Numbers
{
    int null[6][5] = {{0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int one[6][5] = {{0, 0, 0, 0, 1}, {0, 0, 0, 1, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}};
    int two[6][5] = {{0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 1, 1}};
    int three[6][5] = {{0, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 1, 1, 1, 0}};
    int four[6][5] = {{0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}};
    int five[6][5] = {{0, 1, 1, 1, 1}, {0, 1, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int six[6][5] = {{0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int seven[6][5] = {{0, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}};
    int eight[6][5] = {{0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int nine[6][5] = {{0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 1, 1, 1, 0}};
};

void Input(int ***clockface)
{
    for (int k = 0; k < 4; k++)
    {
        clockface[k] = new int *[6];
        for (int i = 0; i < 6; i++)
        {
            clockface[k][i] = new int[5];
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                char symbol = '0';
                std::cin >> symbol;
                if (symbol == '#')
                {
                    clockface[j][i][k] = 1;
                }
                else
                {
                    clockface[j][i][k] = 0;
                }
            }
        }
    }
}

bool IsNull(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.null[i][j] && numbers.null[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsOne(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.one[i][j] && numbers.one[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsTwo(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.two[i][j] && numbers.two[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsThree(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.three[i][j] && numbers.three[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsFour(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.four[i][j] && numbers.four[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsFive(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.five[i][j] && numbers.five[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsSix(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.six[i][j] && numbers.six[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsSeven(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.seven[i][j] && numbers.seven[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsEight(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.eight[i][j] && numbers.eight[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsNine(int **number, Numbers numbers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (number[i][j] != numbers.nine[i][j] && numbers.nine[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

char *Check(int **number, Numbers numbers, int &count)
{
    char *res = new char[10]{};
    if (IsNull(number, numbers))
    {
        res[count++] = '0';
    }
    if (IsOne(number, numbers))
    {
        res[count++] = '1';
    }
    if (IsTwo(number, numbers))
    {
        res[count++] = '2';
    }
    if (IsThree(number, numbers))
    {
        res[count++] = '3';
    }
    if (IsFour(number, numbers))
    {
        res[count++] = '4';
    }
    if (IsFive(number, numbers))
    {
        res[count++] = '5';
    }
    if (IsSix(number, numbers))
    {
        res[count++] = '6';
    }
    if (IsSeven(number, numbers))
    {
        res[count++] = '7';
    }
    if (IsEight(number, numbers))
    {
        res[count++] = '8';
    }
    if (IsNine(number, numbers))
    {
        res[count++] = '9';
    }
    if (count < 1)
    {
        delete[] res;
        char *ans = new char[1];
        ans[0] = 'e';
        return ans;
    }
    char *ans = new char[count];
    for (int i = 0; i < count; i++)
    {
        ans[i] = res[i];
    }
    delete[] res;
    return ans;
}

void Delete(int ***clockface)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; ++j)
        {
            delete[] clockface[i][j];
        }
        delete[] clockface[i];
    }
    delete[] clockface;
}

int main()
{
    Numbers numbers;
    int ***clockface = new int **[4];
    Input(clockface);
    char **ans = new char *[4]{};
    int *count = new int[4]{};
    for (int i = 0; i < 4; i++)
    {
        ans[i] = Check(clockface[i], numbers, count[i]);
        if (ans[i][0] == 'e')
        {
            std::cout << "ERROR";
            for (int j = 0; j < 4; j++)
            {
                delete[] ans[j];
            }
            delete[] ans;
            delete[] count;
            Delete(clockface);
            return 0;
        }
    }
    int count_first = 0;
    int count_second = 0;
    int hours = 0;
    int minutes = 0;
    int ans_hour = 0;
    int ans_minute = 0;
    for (int i = 0; i < count[0]; i++)
    {
        for (int j = 0; j < count[1]; j++)
        {
            hours = (ans[0][i] - '0') * 10 + (ans[1][j] - '0');
            if (hours < 24)
            {
                count_first++;
                ans_hour = hours;
            }
        }
    }
    for (int i = 0; i < count[2]; i++)
    {
        for (int j = 0; j < count[3]; j++)
        {
            minutes = (ans[2][i] - '0') * 10 + (ans[3][j] - '0');
            if (minutes < 60)
            {
                count_second++;
                ans_minute = minutes;
            }
        }
    }
    if (count_first > 1 || count_second > 1)
    {
        std::cout << "AMBIGUITY";
        for (int i = 0; i < 4; i++)
        {
            delete[] ans[i];
        }
        delete[] ans;
        delete[] count;
        Delete(clockface);
        return 0;
    }
    if (count_first == 0 || count_second == 0)
    {
        std::cout << "ERROR";
        for (int i = 0; i < 4; i++)
        {
            delete[] ans[i];
        }
        delete[] ans;
        delete[] count;
        Delete(clockface);
        return 0;
    }
    std::cout << ans_hour / 10 << ans_hour % 10 << ':' << ans_minute / 10 << ans_minute % 10;
    for (int i = 0; i < 4; i++)
    {
        delete[] ans[i];
    }
    delete[] ans;
    delete[] count;
    Delete(clockface);
    return 0;
}