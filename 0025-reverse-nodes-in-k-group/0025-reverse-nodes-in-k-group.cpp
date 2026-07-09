class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Check if at least k nodes exist
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count < k) return head;  // not enough nodes

        // Reverse first k nodes
        ListNode* prev = NULL;
        curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // head is now last node of reversed group
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
