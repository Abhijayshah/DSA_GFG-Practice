class Solution {
  public:
    Node *reverse(Node *head) {

        // Edge case: empty list or single node
        if (head == NULL || head->next == NULL)
            return head;

        Node* curr = head;
        Node* newHead = NULL;

        // Traverse the list
        while (curr != NULL) {

            // Swap next and prev pointers
            Node* temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Update new head
            newHead = curr;

            // Move to next node (which is prev now)
            curr = curr->prev;
        }

        return newHead;
    }
};
