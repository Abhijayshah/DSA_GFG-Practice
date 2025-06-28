#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 40}; // Correct initialization
    int n = arr.size();
    int pos = 2; // Position to delete (0-based index)
  
    cout << "Array before deletion:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
	
  	// Delete the element at the given position
    for(int i = pos; i < n - 1; i++) {
    	arr[i] = arr[i + 1];
    }
  
    // Resize the vector to remove the last element
    arr.pop_back(); // This effectively reduces the size of the vector by 1

    cout << "\nArray after deletion:\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
