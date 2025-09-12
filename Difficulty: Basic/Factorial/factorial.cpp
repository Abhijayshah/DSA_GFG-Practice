class Solution {
  public:
    int factorial(int n) {
        // code here
        if (n == 0) return 1;
        
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
};

// Alternative recursive solution:
/*
class Solution {
  public:
    int factorial(int n) {
        // Base cases
        if (n == 0 || n == 1) return 1;
        
        // Recursive case
        return n * factorial(n - 1);
    }
};
*/

// Test the solution:
/*
Solution sol;
cout << sol.factorial(5) << endl;  // Output: 120
cout << sol.factorial(4) << endl;  // Output: 24
cout << sol.factorial(0) << endl;  // Output: 1
cout << sol.factorial(1) << endl;  // Output: 1
*/