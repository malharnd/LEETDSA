class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size= nums.size();
        int start = 0;
        int mid = 0;
        int end = size -1;
       while(mid<=end){
            if(nums[mid]== 2){
                swap(nums[mid],nums[end]);
                end--;
            }
            else if(nums[mid] == 0){
                swap(nums[mid],nums[start]);
                start++;
                mid++;
            }
            
            else{
                mid++;
            }
            
        }
        
    }
};