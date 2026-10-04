class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        Node* oldTemp = head;
        Node* newHead = new Node(head->val);
        Node* newTemp = newHead;

        m[head] = newHead;

        oldTemp = head->next;

        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != NULL){
            if(oldTemp->random != NULL){
                newTemp->random = m[oldTemp->random];
            }

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};