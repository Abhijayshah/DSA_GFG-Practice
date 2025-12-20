/*
class Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        // Handle edge case (though constraints guarantee at least 1 node)
        if (head == NULL) return -1;
        
        // Initialize slow and fast pointers
        Node* slow = head;
        Node* fast = head;
        
        // Move fast pointer 2 steps and slow pointer 1 step
        // When fast reaches end, slow will be at middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Return the value at middle node
        return slow->data;
    }
};

/*
Time Complexity: O(n) - where n is the number of nodes
- We traverse the list once with the fast pointer

Space Complexity: O(1) - constant extra space
- Only using two pointers regardless of input size

Example Walkthrough:
1->2->3->4->5
Initially: slow=1, fast=1
Iteration 1: slow=2, fast=3
Iteration 2: slow=3, fast=5
Iteration 3: slow=3, fast=NULL (exit loop)
Return: 3

2->4->6->7->5->1
Initially: slow=2, fast=2
Iteration 1: slow=4, fast=6
Iteration 2: slow=6, fast=5
Iteration 3: slow=7, fast=NULL (exit loop)
Return: 7
*/