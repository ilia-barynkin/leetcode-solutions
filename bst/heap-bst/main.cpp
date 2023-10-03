#include <cstdlib>
#include <cassert>

typedef struct node {
    int data;
    node* left;
    node* right;
} node;

typedef node* nodeptr;

nodeptr getNode(nodeptr* root, int val) {
    if(!(*root))
        return *root = new node{val, nullptr, nullptr};

    if ((*root)->data == val) 
        return *root;
    else if ((*root)->data > val)
        return getNode(&(*root)->left, val);
    // else if (root->right->data < val)
    return getNode(&(*root)->right, val);
}

int main(int argc, char* argv) {
    node* root = NULL;
    root = getNode(&root, 1);
    node* left = getNode(&root, 0);
    node* right = getNode(&root, 2);

    return 0;
}