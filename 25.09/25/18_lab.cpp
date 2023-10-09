#include <iostream>
#include <cstdlib>

using namespace std;

struct BST
{
    int data;
    BST *right = nullptr;
    BST *left = nullptr;
};

BST *insertion(BST *root, int value)
{
    if (root == nullptr)
    {
        BST *newNode = new BST;
        newNode->data = value;
        return newNode;
    }
    if (value > root->data)
    {
        root->right = insertion(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = insertion(root->left, value);
    }
    return root;
}

void inorder(BST *node)
{
    //if (node != nullptr)
    //{
        inorder(node->left);
        cout << node->data << " "; // Add a space to separate the numbers
        inorder(node->right);
        cout << "LOL";
        return;
    //}
}

void preorder(BST *node)
{
    if (node != nullptr)
    {
        cout << node->data << " "; // Add a space to separate the numbers
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

BST *search(BST *node, int value)
{
    if (node == NULL)
    {
        cout << "VALUE NOT FOUND!";
    }
    while (node != NULL)
    {
        if (value == node->data)
        {
            return node;
        }
        if (value > node->data)
        {
            node = node->right;
        }
        if (value < node->data)
        {
            node = node->left;
        }
    }
    cout << "ERROR 404";
}

BST *minValueNode(BST *node)
{
    BST *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

BST *deletion(BST *node, int value)
{
    if (node == NULL)
    {
        cout << "ERROR 404";
        return node;
    }

    // Search for the node to delete
    if (value < node->data)
    {
        node->left = deletion(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = deletion(node->right, value);
    }
    else
    {
        // Node with only one child or no child
        if (node->left == NULL)
        {
            BST *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        {
            BST *temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        BST *temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = deletion(node->right, temp->data);
    }

    return node;
}

// BST *deletion(BST *node, int value)
// {
//     if (node == NULL)
//     {
//         cout << "ERROR 404";
//     }
//     BST *toDel = search (node, value);
//     if (toDel->left == NULL)
//     {
//         BST *temp = toDel->right;
//         delete toDel;
//         temp->left = NULL;
//         temp->right = NULL;
//         temp->left;
//         return temp;
//     }
//     else if (toDel->right == NULL)
//     {
//         BST *temp = toDel->left;
//         delete toDel;
//         temp->left = NULL;
//         temp->right = NULL;
//         return temp;
//     }
// }

int main()
{
    BST *root = nullptr;
    int opt;
    cout << "\t 1: Insert an ID. \n";
    cout << "\t 2: Search an ID. \n";
    cout << "\t 3: Delete an ID. \n";
    cout << "\t 4: Traverse the tree. \n";
    cout << "\t 5: Exit. \n";
    cin >> opt;
    
    while (opt != 5)
    {
        if (opt == 1)
        {
            int optInsert = 1;
            while (optInsert == 1)
            {
                int insert;
                cout << "Enter value to be inserted: ";
                cin >> insert;
                insertion (root, insert);
                cout << "\t If you want to add another ID enter 1, if you want to exit enter 0: ";
                cin >> optInsert;
                if (optInsert != 1)
                    opt = 0; 
                //return;
            }
        }
        else if (opt == 2)
        {
            int tosearch;
            cout << "Enter value to be searched: ";
            cin >> tosearch;
            search (root, tosearch);
            //return;
        }
        else if (opt == 3)
        {
            int todelete;
            cout << "Enter value to be deleteed: ";
            cin >> todelete;
            deletion (root, todelete);
           // return;
        }
        else if (opt == 4)
        {
            // int opt2;
            // cout << "\t\t Enter 1 for inorder: \n";
            // cout << "\t\t Enter 2 for preorder: \n";
            // cout << "\t\t Enter 3 for postorder: \n";
            // cin >> opt2;
            // if (opt2 == 1)
            // {
            //    inorder(root);
            //    cout << "LOL";
        }
        else if (opt == 5)
        {
            break;
        }
        //     }
        //     else if (opt2 == 2)
        //     {
        //         preorder(root);
        //     }
        //     else if (opt == 3)
        //     {
        //         postorder(root);
        //     }
        //     else {
        //         break;
        //     }
        // }
    
        cout << "\t 1: Insert an ID. \n";
        cout << "\t 2: Search an ID. \n";
        cout << "\t 3: Delete an ID. \n";
        cout << "\t 4: Traverse the tree. \n";
        cout << "\t 5: Exit. \n";
        cin >> opt;
    }
    inorder(root);
    return 0;
}
    // BST *root = nullptr;
    // root = insertion(root, 60);
    // root = insertion(root, 30);
    // root = insertion(root, 50);
    // root = insertion(root, 90);
    // root = insertion(root, 69);
    // root = insertion(root, 109);

    // inorder(root);
    // cout << endl; // Add a newline at the end for better formatting
    // // BST *curr = search(root, 50);
    // // cout << curr->data;
    // deletion(root, 90);
    // inorder (root);
    // return 0;