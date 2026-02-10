#include <iostream>

void FindMax(int a, int b, int c, int d, int **numbers, int &max_i, int &max_j)
{
    int max_val = numbers[a][b];
    max_i = a;
    max_j = b;
    for (int i = a; i < c; i++)
    {
        for (int j = b; j < d; j++)
        {
            if (numbers[i][j] > max_val)
            {
                max_val = numbers[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
}

void Answer(int &a, int &b, int h, int w, int x, int y, int **numbers)
{
    int max_i = a;
    int max_j = b;
    while (true)
    {
        int new_max_i = 0;
        int new_max_j = 0;
        FindMax(max_i, max_j, std::min(max_i + h, x), std::min(max_j + w, y), numbers, new_max_i, new_max_j);
        if (new_max_i == max_i && new_max_j == max_j)
        {
            break;
        }
        max_i = new_max_i;
        max_j = new_max_j;
    }
    a = max_i;
    b = max_j;
}

int **Input(int x, int y)
{
    int **arr = new int *[x];
    for (int i = 0; i < x; i++)
    {
        arr[i] = new int[y];
        for (int j = 0; j < y; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    return arr;
}

int main()
{
    int x = 0;
    int y = 0;
    int h = 0;
    int w = 0;
    std::cin >> x >> y >> h >> w;
    int **numbers = Input(x, y);
    int x_end = 0;
    int y_end = 0;
    Answer(x_end, y_end, h, w, x, y, numbers);
    std::cout << x_end << ' ' << y_end << std::endl;
    for (int i = 0; i < x; i++)
    {
        delete[] numbers[i];
    }
    delete[] numbers;
}