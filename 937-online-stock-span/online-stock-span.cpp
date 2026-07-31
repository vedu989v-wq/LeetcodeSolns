class StockSpanner {
public:
    
    vector<int>arr;
    vector<int>span;
    stack<int>st;

    StockSpanner() {
        
    }
    
    int next(int price) {
     
     arr.push_back(price);
     span.push_back(1);
     
     int i=arr.size()-1;
            while(!st.empty() && arr[st.top()]<=arr[i]){
                span[i]=span[i]+span[st.top()];
                st.pop();
            }
            
            st.push(i);
        
        
        return span[i];
      }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */