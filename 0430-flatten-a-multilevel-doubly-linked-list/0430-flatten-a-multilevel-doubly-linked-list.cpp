class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* next = curr->next;
                Node* child = flatten(curr->child);

                curr->next = child;
                child->prev = curr;
                curr->child = NULL;

                Node* temp = child;

                while (temp->next != NULL) {
                    temp = temp->next;
                }

                temp->next = next;

                if (next != NULL)
                    next->prev = temp;
            }

            curr = curr->next;
        }

        return head;
    }
};