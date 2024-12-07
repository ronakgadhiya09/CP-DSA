/*
Author - Ronak Gadhiya
Created -
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
// #include <__msvc_chrono.hpp>

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
#define nl cout << endl
#define all(v) v.begin(), v.end()

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mod_inv(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return ((a - b+m) % m);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m) + m) % m;}  //only for prime m
 
using namespace std;

void remove(multiset<int> &my_multiset,int value){
    auto itr = my_multiset.find(value);
    if(itr!=my_multiset.end()){
        my_multiset.erase(itr);
    }
}

const int mod = 1e9 + 7;

void solve() {

    string s;
    cin >> s;

    int n = s.length();

    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < min(n,i+9) ;j++){
            int curr = s[i] - '0';
            int eff = j-i;
            int next = s[j] - '0';
            if(next - eff > curr){
                for (int k = j; k > i; --k) {
                    s[k] = s[k - 1];
                }
                s[i] = next - eff + '0';
            }
        }
    }   

    cout << s << endl;
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
        // auto start = std::chrono::high_resolution_clock::now();
        solve();
        // auto stop = std::chrono::high_resolution_clock::now();

        // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        // // Output the duration in microseconds
        // std::cout << "Time taken by function: " << duration.count()/1000 << " miliseconds" << endl;
    }

    return 0;
}
