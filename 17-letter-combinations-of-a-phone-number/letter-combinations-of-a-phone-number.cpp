class Solution {
public:

void combinator(vector<vector<char>>&v, int index, string current, vector<string>&v1){
    //base case: picked a character, and if all characters are picked, recursion will be over
    if (index==v.size()){
      v1.push_back(current);
      return;
    }
    //recursion: pick one character from each string 
    for(int i=0; i<v[index].size(); i++){
        combinator(v, index+1, current+v[index][i], v1);
    }

}
    vector<string> letterCombinations(string digits) {
    //1)mapping 
        unordered_map<int, vector<char>> m = {
    {2, {'a', 'b', 'c'}},
    {3, {'d', 'e', 'f'}},
    {4, {'g', 'h', 'i'}},
    {5, {'j', 'k', 'l'}},
    {6, {'m', 'n', 'o'}},
    {7, {'p', 'q', 'r', 's'}},
    {8, {'t', 'u', 'v'}},
    {9, {'w', 'x', 'y', 'z'}}
};
//2)seperating the digits
vector<int>v;
for(int i=0; i<digits.length(); i++){
    int f=digits[i]-'0';
    v.push_back(f);
}
vector<string>v1;
vector<vector<char>>v2;
//3)combination
for(int i=0; i<v.size(); i++){
    v2.push_back(m[v[i]]);
}
combinator(v2, 0, "", v1);

return v1;

}
};