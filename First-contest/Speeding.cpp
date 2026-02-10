#include <iostream>

double *InputV(int n)
{
    auto *arr = new double[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    return arr;
}

double *InputL(int n)
{
    auto *arr = new double[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    return arr;
}

double *InputRanges(int m)
{
    auto *arr = new double[m]{};
    for (int i = 1; i < m; i++)
    {
        std::cin >> arr[i];
    }
    return arr;
}

int *InputFine(int m)
{
    int *arr = new int[m + 1]{};
    for (int i = 1; i < m + 1; i++)
    {
        std::cin >> arr[i];
    }
    return arr;
}

double *LimitTime(double *limit_speeds, double *lengths, double *limits, int n, int m)
{
    auto *arr = new double[m]{};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i] += lengths[j] / (limit_speeds[j] + limits[i]);
        }
    }
    delete[] limit_speeds;
    delete[] limits;
    delete[] lengths;
    return arr;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    int m = 0;
    std::cin >> n;
    double *limit_speeds = InputV(n);
    double *lengths = InputL(n);
    std::cin >> m;
    double *limits = InputRanges(m);
    int *fines = InputFine(m);
    double *times = LimitTime(limit_speeds, lengths, limits, n, m);
    int q = 0;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        double start = 0;
        double end = 0;
        std::cin >> start >> end;
        double time = end - start;
        int left = 0;
        int right = m;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (times[mid] >= time)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (time >= times[0])
        {
            std::cout << 0 << "\n";
        }
        else
        {
            std::cout << fines[left] << "\n";
        }
    }
    delete[] times;
    delete[] fines;
}