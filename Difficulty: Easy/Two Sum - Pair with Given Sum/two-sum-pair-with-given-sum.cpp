class Solution {
public:
    // Optimal Solution: Hash Map Approach - O(n) time, O(n) space
    bool twoSum(vector<int>& arr, int target) {
        unordered_set<int> seen;
        
        for (int num : arr) {
            int complement = target - num;
            
            // Check if complement exists in the set
            if (seen.find(complement) != seen.end()) {
                return true;
            }
            
            // Add current number to the set
            seen.insert(num);
        }
        
        return false;
    }
};

// Alternative Solution 1: Two Pointer Approach - O(n log n) time, O(1) space
class SolutionTwoPointer {
public:
    bool twoSum(vector<int>& arr, int target) {
        // Create a vector of pairs (value, original_index) to track indices
        vector<pair<int, int>> indexed_arr;
        for (int i = 0; i < arr.size(); i++) {
            indexed_arr.push_back({arr[i], i});
        }
        
        // Sort by value
        sort(indexed_arr.begin(), indexed_arr.end());
        
        int left = 0, right = indexed_arr.size() - 1;
        
        while (left < right) {
            int sum = indexed_arr[left].first + indexed_arr[right].first;
            
            if (sum == target) {
                // Check if indices are different (they should be after sorting)
                return indexed_arr[left].second != indexed_arr[right].second;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return false;
    }
};

// Alternative Solution 2: Brute Force - O(n²) time, O(1) space
class SolutionBruteForce {
public:
    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == target) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

// Version that returns the actual indices (common variation)
class SolutionWithIndices {
public:
    vector<int> twoSumIndices(vector<int>& arr, int target) {
        unordered_map<int, int> numToIndex;
        
        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];
            
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            
            numToIndex[arr[i]] = i;
        }
        
        return {}; // No solution found
    }
    
    bool twoSum(vector<int>& arr, int target) {
        vector<int> result = twoSumIndices(arr, target);
        return !result.empty();
    }
};

// Test function to demonstrate all approaches
void testAllSolutions() {
    Solution solution;
    SolutionTwoPointer solutionTP;
    SolutionBruteForce solutionBF;
    SolutionWithIndices solutionWI;
    
    vector<pair<vector<int>, int>> testCases = {
        {{0, -1, 2, -3, 1}, -2},     // Expected: true (indices 3,4)
        {{1, -2, 1, 0, 5}, 0},       // Expected: false
        {{11}, 11},                  // Expected: false (only one element)
        {{2, 7, 11, 15}, 9},         // Expected: true (indices 0,1)
        {{3, 2, 4}, 6},              // Expected: true (indices 1,2)
        {{3, 3}, 6},                 // Expected: true (indices 0,1)
        {{1, 2, 3, 4, 5}, 10},       // Expected: false
        {{-1, -2, -3, -4, -5}, -8},  // Expected: true (indices 2,4)
    };
    
    cout << "Testing Two Sum Solutions:\n\n";
    
    for (int t = 0; t < testCases.size(); t++) {
        vector<int> arr = testCases[t].first;
        int target = testCases[t].second;
        
        cout << "Test Case " << (t + 1) << ":\n";
        cout << "Array: [";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ", ";
        }
        cout << "], Target: " << target << "\n";
        
        // Test all solutions
        vector<int> arr1 = arr, arr2 = arr, arr3 = arr, arr4 = arr;
        
        bool result1 = solution.twoSum(arr1, target);
        bool result2 = solutionTP.twoSum(arr2, target);
        bool result3 = solutionBF.twoSum(arr3, target);
        bool result4 = solutionWI.twoSum(arr4, target);
        
        cout << "Hash Map: " << (result1 ? "true" : "false") << "\n";
        cout << "Two Pointer: " << (result2 ? "true" : "false") << "\n";
        cout << "Brute Force: " << (result3 ? "true" : "false") << "\n";
        cout << "With Indices: " << (result4 ? "true" : "false") << "\n";
        
        // Show actual indices if found
        if (result4) {
            vector<int> indices = solutionWI.twoSumIndices(arr, target);
            if (!indices.empty()) {
                cout << "Indices: [" << indices[0] << ", " << indices[1] << "]\n";
                cout << "Values: " << arr[indices[0]] << " + " << arr[indices[1]] 
                     << " = " << (arr[indices[0]] + arr[indices[1]]) << "\n";
            }
        }
        
        // Verify all solutions match
        if (result1 == result2 && result2 == result3 && result3 == result4) {
            cout << "✓ All solutions match\n\n";
        } else {
            cout << "✗ Solutions don't match!\n\n";
        }
    }
}

// Complexity analysis and explanation
void explainComplexity() {
    cout << "TWO SUM ALGORITHM COMPLEXITY ANALYSIS:\n\n";
    
    cout << "1. HASH MAP APPROACH (Recommended):\n";
    cout << "   Time Complexity: O(n) - single pass through array\n";
    cout << "   Space Complexity: O(n) - hash set for storing elements\n";
    cout << "   Pros: Fastest, handles duplicates well\n";
    cout << "   Cons: Uses extra space\n\n";
    
    cout << "2. TWO POINTER APPROACH:\n";
    cout << "   Time Complexity: O(n log n) - due to sorting\n";
    cout << "   Space Complexity: O(n) - for storing index pairs\n";
    cout << "   Pros: Can be modified to O(1) space if indices not needed\n";
    cout << "   Cons: Slower due to sorting, complex index tracking\n\n";
    
    cout << "3. BRUTE FORCE APPROACH:\n";
    cout << "   Time Complexity: O(n²) - nested loops\n";
    cout << "   Space Complexity: O(1) - no extra space\n";
    cout << "   Pros: Simple to understand, no extra space\n";
    cout << "   Cons: Inefficient for large arrays\n\n";
    
    cout << "RECOMMENDATION: Use Hash Map approach for optimal performance\n";
}