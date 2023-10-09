#include <iostream>
using namespace std;

struct BST
{
    int data;
    BST *right = NULL;
    BST *left = NULL;
    int height = 0; // Initialize the height to 0
};

int getHeight(BST *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(BST *node)
{
    // if (node == NULL)
    // {
    //     return 0;
    // }
    // return getHeight(node->left) - getHeight(node->right);

    if (node == NULL){
        return 0;
        }
    int leftHeight = getHeight(node->left); // Get the height of the left subtree
    int rightHeight = getHeight(node->right); // Get the height of the right subtree
    return leftHeight - rightHeight; // Calculate and return the balance factor

}

void updateHeight(BST *node)
{
    if (node != NULL)
    {
        //ternary operator
        node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    }
}

BST *leftRotate(BST *node)
{
    BST *new_node = node->right;
    // node->right = new_node->left;
    new_node->left = node;

    // Update heights
    updateHeight(node);
    updateHeight(new_node);

    return new_node;
}

// BST *rightRotate(BST *node)
// {
//     BST *newRoot = node->left;
//     node->left = newRoot->right;
//     newRoot->right = node;

//     // Update heights
//     updateHeight(node);
//     updateHeight(newRoot);

//     return newRoot;
// }

BST *insertion(BST *node, int value)
{
    if (node == NULL)
    {
        BST *newNode = new BST;
        newNode->data = value;
        return newNode;
    }

    if (value > node->data)
    {
        node->right = insertion(node->right, value);
    }
    else if (value < node->data)
    {
        node->left = insertion(node->left, value);
    }

    // Update height of the current node
    updateHeight(node);

    // Check and perform rotations
    int balance = getBalanceFactor(node);

    // if (balance > 1 && value < node->left->data)
    // {
    //     // Left-Left case, perform a right rotation
    //     return rightRotate(node);
    // }

    // if (balance > 1 && value > node->left->data)
    // {
    //     // Left-Right case, perform left-right rotation
    //     node->left = leftRotate(node->left);
    //     return rightRotate(node);
    // }

    if (balance < -1 && value > node->right->data)
    {
        // Right-Right case, perform left rotation
        return leftRotate(node);
    }

    // if (balance < -1 && value < node->right->data)
    // {
    //     // Right-Left case, perform right-left rotation
    //     node->right = rightRotate(node->right);
    //     return leftRotate(node);
    // }

    return node;
}

void preorder(BST *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}


int main()
{
    BST *root = NULL;
    int n;
    cout << "Enter number of Nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int insert;
        cout << "Enter value to be inserted: ";
        cin >> insert;
        root = insertion(root, insert);
    }
    preorder(root);
    return 0;
}