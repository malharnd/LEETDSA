class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxnum  = 0;
        int totalmax = 0;
        int n = nums.size();

        
        for(int i = 0; i< n; i++){
            if(nums[i] == 1){
                maxnum++;
                if(i == n-1){
                if(totalmax < maxnum){
                    totalmax = maxnum;
                }
                }
            }
            else{
                if(totalmax < maxnum){
                    totalmax = maxnum;
                }
                maxnum = 0;
            }
        }
        
        return totalmax;
    }
};