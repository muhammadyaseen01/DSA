#include <iostream>
#include <cstdlib>

using namespace std;

struct BST
{
    int data;
    BST *right = nullptr;
    BST *left = nullptr;
};
BST *insertion(BST *node, int value)
{
    if (node == nullptr)
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
    return node;
}

void inorder(BST *node)
{
    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void preorder(BST *node)
{
    if (node != nullptr)
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
        cout << node->data << " ";
    }
}

BST *search(BST *node, int value)
{
    if (node == nullptr)
    {
        cerr << "VALUE NOT FOUND!" << endl;
        return nullptr; // Return nullptr to indicate the value was not found
    }
    if (value == node->data)
    {
        return node;
    }
    else if (value > node->data)
    {
        return search(node->right, value);
    }
    else
    {
        return search(node->left, value);
    }
}

BST *minValueNode(BST *node)
{
    BST *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

BST *deletion(BST *node, int value)
{
    if (node == nullptr)
    {
        cerr << "ERROR 404" << endl;
        return node;
    }

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
        if (node->left == nullptr)
        {
            BST *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            BST *temp = node->left;
            delete node;
            return temp;
        }

        BST *temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deletion(node->right, temp->data);
    }

    return node;
}

// 2nd OCT 2023

// int height(BST *node)
// {
//     if (node == NULL)
//         return 0;
//     else
//     {
//         int left_height = height(node->left);
//         int right_height = height(node->right);

//         if (left_height > right_height)
//             return left_height + 1;
//         else
//             return right_height + 1;
//     }
// }
int height(BST *node)
{
    if (node == nullptr)
        return 0;
    else
    {
        int left_height = height(node->left);
        int right_height = height(node->right);

        if (left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;

    }
}
//write a code to print height of every node?
int height_At_Each_Node(BST *node)
{
    if (node == nullptr)
        return 0;

    int left_height = height_At_Each_Node(node->left);
    // cout<<left_height<<endl;
    int right_height = height_At_Each_Node(node->right);
    // cout<<right_height<<endl;

    // Calculate the height of the current node
    int node_height=0;
    if(left_height > right_height){
        node_height = left_height + 1;
    }
    else if(left_height <= right_height){
        
        node_height = right_height + 1;
    }

    cout << "Node with data " << node->data << " has height " << node_height - 1 << endl;

    return node_height;
}

// int height_At_Each_Node(){
    
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
    cout << "\t 6: Height. \n";
    cin >> opt;

    while (true)
    {
        if (opt == 1)
        {
            int optInsert = 1;
            while (optInsert == 1)
            {
                int insert;
                cout << "Enter value to be inserted: ";
                cin >> insert;
                root = insertion(root, insert);
                cout << "\t If you want to add another ID enter 1, if you want to exit enter 0: ";
                cin >> optInsert;
                if (optInsert != 1)
                {
                    break;
                }
            }
        }
        else if (opt == 2)
        {
            int tosearch;
            cout << "Enter value to be searched: ";
            cin >> tosearch;
            root = search(root, tosearch);
            cout << root << endl;
        }
        else if (opt == 3)
        {
            int todelete;
            cout << "Enter value to be deleted: ";
            cin >> todelete;
            root = deletion(root, todelete);
        }
        else if (opt == 4)
        {
            int opt2;
            cout << "\t\t Enter 1 for inorder: \n";
            cout << "\t\t Enter 2 for preorder: \n";
            cout << "\t\t Enter 3 for postorder: \n";
            cin >> opt2;
            if (opt2 == 1)
            {
                cout << "Inorder: " << endl;
                inorder(root);
            }
            else if (opt2 == 2)
            {
                cout << "Preorder: " << endl;
                preorder(root);
            }
            else if (opt2 == 3)
            {
                cout << "Postorder; " << endl;
                postorder(root);
            }
            cout << endl; // Add a newline to separate the output from the menu
        }
        else if (opt == 5)
        {
            break;
        }
        // 2nd OCT 2023
        else if (opt == 6)
        {
            int h = height(root);
            cout <<"height of the tree is: "<< h - 1 << endl;
        }
        else if(opt == 7){
            height_At_Each_Node(root);
            // cout<<"height at each node is: "<< each_h<<endl;
        }
        else
        {
            cout << "INVALID INPUT" << endl;
        }

        cout << "\t 1: Insert an ID. \n";
        cout << "\t 2: Search an ID. \n";
        cout << "\t 3: Delete an ID. \n";
        cout << "\t 4: Traverse the tree. \n";
        cout << "\t 5: Exit. \n";
        cout << "\t 6: Height. \n";
        cin >> opt;
    }

    return 0;
}



    // int node_height = 1 + max(left_height, right_height);
