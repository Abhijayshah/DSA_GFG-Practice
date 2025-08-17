/*
class Node {
public:
    int data ;
    Node *next ;
    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
*/

class Solution {
  public:
    // Approach 1: Iterative (Most efficient and recommended)
    Node* reverseList(struct Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;    // Store next node
            curr->next = prev;    // Reverse the link
            prev = curr;          // Move prev to current
            curr = next;          // Move to next node
        }
        
        return prev; // prev is now the new head
    }
};

// Alternative Approach 2: Recursive
class Solution_Recursive {
  public:
    Node* reverseList(struct Node* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Recursively reverse the rest of the list
        Node* reversedHead = reverseList(head->next);
        
        // Reverse the current connection
        head->next->next = head;
        head->next = nullptr;
        
        return reversedHead;
    }
};

// Alternative Approach 3: Using Stack (Less efficient but intuitive)
class Solution_Stack {
  public:
    Node* reverseList(struct Node* head) {
        if (head == nullptr) return head;
        
        stack<Node*> stk;
        Node* curr = head;
        
        // Push all nodes to stack
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->next;
        }
        
        // Pop from stack and rebuild connections
        Node* newHead = stk.top();
        stk.pop();
        curr = newHead;
        
        while (!stk.empty()) {
            curr->next = stk.top();
            stk.pop();
            curr = curr->next;
        }
        
        curr->next = nullptr; // Last node points to null
        return newHead;
    }
};

// Alternative Approach 4: Two-pass with array (for educational purposes)
class Solution_Array {
  public:
    Node* reverseList(struct Node* head) {
        if (head == nullptr) return head;
        
        vector<int> values;
        Node* curr = head;
        
        // First pass: collect all values
        while (curr != nullptr) {
            values.push_back(curr->data);
            curr = curr->next;
        }
        
        // Second pass: assign values in reverse order
        curr = head;
        int i = values.size() - 1;
        while (curr != nullptr) {
            curr->data = values[i--];
            curr = curr->next;
        }
        
        return head;
    }
};