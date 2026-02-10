#include <iostream>

struct Node
{
    int value = 0;
    int height = 1;
    int size = 1;
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
            this->size++;
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
                    this->size++;
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
                    this->size++;
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
            node->size = 1 + NodeSize(node->left) + NodeSize(node->right);
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

    int NodeSize(Node *node)
    {
        return node ? node->size : 0;
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
        node->size = 1 + NodeSize(node->left) + NodeSize(node->right);
        tmp->size = 1 + NodeSize(tmp->left) + NodeSize(tmp->right);
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
        node->size = 1 + NodeSize(node->left) + NodeSize(node->right);
        tmp->size = 1 + NodeSize(tmp->left) + NodeSize(tmp->right);
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

    int Min()
    {
        if (root == nullptr)
        {
            return -1;
        }
        Node *node = root;
        while (node->left != nullptr)
        {
            node = node->left;
        }
        int value = node->value;
        DeleteNode(node);
        return value;
    }

    int Max()
    {
        if (root == nullptr)
        {
            return -1;
        }
        Node *node = root;
        while (node->right != nullptr)
        {
            node = node->right;
        }
        int value = node->value;
        DeleteNode(node);
        return value;
    }

    int Mid()
    {
        if (root == nullptr)
        {
            return -1;
        }
        int k = (size % 2 == 0) ? size / 2 : (size + 1) / 2;
        Node *node = root;

        while (node != nullptr)
        {
            int left_size = NodeSize(node->left);
            if (k <= left_size)
            {
                node = node->left;
            }
            else if (k == left_size + 1)
            {
                int value = node->value;
                DeleteNode(node);
                return value;
            }
            else
            {
                k -= (left_size + 1);
                node = node->right;
            }
        }
        return -1;
    }

    void DeleteNode(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        Node *parent = node->parent;
        if (node->left == nullptr && node->right == nullptr)
        {
            if (parent == nullptr)
            {
                root = nullptr;
            }
            else if (parent->left == node)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
            delete node;
            size--;
            if (parent != nullptr)
            {
                Balance(parent);
            }
            return;
        }
        if (node->left == nullptr || node->right == nullptr)
        {
            Node *child = (node->left != nullptr) ? node->left : node->right;
            child->parent = parent;
            if (parent == nullptr)
            {
                root = child;
            }
            else if (parent->left == node)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
            delete node;
            size--;
            if (parent != nullptr)
            {
                Balance(parent);
            }
            else if (root != nullptr)
            {
                Balance(root);
            }
            return;
        }
        Node *new_parent = node->right;
        while (new_parent->left != nullptr)
        {
            new_parent = new_parent->left;
        }
        node->value = new_parent->value;
        DeleteNode(new_parent);
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
        if (Equal("add", command))
        {
            std::cin >> value;
            avl_tree.Add(value);
        }
        else if (Equal("min", command))
        {
            if (avl_tree.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << avl_tree.Min() << "\n";
            }
        }
        else if (Equal("max", command))
        {
            if (avl_tree.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << avl_tree.Max() << "\n";
            }
        }
        else if (Equal("mid", command))
        {
            if (avl_tree.Size() == 0)
            {
                std::cout << "error\n";
            }
            else
            {
                std::cout << avl_tree.Mid() << "\n";
            }
        }
    }
    avl_tree.Clear(avl_tree.root);
}