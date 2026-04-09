class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        // Basic check to prevent out-of-bounds
        if (s.length() < 10) return v;

        // We use an unordered_map to store: <The Substring, How many times we've seen it>
        unordered_map<string, int> counts;
        
        int first = 0; 
        // Keep your original 'while' structure
        while (first <= (int)s.length() - 10) {
            string currentSub = s.substr(first, 10);
            
            // Increment the count for this specific 10-letter sequence
            counts[currentSub]++;
            
            // If this is the EXACT second time we see it, add it to our vector.
            // We check for '== 2' so we don't add the same string multiple times 
            // to our results if it appears 3 or 4 times.
            if (counts[currentSub] == 2) {
                v.push_back(currentSub);
            }
            
            // Keep your original pointer increment
            first++;
        }
     
        return v;
    }
};