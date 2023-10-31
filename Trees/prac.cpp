#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


struct BST{
    int val;
    BST* left;
    BST *right;

    BST(int new_val){
        val = new_val;
        left = NULL;
        right = NULL;
    }
};

void preorder(BST *node)
{
    if (node == NULL){
        return;
    }

    cout << node->val << ", ";
    preorder(node->left);
    preorder(node->right);

}
void inorder(BST *node){
    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->val << ", ";
        inorder(node->right);
    }
}
void postorder(BST *node){
    if (node != nullptr)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->val << ", ";
    }
}

int main()
{
    struct BST* root = new BST(1);
    root->left = new BST(2);
    root->right = new BST(3);
    root->left->left = new BST(4);
    root->right->right = new BST(5);
    root->left->left->left = new BST(6);
    root->right->right->right = new BST(7);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

    return 0;
}