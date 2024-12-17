#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }

        gap /= 2;
    }
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3};

    cout << "Original Array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    shellSort(arr);

    cout << "Sorted Array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
