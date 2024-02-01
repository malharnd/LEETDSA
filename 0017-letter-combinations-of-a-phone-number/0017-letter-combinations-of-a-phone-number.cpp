class Solution {
private:
void tel(int index, string output, vector<string> &ans, string mapping[],string digits){

    //base 
    if(index >= digits.length() ){
        ans.push_back(output);
        return;
    }

    int num = digits[index] - '0';
    string alph = mapping[num];

    for(int i = 0 ; i<alph.length(); i++){
        output.push_back(alph[i]);
        tel(index+1,output, ans, mapping,digits);
        output.pop_back();
    }




}
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        string output;
        int index = 0;

        string mapping[10] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        tel(index,output,ans,mapping,digits); 

        return ans;
         

        
    }
};