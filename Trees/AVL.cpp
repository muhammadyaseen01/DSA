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

//-----------------------DELETION------------------------------------//
Node *get_Minue(Node *node){
    Node *curr = node;
    while(curr && curr->left != NULL){
        curr = curr->left; //curr ko left par move krte rahnge jab tk uska left NULL na ho jaye
    }
    return curr;//curr is at smallest value or right sub tree
}

Node *Delete_In_BST(Node *node, int val){ // same BST ka code delete krne k bad balance krdia same insert wala code se
    // cout<<"in delete"<<endl;
    int new_val = val;
    // Node *to_Delete = Search_In_BST(node, new_val);
    if (node == NULL)
        return node;
    else if(new_val > node->val){
        // cout<<"in delete 12"<<endl;
        node->right = Delete_In_BST(node->right, val);

    }
    else if(new_val < node->val){
        node->left = Delete_In_BST(node->left, val);
    }
    else{
        // cout<<to_Delete->right->val;
        if(node->left == NULL){
            Node *curr = node->right;
            free (node);
            return curr;
        }
        else if(node->right == NULL){
            Node *curr = node->left;
            free (node);
            return curr;
        }
        Node *temp= get_Minue(node->right); // min value return pointer which point on minimum value of right subtree
        node->val = temp->val;
        // cout<<"in delete 12"<<endl;
        node->right = Delete_In_BST(node->right, node->val);
        // cout<<node->right->val<<endl;
        // cout<<"in delete 12345"<<endl;
    }
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
void inorder(Node *node){
    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->val << ", ";
        inorder(node->right);
    }
}
void postorder(Node *node){
    if (node != nullptr)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->val << ", ";
    }
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
    cout<<"after deletion"<<endl;
    root = Delete_In_BST(root,4);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    return 0;
}
