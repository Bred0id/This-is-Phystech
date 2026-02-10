#include <iostream>
#include <cstdint>

struct Node
{
    int64_t value;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct Deq
{
    Node *head = nullptr;
    Node *tail = nullptr;
    size_t N = 0;

    void PushFront(int64_t value)
    {
        Node *node = new Node();
        node->value = value;
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
        ++N;
    }

    void PushBack(int64_t value)
    {
        Node *node = new Node();
        node->value = value;
        if (tail == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        ++N;
    }

    int64_t PopFront()
    {
        if (head == nullptr)
        {
            return -1;
        }
        Node *node = head;
        int64_t value = head->value;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete node;
        --N;
        return value;
    }

    int64_t PopBack()
    {
        if (tail == nullptr)
        {
            return -1;
        }
        Node *node = tail;
        int64_t value = tail->value;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete node;
        --N;
        return value;
    }

    int64_t Front() const
    {
        if (head == nullptr)
        {
            return -1;
        }
        return head->value;
    }

    int64_t Back() const
    {
        if (tail == nullptr)
        {
            return -1;
        }
        return tail->value;
    }

    bool IsEmpty() const
    {
        return N == 0;
    }

    size_t Size() const
    {
        return N;
    }

    void Clear()
    {
        Node *node = head;
        while (node != nullptr)
        {
            Node *next = node->next;
            delete node;
            node = next;
        }
        head = nullptr;
        tail = nullptr;
        N = 0;
    }
};

struct Queue
{
    Deq left_deq;
    Deq right_deq;
    size_t size = 0;

    void PushPlus(int64_t value)
    {
        right_deq.PushBack(value);
        ++size;
        if (left_deq.Size() < right_deq.Size())
        {
            left_deq.PushBack(right_deq.PopFront());
        }
    }

    void PushMultiply(int64_t value)
    {
        left_deq.PushBack(value);
        ++size;
        if (left_deq.Size() > right_deq.Size() + 1)
        {
            right_deq.PushFront(left_deq.PopBack());
        }
    }

    int64_t Pop()
    {
        if (size == 0)
        {
            return -1;
        }
        int64_t value = 0;
        if (left_deq.IsEmpty())
        {
            value = right_deq.PopFront();
        }
        else
        {
            value = left_deq.PopFront();
        }
        --size;
        if (left_deq.Size() < right_deq.Size())
        {
            left_deq.PushBack(right_deq.PopFront());
        }
        return value;
    }

    int64_t Front() const
    {
        if (size == 0)
        {
            return -1;
        }
        if (left_deq.IsEmpty())
        {
            return right_deq.Front();
        }
        return left_deq.Front();
    }

    size_t Size() const
    {
        return size;
    }

    void Clear()
    {
        left_deq.Clear();
        right_deq.Clear();
        size = 0;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0;
    std::cin >> n;
    Queue queue;
    for (int i = 0; i < n; ++i)
    {
        int64_t value = 0;
        char command = '0';
        std::cin >> command;
        if (command == '+')
        {
            std::cin >> value;
            queue.PushPlus(value);
        }
        if (command == '-')
        {
            std::cout << queue.Pop() << "\n";
        }
        if (command == '*')
        {
            std::cin >> value;
            queue.PushMultiply(value);
        }
    }
    queue.Clear();
}