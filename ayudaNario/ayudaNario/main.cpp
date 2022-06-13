#include <iostream>
using namespace std;
#include <conio.h>
//declaration for new tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

//allocates new node 
struct node* newNode(int data) {
    // declare and allocate new node  
    struct node* node = new struct node();

    node->data = data;    // Assign data to this node

    // Initialize left and right children as NULL 
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main() {
    /*create root node*/
    struct node* rootNode = newNode(10);
    cout << "General tree created is as follows:" << endl;
    cout << "\t\t\t " << rootNode->data << endl;
    cout << "\t\t\t " << "/ " << "\\" << endl; rootNode->left = newNode(20);

    rootNode->right = newNode(30);
    rootNode->right = newNode(90);
    cout << "\t\t\t" << rootNode->left->data << "  " << rootNode->right->data;
    cout << endl; rootNode->left->left = newNode(40);
    cout << "\t\t\t" << "/" << endl;
    cout << "\t\t      " << rootNode->left->left->data;
    _getch();
    return 0;
}