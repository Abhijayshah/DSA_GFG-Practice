#include <iostream>
#include <string> // Required for std::string and std::to_string

// It's often better to use std::cout, std::cin, etc., but using namespace std
// is common in competitive programming and simple examples.
using namespace std;

int main() {
    int a, b;
    
    // Read two integers from the user's input.
    cin >> a >> b;

    // --- Concatenation Logic ---
    // 1. Convert both integers to their string representations.
    string str_a = to_string(a);
    string str_b = to_string(b);

    // 2. Concatenate (join) the two strings.
    string result = str_a + str_b;

    // 3. Print the final concatenated string to the output.
    cout << result << endl;
    // --- End of Logic ---

    return 0;
}

