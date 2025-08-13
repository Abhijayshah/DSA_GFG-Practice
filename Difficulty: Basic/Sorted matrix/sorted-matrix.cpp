class Solution {
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // Step 1: Extract all elements into a 1D vector
        vector<int> elements;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                elements.push_back(Mat[i][j]);
            }
        }
        
        // Step 2: Sort the elements
        sort(elements.begin(), elements.end());
        
        // Step 3: Put sorted elements back into the matrix
        int index = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Mat[i][j] = elements[index++];
            }
        }
        
        return Mat;
    }
};