
class Node{
public:
    char data;
    Node* children[26];
    bool isTerminal;

Node(char data){
    this -> data =  data;
    for (int i=0; i<26; i++){
        children[i] = NULL;
    }
    this -> isTerminal = false;
}


};



class Trie {
public:
Node* root;

    Trie() {
        root = new Node('\0');
    }
    void insertUtil(Node* root, string word){
        // base case
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        int index = word[0] -'a';
        Node* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            child = new Node(word[0]);
            root -> children[index] = child;
        }
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        return insertUtil(root, word);
        
    }
    
    bool searchUtil(Node* root, string word){
        // base case
        if(word.length() == 0){
            return root -> isTerminal;
        }

        int index = word[0] -'a';
        Node* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root,word);
    }
    
    bool startswithUtil(Node* root, string word){
        // base case
        if(word.length() == 0){
            return true;
        }

        int index = word[0] -'a';
        Node* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return false;
        }
        return startswithUtil(child,word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startswithUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */