class Solution {
    
private:
    void sub(vector<int> nums,vector<int> output, vector<vector<int>>& ans, int index){
        //base
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        sub(nums,output,ans,index+1);

        //include
        int element = nums[index];
        output.push_back(element);
        sub(nums,output,ans,index+1);

        
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        sub(nums, output, ans, index);

        return ans;


        
    }
};