#include <iostream>
using namespace std;
struct node
{
    struct node *left;
    int data;
    struct node *right;
} * root, *ptr, *newnode, *parent, *tpar, *temp, *st[20];

struct node *create(struct node *);
struct node *search(struct node *, int);
struct node *successor(struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void deleteLeaf(struct node *);
void deleteLeft(struct node *);
void deleteRight(struct node *);
void deleteBoth(struct node *);
void inorderStack(struct node *);
void preorderStack(struct node *);
void postorderStack(struct node *);

int main()
{
    int op;
    do
    {
        cout << "\n1.Create\n2.Inorder\n3.Preorder\n4.Postorder\n5.Delete Leaf\n6.Delete Left\n7.Delete Right\n8.Delete Both\n9.Inorder Stack\n10.Preorder Stack\n11.Postorder Stack\n12.Exit\n";
        cout << "Choose your option\n";
        cin >> op;
        switch (op)
        {
        case 1:
            root = create(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            deleteLeaf(root);
            break;
        case 6:
            deleteLeft(root);
            break;
        case 7:
            deleteRight(root);
            break;
        case 8:
            deleteBoth(root);
            break;
        case 9:
            inorderStack(root);
            break;
        case 10:
            preorderStack(root);
            break;
        case 11:
            postorderStack(root);
            break;
        case 12:
            exit(0);

        default:
            cout << "Invalid option";
        }
    } while (op <= 12);
}

struct node *create(struct node *root)
{
    int value, n;
    cout << "Enter the number of nodes\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value\n";
        cin >> value;
        newnode = new struct node;
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        if (root == NULL)
            root = newnode;
        else
        {
            ptr = root;
            parent = NULL;
            while (ptr != NULL)
            {
                parent = ptr;
                if (value > ptr->data)
                    ptr = ptr->right;
                else
                    ptr = ptr->left;
            }
            if (value > parent->data)
                parent->right = newnode;
            else
                parent->left = newnode;
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "\t";
    }
}

struct node *search(struct node *root, int value)
{
    ptr = root;
    if (value > ptr->data)
    {
        parent = ptr;
        return search(ptr->right, value);
    }
    else if (value < ptr->data)
    {
        parent = ptr;
        return search(ptr->left, value);
    }
    else if (value == ptr->data)
        return ptr;
    else
        return NULL;
}

void deleteLeaf(struct node *root)
{
    int value;
    cout << "Enter the value of the leaf node\n";
    cin >> value;
    ptr = search(root, value);
    if (value > parent->data)
        parent->right = NULL;
    else
        parent->left = NULL;
    delete ptr;
}
void deleteLeft(struct node *root)
{
    int value;
    cout << "Enter the value of the node which has a left node only\n";
    cin >> value;
    ptr = search(root, value);
    if (value > parent->data)
        parent->right = ptr->left;
    else
        parent->left = ptr->left;
    delete ptr;
}
void deleteRight(struct node *root)
{
    int value;
    cout << "Enter the value of the node which has a right node only\n";
    cin >> value;
    ptr = search(root, value);
    if (value > parent->data)
        parent->right = ptr->right;
    else
        parent->left = ptr->right;
    delete ptr;
}

struct node *successor(struct node *ptr)
{
    while (ptr->left != NULL)
    {
        tpar = ptr;
        ptr = ptr->left;
    }
    return ptr;
}

void deleteBoth(struct node *root)
{
    int value;
    cout << "Enter the value of the node which has both nodes";
    cin >> value;
    ptr = search(root, value);
    temp = successor(ptr->right);
    ptr->data = temp->data;
    if (tpar == NULL)
        ptr->right = temp->right;
    else
        tpar->left = temp->right;
    delete temp;
}

void inorderStack(struct node *root)
{
    int top = 0;
    ptr = root;

    while (top != -1)
    {
        if (ptr != NULL)
        {
            top++;
            st[top] = ptr;
            ptr = ptr->left;
        }
        else
        {
            ptr = st[top];
            top--;
            //because when stack is empty...ptr->data does not exists, which causes the program to stop abruptly
            if (ptr != NULL)
            {
                cout << ptr->data << "\t";
                ptr = ptr->right;
            }
        }
    }
}

void preorderStack(struct node *root)
{
    int top = 0;
    ptr = root;
    st[top] = ptr;
    while (top != -1)
    {
        if (ptr != NULL)
        {
            cout << ptr->data << "\t";
            top++;
            st[top] = ptr->right;
            top++;
            st[top] = ptr->left;
            ptr = ptr->left;
        }
        ptr = st[top];
        top--;
    }
}

void postorderStack(struct node *root)
{
    cout << "Still not implemented.";
}