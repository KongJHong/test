反转一个单链表。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

-----------------------------------------------------
我------三指针：一探路，两交换

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL )return 0;
        if(head->next == NULL)return head;
        ListNode* curNode = head;
        ListNode* nexNode = head->next;
        ListNode* tmpNode = nexNode->next;
        if(tmpNode == NULL)
        {
            curNode->next = NULL;
            nexNode->next = curNode;
            return nexNode;
        }
        curNode->next = NULL;
        while(nexNode != NULL){
            nexNode->next = curNode;
            
            
            curNode = nexNode;
            nexNode = tmpNode;
            if(tmpNode != NULL && tmpNode->next != NULL) tmpNode = tmpNode->next; 
            else   tmpNode = NULL;
        }
        
     
        return curNode;
        
    }
};
