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
    
private:
    void insertattail(ListNode* &head, ListNode* &tail, int digit){
        //Create new node if no node is present in LL
        ListNode* temp = new ListNode(digit);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }

        // add node to the tail
        else{
            tail -> next = temp;
            tail = temp;
            tail -> next = NULL;
            return;
        }
        
        
    }
    ListNode* add(ListNode* &l1, ListNode* &l2){
        //adding two nuumbers
        int carry = 0;
        ListNode* first =l1;
        ListNode* second =l2;
        
        ListNode* anshead = NULL;
        ListNode* anstail = NULL;
        
        
        
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first !=NULL){
                val1 = first -> val;
                
            }
            int val2 = 0;
            if(second !=NULL){
                val2 = second -> val;
            }
            
            int sum = val1 + val2 + carry;
            
            
            int digit = sum % 10;
            
            insertattail(anshead, anstail,digit);
            
            carry = sum /10;

            
            if(first != NULL){
                first = first -> next;
            }
            if(second != NULL){
                second = second -> next;


            }
        
        }
        
        return anshead;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         
        //add LLs
        ListNode* ans = add(l1,l2);
        
        return ans;
        
    }
};