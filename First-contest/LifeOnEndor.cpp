#include <iostream>

// Вроде я разобрался, но если честно не понимаю почему эта реализация сильно лучше предыдущей

void CreateArrays(int **&arr, int **&arr_next, int len)
{
    arr = new int *[len];
    arr_next = new int *[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = new int[len];
        arr_next[i] = new int[len];
        for (int j = 0; j < len; j++)
        {
            std::cin >> arr[i][j];
        }
    }
}

void Turn(int **arr, int **arr_next, int len, int cnt_turns)
{
    for (int turn = 0; turn < cnt_turns; turn++)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                arr_next[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                int count = 0;
                for (int di = -1; di < 2; di++)
                {
                    for (int dj = -1; dj < 2; dj++)
                    {
                        if (di != 0 || dj != 0)
                        {
                            int ni = i + di;
                            int nj = j + dj;
                            if (ni >= 0 && ni < len && nj >= 0 && nj < len)
                            {
                                count += arr[ni][nj];
                            }
                        }
                    }
                }
                if (arr[i][j] == 1)
                {
                    if (count < 2 || count > 3)
                    {
                        arr_next[i][j] = 0;
                    }
                }
                else
                {
                    if (count == 3)
                    {
                        arr_next[i][j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                arr[i][j] = arr_next[i][j];
            }
        }
    }
}

void DeleteArrays(int **arr, int **arr_next, int len)
{
    for (int i = 0; i < len; i++)
    {
        delete[] arr[i];
        delete[] arr_next[i];
    }
    delete[] arr;
    delete[] arr_next;
}

void Input(int &len, int &cnt_turns)
{
    std::cin >> len >> cnt_turns;
}

void PrintMass(int **arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    int len = 0;
    int cnt_turns = 0;
    Input(len, cnt_turns);
    int **arr = nullptr;
    int **arr_next = nullptr;
    CreateArrays(arr, arr_next, len);
    Turn(arr, arr_next, len, cnt_turns);
    PrintMass(arr, len);
    DeleteArrays(arr, arr_next, len);
}