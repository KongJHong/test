在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:
输入: 4->2->1->3
输出: 1->2->3->4


示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

---------------------------------
思路：就是对一个链表进行排序，但是无论怎么做，链表的结构都是O(n²)

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        qSortList(head,NULL);
        
        return head;
    }
    
    void qSortList(ListNode *head,ListNode *tail){
        if(head != tail && head->next != tail)
        {
            ListNode *mid = partitionList(head,tail);
            qSortList(head,mid);
            qSortList(mid->next,tail);
        }
    }
    
    ListNode* partitionList(ListNode *low,ListNode *high){
        
        int key = low->val;
        ListNode *loc = low;
        for(ListNode *p = low->next; p != high;p = p->next){
            if(p->val < key)
            {
                loc = loc->next;//这里，单指针进行快速排序真的很漂亮
                swap(p->val,loc->val);
            }
        }
        swap(low->val,loc->val);
        return loc;
    }
    
};


//空间复杂度为n，但是时间36ms
class Solution {
public:
    ListNode* sortList(ListNode* head) {
       vector<int> ans;
       ListNode* p = head;
       ListNode* q = head;
       while(p){
           ans.push_back(p->val);
           p = p->next;
       }
       sort(ans.begin(),ans.end());
       vector<int>::iterator it = ans.begin();
       while(it != ans.end() && q){
           q->val = (*it);
           it++;
           q = q->next;
       }
       return head;
    }
};
