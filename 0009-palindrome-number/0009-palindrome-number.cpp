class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
        long long num = x;
        long long rev = 0;
        
        while(num != 0){
            int temp = num % 10;
            rev = rev * 10 + temp;
            
            num = num/10;
        }
        
        if(x == rev){
            return true;
        }
        else{
            return false;
        }
        
    }
};