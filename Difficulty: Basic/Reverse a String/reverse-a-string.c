#include <string.h>   // For strlen()

char* reverseString(char* s) {
    int left = 0;                   // Pointer starting from the beginning
    int right = strlen(s) - 1;      // Pointer starting from the end

    while (left < right) {          // Swap characters until pointers meet

        char temp = s[left];        // Store left character temporarily
        s[left] = s[right];         // Copy right character to the left position
        s[right] = temp;            // Put temp (original left char) into right position

        left++;                     // Move left pointer forward
        right--;                    // Move right pointer backward
    }

    return s;                       // Return the reversed string
}
