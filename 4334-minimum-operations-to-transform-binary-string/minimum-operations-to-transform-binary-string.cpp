class Solution {
public:
    int minOperations(string s1, string s2) {
        //     int n = s1.length();
        //     int ops = 0;

        //     for (int i = 0; i < n; ++i){
        //         if (s1[i] == s2[i]) continue;

        //         if(s1[i] == '0' && s2[i] == '1'){
        //             s1[i] = '1';
        //             ops++;
        //         }
        //         else if (s1[i] == '1' && s2[i] == '0'){
        //             if (i + 1 < n && s1[i + 1] == '1'){
        //                 s1[i] = '0';
        //                 s1[i + 1] = '0';
        //                 ops++;
        //             }
        //             else {
        //                 // s1[i] = '0';
        //                 // ops++;
        //                 return -1;
        //             }
        //         }
        //     }
        // return (s1 == s2) ? ops : -1;

        if (s1 == "1" && s2 == "0") {
            return -1;
        }
        int res = 0, n = s1.length();
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i])
                continue;
            res++;
            if (s1[i] == '1') {
                if (i == n - 1) {
                    res++;
                } else {
                    res += s1[i + 1] == '0';
                    s1[i + 1] = '0';
                }
            }
        }
        return res;
    }
};