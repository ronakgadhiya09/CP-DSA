class Solution {
bool check(int x){
    vector<int> freq(10);

    while(x){
        int d = x%10;
        freq[d]++;
        x/=10;
    }

    for(int i = 0 ; i < 10; i++) if(freq[i] && freq[i]!=i) return false;
    return true;
}

public:
    int nextBeautifulNumber(int n) {
        int i = n + 1;
        while(!check(i)) i++;
        return i;
    }
};