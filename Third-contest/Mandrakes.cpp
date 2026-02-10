#include <iostream>
#include <cstdint>

int64_t Min(int64_t a, int64_t b)
{
    return a < b ? a : b;
}

void Merge(int64_t *left_arr, int64_t size_left, int64_t *right_arr, int64_t size_right, int64_t *merged)
{
    int64_t i = 0;
    int64_t j = 0;
    while (i < size_left && j < size_right)
    {
        if (left_arr[i] < right_arr[j])
        {
            merged[i + j] = left_arr[i];
            i++;
        }
        else
        {
            merged[i + j] = right_arr[j];
            j++;
        }
    }
    while (i < size_left)
    {
        merged[i + j] = left_arr[i];
        i++;
    }
    while (j < size_right)
    {
        merged[i + j] = right_arr[j];
        j++;
    }
}

void MergeSort(int64_t *arr, int64_t size)
{
    if (size < 2)
    {
        return;
    }
    int64_t mid = size / 2;
    auto left_arr = new int64_t[mid];
    auto right_arr = new int64_t[size - mid];
    for (int64_t i = 0; i < mid; i++)
    {
        left_arr[i] = arr[i];
    }
    for (int64_t i = 0; i < size - mid; i++)
    {
        right_arr[i] = arr[mid + i];
    }
    MergeSort(left_arr, mid);
    MergeSort(right_arr, size - mid);
    Merge(left_arr, mid, right_arr, size - mid, arr);
    delete[] left_arr;
    delete[] right_arr;
}

int64_t Answer(int64_t *mass, int64_t n)
{
    MergeSort(mass, n);
    auto dp = new int64_t[n + 1];
    dp[0] = 0;
    dp[1] = 1000000000;
    for (int64_t i = 2; i <= n; ++i)
    {
        dp[i] = 1000000000;
        for (int64_t j = 0; j <= i - 2; ++j)
        {
            dp[i] = Min(dp[i], dp[j] + (mass[i - 1] - mass[j]));
        }
    }
    int64_t ans = dp[n];
    delete[] dp;
    return ans;
}

int main()
{
    int64_t n = 0;
    std::cin >> n;
    auto mass = new int64_t[n];
    for (int64_t i = 0; i < n; ++i)
    {
        std::cin >> mass[i];
    }
    std::cout << Answer(mass, n) << std::endl;
    delete[] mass;
}