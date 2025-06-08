class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<int> ans;

        for(int i = 1 ;i <= min(9,n) ;i++){
            ans.push_back(i);
            for(int j = i*10 ;j <= min(i*10 + 9,n) ;j++){
                ans.push_back(j);
                for(int k = j*10 ;k <= min(j*10 + 9,n) ;k++){
                    ans.push_back(k);
                    for(int l = k*10 ;l <= min(k*10 + 9,n) ;l++){
                        ans.push_back(l);
                        for(int m = l*10 ;m <= min(l*10 + 9,n) ;m++){
                            ans.push_back(m);
                        }
                    }
                }
            }
        }

        return ans;
    }
};