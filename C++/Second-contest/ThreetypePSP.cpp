#include <iostream>

struct Node
{
    char value;
    Node *next = nullptr;
};

struct Stack
{
    Node *top = nullptr;

    void Push(char value)
    {
        Node *node = new Node();
        node->value = value;
        node->next = top;
        top = node;
    }

    char Pop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        Node *tmp = top;
        char value = top->value;
        top = top->next;
        delete tmp;
        return value;
    }

    char Top() const
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

bool Check(Stack &stack)
{
    char brackets[1000010];
    std::cin >> brackets;
    int i = 0;
    while (brackets[i] != '\0' && brackets[i] != '\n')
    {
        if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[')
        {
            stack.Push(brackets[i]);
        }
        if (brackets[i] == ')' || brackets[i] == '}' || brackets[i] == ']')
        {
            if (stack.IsEmpty())
            {
                return false;
            }
            if (brackets[i] == ')' && stack.Top() == '(')
            {
                stack.Pop();
            }
            else if (brackets[i] == '}' && stack.Top() == '{')
            {
                stack.Pop();
            }
            else if (brackets[i] == ']' && stack.Top() == '[')
            {
                stack.Pop();
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    return stack.IsEmpty();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    Stack stack;
    if (Check(stack))
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    stack.Clear();
}