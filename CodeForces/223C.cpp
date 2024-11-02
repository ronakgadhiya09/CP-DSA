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
struct Node {

    int open;
    int close; 
    int full;  

    Node() : open(0), close(0), full(0) {}

};

void build(int ind, int low, int high, const string &s, vector<Node> &seg) {

    if (low == high) {
        if (s[low] == '(') {
            seg[ind].open = 1;
        }
        else {
            seg[ind].close = 1;
        }
        return;
    }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, s, seg);
    build(2 * ind + 2, mid + 1, high, s, seg);

    int matched = min(seg[2 * ind + 1].open, seg[2 * ind + 2].close);
    seg[ind].full = seg[2 * ind + 1].full + seg[2 * ind + 2].full + matched;
    seg[ind].open = seg[2 * ind + 1].open + seg[2 * ind + 2].open - matched;
    seg[ind].close = seg[2 * ind + 1].close + seg[2 * ind + 2].close - matched;
}

Node query(int ind, int low, int high, int l, int r, const vector<Node> &seg) {

    if (r < low || l > high) {
        return Node();
    }

    if (low >= l && high <= r) {
        return seg[ind];
    }

    int mid = (low + high) / 2;
    Node left = query(2 * ind + 1, low, mid, l, r, seg);
    Node right = query(2 * ind + 2, mid + 1, high, l, r, seg);

    Node result;
    int matched = min(left.open, right.close);
    result.full = left.full + right.full + matched;
    result.open = left.open + right.open - matched;
    result.close = left.close + right.close - matched;
    
    return result;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int m;
    cin >> m;

    vector<Node> seg(4 * n);
    build(0, 0, n - 1, s, seg);

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--; 
        Node result = query(0, 0, n - 1, l, r, seg);
        cout << result.full * 2 << endl; 
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
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

// node::node(int o, int c, int f)
// {
// }
