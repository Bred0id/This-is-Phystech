#include <iostream>

struct Node
{
    int value;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct Deq
{
    Node *head = nullptr;
    Node *tail = nullptr;
    size_t N = 0;

    void PushFront(int value)
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
        N++;
    }

    void PushBack(int value)
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
        N++;
    }

    void PopFront()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *node = head;
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
        N--;
    }

    void PopBack()
    {
        if (tail == nullptr)
        {
            return;
        }
        Node *node = tail;
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
        N--;
    }

    int Front()
    {
        if (head == nullptr)
        {
            return 0;
        }
        return head->value;
    }

    int Back()
    {
        if (tail == nullptr)
        {
            return 0;
        }
        return tail->value;
    }

    size_t Size()
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
    int t = 0;
    std::cin >> t;
    int value = 0;
    char command[20];
    Deq deq;
    for (int i = 0; i < t; i++)
    {
        std::cin >> command;
        if (Equal("push_front", command))
        {
            std::cin >> value;
            deq.PushFront(value);
            std::cout << "ok\n";
        }
        if (Equal("push_back", command))
        {
            std::cin >> value;
            deq.PushBack(value);
            std::cout << "ok\n";
        }
        if (Equal("pop_front", command))
        {
            if (deq.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << deq.Front() << "\n";
                deq.PopFront();
            }
        }
        if (Equal("pop_back", command))
        {
            if (deq.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << deq.Back() << "\n";
                deq.PopBack();
            }
        }
        if (Equal("front", command))
        {
            if (deq.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << deq.Front() << "\n";
            }
        }
        if (Equal("back", command))
        {
            if (deq.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << deq.Back() << "\n";
            }
        }
        if (Equal("size", command))
        {
            std::cout << deq.Size() << "\n";
        }
        if (Equal("clear", command))
        {
            deq.Clear();
            std::cout << "ok\n";
        }
        if (Equal("exit", command))
        {
            std::cout << "bye";
            break;
        }
    }
    deq.Clear();
}