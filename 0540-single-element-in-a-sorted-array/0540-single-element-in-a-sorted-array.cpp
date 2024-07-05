class Solution {
public:
    int singleNonDuplicate(vector<int>arr) {
        int ans = 0;
        int start = 0;
        int end = arr.size()-1;

        if(arr.size()==1){
            return arr[0];
        }
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            // if single element if the first or last element
            if(mid == 0){
                if(arr[mid] != arr[mid+1]){
                    return arr[mid];
                }
                else{
                    start = mid +1;
                    continue;
                }
            }
            if(mid==arr.size()-1){
                if(arr[mid] != arr[mid-1]){
                    return arr[mid];
                }
                else{
                    end = mid - 1;
                    continue;
                }

            }
            
            // if it is the single element
            if(mid!=arr.size()-1 && mid != 0 && arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1] ){
                return arr[mid];
            }
            
            // if we are on the left of single element
            // if mid is even
            else if(mid%2 == 0){
                //if its left
                if(arr[mid+1] == arr[mid]){
                    start = mid + 1;
                }
                else{
                    end = mid -1;
                }
            }
            
            else{
                if(arr[mid-1] == arr[mid]){
                    start = mid + 1;
                }
                else{
                    end = mid -1;
                }
            }
        }
        return ans;
    }
};