#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter the Number of Cities :- ";
    cin >> n;

    int cost[n][n], visit[n];

    // Initialize cost Matrix to -1 and visit Array to 0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cost[i][j] = -1;
        }
        visit[i] = 0;
    }

    // Get user input for the cost matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) 
                continue; // Skip diagonal elements

            cout << "Do you Want to add path between city " << i << " and city " << j << "? ";
            char ch; 
            cin >> ch;

            if (ch == 'y' || ch == 'Y') {
                cout << "Enter the Cost of the Edge :- "; 
                cin >> cost[i][j];
                cost[j][i] = cost[i][j]; // Undirected graph
            }
        }
    }

    // Find the minimum cost to visit all cities (using Prim's algorithm)
    int mincost = 0;
    visit[0] = 1; // Start from city 0

    for (int e = 0; e < n - 1; ++e) {
        int min = 999;
        int next;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visit[i] == 1 && visit[j] == 0 && cost[i][j] != -1 && cost[i][j] < min) {
                    min = cost[i][j];
                    next = j;
                }
            }
        }

        mincost += min;
        visit[next] = 1;
    }

    cout << "Minimum Cost to Visit all cities :- " << mincost << endl;

    // Display the cost matrix
    cout << "\n\nCost Matrix:- "<< endl << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(5) << cost[i][j] << " "; 
        }
        cout << endl << endl;
    }

    return 0;
}
