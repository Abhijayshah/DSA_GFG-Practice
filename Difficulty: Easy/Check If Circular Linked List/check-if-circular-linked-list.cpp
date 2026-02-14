class Solution {
  public:
    bool isCircular(Node *head) {
        if (head == NULL) {
            return true;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If we meet again, check if it's at head
            if (slow == fast) {
                // For a true circular list, fast should eventually meet slow at head
                // But since there are no inner loops, any meeting point means we're back to some node
                // For a circular list (tail to head), fast and slow will meet at some node
                // Let's check if we can reach head from this meeting point
                Node* temp = slow;
                while (temp->next != slow) {
                    if (temp->next == head) {
                        return true;
                    }
                    temp = temp->next;
                }
                return (temp->next == head);
            }
        }
        
        return false;
    }
};