
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。
你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

示例 2:
输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL

说明:
应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

--------------------------------
方法：
1.分别凑建奇偶链
2.把奇偶链表合并，偶数链表末尾致为NULL

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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next== NULL || head->next->next== NULL)return head;    
        ListNode *p;
        ListNode *first;
        ListNode *p_head;
        p = head->next;
        p_head = head->next;
        first = head;
        int i = 1;
        
        while(first->next != NULL && p->next != NULL)
        //在编译器中如果while的判断条件是 || 的话，会报错！！！因为并不知道你的next
        {
           
	     if(i % 2 == 1)
         {
            first->next = p->next;
            first = first->next;
         }
         else
         {
            p->next = first->next;
            p = p->next;
         }
         i++;
       }   
        p->next = NULL;
        first->next = p_head;    
        return head;
    }
};