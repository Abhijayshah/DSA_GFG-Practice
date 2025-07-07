#include <vector>
using namespace std;

class Solution {
public:
    // Function to find common elements in three sorted arrays.
    vector<int> commonElements(vector<int> &arr1,
                               vector<int> &arr2,
                               vector<int> &arr3) {
        int i = 0, j = 0, k = 0;
        int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        vector<int> result;
        
        while (i < n1 && j < n2 && k < n3) {
            int v1 = arr1[i], v2 = arr2[j], v3 = arr3[k];
            
            // Case 1: all three are equal → common element!
            if (v1 == v2 && v2 == v3) {
                // Avoid duplicates in result
                if (result.empty() || result.back() != v1) {
                    result.push_back(v1);
                }
                i++; j++; k++;
            }
            // Case 2: advance the smallest pointer
            else if (v1 < v2) {
                i++;
            }
            else if (v2 < v3) {
                j++;
            }
            else {
                k++;
            }
        }
        
        // If no common elements found, return [-1]
        if (result.empty()) 
            return { -1 };
        
        return result;
    }
};
