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

bool Equal(int *arr1, int len_arr1, int *arr2, int len_arr2)
{
    int i = 0;
    int j = 0;
    while (i < len_arr1 && j < len_arr2)
    {
        if (arr1[i] != arr2[j])
        {
            return false;
        }
        i++;
        while (i < len_arr1 && arr1[i] == arr1[i - 1])
        {
            i++;
        }
        j++;
        while (j < len_arr2 && arr2[j] == arr2[j - 1])
        {
            j++;
        }
    }
    return (i == len_arr1) && (j == len_arr2);
}

int main()
{
    int n = 0;
    std::cin >> n;
    int *arr1 = new int[n];
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr1[i];
    }
    std::cin >> m;
    int *arr2 = new int[m];
    for (int i = 0; i < m; i++)
    {
        std::cin >> arr2[i];
    }
    MergeSort(arr1, n);
    MergeSort(arr2, m);
    if (Equal(arr1, n, arr2, m))
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    delete[] arr1;
    delete[] arr2;
}