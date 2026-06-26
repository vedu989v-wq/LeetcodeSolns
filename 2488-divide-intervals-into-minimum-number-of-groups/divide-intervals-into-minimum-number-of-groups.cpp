class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
       vector<int>first;
       vector<int>second;
       for(int i=0; i<intervals.size(); i++){
        first.push_back(intervals[i][0]);
        second.push_back(intervals[i][1]);
       }
       sort(first.begin(), first.end());
       sort(second.begin(), second.end());

       int ans=0;
       int active=0;

       int i=0, j=0;
       while(i<first.size()){
        if(first[i]<=second[j]){
            active++;
            ans=max(ans, active);
            i++;
        }
        else{
            active--;
            j++;
        }
       }

       return ans;
    }
};