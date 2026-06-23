class Solution {
public:
    int numberOfPoints(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
        return intervals[0][1]-intervals[0][0]+1;
        
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

       int points=0;
       for(int i=0; i<ans.size(); i++){
          points+=ans[i][1]-ans[i][0]+1;
       }

       return points;
    }
};