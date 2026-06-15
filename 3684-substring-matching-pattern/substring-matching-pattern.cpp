class Solution {
public:
    bool hasMatch(string s, string p) {
        size_t star = p.find('*');
        string pre = p.substr(0, star);
        string suf = p.substr(star + 1);
        
        size_t i = s.find(pre);
        if (i == string::npos) return false;
        
        return s.find(suf, i + pre.length()) != string::npos;
    }
};
