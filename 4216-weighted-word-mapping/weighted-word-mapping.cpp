class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (const string& w : words) {
            int sum = 0;
            for (char c : w) {
                sum += weights[c - 'a'];
            }
            ans += (char)('z' - (sum % 26));
        }
        return ans;
    }
};