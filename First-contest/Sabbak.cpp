#include <iostream>

void Move(int n, int start, int fin)
{
    if (n > 0)
    {
        Move(n - 1, start, 6 - start - fin);
        std::cout << n << " " << start << " " << fin << "\n";
        Move(n - 1, 6 - start - fin, fin);
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    Move(n, 1, 3);
}