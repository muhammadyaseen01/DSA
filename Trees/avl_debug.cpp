#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Node
{
    int val, height;
    Node *left, *right;
};

int get_height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

Node *create_node(int new_val)
{
    Node *new_node = new Node;
    new_node->val = new_val;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

int get_balanceFactor(Node *node)
{
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

Node *shift_left(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;

    return y;
}

Node *shift_right(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

// Node *insert(Node *node, int new_val)
// {
//     if (node == NULL)
//         return create_node(new_val);

//     if (new_val < node->val)
//         node->left = insert(node->left, new_val);
//     else if (new_val > node->val)
//         node->right = insert(node->right, new_val);

//     node->height = 1 + max(get_height(node->left), get_height(node->right));
//     int bf = get_balanceFactor(node);

//     // Left Left Case
//     if (bf > 1 && new_val < node->left->val)
//         return shift_right(node);

//     // Right Right Case
//     if (bf < -1 && new_val > node->right->val)
//         return shift_left(node);

//     // Left Right Case
//     if (bf > 1 && new_val > node->left->val)
//     {
//         node->left = shift_left(node->left);
//         return shift_right(node);
//     }

//     // Right Left Case
//     if (bf < -1 && new_val < node->right->val)
//     {
//         node->right = shift_right(node->right);
//         return shift_left(node);
//     }

//     return node;
// }
Node *insert(Node *node, int new_val)
{
    if (node == NULL)
        return (create_node(new_val));
    if (new_val > node->val)
        node->right = insert(node->right, new_val);
    else if (new_val < node->val)
        node->left = insert(node->left, new_val);
    // return node;
    // node insert at leaf position
    node->height = 1 + max(get_height(node->left), get_height(node->right));
    int bf = get_balanceFactor(node);

    // left left case

    if (bf > 1 && new_val < node->left->val)
        return shift_right(node);

    // left right case
    if (bf > 1 && new_val > node->left->val)
    {
        node->left = shift_left(node->left);
        return shift_right(node);
    }
    // right right case
    if (bf < -1 && new_val > node->right->val)
        return shift_left(node);
    // right left case
    if (bf < -1 && new_val < node->right->val){
        node->right = shift_right(node->right);
        return shift_left(node);
    }
    return node;
}


void preorder(Node *node)
{
    if (node == NULL)
        return;

    cout << node->val << ", ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 1);
    preorder(root);
    cout << endl;
    root = insert(root, 2);
    preorder(root);
    cout << endl;
    root = insert(root, 3);
    preorder(root);
    cout << endl;
    root = insert(root, 4);
    preorder(root);
    cout << endl;
    root = insert(root, 7);
    preorder(root);
    cout << endl;
    root = insert(root, 5);
    preorder(root);
    cout << endl;

    return 0;
}
