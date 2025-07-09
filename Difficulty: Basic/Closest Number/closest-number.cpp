class Solution {
  public:
    int closestNumber(int n, int m) {
    // Find integer quotient when n is divided by m
    int q = n / m; // For example, if n = 13, m = 4 => q = 3

    // First possible closest multiple (just below or equal to n)
    int n1 = m * q; // For example, 4 * 3 = 12

    // Second possible closest multiple (just above or below, depending on sign)
    int n2;

    // Check sign of n and m
    // If n and m have the same sign, we move forward (q + 1)
    // Example: n = 13, m = 4 => n * m = 52 > 0 ⇒ n2 = 4 * (3 + 1) = 16
    if (n * m > 0) {
        n2 = m * (q + 1);
    }
    // If n and m have opposite signs, we move backward (q - 1)
    // Example: n = -15, m = 6 => n * m = -90 < 0 ⇒ n2 = 6 * ( -3 - 1 ) = -24
    else {
        n2 = m * (q - 1);
    }

    // Check which multiple is closer to n
    if (abs(n - n1) < abs(n - n2)) {
        // n1 is closer
        return n1;
    }
    if (abs(n - n1) > abs(n - n2)) {
        // n2 is closer
        return n2;
    }

    // If both are equally close, choose the one with greater absolute value
    if (abs(n1) > abs(n2)) {
        return n1;
    } else {
        return n2;
    }
}

};