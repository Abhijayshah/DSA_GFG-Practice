class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

        vector<pair<int, int>> ans;

        // Edge case: empty or single node
        if (!head || !head->next)
            return ans;

        // Step 1: Set left pointer at head
        Node* left = head;

        // Step 2: Move right pointer to last node
        Node* right = head;
        while (right->next != NULL) {
            right = right->next;
        }

        // Step 3: Two-pointer traversal
        while (left != right && left->data < right->data) {

            int sum = left->data + right->data;

            if (sum == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return ans;
    }
};
