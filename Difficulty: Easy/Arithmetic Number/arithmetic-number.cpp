class Solution {
public:
    int inSequence(int a, int b, int c) {

        if (c == 0) {                     // If common difference is zero
            return (a == b);              // Only one constant value
        }

        int term = a;                     // Start from first term

        // Loop until we cross b
        while ((c > 0 && term <= b) || (c < 0 && term >= b)) {

            if (term == b) {              // If b is found
                return 1;                 // Present in sequence
            }

            term += c;                    // Move to next term
        }

        return 0;                         // b not found
    }
};
