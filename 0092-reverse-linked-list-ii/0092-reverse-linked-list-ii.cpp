class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL){
            return NULL;
        }

        ListNode* ans = new ListNode(0);
        ans->next = head;

        ListNode* prev = ans;

        for(int i = 1; i < left; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* before = prev;

        for(int i = left; i <= right; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        before->next->next = curr;
        before->next = prev;

        return ans->next;
    }
};