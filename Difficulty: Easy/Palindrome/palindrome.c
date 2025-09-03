bool isPalindrome(int n) {
    int original = n;
    long long reversedNum = 0; // long long to avoid overflow for 10^9

    while (n > 0) {
        int digit = n % 10;
        reversedNum = reversedNum * 10 + digit;
        n /= 10;
    }

    return original == reversedNum;
}
