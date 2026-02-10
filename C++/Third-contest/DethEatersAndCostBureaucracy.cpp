#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int *arr = new int[2001]{};
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        std::cin >> x;
        arr[x + 1000]++;
    }
    std::cin >> n;
    std::cout << arr[n + 1000];
    delete[] arr;
}