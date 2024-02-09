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




ListNode* solve(ListNode* first, ListNode* second) {

    if(first->next == NULL){
        first ->next = second;
        return first;
    }

    ListNode* prev = first;
    ListNode* curr = prev->next;

    ListNode* curr2 = second; 
    ListNode* next2 = curr2 -> next; 

    while(curr2 != NULL && curr != NULL ){

        if((prev -> val <= curr2 -> val ) && (curr2 -> val <= curr -> val) ){
            next2 = curr2 -> next;
            prev -> next = curr2;
            curr2 -> next = curr;
            prev = curr2;
            //second list update ptr
            curr2 = next2;

        }

        else{
            prev = curr;
            curr = curr -> next;

            if(curr == NULL){
                prev -> next = curr2;
                return first;
            }
            
        }
    }

    return first;




    

}


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if any one of the list is empty
        if(list1 == NULL ){
            return list2;
        }

        if(list2 == NULL ){
            return list1;
        }

        // Make list with the smaller first value as the first list

        if(list1 -> val <= list2 -> val){
            return solve(list1, list2);
        }

        else{
            return solve(list2, list1);
        }
        
    }
};