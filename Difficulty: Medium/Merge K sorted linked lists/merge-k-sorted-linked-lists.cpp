class Solution {
public:

    // Custom comparator for min heap
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;      // Min heap based on node data
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {

        // Min heap to store current nodes of each list
        priority_queue<Node*, vector<Node*>, compare> pq;

        // Step 1: Push head of each non-empty list into heap
        for (Node* head : arr) {
            if (head != NULL) {
                pq.push(head);
            }
        }

        // Dummy node to simplify list creation
        Node* dummy = new Node(-1);
        Node* tail = dummy;

        // Step 2: Process heap
        while (!pq.empty()) {

            Node* smallest = pq.top();     // Get smallest node
            pq.pop();

            tail->next = smallest;         // Attach to merged list
            tail = tail->next;

            if (smallest->next != NULL) {  // Push next node of same list
                pq.push(smallest->next);
            }
        }

        return dummy->next;                // Return head of merged list
    }
};
