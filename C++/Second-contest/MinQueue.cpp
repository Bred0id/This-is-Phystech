#include <cstdint>
#include <iostream>

struct Node
{
    int64_t value = 0;
    int64_t min;
    Node *next = nullptr;
};

struct Stack
{
    Node *top = nullptr;

    void Push(int64_t value)
    {
        Node *node = new Node();
        node->value = value;
        node->next = top;
        if (top == nullptr)
        {
            node->min = value;
        }
        else
        {
            if (value < top->min)
            {
                node->min = value;
            }
            else
            {
                node->min = top->min;
            }
        }
        top = node;
    }

    int64_t Pop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        Node *tmp = top;
        int64_t value = top->value;
        top = top->next;
        delete tmp;
        return value;
    }

    int64_t TopValue() const
    {
        if (top == nullptr)
        {
            return -1;
        }
        return top->value;
    }

    int64_t GetMin() const
    {
        if (top == nullptr)
        {
            return INT64_MAX;
        }
        return top->min;
    }

    bool IsEmpty() const
    {
        return top == nullptr;
    }

    void ClearStack()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }
};

struct MinQueue
{
    Stack input;
    Stack output;
    size_t size = 0;

    void Enqueue(int64_t value)
    {
        input.Push(value);
        ++size;
    }

    int64_t Dequeue()
    {
        if (size == 0)
        {
            return -1;
        }
        if (output.IsEmpty())
        {
            while (!input.IsEmpty())
            {
                output.Push(input.Pop());
            }
        }
        --size;
        return output.Pop();
    }

    int64_t Front()
    {
        if (size == 0)
        {
            return -1;
        }
        if (output.IsEmpty())
        {
            while (!input.IsEmpty())
            {
                output.Push(input.Pop());
            }
        }
        return output.TopValue();
    }

    int64_t Min() const
    {
        if (size == 0)
        {
            return -1;
        }
        int64_t input_min = input.GetMin();
        int64_t output_min = output.GetMin();
        if (input.IsEmpty())
        {
            return output_min;
        }
        if (output.IsEmpty())
        {
            return input_min;
        }
        if (input_min < output_min)
        {
            return input_min;
        }
        return output_min;
    }

    size_t Size() const
    {
        return size;
    }

    void Clear()
    {
        input.ClearStack();
        output.ClearStack();
        size = 0;
    }
};

bool Equal(const char *a, const char *b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
        {
            return false;
        }
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t t = 0;
    std::cin >> t;
    MinQueue min_queue;
    for (int64_t i = 0; i < t; i++)
    {
        char command[20]{};
        int64_t value = 0;
        std::cin >> command;
        if (Equal("enqueue", command))
        {
            std::cin >> value;
            if (value < 1)
            {
                std::cout << "error\n";
            }
            else
            {
                min_queue.Enqueue(value);
                std::cout << "ok\n";
            }
        }
        else if (Equal("dequeue", command))
        {
            if (min_queue.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << min_queue.Front() << "\n";
                min_queue.Dequeue();
            }
        }
        else if (Equal("front", command))
        {
            if (min_queue.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << min_queue.Front() << "\n";
            }
        }
        else if (Equal("size", command))
        {
            std::cout << min_queue.Size() << "\n";
        }
        else if (Equal("clear", command))
        {
            min_queue.Clear();
            std::cout << "ok\n";
        }
        else if (Equal("min", command))
        {
            if (min_queue.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << min_queue.Min() << "\n";
            }
        }
    }
    min_queue.Clear();
}