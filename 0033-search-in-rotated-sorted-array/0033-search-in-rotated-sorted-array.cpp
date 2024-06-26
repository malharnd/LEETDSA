class Solution {
public:
    int search(vector<int>& arr, int k) {
        // Find pivot
        int start = 0 ;
        int end = arr.size() - 1;
        int pivot = -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] ==k){
                return mid;
            }
            else if(arr[start] <= arr[mid]){
                if(arr[start]<=k && k<=arr[mid]){
                    end = mid- 1;
                }
                else{
                    start = mid + 1;
                }
            }
            
            else{
                if(arr[mid]<=k && k<=arr[end]){
                    start = mid+1;
                }
                else{
                    end = mid -1;
                }
                
            }
    }
        return -1;
        
            
    }
};