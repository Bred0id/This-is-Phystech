#include <iostream>

struct Node
{
    int value = 0;
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
};

struct BinaryTree
{
    Node *root = nullptr;
    int height = 0;

    void Add(int value)
    {
        if (root == nullptr)
        {
            root = new Node();
            root->value = value;
            height = 1;
            return;
        }
        Node *newest = root;
        int count = 1;
        while (newest != nullptr)
        {
            if (value < newest->value)
            {
                if (newest->left != nullptr)
                {
                    newest = newest->left;
                    count++;
                }
                else
                {
                    newest->left = new Node();
                    newest->left->value = value;
                    newest->left->parent = newest;
                    count++;
                    if (count > height)
                    {
                        height = count;
                    }
                    break;
                }
            }
            else if (value > newest->value)
            {
                if (newest->right != nullptr)
                {
                    newest = newest->right;
                    count++;
                }
                else
                {
                    newest->right = new Node();
                    newest->right->value = value;
                    newest->right->parent = newest;
                    count++;
                    if (count > height)
                    {
                        height = count;
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    int SecondMax(Node *node)
    {
        if (node->right == nullptr)
        {
            if (node->left != nullptr)
            {
                node = node->left;
                while (node->right != nullptr)
                {
                    node = node->right;
                }
                return node->value;
            }
            return node->parent->value;
        }
        return SecondMax(node->right);
    }

    int Height() const
    {
        return height;
    }

    void Clear(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        Clear(node->right);
        Clear(node->left);
        delete node;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    BinaryTree binary_tree;
    int value = 0;
    std::cin >> value;
    while (value != 0)
    {
        binary_tree.Add(value);
        std::cin >> value;
    }
    std::cout << binary_tree.SecondMax(binary_tree.root);
    binary_tree.Clear(binary_tree.root);
}