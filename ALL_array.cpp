// #include <iostream>
// using namespace std;
// int main()
// {
  
// }



// // 	Questions by Love Babbar:
// // Types of Array Traversal
// // There are mainly two types of array traversal:
// // 1. Linear Traversal	

// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};

//     // int a = sizeof(arr);   // 20 
//     // int b = sizeof(arr[0]);   // 4
//     // cout<<a << endl;;
//     // cout<<b << endl; ;
 
//     int n = sizeof(arr) / sizeof(arr[0]);
//     // cout<<n << endl;        // 5 
//     cout << "Linear Traversal: ";
//     for(int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// // 20
// // 4
// // 5
// // Linear Traversal: 1 2 3 4 5 




// // Linear Traversal of array 
// #include <iostream>
// using namespace std;
// int main()
// {
// int arr[]= {1,2,8,4,5} ;
// int n=sizeof(arr)/sizeof(arr[0]);
// cout<< "linear array" <<endl;
// for(int i=0;i<n ; i++){
//   cout<< arr[i]<< " " ;
// }
// }

// // Output
// // Linear Traversal: 1 2 3 4 5 
// // Time Complexity: O(n)
// // Auxiliary Space: O(1)



// // reverse  Traversal of array 
// #include <iostream>
// using namespace std;
// int main()
// {
// int arr[]= {1,2,8,4,5} ;
// int n=sizeof(arr)/sizeof(arr[0]);
// cout<< "Reversal  traversal array  " <<endl;
// for(int i=n-1 ;i>=0 ; i--){
//   cout<< arr[i]<< " " ;
// }
// }

// // Output
// // Reverse Traversal: 5 4 3 2 1 
// // Time Complexity: O(n)
// // Auxiliary Space: O(1)


// // 2. Using While Loop  traversal method 
// #include <iostream>
// using namespace std;
// int main()
// {
// int arr[]= {1,2,8,4,5} ;
// int n=sizeof(arr)/sizeof(arr[0]);
// int i=0;

// cout<< "Array traversal using while loop : " ;
// while( i<n ){
//   cout<< arr[i] << " ";
//   i++;

// }
// cout<< endl;
// }
// // output 
// // Array traversal using while loop : 1 2 8 4 5 
// // Time Complexity: O(n)
// // Auxiliary Space: O(1)


// // Applications of Array Traversal
// // 1. Searching Elements

// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {10, 20, 30, 40, 50};
//     // int target =30 ;
//     int n =sizeof(arr)/sizeof(arr[0]);

//     cout << "searching the target :" ;

//     bool found = false ;
//     for (int i=0 ; i<n; i++ ){
//       if(arr[i]== 30  ){
//         found= true;
//         break;

//       }
//     }
//     if (found){
//       cout<<" Element found!"<<endl;

//     }
//     else{
//       cout<<" target Element not found!"<<endl;
//     }

// return 0;
// }

// // Output
// // Element found!
// // Time Complexity: O(n)
// // Auxiliary Space: O(1)




// // 2. Modifying Elements 
// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {10, 20, 30, 40, 50};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     cout<<"mofifying..... " <<endl;
//     for (int i=0 ;i<n ; i++ ){
//        arr[i]+= 5;

//     }
//     cout<<"mofified array  : " ;
//     for (int i=0; i<n; i++ ){
//       cout<<arr[i]<< " ";

//     }
//     return 0;
// }



// // Output
// // mofifying..... 
// // mofified array  : 15 25 35 45 55 %   

// // Time Complexity: O(n)
// // Auxiliary Space: O(1)





// // 2. Insertion in Array

// Identify the Position: 
// Shift Elements: 
// Insert the New Element: 
// Update the Size (if applicable): 

// Types of Insertion

// 1. Insertion at the Beginning (Index 0)

// Every element must shift one position right.
// This is the least efficient case for large arrays as it affects all elements.

// https://www.geeksforgeeks.org/dsa/insert-element-at-the-beginning-of-an-array/#:~:text=Table%20of%20Content-,%5BApproach%201%5D%20Using%20Built%2DIn%20Methods,-%5BApproach%202%5D%20Using 

// // [Approach 1] Using Built-In Methods
// // [Approach 2] Using Custom Method


// // [Approach 1] Using Built-In Methods

// #include <iostream>
// #include<vector>
// using namespace std;
// int main(){
//   vector<int> arr = {10, 20, 30, 40};
//   int element =50 ;


//   cout<< " before insertion at beginning " <<endl ;
//   for(int i=0; i<arr.size(); i++){
//     cout<< arr[i]<<" ";

//   }
//   cout<<endl;
//   arr.insert(arr.begin(),element);


//   // cout<< " after insertion at beginning\n" ;
//   for(int i=0; i<arr.size(); i++){
//     cout<< arr[i]<<" "; 
    
//   }
//   cout<<endl;
// return 0;

// }


// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<int> arr = {10, 20, 30, 40};
//     int element = 50;

//     cout << "Before insertion at beginning:\n";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl; // Add a newline for better formatting

//     arr.insert(arr.begin(), element);

//     cout << "After insertion at beginning:\n";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl; // Add a newline for better formatting

//     return 0;
// }





  


