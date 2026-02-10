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
        int count = 1;
        Node *newest = root;
        while (newest != nullptr)
        {
            if (newest->value < value)
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
                    break;
                }
            }
            else if (newest->value > value)
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
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (count > height)
        {
            height = count;
        }
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
    std::cout << binary_tree.Height();
    binary_tree.Clear(binary_tree.root);
}