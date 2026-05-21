class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int >m1;
        unordered_map<int, int >m2;
        
        //for array 1
        for(int i=0; i<arr1.size(); i++){
            int a=arr1[i];
            while(a){
                int bit=a%10;
                m1[a]=1;
                a=a/10;
            }
        }
        //for array 2
        for(int i=0; i<arr2.size(); i++){
            int a=arr2[i];
            while(a){
                int bit=a%10;
                m2[a]=1;
                a=a/10;
            }
        }
        
        int maxipre=0;
        for (const auto& [key, value] : m2) {
        
        if(m1.count(key)){
          maxipre=max(maxipre, key);
        }
        
    }
    int a=maxipre;
    int size=0;
    while(a){
    size++;
    a=a/10;
    }

    return size;

    }
};