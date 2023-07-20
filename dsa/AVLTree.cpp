class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};


struct AVLTree
{

    Node* root=0;

    int height(Node * now )
    {
        if (now == NULL) return 0;
        return now->height;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    Node *newNode(int key)
    {
        Node *node = new Node();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return (node);
    }

    int getBalanceFactor(Node *now )
    {
        if (now == NULL) return 0;
        return height(now->left) - height(now->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    int insert( int key )
    {
        root=insertNode( root, key );
    }

    Node *insertNode(Node *node, int key)
    {
        if (node == NULL) return (newNode(key));
        if (key < node->key) node->left = insertNode(node->left, key);
        else if (key > node->key) node->right = insertNode(node->right, key);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1)
        {
            if (key < node->left->key)
            {
                return rightRotate(node);
            }
            else if (key > node->left->key)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        if (balanceFactor < -1)
        {
            if (key > node->right->key)
            {
                return leftRotate(node);
            }
            else if (key < node->right->key)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }

    Node* nodeWithMinimumValue(Node *node)
    {
        Node *current = node;
        while (current->left != NULL) current = current->left;
        return current;
    }

    int remove( int key )
    {
        root=deleteNode( root, key );
    }

    Node* deleteNode(Node *node, int key)
    {
        if (node == NULL) return node;
        if (key < node->key) node->left = deleteNode( node->left, key);
        else if (key > node->key) node->right = deleteNode(node->right, key);
        else
        {
            if (( node->left == NULL) || ( node->right == NULL ) )
            {
                Node *temp = node->left ? node->left : node->right;
                if (temp == NULL)
                {
                    temp = root;
                    node = NULL;
                }
                else *node = *temp;
                free(temp);
            }
            else
            {
                Node *temp = nodeWithMinimumValue(node->right);
                node->key = temp->key;
                node->right = deleteNode( node->right, temp->key);
            }
        }
        if (node == NULL) return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1)
        {
            if (getBalanceFactor(node->left) >= 0)
            {
                return rightRotate(node);
            }
            else
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        if (balanceFactor < -1)
        {
            if (getBalanceFactor(node->right) <= 0)
            {
                return leftRotate(node);
            }
            else
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }

    void print(  )
    {
        printTree( root, "", true );
    }

    void printTree(Node *node, string indent, bool last)
    {
        if ( node != nullptr)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "  ";
            }
            cout << node->key << endl;
            printTree(node->left, indent, false);
            printTree(node->right, indent, true);
        }
    }
};
