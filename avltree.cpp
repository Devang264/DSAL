#include <iostream>

using namespace std;

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int choice, data;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int num_insertions;
                cout << "Enter the number of elements to insert: ";
                cin >> num_insertions;
                for (int i = 0; i < num_insertions; ++i) {
                    cout << "Enter data to insert: ";
                    cin >> data;
                    root = insert(root, data);
                }
                break;
            }
            case 2:
                cout << "Preorder traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
