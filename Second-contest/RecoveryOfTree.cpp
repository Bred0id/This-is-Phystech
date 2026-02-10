#include <iostream>

struct Node
{
    int value = 0;
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
};

struct NodeStack
{
    Node *value = nullptr;
    NodeStack *next = nullptr;
};

struct Stack
{
    NodeStack *head = nullptr;

    void Push(Node *node)
    {
        auto new_node = new NodeStack();
        new_node->value = node;
        new_node->next = head;
        head = new_node;
    }

    Node *Pop()
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        NodeStack *node = head;
        head = head->next;
        Node *value = node->value;
        delete node;
        return value;
    }

    Node *Top()
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        return head->value;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }

    void Clear()
    {
        while (head != nullptr)
        {
            NodeStack *node = head;
            head = head->next;
            delete node;
        }
    }
};

struct BinaryTree
{
    Node *root = nullptr;

    void PreOrderRecovery(int *values, int n)
    {
        if (n == 0)
        {
            return;
        }
        root = new Node();
        root->value = values[0];
        Stack stack;
        stack.Push(root);
        for (int i = 1; i < n; i++)
        {
            Node *new_node = new Node();
            new_node->value = values[i];
            Node *parent = nullptr;
            while (!stack.IsEmpty() && values[i] > stack.Top()->value)
            {
                parent = stack.Pop();
            }
            if (parent != nullptr)
            {
                parent->right = new_node;
                new_node->parent = parent;
            }
            else
            {
                stack.Top()->left = new_node;
                new_node->parent = stack.Top();
            }
            stack.Push(new_node);
        }
        stack.Clear();
    }

    void PostOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        PostOrder(node->left);
        PostOrder(node->right);
        std::cout << node->value << " ";
    }

    void Clear(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        Clear(node->left);
        Clear(node->right);
        delete node;
    }
};

int main()
{
    int n = 0;
    std::cin >> n;
    BinaryTree binary_tree;
    int *values = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i];
    }
    binary_tree.PreOrderRecovery(values, n);
    binary_tree.PostOrder(binary_tree.root);
    binary_tree.Clear(binary_tree.root);
    delete[] values;
}