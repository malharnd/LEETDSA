class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count = 0;
        int element = -1;
        
        for(int i = 0; i<arr.size(); i++){
            if(count == 0){
                element = arr[i];
                count ++;
            }
            
            else if(arr[i]== element){
                count ++;
            }
            
            else{
                count --;
            }
        }
        return element;
    }
};