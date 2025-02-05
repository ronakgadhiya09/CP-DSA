/*
Author - Ronak Gadhiya
Created - [Insert Date]
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_set;
/*
    s.find_by_order(k): Returns an iterator to the kth element (counting from zero) in the set s.
    s.order_of_key(k): Returns the number of items strictly smaller than k in the set s.
*/

using namespace std;

// Type aliases for convenience
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define pi pair<int, int>
#define pll pair<ll, ll>

// Utility macros
#define pb push_back
#define mkp make_pair
#define all(v) (v).begin(), (v).end()
#define fr(i, a, n) for (int i = (a); i < (n); ++i)
#define rfr(i, a, n) for (int i = (n)-1; i >= (a); --i)
#define in(a, n) fr(i, 0, n) cin >> (a)[i];
#define out(a, n) fr(i, 0, n) cout << (a)[i] << " "; cout << endl;
#define Y cout << "YES" << endl;
#define N cout << "NO" << endl;
#define nl cout << endl;

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Utility functions
ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
ll expo(ll a, ll b, ll m) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res; }
ll mod_inv(ll a, ll m) { return expo(a, m - 2, m); }
ll mod_add(ll a, ll b, ll m) { return ((a % m + b % m) % m + m) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m * b % m) % m + m) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((a % m - b % m) % m + m) % m; }
ll mod_div(ll a, ll b, ll m) { return mod_mul(a, mod_inv(b, m), m); }
void remove(multiset<int>& ms, int value) { auto it = ms.find(value); if (it != ms.end()) ms.erase(it); }

int popcount(int x) { return __builtin_popcount(x); }     // Count 1 bits
int popcountll(ll x) { return __builtin_popcountll(x); }  // Count 1 bits (long long)
int lsb(int x) { return x & -x; }                         // Get least significant bit

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>; // Min-Heap

template<typename T>
using max_heap = priority_queue<T>; // Max-Heap

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll>>a(n,vector<ll>(n));

    fr(i,0,n){
        fr(j,0,n){
            cin >> a[i][j];
        }   
    }

    vi ones;
    fr(i,0,n){
        int cont = 0;
        rfr(j,0,n){
            if(a[i][j]!=1) break;
            cont++;
        }
        if(cont)
            ones.pb(cont);
    }

    int m = ones.size();
    sort(all(ones));
    // fr(i,0,m) cout << ones[i] << " ";
    // cout << endl;

    int mex = n;
    int cur = 1;
    for(int i = 0 ; i < m ; i++){
        if(ones[i]>=cur) cur++; 
        // cout << "cur in loop is : " << cur << " ones[i] in loop is: " << ones[i] << endl;
    }

    // cout << "cur is : " << cur << endl;
    cout << min(mex,cur) << endl;

}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // auto start = std::chrono::high_resolution_clock::now();
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // // Output the duration in microseconds
    // std::cout << "Time taken by function: " << duration.count()/1000 << " miliseconds" << endl;

    return 0;
}
