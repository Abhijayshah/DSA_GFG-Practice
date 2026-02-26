class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        
        // If list is empty or has one node
        if (head == NULL || head->next == NULL)
            return head;
        
        unordered_set<int> seen; // Store unique values
        
        Node* curr = head;       // Current node pointer
        Node* prev = NULL;       // Previous node pointer
        
        while (curr != NULL) {
            
            // If value already seen → remove node
            if (seen.find(curr->data) != seen.end()) {
                
                prev->next = curr->next; // Skip duplicate node
                delete curr;             // Free memory
                curr = prev->next;       // Move forward
            }
            else {
                // First occurrence → store in set
                seen.insert(curr->data);
                
                prev = curr;             // Move prev forward
                curr = curr->next;       // Move curr forward
            }
        }
        
        return head; // Return modified list
    }
};