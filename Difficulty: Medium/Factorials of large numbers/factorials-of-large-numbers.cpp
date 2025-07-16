class Solution {
  public:
    vector<int> factorial(int n) {
        vector<int> result;
        result.push_back(1); // Initial factorial of 0! or 1! is 1
        
        for (int i = 2; i <= n; ++i) {
            int carry = 0;
            
            // Multiply each digit of result by i
            for (int j = 0; j < result.size(); ++j) {
                int product = result[j] * i + carry;
                result[j] = product % 10;
                carry = product / 10;
            }
            
            // Handle remaining carry
            while (carry) {
                result.push_back(carry % 10);
                carry /= 10;
            }
        }
        
        // The result is in reverse order (least significant digit first)
        reverse(result.begin(), result.end());
        return result;
    }
};
