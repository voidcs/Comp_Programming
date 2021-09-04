//https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l2)
            return l1;
        if(!l1)
            return l2;
        ListNode* ans = new ListNode;
        ListNode* t = ans;
        while(l1 && l2){
            if(l1->val < l2->val){
                t->val = l1->val;
                l1 = l1->next;
            }
            else{
                t->val = l2->val;
                l2 = l2->next;
            }
            t->next = new ListNode;
            if(l1 && l2)
                t = t->next;
        }
        if(l1)
            t->next = l1;
        else
            t->next = l2;
        return ans;
    }
};