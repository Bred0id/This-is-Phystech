#include <iostream>

struct Node
{
    int value = 0;
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
};

struct SplayTree
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
            if (value < newest->value)
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
                    Splay(newest->left);
                    break;
                }
            }
            else if (value > newest->value)
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
                    Splay(newest->right);
                    break;
                }
            }
            else
            {
                Splay(newest);
                break;
            }
        }
    }

    int Next(int value)
    {
        Node *node = root;
        Node *result_node = nullptr;
        int result = -1;
        while (node != nullptr)
        {
            if (value <= node->value)
            {
                result_node = node;
                result = node->value;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        if (result_node != nullptr)
        {
            Splay(result_node);
        }
        return result;
    }

    void Splay(Node *node)
    {
        while (node->parent != nullptr)
        {
            if (node->parent->parent == nullptr)
            {
                if (node->parent->left == node)
                {
                    SmallRightTurn(node->parent);
                }
                else
                {
                    SmallLeftTurn(node->parent);
                }
            }
            else if (node->parent->left == node && node->parent->parent->left == node->parent)
            {
                SmallRightTurn(node->parent->parent);
                SmallRightTurn(node->parent);
            }
            else if (node->parent->right == node && node->parent->parent->right == node->parent)
            {
                SmallLeftTurn(node->parent->parent);
                SmallLeftTurn(node->parent);
            }
            else if (node->parent->left == node && node->parent->parent->right == node->parent)
            {
                SmallRightTurn(node->parent);
                SmallLeftTurn(node->parent);
            }
            else
            {
                SmallLeftTurn(node->parent);
                SmallRightTurn(node->parent);
            }
        }
        root = node;
    }

    void SmallRightTurn(Node *node)
    {
        Node *tmp = node->left;
        Node *tmp_right = tmp->right;
        tmp->parent = node->parent;
        if (node->parent == nullptr)
        {
            root = tmp;
        }
        else if (node->parent->left == node)
        {
            node->parent->left = tmp;
        }
        else
        {
            node->parent->right = tmp;
        }
        node->left = tmp_right;
        if (tmp_right != nullptr)
        {
            tmp_right->parent = node;
        }
        tmp->right = node;
        node->parent = tmp;
    }

    void SmallLeftTurn(Node *node)
    {
        Node *tmp = node->right;
        Node *tmp_left = tmp->left;
        tmp->parent = node->parent;
        if (node->parent == nullptr)
        {
            root = tmp;
        }
        else if (node->parent->left == node)
        {
            node->parent->left = tmp;
        }
        else
        {
            node->parent->right = tmp;
        }
        node->right = tmp_left;
        if (tmp_left != nullptr)
        {
            tmp_left->parent = node;
        }
        tmp->left = node;
        node->parent = tmp;
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
    int n = 0;
    std::cin >> n;
    SplayTree splay_tree;
    char command = '0';
    int value = 0;
    char previous_command = '0';
    int previous_result = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> command;
        if (command == '+')
        {
            if (previous_command == '?')
            {
                std::cin >> value;
                splay_tree.Add((value + previous_result) % 1000000000);
                previous_command = '+';
            }
            else
            {
                std::cin >> value;
                splay_tree.Add(value);
                previous_command = '+';
            }
        }
        if (command == '?')
        {
            std::cin >> value;
            previous_result = splay_tree.Next(value);
            std::cout << previous_result << '\n';
            previous_command = '?';
        }
    }
    splay_tree.Clear(splay_tree.root);
}