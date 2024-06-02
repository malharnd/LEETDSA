class Solution {
public:
    bool check(vector<int>& arr) {
        int counter = 0;
        int size = arr.size();
        for(int i = 0; i<size ; i++){
            if(arr[(i+1)%size] > arr[i%size]){
                continue;
            }
            
            else if(arr[(i+1)%size] < arr[i%size]){
                counter ++;
            }
        }
        
        if(counter == 0 || counter == 1){
            return true;
        }
        
        else{
            return false;
        }
    }
};