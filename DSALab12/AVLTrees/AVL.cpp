#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        int height;

        Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int Height(Node* n) {
        if (n == nullptr) return 0;
        return n->height;
    }

    int HeightDifference(Node* n) {
        return Height(n->left) - Height(n->right);
    }

    bool IsBalanced(Node* n) {
        if (n == nullptr) return true;

        int balance = HeightDifference(n);
        return (abs(balance) <= 1) && IsBalanced(n->left) && IsBalanced(n->right);
    }

    Node* RightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + std::max(Height(y->left), Height(y->right));
        x->height = 1 + std::max(Height(x->left), Height(x->right));

        return x;
    }

    Node* LeftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + std::max(Height(x->left), Height(x->right));
        y->height = 1 + std::max(Height(y->left), Height(y->right));

        return y;
    }

    Node* InsertInAVL(Node* root, int v) {
        if (root == nullptr) return new Node(v);

        if (v < root->value)
            root->left = InsertInAVL(root->left, v);
        else if (v > root->value)
            root->right = InsertInAVL(root->right, v);
        else
            return root; 

        root->height = 1 + std::max(Height(root->left), Height(root->right));

        int balance = HeightDifference(root);

       
        if (balance > 1 && v < root->left->value)
            return RightRotate(root);
        if (balance < -1 && v > root->right->value)
            return LeftRotate(root);
        if (balance > 1 && v > root->left->value) {
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }
        if (balance < -1 && v < root->right->value) {
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }

        return root;
    }

    Node* FindMinValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* DelFromAVL(Node* root, int v) {
        if (root == nullptr) return root;

        if (v < root->value)
            root->left = DelFromAVL(root->left, v);
        else if (v > root->value)
            root->right = DelFromAVL(root->right, v);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else {
                Node* temp = FindMinValueNode(root->right);

                root->value = temp->value;

                root->right = DelFromAVL(root->right, temp->value);
            }
        }

        if (root == nullptr) return root;

        root->height = 1 + std::max(Height(root->left), Height(root->right));

        int balance = HeightDifference(root);

        if (balance > 1 && HeightDifference(root->left) >= 0)
            return RightRotate(root);
        if (balance > 1 && HeightDifference(root->left) < 0) {
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }
        if (balance < -1 && HeightDifference(root->right) <= 0)
            return LeftRotate(root);
        if (balance < -1 && HeightDifference(root->right) > 0) {
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }

        return root;
    }

public:
    AVLTree() : root(nullptr) {}

    void InsertInAVL(int v) {
        root = InsertInAVL(root, v);
    }

    void DelFromAVL(int v) {
        root = DelFromAVL(root, v);
    }

    bool IsBalanced() {
        return IsBalanced(root);
    }

    void PrintTree(Node* root, int space) {
        if (root == nullptr) return;

        space += 5;

        PrintTree(root->right, space);

        cout << std::endl;
        for (int i = 5; i < space; i++)
            std::cout << " ";
        cout << root->value << "\n";

      
        PrintTree(root->left, space);
    }

    void PrintTree() {
        PrintTree(root, 0);
    }
};

int main() {
    AVLTree avlTree;

  
    avlTree.InsertInAVL(10);
    avlTree.InsertInAVL(20);
    avlTree.InsertInAVL(30);
    avlTree.InsertInAVL(45);
    avlTree.InsertInAVL(78);
    
    cout << "AVL Tree after insertion:\n";
    avlTree.PrintTree();


    cout<< "\nIs the tree balanced? " << (avlTree.IsBalanced() ? "Yes" : "No") << "\n";


    avlTree.DelFromAVL(20);

  cout << "\nAVL Tree after deletion:\n";
    avlTree.PrintTree();

    return 0;
}
