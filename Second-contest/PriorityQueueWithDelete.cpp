#include <iostream>

void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int Parent(int i)
{
    return (i - 1) / 2;
}

int LeftChild(int i)
{
    return i * 2 + 1;
}

int RightChild(int i)
{
    return i * 2 + 2;
}

struct PriorityQueue
{
    int max_size = 0;
    int size = 0;
    int *arr = nullptr;

    PriorityQueue() = default;

    explicit PriorityQueue(int n)
    {
        max_size = n;
        arr = new int[max_size + 1];
        size = 0;
    }

    ~PriorityQueue()
    {
        delete[] arr;
    }

    int SiftDown(int i)
    {
        int l = LeftChild(i);
        int r = RightChild(i);
        int largest = i;
        if (l < size && arr[largest] < arr[l])
        {
            largest = l;
        }
        if (r < size && arr[largest] < arr[r])
        {
            largest = r;
        }
        if (largest != i)
        {
            Swap(arr[i], arr[largest]);
            return SiftDown(largest);
        }
        return i;
    }

    int SiftUp(int i)
    {
        int p = Parent(i);
        if (0 < i && arr[p] < arr[i])
        {
            Swap(arr[i], arr[p]);
            return SiftUp(p);
        }
        return i;
    }

    int AddElement(int element)
    {
        if (size == max_size)
        {
            return -1;
        }
        arr[size] = element;
        ++size;
        return SiftUp(size - 1) + 1;
    }

    void MaxElement()
    {
        if (size == 0)
        {
            std::cout << -1 << '\n';
            return;
        }
        Swap(arr[0], arr[size - 1]);
        --size;
        if (size > 0)
        {
            std::cout << SiftDown(0) + 1 << " " << arr[size] << '\n';
        }
        else
        {
            std::cout << 0 << " " << arr[size] << '\n';
        }
    }

    int Delete(int ind)
    {
        if (ind < 0 || ind >= size)
        {
            return -1;
        }
        Swap(arr[ind], arr[size - 1]);
        --size;
        if (size > 0 && ind < size)
        {
            if (ind > 0 && arr[Parent(ind)] < arr[ind])
            {
                SiftUp(ind);
            }
            else
            {
                SiftDown(ind);
            }
        }
        return arr[size];
    }

    void Print() const
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << ' ';
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    PriorityQueue priority_queue(n);
    for (int i = 0; i < m; ++i)
    {
        int command = 0;
        int value = 0;
        std::cin >> command;
        if (command == 1)
        {
            priority_queue.MaxElement();
        }
        else if (command == 2)
        {
            std::cin >> value;
            std::cout << priority_queue.AddElement(value) << '\n';
        }
        else if (command == 3)
        {
            std::cin >> value;
            std::cout << priority_queue.Delete(value - 1) << '\n';
        }
    }
    priority_queue.Print();
}