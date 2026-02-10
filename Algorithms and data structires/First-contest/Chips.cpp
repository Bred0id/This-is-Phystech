#include <iostream>

void Clean(int n);

void Fill(int n)
{
    if (n < 3)
    {
        for (int i = 1; i < n + 1; i++)
        {
            std::cout << i << " ";
        }
        return;
    }
    Fill(n - 1);
    Clean(n - 2);
    std::cout << n << " ";
    Fill(n - 2);
}

void Clean(int n)
{
    if (n < 3)
    {
        for (int i = -n; i < 0; i++)
        {
            std::cout << i << " ";
        }
        return;
    }
    Clean(n - 2);
    std::cout << -n << " ";
    Fill(n - 2);
    Clean(n - 1);
}

int main()
{
    int n = 0;
    std::cin >> n;
    Fill(n);
}