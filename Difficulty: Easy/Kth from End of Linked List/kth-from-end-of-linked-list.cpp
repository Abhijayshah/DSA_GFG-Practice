class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        
        Node* fast = head; // Fast pointer
        Node* slow = head; // Slow pointer
        
        // Move fast pointer k steps ahead
        for (int i = 0; i < k; i++) {
            
            if (fast == NULL) {
                return -1; // If list has fewer than k nodes
            }
            
            fast = fast->next; // Move fast pointer forward
        }
        
        // Move both pointers until fast reaches end
        while (fast != NULL) {
            
            fast = fast->next; // Move fast pointer
            slow = slow->next; // Move slow pointer
        }
        
        // Slow now points to kth node from end
        return slow->data;
    }
};