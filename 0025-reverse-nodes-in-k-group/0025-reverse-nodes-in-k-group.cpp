class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;

        for(int i = 0; i < k; i++) {
            if(node == NULL) return head;
            node = node->next;
        }

        ListNode* back = NULL;
        ListNode* cur = head;

        for(int i = 0; i < k; i++) {
            ListNode* nxt = cur->next;
            cur->next = back;
            back = cur;
            cur = nxt;
        }

        head->next = reverseKGroup(cur, k);

        return back;
    }
};