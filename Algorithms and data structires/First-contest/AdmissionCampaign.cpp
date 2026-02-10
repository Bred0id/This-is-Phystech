#include <iostream>

struct Info
{
    int result = 0;
    char name[82]{};

    void InputName()
    {
        int j = 0;
        int count = 0;
        while (count < 2)
        {
            char letter = '0';
            std::cin.get(letter);
            if (letter == ' ')
            {
                count++;
            }
            name[j++] = letter;
        }
        name[j - 1] = '\0';
    }

    void InputResult()
    {
        for (int i = 0; i < 3; i++)
        {
            int subject = 0;
            std::cin >> subject;
            result += subject;
        }
    }
};

void Merge(Info *left_arr, int left_size, Info *right_arr, int right_size, Info *merged)
{
    int i = 0;
    int j = 0;
    while (i < left_size && j < right_size)
    {
        if (left_arr[i].result >= right_arr[j].result)
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
    while (i < left_size)
    {
        merged[i + j] = left_arr[i];
        i++;
    }
    while (j < right_size)
    {
        merged[i + j] = right_arr[j];
        j++;
    }
}

void MergeSort(Info *arr, int size)
{
    if (size < 2)
    {
        return;
    }
    int mid = size / 2;
    Info *left_arr = new Info[mid];
    Info *right_arr = new Info[size - mid];
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

int main()
{
    int n = 0;
    std::cin >> n;
    Info *students = new Info[n];
    for (int i = 0; i < n; i++)
    {
        students[i].InputName();
        students[i].InputResult();
    }
    MergeSort(students, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << students[i].name << "\n";
    }
    delete[] students;
}