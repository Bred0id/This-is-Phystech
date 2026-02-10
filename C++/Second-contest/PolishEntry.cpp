#include <iostream>

struct Node
{
    int value;
    Node *next = nullptr;
};

struct Stack
{
    Node *top = nullptr;

    void Push(int value)
    {
        Node *node = new Node();
        node->value = value;
        node->next = top;
        top = node;
    }

    int Pop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        Node *tmp = top;
        int value = top->value;
        top = top->next;
        delete tmp;
        return value;
    }

    int Top() const
    {
        if (top == nullptr)
        {
            return -1;
        }
        return top->value;
    }

    bool IsEmpty() const
    {
        return top == nullptr;
    }

    void Clear()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }
};

int Answer(Stack &stack)
{
    char value = '0';
    while (value != '\0' && value != '\n')
    {
        std::cin.get(value);
        if (value >= '0' && value <= '9')
        {
            stack.Push(value - '0');
        }
        if (value == '+')
        {
            int elem_one = stack.Pop();
            int elem_two = stack.Pop();
            stack.Push(elem_one + elem_two);
        }
        if (value == '-')
        {
            int elem_one = stack.Pop();
            int elem_two = stack.Pop();
            stack.Push(elem_two - elem_one);
        }
        if (value == '*')
        {
            int elem_one = stack.Pop();
            int elem_two = stack.Pop();
            stack.Push(elem_one * elem_two);
        }
    }
    return stack.Pop();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    Stack stack;
    std::cout << Answer(stack);
    stack.Clear();
}