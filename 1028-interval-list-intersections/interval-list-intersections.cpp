class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

    firstList.reserve(firstList.size() + secondList.size());
    firstList.insert(firstList.end(), secondList.begin(), secondList.end());

    vector<vector<int>>intervals=firstList;
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

     
     vector<vector<int>>isec;

       for(int i=0; i<intervals.size()-1; i++){
        while(i<intervals.size()-1 && intervals[i][0]<=intervals[i+1][0] && intervals[i+1][0]<=intervals[i][1]){
            if(intervals[i][0]<=intervals[i+1][1] && intervals[i+1][1]<=intervals[i][1]){
                isec.push_back({intervals[i+1][0], intervals[i+1][1]});
                intervals[i+1]={intervals[i][0], intervals[i][1]};
            }
            else{
               isec.push_back({intervals[i+1][0], intervals[i][1]});
               intervals[i+1]={intervals[i][0], intervals[i+1][1]};
               
               }

            i++;
        }
       }

       return isec;
  }
};