class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;

        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;

        while(p != NULL || q != NULL || carry != 0) {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;

            int sum = x + y + carry;

            carry = sum / 10;
            int digit = sum % 10;

            curr->next = new ListNode(digit);
            curr = curr->next;

            if(p != NULL) p = p->next;
            if(q != NULL) q = q->next;
        }

        return ans->next;
    }
};