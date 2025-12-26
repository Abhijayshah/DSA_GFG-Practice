class Solution {
  public:
    Node* divide(Node* head) {

        // Edge case: empty list or single node
        if (head == NULL || head->next == NULL)
            return head;

        // Dummy heads for even and odd lists
        Node* evenDummy = new Node(0);
        Node* oddDummy = new Node(0);

        // Tail pointers to build lists
        Node* evenTail = evenDummy;
        Node* oddTail = oddDummy;

        // Traverse original list
        Node* curr = head;

        while (curr != NULL) {

            // If current node is even
            if (curr->data % 2 == 0) {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
            // If current node is odd
            else {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }

            curr = curr->next;
        }

        // Important: terminate odd list
        oddTail->next = NULL;

        // Connect even list to odd list
        evenTail->next = oddDummy->next;

        // Head of modified list is even list head if exists
        Node* newHead = evenDummy->next ? evenDummy->next : oddDummy->next;

        return newHead;
    }
};
