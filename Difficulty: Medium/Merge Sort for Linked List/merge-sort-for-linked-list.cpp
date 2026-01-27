class Solution {
public:
    
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        
        Node* result = NULL;
        
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        
        return result;
    }
    
    // Function to find middle of the linked list
    Node* getMid(Node* head) {
        if (!head) return head;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Main merge sort function
    Node* mergeSort(Node* head) {
        // Base case
        if (!head || !head->next)
            return head;
        
        // Find middle
        Node* mid = getMid(head);
        Node* right = mid->next;
        mid->next = NULL;
        
        // Sort both halves
        Node* leftSorted = mergeSort(head);
        Node* rightSorted = mergeSort(right);
        
        // Merge sorted halves
        return merge(leftSorted, rightSorted);
    }
};
