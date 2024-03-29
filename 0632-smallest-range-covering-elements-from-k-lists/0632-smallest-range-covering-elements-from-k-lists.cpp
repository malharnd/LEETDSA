
class Node{
public:
    int data;
    int row;
    int col;

Node(int data, int row, int col){
    this -> data = data;
    this -> row = row;
    this -> col = col;
}

};


class compare{
public:
    bool operator()(Node* a, Node* b){
        return a -> data > b -> data;
    }

};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
    int mini = INT_MAX;
    int maxi  = INT_MIN;
    priority_queue<Node*, vector<Node*> , compare> pq;

    int size = nums.size();
    
    for (int i= 0; i <size ; i++){
        int element = nums[i][0];
        maxi  = max(element , maxi);
        pq.push(new Node(element , i , 0));
    }

    mini = pq.top() -> data;

    int start = mini;
    int end = maxi;

    while(!pq.empty()){
        Node* temp = pq.top();
        pq.pop();

        mini = temp -> data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }
        int row = temp->row, col = temp->col;
        if(col + 1 < nums[row].size()){
            maxi = max(maxi , nums[row][col +1]);
            pq.push(new Node(nums[row][col +1], row , col + 1 ));
        }

        else{
            break;
        }

    }

    return {start, end};
    }
};