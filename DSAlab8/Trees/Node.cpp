#include "Node.h"
int main(){
    Node node;
    Node* root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->right->right = new Node(9);

    int evenCount = node.countEvenNumbers(root);
    cout << evenCount;
	return 0;
}