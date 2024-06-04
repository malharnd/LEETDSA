class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currelement = INT_MIN;
        int currpointer = 0;

        for(int i =0 ; i<nums.size(); i++){
            if(currelement < nums[i] ){
                currelement = nums[i];
                nums[currpointer] = currelement;
                currpointer++;
            }
            else{
                continue;
            }
        }
        
        for(int j = currpointer ; j < nums.size(); j++){
            nums[j] = -1000;
        }
        return currpointer;

        
    }
};