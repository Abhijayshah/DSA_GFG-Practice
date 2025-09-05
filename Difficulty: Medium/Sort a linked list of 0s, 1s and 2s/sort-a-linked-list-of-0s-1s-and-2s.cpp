/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) {
            return head;
        }
        
        // Create three separate lists for 0s, 1s, and 2s
        Node* zeroHead = nullptr;
        Node* zeroTail = nullptr;
        Node* oneHead = nullptr;
        Node* oneTail = nullptr;
        Node* twoHead = nullptr;
        Node* twoTail = nullptr;
        
        Node* current = head;
        
        // Traverse the original list and distribute nodes
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = nullptr; // Break the link
            
            if (current->data == 0) {
                if (zeroHead == nullptr) {
                    zeroHead = zeroTail = current;
                } else {
                    zeroTail->next = current;
                    zeroTail = current;
                }
            }
            else if (current->data == 1) {
                if (oneHead == nullptr) {
                    oneHead = oneTail = current;
                } else {
                    oneTail->next = current;
                    oneTail = current;
                }
            }
            else { // current->data == 2
                if (twoHead == nullptr) {
                    twoHead = twoTail = current;
                } else {
                    twoTail->next = current;
                    twoTail = current;
                }
            }
            
            current = nextNode;
        }
        
        // Now connect the three lists
        Node* newHead = nullptr;
        Node* newTail = nullptr;
        
        // Connect 0s list
        if (zeroHead != nullptr) {
            newHead = zeroHead;
            newTail = zeroTail;
        }
        
        // Connect 1s list
        if (oneHead != nullptr) {
            if (newHead == nullptr) {
                newHead = oneHead;
                newTail = oneTail;
            } else {
                newTail->next = oneHead;
                newTail = oneTail;
            }
        }
        
        // Connect 2s list
        if (twoHead != nullptr) {
            if (newHead == nullptr) {
                newHead = twoHead;
            } else {
                newTail->next = twoHead;
            }
        }
        
        return newHead;
    }
};

// Alternative Approach: Counting Method (simpler but requires two passes)
class SolutionAlternative {
public:
    Node* segregate(Node* head) {
        if (!head) return head;
        
        // Count occurrences of 0s, 1s, and 2s
        int count[3] = {0, 0, 0};
        Node* current = head;
        
        while (current != nullptr) {
            count[current->data]++;
            current = current->next;
        }
        
        // Overwrite the linked list with sorted values
        current = head;
        int i = 0;
        
        while (current != nullptr) {
            if (count[i] == 0) {
                i++;
            } else {
                current->data = i;
                count[i]--;
                current = current->next;
            }
        }
        
        return head;
    }
};

// Helper function to create a linked list from array (for testing)
Node* createLinkedList(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to print linked list (for testing)
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " → ";
        }
        head = head->next;
    }
    cout << endl;
}

// Example usage and test cases
void testSolution() {
    Solution solution;
    
    // Test Case 1: 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
    vector<int> test1 = {1, 2, 2, 1, 2, 0, 2, 2};
    Node* head1 = createLinkedList(test1);
    cout << "Input: ";
    printLinkedList(head1);
    
    head1 = solution.segregate(head1);
    cout << "Output: ";
    printLinkedList(head1);
    cout << endl;
    
    // Test Case 2: 2 → 2 → 0 → 1
    vector<int> test2 = {2, 2, 0, 1};
    Node* head2 = createLinkedList(test2);
    cout << "Input: ";
    printLinkedList(head2);
    
    head2 = solution.segregate(head2);
    cout << "Output: ";
    printLinkedList(head2);
}