class Solution {
    
private:
    vector<int> getnextsmall(vector<int> heights,int size){
        stack<int> stack;
        vector<int> ans(size);
        
        stack.push(-1);
        
        for(int i = size-1 ; i>= 0 ;i--){
            int temp = heights[i];
            
            while(stack.top() != -1 && heights[stack.top()] >= temp ){
                cout << stack.top() << " ";
                cout << heights[stack.top()];
                stack.pop();
            }


            ans[i] = stack.top();
            stack.push(i);
            
        }
        return ans;
        
        
    }
    vector<int> getprevsmall(vector<int> heights,int size){
        stack<int> stack;
        vector<int> ans(size);

        
        stack.push(-1);
        
        for(int i = 0 ; i < size ;i++){
            int temp = heights[i];
            while(stack.top() != -1 &&   heights[stack.top()] >= temp ){
                stack.pop();
            }

            ans[i] = stack.top();
            stack.push(i);
            
        }
        return ans;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();

        if(size == 1 && heights[0] == 0 ){
            return heights[0];

        }
        
        vector<int> nextsmall(size);
        nextsmall = getnextsmall(heights,size);
        
        vector<int> prevsmall(size);
        prevsmall = getprevsmall(heights,size);
        
        int area = INT_MIN;
        
        for(int i = 0 ; i< size ; i++){

            int h = heights[i];
            if(nextsmall[i] == -1){
                nextsmall[i] = size;
            }
            int b = nextsmall[i] - prevsmall[i] - 1;

            int newarea = h*b;

            area = max(area,newarea);
            
        }
        
        return area;
        
    }
};