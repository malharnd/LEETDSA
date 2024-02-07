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


ListNode* rev(ListNode* &head){
    //base
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    ListNode* temphead = rev(head-> next);
    
    head-> next -> next = head;
    head -> next = NULL;
    
    return temphead;
    
    
    
    
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode * ans = rev(head);
        return ans;
        
    }
};