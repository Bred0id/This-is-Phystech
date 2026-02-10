#include <iostream>

struct Team
{
    int number = 0;
    int score = 0;
    int fine = 0;
};

bool ComparatorFine(const Team &a, const Team &b)
{
    return a.fine < b.fine;
}

bool ComparatorScore(const Team &a, const Team &b)
{
    return a.score > b.score;
}

void Merge(Team *left_arr, int size_left, Team *right_arr, int size_right, Team *merged,
           bool (*comparator)(const Team &, const Team &))
{
    int i = 0;
    int j = 0;
    while (i < size_left && j < size_right)
    {
        if (!comparator(right_arr[j], left_arr[i]))
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

void MergeSort(Team *arr, int size, bool (*comparator)(const Team &, const Team &))
{
    if (size < 2)
    {
        return;
    }
    int mid = size / 2;
    Team *left_arr = new Team[mid];
    Team *right_arr = new Team[size - mid];
    for (int i = 0; i < mid; i++)
    {
        left_arr[i] = arr[i];
    }
    for (int i = 0; i < size - mid; i++)
    {
        right_arr[i] = arr[mid + i];
    }
    MergeSort(left_arr, mid, comparator);
    MergeSort(right_arr, size - mid, comparator);
    Merge(left_arr, mid, right_arr, size - mid, arr, comparator);
    delete[] left_arr;
    delete[] right_arr;
}

void Rating(Team *teams, int n)
{
    MergeSort(teams, n, ComparatorFine);
    MergeSort(teams, n, ComparatorScore);
}

Team *Input(int n)
{
    Team *teams = new Team[n];
    for (int i = 0; i < n; i++)
    {
        teams[i].number = i + 1;
        std::cin >> teams[i].score >> teams[i].fine;
    }
    return teams;
}

int main()
{
    int n = 0;
    std::cin >> n;
    Team *teams = Input(n);
    Rating(teams, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << teams[i].number << "\n";
    }
    delete[] teams;
}