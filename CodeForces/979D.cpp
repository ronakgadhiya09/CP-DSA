/*
Author - Ronak Gadhiya
Created -
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int> , rb_tree_tag, tree_order_statistics_node_update> o_set;
// /*
//     s.find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set s
//     s.order_of_key(k) : It returns to the number of items that are strictly smaller than our item k
// */

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mkp make_pair
#define fr(i, a, n) for (int i = a; i < n; ++i)
#define rfr(i, a, n) for (int i = n; i > a; --i)
#define in(a, n) fr(i, 0, n) cin >> a[i];
#define out(a, n) fr(i, 0, n) cout << a[i] << " ";
#define Y cout << "YES"
#define N cout << "NO"
#define endl '\n'
#define nl cout << endl;
#define all(v) v.begin(), v.end()

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mod_inv(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return ((a - b+m) % m);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m) + m) % m;}  //only for prime m
 
using namespace std;

const int mod = 1e9 + 7;

void remove(multiset<int> &my_multiset,int value){
    auto itr = my_multiset.find(value);
    if(itr!=my_multiset.end()){
        my_multiset.erase(itr);
    }
}

void solve() {

    int n,q;
    cin >> n >> q;

    vi v(n);
    in(v,n);

    string s;
    cin >> s;

    vi pre_max(n,0);

    pre_max[0] = v[0];

    fr(i,1,n) pre_max[i] = max(v[i],pre_max[i-1]);

    // out(pre_max,n);
    // cout << endl;

    set<int> blocked;

    fr(i,1,n-1){
        if(s[i]=='L' && s[i+1]=='R' && pre_max[i]!=i+1){
            blocked.insert(i);
            // cout << i << " is blocked" << endl;
        }
    }
    // cout << endl;

    // if(s.empty()){
    //     cout << "s is empty " << endl;
    // }

    while(q--){

        int x;
        cin >> x;
        x--;

        if(s[x]=='L'){
            s[x] = 'R';
            if(blocked.find(x)!=blocked.end()){
                blocked.erase(x);
            }
            if(s[x-1]=='L' && pre_max[x-1]!=x) blocked.insert(x-1);

        }
        else{
            s[x] = 'L';
            if(blocked.find(x-1)!=blocked.end()) blocked.erase(x-1);
            if(s[x+1]=='R' && pre_max[x]!=x+1) blocked.insert(x);
        }

        if(blocked.empty()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t=1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
