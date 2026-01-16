class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {

        Node* a = head1;
        Node* b = head2;

        int len1 = 0, len2 = 0;

        // Calculate length of first list
        while (a != NULL) {
            len1++;
            a = a->next;
        }

        // Calculate length of second list
        while (b != NULL) {
            len2++;
            b = b->next;
        }

        a = head1;
        b = head2;

        // Move the longer list ahead
        if (len1 > len2) {
            int diff = len1 - len2;
            while (diff--)
                a = a->next;
        } else {
            int diff = len2 - len1;
            while (diff--)
                b = b->next;
        }

        // Move both pointers together
        while (a != NULL && b != NULL) {
            if (a == b)
                return a;
            a = a->next;
            b = b->next;
        }

        return NULL; // guaranteed intersection exists
    }
};
