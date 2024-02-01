class Solution {
private:
void per(vector<int> nums, int index,vector<vector<int>> &ans ){
    //base
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); i++ ){
        swap(nums[index],nums[i]);
        per(nums,index+1,ans);
        swap(nums[index],nums[i]);

    }

}
public:
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0 ;

    per(nums,index,ans);
    return ans;



        
    }
};