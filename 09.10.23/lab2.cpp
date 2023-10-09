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


BST* shift_left(BST* node){
    BST *new_node = node->right;
    new_node->left = node;

    updateHeight(node);
    updateHeight(new_node);

    return new_node;
}
// BST *insertion(BST *node, int value)
// {
//     if (node == nullptr)
//     {
//         BST *newNode = new BST;
//         newNode->data = value;
//         return newNode;
//     }
//     if (value > node->data)
//     {
//         node->right = insertion(node->right, value);
//     }
//     else if (value < node->data)
//     {
//         node->left = insertion(node->left, value);
//     }
//     return node;
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

    if (balance < -1 && value > node->right->data)
    {
        return shift_left(node);
    }

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

void postorder(BST *node)
{
    if (node != nullptr)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " "; // Add a space to separate the numbers
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
    postorder(root);
    return 0;
}