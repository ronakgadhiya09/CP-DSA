class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());
        unordered_set<string> st;

        for(auto &f : folder){

            string temp = "";
            int m = f.size();
            bool flag = true;
            for(int i = 0 ; i < m ; i++){
                temp += f[i];
                if((i < m - 1 && f[i+1]=='/')){
                    if(st.find(temp)!=st.end()){
                        flag = false;
                        break;
                    }
                }
                if(i==m-1){
                    if(st.find(temp)!=st.end()){
                        flag = false;
                        break;
                    }
                }
            }

            if(flag){
                st.insert(temp);
            }
        }

        vector<string> ans(st.begin(),st.end());
        return ans;
    }
};