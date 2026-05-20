class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       //module 1:
       
        vector<int>prefix;
        unordered_map<int , int>m1;
        unordered_map<int , int>m2;
        for(int i=0; i<A.size(); i++){
            int com=0;
            m1[A[i]]=1;
            m2[B[i]]=1;
        
        for (const auto& [key, value] : m1) {
        
        if(m2.count(key)){
            com++;
        }
        
    }
    prefix.push_back(com);
}
//    reverse(prefix.begin(), prefix.end());
   return prefix;
   }
};