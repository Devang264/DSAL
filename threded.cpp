#include <iostream>
#include <queue>

using namespace std;

class ThreadedNode {
public:
    int data;
    ThreadedNode* left;
    ThreadedNode* right;
    bool isThreaded;

    ThreadedNode(int data) : data(data), left(nullptr), right(nullptr), isThreaded(false) {}
};

ThreadedNode* insert(ThreadedNode* root, int data) {
    if (root == nullptr) {
        ThreadedNode* newNode = new ThreadedNode(data);
        return newNode;
    }

    if (data < root->data) {
        if (root->left == nullptr) {
            root->left = new ThreadedNode(data);
            root->left->right = root; 
        } else {
            root->left = insert(root->left, data);
        }
    } else if (data > root->data) {
        if (root->right == nullptr) {
            root->right = new ThreadedNode(data);
            root->right->isThreaded = true; 
        } else if (!root->right->isThreaded) {
            root->right = insert(root->right, data);
        } else {
            ThreadedNode* temp = root->right;
            while (!temp->isThreaded) {
                temp = temp->right;
            }
            temp->right = new ThreadedNode(data);
            temp->right->isThreaded = true;
        }
    }

    return root;
}

void inorder(ThreadedNode* root) {
    ThreadedNode* current = root;
    while (current != nullptr) {
        if (!current->isThreaded) { 
            current = current->left; 
        } else {
            cout << current->data << " ";
            current = current->right;
        }
    }
}

void preorder(ThreadedNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " "; 

    if (root->left != nullptr && !root->left->isThreaded) { 
        preorder(root->left); 
    }

    if (root->right != nullptr && root->right->isThreaded) { 
        preorder(root->right); 
    }
}

void display(ThreadedNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<ThreadedNode*> q;
    q.push(root);

    while (!q.empty()) {
        int nodeCount = q.size();

        for (int i = 0; i < nodeCount; ++i) {
            ThreadedNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left && !current->left->isThreaded) {
                q.push(current->left);
            }

            if (current->right && current->right->isThreaded) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
}

int main() {
    ThreadedNode* root = nullptr;
    int choice, data;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Display Tree Level-by-Level\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter data to insert: ";
                cin >> data;
                root = insert(root, data);
                break;
            }
            case 2:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Display Tree Level-by-Level:\n";
                display(root); 
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
