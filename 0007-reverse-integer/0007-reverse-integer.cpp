class Solution {
public:
    int reverse(int x) {
        long rev_digit;
        rev_digit = 0;
        while(x!=0){
            int temp = x%10;
            rev_digit = rev_digit * 10 + temp;
            x = x / 10;
        }

        if(rev_digit < INT32_MIN || rev_digit > INT32_MAX ) return 0;

        return rev_digit;
    }
};