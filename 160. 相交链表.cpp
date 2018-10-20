编写一个程序，找到两个单链表相交的起始节点。

例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
在节点 c1 开始相交。

注意：
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
-------------------------------------------------
思路：如果有公共链表，则同样在链表等长的条件下，一定是同时找到公共区域，有点像，马拉车
    现在问题可以转移为怎么把链表弄成等长，先做一次计数，再按数目差值做等长...

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)return NULL;
        
        ListNode *tmpA = headA;
        ListNode *tmpB = headB;
        int Acount = 0;
        int Bcount = 0;
        
        while(tmpA != NULL)
        {
            Acount++;
            tmpA = tmpA->next;
        }
        
        while(tmpB != NULL)
        {
            Bcount++;
            tmpB = tmpB->next;
        }
            
        tmpA = headA;
        tmpB = headB;
        
        while(Acount>Bcount)
        {
            tmpA = tmpA->next;
            Acount--;
        }
        
        while(Bcount>Acount)
        {
            tmpB = tmpB->next;
            Bcount--;
        }
            
        while(tmpA != NULL)
        {
            if(tmpA == tmpB)return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        
        return NULL;
    }
};



