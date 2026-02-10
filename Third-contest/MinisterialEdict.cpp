#include <iostream>
#include <cstdint>

int64_t Answer(int n, int number, int64_t **answers)
{
    if (n == 1)
    {
        answers[number][n] = 1;
        return answers[number][1];
    }
    if (number == 0)
    {
        if (answers[number][n] != 0)
        {
            return answers[number][n];
        }
        answers[number][n] = Answer(n - 1, 4, answers) + Answer(n - 1, 6, answers);
        return answers[number][n];
    }
    if (number == 1)
    {
        if (answers[number][n] != 0)
        {
            return answers[number][n];
        }
        answers[number][n] = Answer(n - 1, 6, answers) + Answer(n - 1, 8, answers);
        return answers[number][n];
    }
    if (number == 2)
    {
        if (answers[number][n] != 0)
        {
            return answers[number][n];
        }
        answers[number][n] = Answer(n - 1, 7, answers) + Answer(n - 1, 9, answers);
        return answers[number][n];
    }
    if (number == 3)
    {
        if (answers[number][n] != 0)
        {
            return answers[number][n];
        }
        answers[number][n] = Answer(n - 1, 4, answers) + Answer(n - 1, 8, answers);
        return answers[number][n];
    }
    if (number == 4)
    {
        if (answers[number][n] != 0)
        {
            return answers[number][n];
        }
        answers[number][n] = Answer(n - 1, 0, answers) + Answer(n - 1, 3, answers) + Answer(n - 1, 9, answers);
        return answers[number][n];
    }
    if (number == 6)
    {
        if (answers[number][n] != 0)
        {
            return answers[number][n];
        }
        answers[number][n] = Answer(n - 1, 0, answers) + Answer(n - 1, 1, answers) + Answer(n - 1, 7, answers);
        return answers[number][n];
    }
    if (number == 7)
    {
        if (answers[number][n] != 0)
        {
            return answers[number][n];
        }
        answers[number][n] = Answer(n - 1, 2, answers) + Answer(n - 1, 6, answers);
        return answers[number][n];
    }
    if (number == 8)
    {
        if (answers[number][n] != 0)
        {
            return answers[number][n];
        }
        answers[number][n] = Answer(n - 1, 1, answers) + Answer(n - 1, 3, answers);
        return answers[number][n];
    }
    if (number == 9)
    {
        if (answers[number][n] != 0)
        {
            return answers[number][n];
        }
        answers[number][n] = Answer(n - 1, 4, answers) + Answer(n - 1, 2, answers);
        return answers[number][n];
    }
    return 0;
}

int main()
{
    int n = 0;
    std::cin >> n;
    int64_t ans = 0;
    auto **answers = new int64_t *[10];
    for (int i = 0; i < 10; i++)
    {
        answers[i] = new int64_t[n + 1]{};
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 0 || i == 8)
        {
            continue;
        }
        ans += Answer(n, i, answers);
    }
    std::cout << ans;
    for (int i = 0; i < 10; i++)
    {
        delete[] answers[i];
    }
    delete[] answers;
}