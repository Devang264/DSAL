#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}

    static Node* insert(Node* root, int value) {
        if (!root) return new Node(value);
        if (value < root->data) root->left = insert(root->left, value);
        else root->right = insert(root->right, value);
        return root;
    }

    static void preOrder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    static void postOrder(Node* root) {
        if (!root) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    static Node* findMin(Node* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    static Node* deleteNode(Node* root, int value) {
        if (!root) return nullptr;
        if (value < root->data) root->left = deleteNode(root->left, value);
        else if (value > root->data) root->right = deleteNode(root->right, value);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            Node* minRight = findMin(root->right);
            root->data = minRight->data;
            root->right = deleteNode(root->right, minRight->data);
        }
        return root;
    }

    static int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "1: Insert  2: Pre-order  3: Post-order  4: Delete  5: Height  6: Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            root = Node::insert(root, value);
            break;
        case 2:
            cout << "Pre-order: ";
            Node::preOrder(root);
            cout << "\n";
            break;
        case 3:
            cout << "Post-order: ";
            Node::postOrder(root);
            cout << "\n";
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            root = Node::deleteNode(root, value);
            break;
        case 5:
            cout << "Height: " << Node::height(root) << "\n";
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
