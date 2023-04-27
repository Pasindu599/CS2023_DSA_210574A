#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};


// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key <<" ";
        traverseInOrder(root->right);
    }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
     
    if (node == NULL){ // check whether the root is empty 
        // create a new node
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (key < node->key)
        // traverse to the left side of the tree
        node->left = insertNode(node->left, key);
    else if(key > node->key)
        // traverse to the right side of the tree
        node->right = insertNode(node->right, key);

    return node;

}
/*
    find the node with minimium value
*/
struct node* findMinValueNode(struct node* node)
{
    struct node* currentNode = node;
    while (currentNode && currentNode->left != NULL)
        currentNode = currentNode->left;
 
    return currentNode;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        // node has no child
        if (root->left == NULL and root->right == NULL)
            return NULL;
 
        // node with only one child 
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
            }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
            }
        
        // with both children
        struct node* tempNode = findMinValueNode(root->right); // check the node with minimum value
        root->key = tempNode->key; 
        root->right = deleteNode(root->right, tempNode->key); // delete the duplicate value of minimum value
        }
    return root;
 
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
