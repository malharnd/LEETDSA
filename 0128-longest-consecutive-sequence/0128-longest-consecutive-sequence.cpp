class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(), nums.end()); better not optimal O(NlogN)
        int maxi= 0;
        int curr = 0;
        unordered_set<int> st;

        for(int i= 0 ; i< nums.size() ;i++){
            st.insert(nums[i]);
        }

        for(auto it:st){

            if(st.find(it-1) == st.end()){
                int count = 1;
                int x= it;
                while(st.find(x+1) != st.end()){
                    x= x+1;
                    count++;
                }
                maxi = max(maxi,count);
            }
        }
        return maxi;        
    }
};