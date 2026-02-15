class Solution {
  public:
    Node* deleteNode(Node* head, int key) {
        
        // If list is empty, nothing to delete
        if (head == NULL)
            return NULL;
        
        Node* curr = head;      // Pointer to traverse list
        Node* prev = NULL;      // Pointer to store previous node
        
        // Case 1: If head node itself has the key
        if (head->data == key) {
            
            // If only one node in circular list
            if (head->next == head) {
                delete head;     // Delete the only node
                return NULL;     // List becomes empty
            }
            
            // Find last node to update its next pointer
            Node* last = head;
            while (last->next != head) {
                last = last->next;   // Move to last node
            }
            
            last->next = head->next; // Make last node point to second node
            Node* temp = head;       // Store old head
            head = head->next;       // Move head to next node
            delete temp;             // Delete old head
            
            return head;             // Return new head
        }
        
        // Case 2: Deleting node other than head
        prev = head;
        curr = head->next;
        
        // Traverse until we either find key or come back to head
        while (curr != head) {
            
            if (curr->data == key) {
                prev->next = curr->next; // Bypass the node
                delete curr;             // Delete node
                return head;             // Return unchanged head
            }
            
            prev = curr;         // Move prev forward
            curr = curr->next;   // Move curr forward
        }
        
        // If key not found, return original head
        return head;
    }
};
