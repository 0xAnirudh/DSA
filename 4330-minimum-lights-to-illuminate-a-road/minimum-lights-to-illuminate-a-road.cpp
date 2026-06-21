class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            if (lights[i] == 0)
                continue;

            int l = max(0, i - lights[i]);
            int r = min(n - 1, i + lights[i]);

            v.push_back({l, r});
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        int e = -1;

        for (auto& p : v) {
            int l = p.first;
            int r = p.second;

            if (l > e + 1) {
                int gap = l - e - 1;
                ans += (gap + 2) / 3;
            }

            e = max(e, r);
        }

        if (e < n - 1) {
            int gap = n - e - 1;
            ans += (gap + 2) / 3;
        }

        return ans;
    }
};