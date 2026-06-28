class Solution {
public:

    int countWays(vector<vector<int>>& intervals) {
        int count=0;
        if(intervals.size()==1)
        count++;
        

        long long mod=1e9+7; //modulo
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

        

        for(int i=0; i<intervals.size()-1; i++){
        while(i<intervals.size()-1 && intervals[i][0]<=intervals[i+1][0] && intervals[i+1][0]<=intervals[i][1]){
            if(intervals[i][0]<=intervals[i+1][1] && intervals[i+1][1]<=intervals[i][1]){
                intervals[i+1]={intervals[i][0], intervals[i][1]};
            }
            else
               intervals[i+1]={intervals[i][0], intervals[i+1][1]};

            i++;
        }
        count++;

        if(i==intervals.size()-2)
        count++;
       }
       
       int result=1;
       for(int i=0; i<count; i++){
        result=(result*2)%mod;
       }
       return result;
    }
};