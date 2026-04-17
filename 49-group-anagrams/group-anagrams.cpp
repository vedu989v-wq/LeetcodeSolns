class Solution {
public:
    void counter(string s, unordered_multimap<string, vector<int>>&m){
        vector<int>v1;
        for(int i=0; i<s.length(); i++){
            v1.push_back(int(s[i]));
        }
        sort(v1.begin(), v1.end());
        // CHANGE: multimap does NOT support [], use insert()
        m.insert({s, v1});
    }
    // Custom hash for vector<int>
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t hash = 0;
            for (int i : v) {
                hash ^= hash * 31 + i;
            }
            return hash;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_multimap<string, vector<int>>m;
        for(int i=0; i<strs.size(); i++){
            counter(strs[i], m);
        }
      
    // 2. Grouped map (Key: int, Value: vector of strings)
    // Add hash here
        unordered_map<vector<int>, vector<string>, VectorHash> groupedMap;

    // 3. Process the original map
    for (const auto& [key, value] : m) {
        groupedMap[value].push_back(key); // Group keys under their common value
    }
    vector<vector<string>>v;
    for (const auto& pair : groupedMap) {
        v.push_back(pair.second);
    }
        return v;
    }
};