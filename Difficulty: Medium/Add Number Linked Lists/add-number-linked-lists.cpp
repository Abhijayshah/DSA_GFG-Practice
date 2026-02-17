class Solution {
  public:
    
    // Function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = NULL;          // Previous pointer
        Node* curr = head;          // Current pointer
        
        while (curr != NULL) {      // Traverse list
            Node* nextNode = curr->next; // Store next node
            curr->next = prev;           // Reverse current node pointer
            prev = curr;                 // Move prev forward
            curr = nextNode;             // Move curr forward
        }
        
        return prev; // New head after reversal
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        
        // Reverse both lists to add from least significant digit
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        
        Node* result = NULL; // Head of result list
        Node* tail = NULL;   // Tail pointer for result
        int carry = 0;       // Carry for addition
        
        // Add digits until both lists and carry are exhausted
        while (head1 != NULL || head2 != NULL || carry) {
            
            int sum = carry; // Start sum with carry
            
            if (head1 != NULL) {
                sum += head1->data; // Add digit from first list
                head1 = head1->next; // Move pointer
            }
            
            if (head2 != NULL) {
                sum += head2->data; // Add digit from second list
                head2 = head2->next; // Move pointer
            }
            
            carry = sum / 10;       // Update carry
            int digit = sum % 10;   // Extract digit
            
            Node* newNode = new Node(digit); // Create new node
            
            if (result == NULL) {
                result = newNode; // First node becomes head
                tail = newNode;
            } else {
                tail->next = newNode; // Attach to result
                tail = newNode;       // Move tail
            }
        }
        
        // Reverse result to restore forward order
        result = reverseList(result);
        
        // Remove leading zeros if any
        while (result != NULL && result->data == 0 && result->next != NULL) {
            result = result->next;
        }
        
        return result; // Return final summed list
    }
};
