class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> mp;

        for(int i = 0 ; i<arr.size() ; i++){
            int temp = target - arr[i];
            if(mp.find(arr[i]) != mp.end()){
                return{mp[arr[i]], i};
            }
            mp[temp] = i;
        }

        return {};
        
    }
};