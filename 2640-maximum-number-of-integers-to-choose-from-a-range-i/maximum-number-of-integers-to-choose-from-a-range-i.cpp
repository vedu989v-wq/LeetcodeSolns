class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        //marking phase/ invalid elements ki aesi ki tesi
        unordered_map<int, int>m;
        for(int i=0; i<banned.size(); i++){
            m[banned[i]]=-1;
        }
        
        //sorted order me elements push back in array
        vector<int>arr;
        for(int i=1; i<=n; i++){
           if(m[i]!=-1){
             arr.push_back(i);
           }
        }

        //simple sa counting logic implement kar sakte hai idhar
        int sum=0;
        int count=0;

        for(int i=0; i<arr.size(); i++){
            if(sum+arr[i]<=maxSum){
                sum+=arr[i];
                count++;
            }
            else
            break;
        }

        
        return count;
    }
};