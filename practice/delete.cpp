#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int indexToDelete = 2; // Index of the element to delete

    // Check if the index is valid
    if (indexToDelete >= 0 && indexToDelete < arr.size()) {
        arr.erase(arr.begin() + indexToDelete);
    } else {
        cout << "Index out of bounds." << endl;
    }

    // Print the modified array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}