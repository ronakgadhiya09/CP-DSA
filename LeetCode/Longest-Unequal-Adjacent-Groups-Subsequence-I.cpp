class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {

        vector<string> startsWithZero;
        vector<string> startsWithOne;

        int n = words.size();
        for(int i = 0; i < n ; i++){
            if(startsWithZero.size()%2==0){
                if(!groups[i]) startsWithZero.push_back(words[i]);
            }
            else{
                if(groups[i]) startsWithZero.push_back(words[i]);
            }

            if(startsWithOne.size()%2==0){
                if(groups[i]) startsWithOne.push_back(words[i]);
            }
            else{
                if(!groups[i]) startsWithOne.push_back(words[i]);
            }
        } 

        return startsWithZero.size() >= startsWithOne.size() ? startsWithZero : startsWithOne;   
    }
};