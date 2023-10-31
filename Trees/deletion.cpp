#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BST_Node
{
    int val;
    BST_Node *left = NULL;
    BST_Node *right = NULL;
};
//-----------------------INSERTION------------------------------------//
BST_Node *insert_At_BST(BST_Node *node, int val) // repeated value not allowed
{
    int new_val = val;
    if (node == NULL)
    {
        BST_Node *new_node = new BST_Node; // contruct a pointer which point on new node user want to insert
        new_node->val = new_val;           // storing value of input in new node k val me
        // cout<< "value has been inserted!"<<endl;
        return new_node;
    }
    if (node->val > new_val)
    {
        node->left = insert_At_BST(node->left, val);
    }
    else if (node->val < new_val)
    {
        node->right = insert_At_BST(node->right, val);
    }
    // cout << "value has been inserted!" << endl;
    return node;
}

//-----------------------TRAVERSALS------------------------------------//
void preorder(BST_Node *node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->val << ", ";
    preorder(node->left);
    preorder(node->right);
}
void inorder(BST_Node *node)
{
    if (node == NULL)
    {
        return;
    }

    inorder(node->left);
    cout << node->val << ", ";
    inorder(node->right);
}
void postorder(BST_Node *node)
{
    if (node == NULL)
    {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    cout << node->val << ", ";
}
//-----------------------SEARCHING------------------------------------//

BST_Node *Search_In_BST(BST_Node *node, int val)
{
    int new_val= val;
    if (node == NULL)
    {
        return NULL;
    }
    if(new_val == node->val){
        return node;
    }
    else if (new_val > node->val)
    {
        return Search_In_BST(node->right, val);
    }
    else { // new_val < node->val
        return Search_In_BST (node->left , val);
    }
}

//-----------------------DELETION------------------------------------//
BST_Node *get_Minue(BST_Node *node){
    BST_Node *curr = node;
    while(curr && curr->left != NULL){
        curr = curr->left; //curr ko left par move krte rahnge jab tk uska left NULL na ho jaye
    }
    return curr;//curr is at smallest value or right sub tree
}

BST_Node *Delete_In_BST(BST_Node *node, int val){
    // cout<<"in delete"<<endl;
    int new_val = val;
    // BST_Node *to_Delete = Search_In_BST(node, new_val);
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
            BST_Node *curr = node->right;
            free (node);
            return curr;
        }
        else if(node->right == NULL){
            BST_Node *curr = node->left;
            free (node);
            return curr;
        }
        BST_Node *temp= get_Minue(node->right); // min value return pointer which point on minimum value of right subtree
        node->val = temp->val;
        // cout<<"in delete 12"<<endl;
        node->right = Delete_In_BST(node->right, node->val);
        // cout<<node->right->val<<endl;
        // cout<<"in delete 12345"<<endl;
    }
    return node;
}


int main()
{
    BST_Node *root = NULL;

    int n;
    cout << "enter how many node you want to enter: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int new_val; // initialize var for input
        cout << "\t 1.enter the value: ";
        cin >> new_val; // taking input
        root = insert_At_BST(root, new_val);
        // cout<<"okay";
        // insert_At_BST(root, new_val);
        // insert_At_BST(root, new_val);
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

    // BST_Node *searched = Search_In_BST(root, 4);
    if(Search_In_BST(root, 2) == NULL){
        cout<< "Value doesnot exist! "<<endl;
    }else{
        cout<<"Value Exist! "<<endl;
        cout<<"Value is: "<<Search_In_BST(root, 2)->val<<endl;
    }
    // cout<<"okay"<<endl;
    root = Delete_In_BST(root, 173);
    // cout<<"okay"<<endl;
    cout<<endl;
    inorder(root);
    return 0;
}
