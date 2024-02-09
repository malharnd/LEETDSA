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

ListNode* reverse(ListNode* &head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    ListNode* temphead= reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return temphead;
}

ListNode* getmid(ListNode* &head ){
    //create two pointer

    if(head -> next == NULL || head == NULL){
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head -> next;

    while(fast != NULL && fast ->next != NULL){
        slow = slow-> next;
        fast  = fast -> next -> next;
    }
    
    return slow;

}

public:
    bool isPalindrome(ListNode* head) {

        if(head -> next == NULL){
            return true;
        }

        //get mid
        ListNode* mid = getmid (head);

        //reverse list
        ListNode* rev = mid ->next;
        rev = reverse(rev);
        

        // join the mid to reverse list
        mid -> next = rev;
        
        //check palindrome

        ListNode* first = head;
        ListNode* second = mid -> next;

        // while loop to check for plaindrome
        while(first != mid-> next && second!= NULL){
            if(first -> val == second -> val){
                first = first -> next;
                second = second -> next;
            }

            else{
                return false;
            }
        }

        return true;



    }
};