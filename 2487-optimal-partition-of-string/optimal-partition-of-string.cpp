class Solution {
public:
    int partitionString(string s) {
        vector<bool>v(26, 0);
        int first=0;
        int second=0;
        
        int count=0;

        while(second<s.size()){

            if(v[s[second]-'a']){
            count++;
            
            //clearing current partition
            while(first<second){
                v[s[first]-'a']=0;
                first++;
            }

        }
        v[s[second]-'a']=1;
        second++;
          
        }

        return count+1;
    }
};