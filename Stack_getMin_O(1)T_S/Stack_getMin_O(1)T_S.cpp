class SpecialStack {
    public:

    stack<int> s;
    int mini;
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
        if(data < mini){
            int val = 2*data - mini; // to get prev mini with same space
            s.push(val);
            mini = data;
        } else {
            s.push(data);
        }
        }
    }

    void pop() {
        // Implement the pop() function.


        if(s.empty()){
            return;
        }
        int curr = s.top();
        s.pop();

        if(curr > mini){
            return ;
        }
        else{
            int val = 2*mini - curr;
            mini = val;
            return ;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }

        int curr = s.top();

        if(curr<mini){
            return  mini;
        }
        else{
            return curr;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()){
            return -1;
        }

        return mini;

    }  
};

class SpecialStack {
    public:


    int mini;
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
        if(data < mini){
            int val = 2*data - mini; // to get prev mini with same space
            s.push(val);
            mini = data;
        } else {
            s.push(data);
        }
        }
    }

    void pop() {
        // Implement the pop() function.


        if(s.empty()){
            return;
        }
        int curr = s.top();
        s.pop();

        if(curr > mini){
            return ;
        }
        else{
            int val = 2*mini - curr;
            mini = val;
            return ;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }

        int curr = s.top();

        if(curr<mini){
            return  mini;
        }
        else{
            return curr;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()){
            return -1;
        }

        return mini;

    }  
};