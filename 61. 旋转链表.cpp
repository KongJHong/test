给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

------------------------------------
思路：利用快慢指针的思想，找到其中的差值距离就好了

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0)return head;
        if(head == NULL)return NULL;
        if(head != NULL && head->next == NULL)return head;
        
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *tmpHead = head;
        int count = 1;
        while(tmpHead != NULL && tmpHead->next != NULL){
            count++;
            tmpHead = tmpHead->next;
        }
        
        
        k = k % count;
        
        while(k-->0)
            fast = fast->next;
          
        while(fast != NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        fast = slow->next;
        slow->next = NULL;
        return fast;
        
        
    }
};
