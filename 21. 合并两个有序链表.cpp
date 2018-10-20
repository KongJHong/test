将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

-----------------------------
思路：没什么好说的，就对比，构成链

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3;
        if(l1 == NULL && l2 == NULL)return NULL;
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        if(l1->val > l2->val)
        {
            l3 = l2;
            l2 = l2->next;
        }
        else
        {
            l3 = l1;
            l1 = l1->next;
        }
        
        ListNode* head = l3;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val > l2->val)
            {
                l3->next = l2;
                l2 = l2->next;
            }
            else
            {
                l3->next = l1;
                l1 = l1->next;
            }
            
            l3 = l3->next;
            l3->next = NULL;
        }
        
        if(l1 != NULL)l3->next = l1;
        if(l2 != NULL)l3->next = l2;
        return head;
        
    }
};
