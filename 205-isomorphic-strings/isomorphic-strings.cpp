class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, char> mapST, mapTS;
        
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            
            // If mapping exists, it must match
            if (mapST.count(a) && mapST[a] != b) return false;
            if (mapTS.count(b) && mapTS[b] != a) return false;
            
            // Store mapping
            mapST[a] = b;
            mapTS[b] = a;
        }
        
        return true;
    }
};