class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int numColumns = colsum.size();
        vector<vector<int>> resultMatrix(2, vector<int>(numColumns, 0));
        for (int col = 0; col < numColumns; ++col) {
            if (colsum[col] == 2) {
                resultMatrix[0][col] = 1;
                resultMatrix[1][col] = 1;
                upper--;
                lower--;
            }
            else if (colsum[col] == 1) {
                if (upper > lower) {
                    resultMatrix[0][col] = 1;
                    upper--;
                } else {
                    resultMatrix[1][col] = 1;
                    lower--;
                }
            }
            if (upper < 0 || lower < 0) {
                break;
            }
        }
    
        return (upper == 0 && lower == 0) ? resultMatrix : vector<vector<int>>();
    }
};