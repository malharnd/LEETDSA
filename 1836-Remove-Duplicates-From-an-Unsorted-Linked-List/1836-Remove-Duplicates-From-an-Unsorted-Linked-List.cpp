#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    // Write your code here
    unordered_map<int, bool> visited;

    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = head;




    while(curr != NULL){
        if(visited[curr->data] == true){
            prev -> next = curr ->next;
            curr = curr -> next;
        }

        else{
            visited[curr->data] = true;
            prev = curr;
            curr = curr -> next;
        }
    }
    return head;
    

}