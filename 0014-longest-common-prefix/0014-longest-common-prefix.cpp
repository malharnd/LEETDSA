class Node{
public:
    char data;
    Node* childrens[26];
    int childcount;
    bool isTerminal;
Node(char data){
    this -> data = data;
    for(int i = 0; i<26;i++){
        childrens[i] = NULL;
    }
    this -> childcount = 0;
    this -> isTerminal = false;
}
};

class Trie{
public:
    Node* root;
Trie(){
    root = new Node('\0');
}


void insertUtil(Node* root, string word){
    //base 
    if(word.length() == 0){
        root -> isTerminal = true;
        return;
    }

    int index = word[0] - 'a';
    Node* child;

    if(root -> childrens[index] != NULL){
        child = root -> childrens[index];
    }

    else{
        root -> childcount ++;
        child = new Node(word[0]);
        root -> childrens[index] =child;
    }
    insertUtil(child,word.substr(1));

}

void insert(string word){
    insertUtil(root,word);
}

void searchUtil(string word, string &ans){
    //base 
    for(int i = 0 ; i<word.length() ;i++){
        char ch = word[i];
        if(root -> childcount == 1){
            ans.push_back(ch);
            int index = ch - 'a';
            root = root -> childrens[index];
        }

        else{
            break;
        }

        if(root -> isTerminal == true){
            break;
        }
    }
}


};



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie() ;
        for(int i = 0 ; i<strs.size() ;i++){
            if(strs[i].length() == 0){
                return "";
            }
            t -> insert(strs[i]);
        }
        string word = strs[0];
        string ans = "";
        t -> searchUtil(word, ans);
        return ans;
    }
};