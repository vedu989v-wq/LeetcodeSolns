class Solution {
public:
    //interval problems: standard checklist for edge cases
//     1. Empty input?
// 2. Single element?
// 3. Before all?
// 4. After all?
// 5. Inside existing interval?
// 6. Covers existing interval?
// 7. Covers multiple intervals?
// 8. Touches boundary?
// just like that of linked list
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

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>>ans;
       intervals.push_back(newInterval);
       sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
      ans=merge(intervals);

      return ans;
    }

            
    
};