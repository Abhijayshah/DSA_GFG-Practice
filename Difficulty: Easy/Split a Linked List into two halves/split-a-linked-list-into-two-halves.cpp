class Solution {
public:
    pair<Node*, Node*> splitList(Node* head) {

        // Edge case (though constraints say >= 2 nodes)
        if (head == NULL || head->next == head) {
            return {head, NULL};
        }

        Node* slow = head;      // Slow pointer
        Node* fast = head;      // Fast pointer

        // Move fast by 2 and slow by 1
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // If even number of nodes, move fast one more step
        if (fast->next->next == head) {
            fast = fast->next;
        }

        // head1 will be the first half
        Node* head1 = head;

        // head2 will be the second half
        Node* head2 = slow->next;

        // Make first half circular
        slow->next = head1;

        // Make second half circular
        fast->next = head2;

        return {head1, head2};
    }
};
