#include <iostream>

int Abs(int x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

bool NoHit(int *ver, int *hor, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (hor[i] == hor[len - 1])
        {
            return false;
        }
        if (Abs(hor[i] - hor[len - 1]) == Abs(ver[i] - ver[len - 1]))
        {
            return false;
        }
    }
    return true;
}

int NextQueen(int *ver, int *hor, int len, int n)
{
    if (len == n)
    {
        return 1;
    }
    int count = 0;
    ver[len] = len;
    for (int j = 0; j < n; j++)
    {
        hor[len] = j;
        if (NoHit(ver, hor, len + 1))
        {
            count += NextQueen(ver, hor, len + 1, n);
        }
    }
    return count;
}

int Counter(int n)
{
    int *ver = new int[n];
    int *hor = new int[n];
    int count = 0;
    count = NextQueen(ver, hor, 0, n);
    delete[] ver;
    delete[] hor;
    return count;
}

int main()
{
    int n = -1;
    std::cin >> n;
    std::cout << Counter(n);
}