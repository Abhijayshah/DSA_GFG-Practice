class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;

        while (curr != NULL && curr->next != NULL) {
            if (curr->data == curr->next->data) {
                // Duplicate found, remove next node
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                // Move to next distinct element
                curr = curr->next;
            }
        }
        return head;
    }
};
