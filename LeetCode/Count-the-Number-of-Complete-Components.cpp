class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        unordered_map<int,int> isInRow;
        unordered_map<int,int> isInColumn;

        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int ele = mat[i][j];
                isInRow[ele] = i;
                isInColumn[ele] = j;
            }
        }

        vector<int> valuesInRow(m,n);
        vector<int> valuesInColumn(n,m);

        for(int i = 0 ; i < m*n ; i++){

            int row = isInRow[arr[i]];
            int column = isInColumn[arr[i]];

            valuesInRow[row]--;
            valuesInColumn[column]--;

            if(valuesInRow[row]==0 || valuesInColumn[column]==0) return i;
        }

        return m*n-1;
    }
};