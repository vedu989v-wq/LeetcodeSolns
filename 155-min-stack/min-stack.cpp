class MinStack {
public:
//declaration
    vector<int>arr;
    stack<int>st;
    int size;
    int peak;
//initialisation 
    MinStack() {
        size=arr.size();
        peak=-1;
    }
//push operation, along with taking advantage of top to find the minimum current present element, according to the standard algorithm of Get Minimum at Pop Problem  
    void push(int value) {
        arr.push_back(value);
        peak++;
        size++;

        if(peak==0)
        st.push(arr[peak]);
        else
        st.push(min(arr[peak], st.top()));
    }
//similarly written pop function 
    void pop() {
        if(peak==-1){
            return;
        }
        else{
        arr.pop_back();
        peak--;
        size--;
        st.pop();
        }
    }
//top function  
    int top() {
        if(peak==-1){
            return -1;
        }
        else{
            return arr[peak];
        }
    }
//get Min: sheerly implemented in O(1) standard time complexity   
    int getMin() {
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */