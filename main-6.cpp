#include<iostream>
using namespace std;

struct bstnode
{
   int data;
   struct bstnode *leftchild, *rightchild;
};

struct bstnode *newNode(char val)
{
    bstnode* temp = new bstnode();
    temp->data = val;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}

void inorder(struct bstnode *root)
{
    if (root != NULL)
    {
        inorder(root->leftchild);
        cout<<root->data<<" ";
        inorder(root->rightchild);
    }
}

struct bstnode* insert(struct bstnode* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->data)
        node->leftchild = insert(node->leftchild, key);
    else
        node->rightchild = insert(node->rightchild, key);
   return node;
}

struct bstnode* search(struct bstnode* root, int key)
{
    if (root == NULL || root->data == key)
        return root;


    if (root->data < key)
       return search(root->rightchild, key);
    else
        return search(root->leftchild, key);
}

struct bstnode * minValueNode(struct bstnode* node)
{
    struct bstnode* current = node;
    while (current && current->leftchild != NULL)
        current = current->leftchild;
    return current;
}

struct bstnode* deleteNode(struct bstnode* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->leftchild = deleteNode(root->leftchild, key);
    else if (key > root->data)
        root->rightchild = deleteNode(root->rightchild, key);
   else
    {

        if (root->leftchild == NULL)
        {
            struct bstnode *temp = root->rightchild;
            free(root);
            return temp;
        }

        else if (root->rightchild == NULL)
        {
            struct bstnode *temp = root->leftchild;
            free(root);
            return temp;
        }
        else
        {
            struct bstnode* temp = minValueNode(root->rightchild);
            root->data = temp->data;
            root->rightchild = deleteNode(root->rightchild, temp->data);
        }
    }
   return root;
}

void mirror(struct bstnode* node)
{
    if (node == NULL)
        return;
    else
    {
        struct bstnode* temp;
        mirror(node->leftchild);
        mirror(node->rightchild);

        temp= node->leftchild;
        node->leftchild = node->rightchild;
        node->rightchild = temp;
    }
}

struct bstnode* copy(struct bstnode *root)
{
    bstnode *root2;
    if(root==NULL)
        return NULL;
    root2=new bstnode;
    root2->leftchild=copy(root->leftchild);
    root2->rightchild=copy(root->rightchild);
    root2->data=root->data;

    return root2;
}
int Maxdepth(struct bstnode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int depth1=Maxdepth(root->leftchild);
        int depth2=Maxdepth(root->rightchild);
        if(depth1>depth2)
            return (depth1+1);
        else
            return (depth2+1);

    }
}

int main()
{
    struct bstnode *root = NULL;
    struct bstnode *root2=NULL;
    struct bstnode *root1=NULL;
    struct bstnode *root3=NULL;
    int ch,n,d,depth;
    do
    {
        cout<<"\n1.Insert the elements in the BST.\n2.Delete elements from the BST.\n3.Search an element from the BST.\n4.Traverse through the BST.\n5.Depth of BST.\n6.Display copy of BST.\n7.Display the Mirror image of BST.\n8.EXIT.\nEnter your choice - "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter total number of elements in the BST - ";
                cin>>n;
                cout<<"\nEnter the values to create BST: ";
                for(int i=0; i<n; i++)
                {
                    cin>>d;
                    root = insert(root, d);
                }
                break;
            case 2:
                cout<<"\nEnter the element to be deleted: ";
                cin>>d;
                root3=deleteNode(root, d);
                break;
            case 3:
                cout<<"\nEnter the element to be searched: ";
                cin>>d;
                root1=search(root, d);
                if(root1!=NULL)
                    cout<<"\nElement Found in BST!!";
                else
                    cout<<"\nElement not Found in BST!!";
                break;
            case 4:
                cout<<"\nTraversal of BST: ";
                inorder(root);
                break;
            case 5:
                depth=Maxdepth(root);
                cout<<"The depth of BST is: "<<depth;
                break;
            case 6:
                root2=copy(root);
                cout<<"The copy of BST is: ";
                inorder(root2);
                break;
            case 7:
                mirror(root);
                cout <<"\nInorder traversal of the mirror BST is: ";
                inorder(root);
                mirror(root);
                break;
            case 8:
                cout<<"YOU ARE OUT";
                break;
            default:
                cout<<"\nInvalid choice";
        }
    }while(ch!=8);
    
    return 0;
}
