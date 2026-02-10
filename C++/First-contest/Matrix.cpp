#include <iostream>
// это ужас какой-то, ну серьезно проверять на натуральные числа?
int **InputMatrix(int n)
{
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}

int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int *Answer(int **matrix, int n)
{
    int *ans = new int[n];
    if (n == 1 && matrix[0][0] == 0)
    {
        ans[0] = 10;
        return ans;
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = 1001;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && matrix[i][j] < ans[i])
            {
                ans[i] = matrix[i][j];
            }
        }
    }
    return ans;
}

bool Correct(int *ans, int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] != 0)
        {
            return false;
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
            if (i != j && matrix[i][j] != Max(ans[i], ans[j]))
            {
                return false;
            }
            if (i != j && matrix[i][j] < 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 0;
    std::cin >> n;
    int **matrix = InputMatrix(n);
    int *ans = Answer(matrix, n);
    if (Correct(ans, matrix, n))
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << ans[i] << " ";
        }
    }
    else
    {
        std::cout << -1;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] ans;
}