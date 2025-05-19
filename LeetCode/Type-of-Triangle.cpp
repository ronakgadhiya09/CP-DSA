class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if(c>b) swap(c,b);
        if(b>a) swap(a,b);

        if(b+c <= a) return "none";

        if(a==b && b==c) return "equilateral";
        else if(a==b || b==c || a==c) return "isosceles";
        else if(a!=b && b!=c && c!=a) return "scalene";

        return "none";
    }
};