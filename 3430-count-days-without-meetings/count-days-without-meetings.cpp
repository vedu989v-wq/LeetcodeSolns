class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
        return intervals;
        
        vector<vector<int>>ans;
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
        ans.push_back(intervals[i]);

        if(i==intervals.size()-2)
        ans.push_back(intervals[i+1]);
       }
    

       return ans;
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>>meets=merge(meetings);
        for(int i=0; i<meets.size(); i++){
            int na=meets[i][1]-meets[i][0]+1;
            if(days-na<=0)
            return 0;

            days=days-na;
        }

        return days;
    }
};