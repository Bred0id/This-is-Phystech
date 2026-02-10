#include <iostream>
#include <cstdint>

struct Card
{
    int64_t value = 0;
    int64_t count = 0;

    void Input()
    {
        std::cin >> value;
        count = 1;
    }
};

void Merge(Card *left_arr, int64_t left_size, Card *right_arr, int64_t right_size, Card *merged)
{
    int64_t i = 0;
    int64_t j = 0;
    int64_t k = 0;
    while (i < left_size && j < right_size)
    {
        if (left_arr[i].value > right_arr[j].value)
        {
            merged[k++] = left_arr[i++];
        }
        else
        {
            merged[k++] = right_arr[j++];
        }
    }
    while (i < left_size)
    {
        merged[k++] = left_arr[i++];
    }
    while (j < right_size)
    {
        merged[k++] = right_arr[j++];
    }
}

void MergeSort(Card *arr, int64_t size)
{
    if (size < 2)
    {
        return;
    }
    int64_t mid = size / 2;
    Card *left_arr = new Card[mid];
    Card *right_arr = new Card[size - mid];
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

int64_t Right(Card *cards, int64_t size, int64_t i, int64_t k)
{
    int64_t left = i;
    int64_t right = size - 1;
    int64_t res = i;
    while (left <= right)
    {
        int64_t mid = (left + right) / 2;
        if (cards[mid].value * k >= cards[i].value)
        {
            res = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}

int64_t Answer(Card *cards, int64_t size, int64_t k)
{
    auto *count_2 = new int64_t[size];
    if (cards[0].count >= 2)
    {
        count_2[0] = 1;
    }
    else
    {
        count_2[0] = 0;
    }
    for (int64_t i = 1; i < size; i++)
    {
        if (cards[i].count >= 2)
        {
            count_2[i] = count_2[i - 1] + 1;
        }
        else
        {
            count_2[i] = count_2[i - 1];
        }
    }
    int64_t ans = 0;
    for (int64_t i = 0; i < size; i++)
    {
        int64_t right = Right(cards, size, i, k);
        int64_t len = right - i;
        if (cards[i].count >= 3)
        {
            ans++;
        }
        if (cards[i].count >= 2)
        {
            ans += len * 3;
        }
        if (len >= 2)
        {
            ans += len * (len - 1) / 2 * 6;
        }
        ans += (count_2[right] - count_2[i]) * 3;
    }
    delete[] count_2;
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int64_t n = 0;
    int64_t k = 0;
    std::cin >> n >> k;
    Card *cards = new Card[n];
    for (int64_t i = 0; i < n; i++)
    {
        cards[i].Input();
    }
    MergeSort(cards, n);
    Card *real_cards = new Card[n];
    int64_t j = 0;
    for (int64_t i = 0; i < n; i++)
    {
        if (j == 0)
        {
            real_cards[j] = cards[i];
            j++;
        }
        else
        {
            if (real_cards[j - 1].value == cards[i].value)
            {
                real_cards[j - 1].count = real_cards[j - 1].count + cards[i].count;
            }
            else
            {
                real_cards[j] = cards[i];
                j++;
            }
        }
    }
    int64_t size = j;
    std::cout << Answer(real_cards, size, k);
    delete[] cards;
    delete[] real_cards;
}