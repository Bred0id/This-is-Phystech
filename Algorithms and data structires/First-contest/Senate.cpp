#include <iostream>

void Merge(int *left_arr, int size_left, int *right_arr, int size_right, int *merged)
{
    int i = 0;
    int j = 0;
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

void MergeSort(int *arr, int size)
{
    if (size < 2)
    {
        return;
    }
    int mid = size / 2;
    int *left_arr = new int[mid];
    int *right_arr = new int[size - mid];
    for (int i = 0; i < mid; i++)
    {
        left_arr[i] = arr[i];
    }
    for (int i = 0; i < size - mid; i++)
    {
        right_arr[i] = arr[mid + i];
    }
    MergeSort(left_arr, mid);
    MergeSort(right_arr, size - mid);
    Merge(left_arr, mid, right_arr, size - mid, arr);
    delete[] left_arr;
    delete[] right_arr;
}

bool Check(int x, int *a, int n, int m, int k)
{
    int count = 0;
    int i = 0;
    while (i < n - k + 1)
    {
        if (a[i + k - 1] - a[i] <= x)
        {
            count++;
            i += k;
        }
        else
        {
            i++;
        }
    }
    return count >= m;
}

int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    std::cin >> n >> m >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    MergeSort(arr, n);
    int left = 0;
    int right = arr[n - 1] - arr[0];
    while (right > left)
    {
        int mid = (right + left) / 2;
        if (Check(mid, arr, n, m, k))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    std::cout << left;
    delete[] arr;
}