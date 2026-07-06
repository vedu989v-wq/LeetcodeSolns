class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        //if size of interval array is one, return as it is
        if(intervals.size()==1)
        return 1;

        //final answer storing 2d array
        vector<vector<int>>ans;
        
        //custom comparator
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
          if(a[0]==b[0])
          return a[1]>b[1];

          return a[0]<b[0];
        });
        
        //chota aage hi ayenga, tabhi to saaanp ki trah dasenga
        for(int i=0; i<intervals.size()-1; i++){
          while(i<intervals.size()-1 && (intervals[i][0]<=intervals[i+1][0] && intervals[i+1][0]<=intervals[i][1]) && (intervals[i][0]<=intervals[i+1][1] && intervals[i+1][1]<=intervals[i][1])){
            intervals[i+1]={intervals[i][0], intervals[i][1]};

            i++;
          }

          ans.push_back(intervals[i]);

          if(i==intervals.size()-2){
            ans.push_back(intervals[i+1]);
          }
        }
        
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[i].size(); j++){
                cout<<ans[i][j]<<",";
            }
            cout<<" ";
        }
        return ans.size();

    }
};