class Solution {
  public:

    // Merge two sorted linked lists using bottom pointer
    Node* merge(Node* a, Node* b) {

        if (!a) return b;
        if (!b) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL; // important
        return result;
    }

    Node* flatten(Node* root) {

        // Base case
        if (root == NULL || root->next == NULL)
            return root;

        // Flatten the right side
        root->next = flatten(root->next);

        // Merge current list with flattened right list
        root = merge(root, root->next);

        return root;
    }
};
