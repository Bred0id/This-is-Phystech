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
    int size = 0;

    void Add(int value)
    {
        if (root == nullptr)
        {
            root = new Node();
            root->value = value;
            size++;
            return;
        }
        Node *newest = root;
        while (newest != nullptr)
        {
            if (value <= newest->value)
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
                    size++;
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
                    size++;
                    Balance(newest->right);
                    break;
                }
            }
        }
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
            }
            else if (balance == 2)
            {
                if (NodeBalance(node->right) >= 0)
                {
                    SmallLeftTurn(node);
                }
                else
                {
                    BigLeftTurn(node);
                }
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

    int Size()
    {
        return size;
    }

    Node *MaxElement(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }

    Node *MinElement(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void DeleteMax(Node *max)
    {
        if (max == nullptr)
        {
            return;
        }
        Node *parent = max->parent;
        if (parent == nullptr)
        {
            if (max->left != nullptr)
            {
                root = max->left;
                root->parent = nullptr;
            }
            else
            {
                root = nullptr;
            }
        }
        else
        {
            if (max->left != nullptr)
            {
                max->left->parent = parent;
                parent->right = max->left;
            }
            else
            {
                parent->right = nullptr;
            }
        }
        delete max;
        size--;
        if (parent != nullptr)
        {
            Balance(parent);
        }
        else if (root != nullptr)
        {
            Balance(root);
        }
    }

    void DeleteMin(Node *min)
    {
        if (min == nullptr)
        {
            return;
        }
        Node *parent = min->parent;
        if (parent == nullptr)
        {
            if (min->right != nullptr)
            {
                root = min->right;
                root->parent = nullptr;
            }
            else
            {
                root = nullptr;
            }
        }
        else
        {
            if (min->right != nullptr)
            {
                min->right->parent = parent;
                parent->left = min->right;
            }
            else
            {
                parent->left = nullptr;
            }
        }
        delete min;
        size--;
        if (parent != nullptr)
        {
            Balance(parent);
        }
        else if (root != nullptr)
        {
            Balance(root);
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
    int t = 0;
    std::cin >> t;
    AVLTree avl_tree;
    for (int i = 0; i < t; i++)
    {
        char command[20]{};
        int value = 0;
        std::cin >> command;
        if (Equal("insert", command))
        {
            std::cin >> value;
            avl_tree.Add(value);
            std::cout << "ok\n";
        }
        else if (Equal("extract_min", command))
        {
            if (avl_tree.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                Node *result = avl_tree.MinElement(avl_tree.root);
                std::cout << result->value << "\n";
                avl_tree.DeleteMin(result);
            }
        }
        else if (Equal("get_min", command))
        {
            if (avl_tree.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << avl_tree.MinElement(avl_tree.root)->value << "\n";
            }
        }
        else if (Equal("size", command))
        {
            std::cout << avl_tree.Size() << "\n";
        }
        else if (Equal("clear", command))
        {
            avl_tree.Clear(avl_tree.root);
            avl_tree.root = nullptr;
            avl_tree.size = 0;
            std::cout << "ok\n";
        }
        else if (Equal("extract_max", command))
        {
            if (avl_tree.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                Node *result = avl_tree.MaxElement(avl_tree.root);
                std::cout << result->value << "\n";
                avl_tree.DeleteMax(result);
            }
        }
        else if (Equal("get_max", command))
        {
            if (avl_tree.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << avl_tree.MaxElement(avl_tree.root)->value << "\n";
            }
        }
    }
    avl_tree.Clear(avl_tree.root);
}