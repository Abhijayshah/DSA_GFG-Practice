class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;

        Node* curr = head;
        int count = 0;
        
        // Count k nodes ahead
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        
        // If fewer than k remain, still reverse them (as per problem statement)
        if (count < k) {
            return reverse(head, count);
        }
        
        // Reverse first k nodes
        Node* newHead = reverse(head, k);
        
        // Recurse for remaining list
        head->next = reverseKGroup(curr, k);
        
        return newHead;
    }

  private:
    // Helper to reverse k nodes starting from head
    Node* reverse(Node* head, int k) {
        Node* prev = nullptr;
        Node* curr = head;
        while (k-- && curr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev; // new head
    }
};
