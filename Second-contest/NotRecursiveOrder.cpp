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

    void Add(int value)
    {
        if (root == nullptr)
        {
            root = new Node();
            root->value = value;
            return;
        }
        Node *newest = root;
        while (newest != nullptr)
        {
            if (newest->value < value)
            {
                if (newest->right != nullptr)
                {
                    newest = newest->right;
                }
                else
                {
                    newest->right = new Node();
                    newest->right->value = value;
                    newest->right->parent = newest;
                    break;
                }
            }
            else if (newest->value > value)
            {
                if (newest->left != nullptr)
                {
                    newest = newest->left;
                }
                else
                {
                    newest->left = new Node();
                    newest->left->value = value;
                    newest->left->parent = newest;
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    void NotRecursive() const
    {
        Node *node = root;

        while (node != nullptr)
        {
            if (node->left == nullptr)
            {
                std::cout << node->value << "\n";
                node = node->right;
            }
            else
            {
                Node *previous = node->left;
                while (previous->right != nullptr && previous->right != node)
                {
                    previous = previous->right;
                }
                if (previous->right == nullptr)
                {
                    previous->right = node;
                    node = node->left;
                }
                else
                {
                    previous->right = nullptr;
                    std::cout << node->value << "\n";
                    node = node->right;
                }
            }
        }
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
    BinaryTree tree;
    int value = 0;
    while (std::cin >> value && value != 0)
    {
        tree.Add(value);
    }
    tree.NotRecursive();
    tree.Clear(tree.root);
}