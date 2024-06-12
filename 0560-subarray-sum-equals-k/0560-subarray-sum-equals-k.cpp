class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        
        unordered_map<int,int> mp;
        int max_len = 0;
        int sum = 0;
        int N = A.size();
        int count = 0;
        mp[0] = 1;
        
        
        for(int i=0; i<N; i++){
            sum += A[i];

            int rem = sum - k;
            
            if(mp.find(rem) != mp.end()){
                count  = count + mp[rem];
                
            }
            mp[sum]++;
            

        }
        
        return count;
        
    }
};