class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int longest_diag = 0;
        int area = 0;

        for(auto &rec : dimensions){
            int length = rec[0];
            int width = rec[1];

            if(length*length + width*width > longest_diag){
                area = length*width;
                longest_diag = length*length + width*width;
            }
            else if(length*length + width*width == longest_diag){
                area = max(area,length*width);
            }
        }
        
        return area;
    }
};