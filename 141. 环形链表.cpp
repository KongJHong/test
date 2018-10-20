给定一个链表，判断链表中是否有环
------------------------------
思路：其实这是一个快慢指针的问题，如果有环，快的一定能追上慢的

-----------------------
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)return false;
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow || slow == fast->next)return true;
            //slow==fasty->next 是不让它空跑
        }
        
        return false;
        
    }
};


