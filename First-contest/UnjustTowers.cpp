#include <iostream>

void Move(int n, bool flag)
{
    if (n == 1)
    {
        if (flag)
        {
            std::cout << 1 << " " << 1 << " " << 3 << "\n";
        }
        else
        {
            std::cout << 1 << " " << 3 << " " << 1 << "\n";
        }
    }
    if (n > 1)
    {
        if (flag)
        {
            Move(n - 1, true);
            std::cout << n << " " << 1 << " " << 2 << "\n";
            Move(n - 1, false);
            std::cout << n << " " << 2 << " " << 3 << "\n";
            Move(n - 1, true);
        }
        else
        {
            Move(n - 1, false);
            std::cout << n << " " << 3 << " " << 2 << "\n";
            Move(n - 1, true);
            std::cout << n << " " << 2 << " " << 1 << "\n";
            Move(n - 1, false);
        }
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    Move(n, true);
}