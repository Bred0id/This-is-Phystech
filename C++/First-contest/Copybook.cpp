#include <iostream>

char **InputArray(int n, int m)
{
    char **arr = new char *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
        for (int j = 0; j < m; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    return arr;
}

int Horizontal(char **arr, int n, int m, int *pos)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != '1')
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            pos[count++] = i;
        }
    }
    return count;
}

int Vertical(char **arr, int n, int m, int *pos)
{
    int count = 0;
    for (int j = 0; j < m; j++)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] != '1')
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            pos[count++] = j;
        }
    }
    return count;
}

int StepBetween(int *pos, int count)
{
    if (count < 2)
    {
        return 0;
    }
    return pos[1] - pos[0];
}

void Answer(char **arr, int n, int m)
{
    int *row_pos = new int[n];
    int *col_pos = new int[m];
    int horizont_count = Horizontal(arr, n, m, row_pos);
    int vertical_count = Vertical(arr, n, m, col_pos);
    int dh = StepBetween(row_pos, horizont_count);
    int dv = StepBetween(col_pos, vertical_count);
    if (horizont_count > 0 && vertical_count > 0 && m > 1 && n > 1)
    {
        std::cout << "Square";
    }
    else if (horizont_count > 1 && vertical_count == 0 && dh < m)
    {
        std::cout << "Line";
    }
    else if (vertical_count > 1 && horizont_count == 0 && dv < n)
    {
        std::cout << "Vertical line";
    }
    else
    {
        std::cout << '?';
    }
    delete[] row_pos;
    delete[] col_pos;
}

int main()
{
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    char **arr = InputArray(n, m);
    Answer(arr, n, m);
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}