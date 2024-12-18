#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node() : left(NULL), right(NULL) {}
};

class BinaryTree {
    Node *root;

    Node* createNode(int data) {
        Node* temp = new Node();
        temp->data = data;
        return temp;
    }

    void insert(Node* &current, int data, char direction) {
        if (direction == 'L' || direction == 'l') {
            if (!current->left) current->left = createNode(data);
            else insert(current->left, data, direction);
        } else {
            if (!current->right) current->right = createNode(data);
            else insert(current->right, data, direction);
        }
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(NULL) {}

    void create() {
        char more, direction;
        int data;
        do {
            cout << "Enter data: ";
            cin >> data;
            if (!root) root = createNode(data);
            else {
                cout << "Insert data to left (L) or right (R): ";
                cin >> direction;
                insert(root, data, direction);
            }
            cout << "Add more nodes? (y/n): ";
            cin >> more;
        } while (more == 'y' || more == 'Y');
    }

    void displayMenu() {
        int choice;
        cout << "1. Preorder\n2. Inorder\n3. Postorder\nChoose traversal: ";
        cin >> choice;
        cout << "Traversal: ";
        switch (choice) {
        case 1: preorder(root); break;
        case 2: inorder(root); break;
        case 3: postorder(root); break;
        default: cout << "Invalid choice";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    char cont;
    int choice;

    do {
        cout << "1. Create Tree\n2. Display Traversal\n3. Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
        case 1: tree.create(); break;
        case 2: tree.displayMenu(); break;
        case 3: return 0;
        default: cout << "Invalid choice\n";
        }
        cout << "Continue? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
    return 0;
}
