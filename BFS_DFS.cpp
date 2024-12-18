#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void BFS(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

void DFS(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>());

    cout << "Enter the adjacency matrix (0 for no edge, 1 for edge):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int edge;
            cin >> edge;
            if (edge == 1) {
                graph[i].push_back(j);
            }
        }
    }

    cout << "Choose traversal method:" << endl;
    cout << "1. BFS (Breadth First Search)" << endl;
    cout << "2. DFS (Depth First Search)" << endl;
    int choice;
    cin >> choice;

    cout << "Enter starting vertex: ";
    int start;
    cin >> start;

    switch (choice) {
        case 1:
            cout << "BFS Traversal: ";
            BFS(graph, start);
            break;
        case 2:
            cout << "DFS Traversal: ";
            DFS(graph, start);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
