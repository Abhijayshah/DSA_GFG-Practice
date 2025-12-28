class Solution {
public:
    bool isPalindrome(Node *head) {

        vector<int> values;              // Store linked list values

        Node* temp = head;
        while (temp != NULL) {            // Traverse list
            values.push_back(temp->data); // Store data
            temp = temp->next;
        }

        int left = 0;
        int right = values.size() - 1;

        while (left < right) {             // Check palindrome
            if (values[left] != values[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;                       // Palindrome confirmed
    }
};
