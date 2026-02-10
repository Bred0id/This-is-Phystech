#include <iostream>

struct Node
{
    int value = 0;
    int height = 1;
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
};

struct AVLTree
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
                    Balance(newest->left);
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
                    Balance(newest->right);
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    int Next(int value)
    {
        Node *node = root;
        int result = -1;
        while (node != nullptr)
        {
            if (value <= node->value)
            {
                result = node->value;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return result;
    }

    void Balance(Node *node)
    {
        while (node != nullptr)
        {
            int left_height = NodeHeight(node->left);
            int right_height = NodeHeight(node->right);
            node->height = 1 + Max(left_height, right_height);
            int balance = right_height - left_height;
            if (balance == -2)
            {
                if (NodeBalance(node->left) <= 0)
                {
                    SmallRightTurn(node);
                }
                else
                {
                    BigRightTurn(node);
                }
                break;
            }
            if (balance == 2)
            {
                if (NodeBalance(node->right) >= 0)
                {
                    SmallLeftTurn(node);
                }
                else
                {
                    BigLeftTurn(node);
                }
                break;
            }
            node = node->parent;
        }
    }

    int NodeHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    int NodeBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left_height = NodeHeight(node->left);
        int right_height = NodeHeight(node->right);
        return right_height - left_height;
    }

    int Max(int a, int b)
    {
        return (a > b) ? a : b;
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
        node->height = 1 + Max(NodeHeight(node->left), NodeHeight(node->right));
        tmp->height = 1 + Max(NodeHeight(tmp->left), NodeHeight(tmp->right));
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
        node->height = 1 + Max(NodeHeight(node->left), NodeHeight(node->right));
        tmp->height = 1 + Max(NodeHeight(tmp->left), NodeHeight(tmp->right));
    }

    void BigRightTurn(Node *node)
    {
        SmallLeftTurn(node->left);
        SmallRightTurn(node);
    }

    void BigLeftTurn(Node *node)
    {
        SmallRightTurn(node->right);
        SmallLeftTurn(node);
    }

    int TreeHeight()
    {
        return NodeHeight(root);
    }

    void Fork(Node *node)
    {
        if (node != nullptr)
        {
            Fork(node->left);
            if (node->right != nullptr && node->left != nullptr)
            {
                std::cout << node->value << '\n';
            }
            Fork(node->right);
        }
    }

    void Leaves(Node *node)
    {
        if (node != nullptr)
        {
            Leaves(node->left);
            if (node->right == nullptr && node->left == nullptr)
            {
                std::cout << node->value << ' ';
            }
            Leaves(node->right);
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
    AVLTree avl_tree;
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
                avl_tree.Add((value + previous_result) % 1000000000);
                previous_command = '+';
            }
            else
            {
                std::cin >> value;
                avl_tree.Add(value);
                previous_command = '+';
            }
        }
        if (command == '?')
        {
            std::cin >> value;
            previous_result = avl_tree.Next(value);
            std::cout << previous_result << '\n';
            previous_command = '?';
        }
    }
    avl_tree.Clear(avl_tree.root);
}