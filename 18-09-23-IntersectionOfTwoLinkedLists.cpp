/*
https://leetcode.com/problems/intersection-of-two-linked-lists/description/
Time O(n + m) onde n == size(headA), m == size(headB);
Space O(1);
*/

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getSize(headA);
        int lenB = getSize(headB);

        if (lenA > lenB) {
            while (lenA > lenB) {
                headA = headA->next;
                lenA--;
            }
        } else {
            while (lenB > lenA) {
                headB = headB->next;
                lenB--;
            }
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }

    int getSize(ListNode *head) {
        int len = 1;

        while (head != nullptr) {
            head = head->next;
            len++;
        }

        return len;
    }
};