// [Approach 2] Using Custom Method

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<int> arr; // Corrected initialization
//      int n = arr.size(); // Get the size of the array
//     for(int i = 0 ; i <n ; i++){
//         cin>>arr[i];
//     }
   
//     int element = 50;

//     cout << "Array before insertion:\n"; 
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     // Shift elements to the right to make space for the new element
//     arr.push_back(0); // Increase the size of the vector by 1
//     for (int i = n - 1; i >= 0; i--) {
//         arr[i + 1] = arr[i];
//     }
//     arr[0] = element;

//     cout << "\nArray after insertion:\n"; 
//     for (int i = 0; i < n + 1; i++) { // Print the new size of the array
//         cout << arr[i] << " ";
//     }

//     return 0;
// }



// 2. Insertion at a Specific Index

// Elements after the index shift right.
// If the index is in the middle, half of the array moves.

// C++ program to insert given element at a given position
// in an array using in-built methods








// 3. Insertion at the End

// The simplest case since no shifting is required.
// Used in dynamic arrays where size increases automatically (e.g., Python lists, Java ArrayList).

// C++ program to insert given element at the end 
// of an array using custom methods

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

// 3. Deletion in Array
// How Deletion Works in an Array?

// Since arrays have contiguous memory allocation, deleting an element does not reduce the allocated memory size. Instead, it involves:

// Identify the Position: Find the index of the element to be deleted.
// Shift Elements: Move the elements after the deleted element one position to the left.
// Update the Size (if applicable): If using a dynamic array, the size might be reduced.

// Types of Deletion

// 1. Deletion at the Beginning (Index 0)
// Every element shifts left by one position.
// This is the most expensive case as it affects all elements.
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {  
//     vector<int> arr = {10, 20, 30, 40};
  
//     cout << "Array before deletion:\n";
//     for (int i = 0; i < arr.size(); i++)
//         cout << arr[i] << " ";

//     // Shift all the elements 1 position to the left
//     // starting from the second element
//     for (int i = 1; i < arr.size(); i++)
//         arr[i - 1] = arr[i];
   
//     // Reduce the array size by 1
//     arr.resize(arr.size() - 1); // Resize the vector to remove the last element

//     cout << "\nArray after deletion:\n";
//     for (int i = 0; i < arr.size(); i++)
//         cout << arr[i] << " ";

//     return 0;
// }

// 2. Deletion at a Specific Index
// Only elements after the index shift left.
// If the index is in the middle, half of the array moves.

// 3. Deletion at the End
// The simplest case since no shifting is required.
// The size of the array is reduced (in dynamic arrays).







	
// // 1. Array	Reverse the array

// class Solution {
//   public:
//     void reverseArray(vector<int> &arr) {
        
        
//         // code here
//         // reverse(arr.begin(), arr.end());
        
//         // inplace 
//         int s = 0 , e = arr.size() - 1;
//         while(s < e){
//             swap(arr[s] , arr[e]);
//             s++;
//             e--;
//         }
//     }
// };






// 2. Array	Find the maximum and minimum element in an array


// // User function Template for C++
// class Solution {
//   public:
//     pair<int, int> getMinMax(vector<int> arr) {
//         // code here
//         int n = arr.size();
//         sort(arr.begin() , arr.end());
//         pair<int,int> p = make_pair(arr[0] , arr[n-1]);
//         return p;
        
//     }
// };


// 3. Array	Find the "Kth" max and min element of an array 
// 4. Array	Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
// 5. Array	Move all the negative elements to one side of the array 
// 6. Array	Find the Union and Intersection of the two sorted arrays.
// 7. Array	Write a program to cyclically rotate an array by one.
// 8. Array	find Largest sum contiguous Subarray [V. IMP]
// 9. Array	Minimise the maximum difference between heights [V.IMP]
// 10. Array	Minimum no. of Jumps to reach end of an array
// 11. Array	find duplicate in an array of N+1 Integers
// 12. Array	Merge 2 sorted arrays without using Extra space.
// 13. Array	Kadane's Algo [V.V.V.V.V IMP]
// 14. Array	Merge Intervals
// 15. Array	Next Permutation
// 16. Array	Count Inversion
// 17. Array	Best time to buy and Sell stock
// 18. Array	find all pairs on integer array whose sum is equal to given number
// 19. Array	find common elements In 3 sorted arrays
// 20. Array	Rearrange the array in alternating positive and negative items with O(1) extra space
// 21. Array	Find if there is any subarray with sum equal to 0
// 22. Array	Find factorial of a large number
// 23. Array	find maximum product subarray 
// 24. Array	Find longest coinsecutive subsequence
// 25. Array	Given an array of size n and a number k, fin all elements that appear more than " n/k " times.
// 26. Array	Maximum profit by buying and selling a share atmost twice
// 27. Array	Find whether an array is a subset of another array
// 28. Array	Find the triplet that sum to a given value
// 29. Array	Trapping Rain water problem
// 30. Array	Chocolate Distribution problem
// 31. Array	Smallest Subarray with sum greater than a given value
// 32. Array	Three way partitioning of an array around a given value
// 33. Array	Minimum swaps required bring elements less equal K together
// 34. Array	Minimum no. of operations required to make an array palindrome
// 35. Array	Median of 2 sorted arrays of equal size
// 36. Array	Median of 2 sorted arrays of different size





hello 