class Solution {
  public:
    void removeLoop(Node* head) {
        
        // Edge case: empty list or single node
        if (head == NULL || head->next == NULL)
            return;

        Node* slow = head;
        Node* fast = head;

        // STEP 1: Detect loop using Floyd's algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;    // move 2 steps

            // Loop detected
            if (slow == fast)
                break;
        }

        // If no loop is present, return
        if (slow != fast)
            return;

        // STEP 2: Find starting point of loop
        slow = head;

        // Special case: loop starts at head
        if (slow == fast) {
            // Move fast to the last node of loop
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            // Move both one step until they meet at loop start
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // STEP 3: Remove loop
        fast->next = NULL;
    }
};
