class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int size = prices.size();
        int profit = 0;
        int max_prof = 0;

        for(int i = 0 ; i<size ;i++){
            profit = prices[i]-prices[buy];
            if(profit <= 0){
                profit = 0;
                buy = i;
            }
            else{
                max_prof = max(profit,max_prof);
            }
        }

        return max_prof;
        
    }
};