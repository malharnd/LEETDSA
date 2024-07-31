class Solution {
private:
    int getmaxarr(vector<int>& nums){
        int maxi = INT_MIN;
        for(int i=0; i<nums.size();i++){
            maxi= max(nums[i],maxi);
        }
        return maxi;
    }

    int getsum(vector<int>& nums, double divisor){
        int div_sum = 0;
        for(int i = 0; i<nums.size();i++){
            double temp = nums[i]/divisor;
            div_sum = div_sum + ceil(temp);
        }
        return div_sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int maxi = getmaxarr(nums);
        int start = 1;
        int end = maxi;
        int ans= INT_MAX;

        while(start <= end){
            int mid = start + (end-start)/2;
            int sum_mid = getsum(nums,mid);
            cout<< sum_mid<< endl;

            if(sum_mid <= threshold){
                ans = min(ans,mid);
                end = mid-1;
            }

            else{
                start = mid + 1;
            }
        }
        
        return ans;


        
    }
};