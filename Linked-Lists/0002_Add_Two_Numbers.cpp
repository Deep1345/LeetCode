// Problem   : 2. Add Two Numbers
// Difficulty: Medium
// Tags      : Linked List, Math, Recursion
// URL       : https://leetcode.com/problems/add-two-numbers/
// Language  : Cpp
// Date      : 2026-08-14
//

        ListNode dummy(-1);
        ListNode* tail = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
class Solution {
public:
 */
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode() : val(0), next(nullptr) {}
 *     int val;
 *     ListNode *next;
 * Definition for singly-linked list.
 * struct ListNode {
                sum += l2->val;
                l2 = l2->next;
