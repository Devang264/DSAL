#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val = 0) : data(val), left(nullptr), right(nullptr) {}
};

Node* construct(int r[10][10], int i, int j) {
    if (i > j) return nullptr;
    int rootIndex = r[i][j];
    Node* root = new Node(rootIndex);
    root->left = construct(r, i, rootIndex - 1);
    root->right = construct(r, rootIndex + 1, j);
    return root;
}

void optimalBST(int p[], int q[], int n, int c[10][10], int r[10][10]) {
    int w[10][10] = {0};
    for (int i = 0; i <= n; i++) c[i][i] = q[i], r[i][i] = 0;

    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            c[i][j] = INT_MAX;

            for (int k = i + 1; k <= j; k++) {
                int cost = c[i][k - 1] + c[k][j] + w[i][j];
                if (cost < c[i][j]) c[i][j] = cost, r[i][j] = k;
            }
        }
    }
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    int p[10], q[10], n, c[10][10], r[10][10];
    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter probabilities p[] for keys: ";
    for (int i = 1; i <= n; i++) cin >> p[i];
    cout << "Enter probabilities q[] for dummy keys: ";
    for (int i = 0; i <= n; i++) cin >> q[i];

    optimalBST(p, q, n, c, r);

    cout << "Optimal cost of BST: " << c[0][n] << endl;
    Node* root = construct(r, 1, n);
    cout << "In-order traversal of OBST: ";
    inOrder(root);
    cout << endl;
    return 0;
}
