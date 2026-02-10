#include <iostream>

int *Merge(int *left_array, int size_left, int *right_array, int size_right)
{
    int i = 0;
    int j = 0;
    int *merged = new int[size_left + size_right];
    while (i < size_left && j < size_right)
    {
        if (left_array[i] < right_array[j])
        {
            merged[i + j] = left_array[i];
            i++;
        }
        else
        {
            merged[i + j] = right_array[j];
            j++;
        }
    }
    while (i < size_left)
    {
        merged[i + j] = left_array[i];
        i++;
    }
    while (j < size_right)
    {
        merged[i + j] = right_array[j];
        j++;
    }
    delete[] left_array;
    delete[] right_array;
    return merged;
}

int *InputArr(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    return arr;
}

int main()
{
    int k = 0;
    std::cin >> k;
    int *size = new int[k];
    int **arr = new int *[k];
    for (int i = 0; i < k; i++)
    {
        std::cin >> size[i];
        arr[i] = InputArr(size[i]);
    }
    while (k > 1)
    {
        if (k % 2 == 0)
        {
            for (int i = 0; i + 1 < k; i += 2)
            {
                arr[i / 2] = Merge(arr[i], size[i], arr[i + 1], size[i + 1]);
                size[i / 2] = size[i] + size[i + 1];
            }
        }
        else
        {
            for (int i = 0; i + 1 < k; i += 2)
            {
                arr[i / 2] = Merge(arr[i], size[i], arr[i + 1], size[i + 1]);
                size[i / 2] = size[i] + size[i + 1];
            }
            arr[k / 2] = arr[k - 1];
            size[k / 2] = size[k - 1];
        }
        k = (k + 1) / 2;
    }
    for (int i = 0; i < size[0]; i++)
    {
        std::cout << arr[0][i] << " ";
    }
    delete[] arr[0];
    delete[] arr;
    delete[] size;
}