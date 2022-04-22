#include<iostream>
#include "QueueCPP.h"

using namespace std;

/*
    Author: Rakin
    Date:  22-04-2022
    Language: C++
    Content: Tree
*/

class Tree
{
private:
    Node * root;

public:
    Tree();
    ~Tree();
    void createTree();
    void preorderTraversal(Node *node);
    void postorderTraversal(Node *node);
    void inorderTraversal(Node *node);
    Node * rootNode();
};

Tree :: Tree()
{
    root = NULL;
}

Tree :: ~Tree()
{
    delete root;
}

void Tree :: createTree()
{
    Node *current, *temp;
    Queue qt;
    int data;

    // creating root node
    cout << "Enter root node value : ";
    cin >> data;
    root = new Node;
    root->data = data;
    root->leftChild = NULL;
    root->rightChild = NULL;

    qt.enqueueElement(root);

    while(!qt.isEmpty())
    {
        current = qt.dequeueElement();

        // For left child
        cout << "\nEnter left child of node-> [" << current->data << "] : ";
        cin >> data;
        if(data != -1)
        {
            temp = new Node;
            temp->data = data;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
            current->leftChild = temp;
            qt.enqueueElement(temp);
        }

        // For Right child
        cout << "Enter right child of node-> [" << current->data << "] : ";
        cin >> data;
        if(data != -1)
        {
            temp = new Node;
            temp->data = data;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
            current->rightChild = temp;
            qt.enqueueElement(temp);
        }
    }
    cout << endl << endl;
}

Node * Tree :: rootNode()
{
    return root;
}

void Tree :: preorderTraversal(Node *node)
{
    if(node)
    {
        cout << "\t" << node->data;
        preorderTraversal(node->leftChild);
        preorderTraversal(node->rightChild);
    }
}

void Tree :: inorderTraversal(Node *node)
{
    if(node)
    {
        inorderTraversal(node->leftChild);
        cout << "\t" << node->data;
        inorderTraversal(node->rightChild);
    }
}

void Tree :: postorderTraversal(Node *node)
{
    if(node)
    {
        postorderTraversal(node->leftChild);
        postorderTraversal(node->rightChild);
        cout << "\t" << node->data;
    }
}

int main()
{
    cout << "\t***** An Example of Tree in C++ *****\n\n";

    Tree t;
    t.createTree();

    cout << "Preorder Traversal : " << endl;
    t.preorderTraversal(t.rootNode());
    cout << endl;

    cout << "Inorder Traversal : " << endl;
    t.inorderTraversal(t.rootNode());
    cout << endl;

    cout << "Postorder Traversal : " << endl;
    t.postorderTraversal(t.rootNode());
    cout << endl;

    return 0;
}
