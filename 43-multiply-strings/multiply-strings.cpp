class Solution {
public:
    string addStrings(string num1, string num2) {
       string bigger, smaller;
       if(num1.size()>num2.size())
        bigger=num1, smaller=num2;
       else
        bigger=num2, smaller=num1;
       int index1= bigger.size()-1, index2=smaller.size()-1;
       string ans;
       int carry=0, sum=0;
       while(index2>=0){
        sum=(bigger[index1]-'0'+smaller[index2]-'0' + carry);       
        carry=sum/10;
        char c='0'+sum%10;
        ans+=c;
        index2--, index1--;}

        while(index1>=0){
            sum=bigger[index1]-'0'+carry;
            carry=sum/10;
            char c='0'+sum%10;
            ans+=c;
            index1--;

   
        }
    if(carry>0){
        ans+=char('0'+carry);
    }
    int start=0, end=ans.size()-1;
    while(start<end){
        swap(ans[start], ans[end]);
        start++;
        end--;
    } 
     
       
      return ans;
    }
     string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
         return "0";  // 🔥 fix 1
        int carry=0, current;
        string ans="0", sequence="";
        for(int i=num2.length()-1; i>=0; i--){
            carry=0;
            sequence="";
            for(int j=num1.length()-1; j>=0; j--){
                current=carry+(num2[i]-'0')*(num1[j]-'0');
                sequence += (current % 10) + '0';
                carry=current/10;
                
            }
            if(carry) 
            sequence += (carry + '0');

            reverse(sequence.begin(), sequence.end());
            //shifting, 
            sequence += string(num2.length()-1-i, '0');
            //adding sequence by sequence
            ans = addStrings(ans, sequence);
        }
     // 🔥 fix 3 (remove leading zeros)
    int i = 0;
    while(i < ans.size()-1 && ans[i] == '0') i++;

    return ans.substr(i);
}

       
    
};