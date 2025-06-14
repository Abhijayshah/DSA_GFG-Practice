#include <iostream>
using namespace std;

int main() {

    // Declaring 2D array
    int arr[4][4];

    // Initialize 2D array using loop
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = i + j;
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }

    // Printing the element of 2D array
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
            
    //     }
    //     cout << endl;
    // }

    return 0;
}