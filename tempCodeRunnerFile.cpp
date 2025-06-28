#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;
    vector<int> arr = {10, 20, 30, 40, 0};
  	int ele = 50;
    cout << "Array before insertion\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
	
  	arr[n] = ele;

    cout << "\nArray after insertion\n";
    for (int i = 0; i <= n; i++)
        cout << arr[i] << " ";

    return 0;
}