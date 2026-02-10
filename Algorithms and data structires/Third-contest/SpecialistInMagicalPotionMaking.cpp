#include <iostream>
#include <cstdint>

int main()
{
    int64_t n = 0;
    std::cin >> n;
    auto **arr = new int64_t *[3]{};
    arr[0] = new int64_t[n + 1]{};
    arr[1] = new int64_t[n + 1]{};
    arr[2] = new int64_t[n + 1]{};
    arr[0][1] = 1;
    arr[1][1] = 1;
    arr[2][1] = 1;
    for (int64_t i = 2; i < n + 1; i++)
    {
        arr[2][i] = arr[0][i - 1] + arr[1][i - 1];
        arr[1][i] = arr[0][i - 1] + arr[1][i - 1] + arr[2][i - 1];
        arr[0][i] = arr[0][i - 1] + arr[1][i - 1] + arr[2][i - 1];
    }
    std::cout << arr[1][n] + arr[0][n] + arr[2][n] << std::endl;
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr[2];
    delete[] arr;
}