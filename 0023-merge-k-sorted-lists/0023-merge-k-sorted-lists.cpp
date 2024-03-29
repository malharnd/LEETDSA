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


class Node{
public:
    ListNode* val;
    int row;
    int col;
    
Node(ListNode* val, int row, int col){
    this -> val = val;
    this -> row = row;
    this -> col = col;
}
    
};



class compare{
  public:
    bool operator()(ListNode*a , ListNode*b){
        return a -> val > b-> val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        int num_list = lists.size();
        if(num_list == 0) return NULL;
        
        // Adding first values in the heap
        
        for (int i = 0 ; i< num_list ; i++){
            ListNode* temp=lists[i];
            if(temp != NULL){
            pq.push(temp);
            }
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(pq.size() > 0){
            ListNode* temp = pq.top();
            pq.pop();
            
            
            if(temp -> next != NULL){
                    pq.push(temp->next);
                }
            
            if(head == NULL){
                head = temp;
                tail = temp;
                
            }
            
            else{
                tail -> next = temp;
                tail = temp;
            }
            
        }
        return head;
        
    }
};