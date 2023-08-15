/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0); // Dummy node for nodes less than x
        ListNode greaterDummy(0); // Dummy node for nodes greater than or equal to x
        ListNode* lessCurrent = &lessDummy;
        ListNode* greaterCurrent = &greaterDummy;

        while (head) {
            if (head->val < x) {
                lessCurrent = lessCurrent->next = head;
            } else {
                greaterCurrent = greaterCurrent->next = head;
            }
            head = head->next;
        }

        // Connect the two partitions
        greaterCurrent->next = nullptr; // Terminate the end of the greater partition
        lessCurrent->next = greaterDummy.next;

        return lessDummy.next;
    }
};
