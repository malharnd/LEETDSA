class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        for(int i =0 ; i<s.length();i++){
            char temp = s[i];
            if(temp == '(' || temp == '{' || temp == '['){
                st.push(temp);
            }
            else{
                if(!st.empty()){
                char top = st.top();
                if(top == '(' && s[i]== ')'){
                    st.pop();
                }
                else if(top == '{' && s[i]== '}'){
                    st.pop();
                }
                else if(top == '[' && s[i]== ']'){
                    st.pop();
                
                }
                else{
                    return false;
                }


                }
                else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
        
    }
};