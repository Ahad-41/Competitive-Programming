#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 3e5 + 9;
const ll LG = 18;

void induced_sort(const vector<ll> &vec, ll val_range, vector<ll> &SA, const vector<bool> &sl, const vector<ll> &lms_idx) {
    vector<ll> l(val_range, 0), r(val_range, 0);
    for (ll c : vec) {
        if (c+1 < val_range) l[c+1]++;
        r[c]++;
    }
    partial_sum(l.begin(), l.end(), l.begin());
    partial_sum(r.begin(), r.end(), r.begin());
    fill(SA.begin(), SA.end(), -1);
    for (ll i = lms_idx.size() - 1; i >= 0; --i) SA[--r[vec[lms_idx[i]]]] = lms_idx[i];
    for (auto &u : SA) {
        if (u >= 1 and sl[u-1]) SA[l[vec[u-1]]++] = u-1;
    }
    fill(r.begin(), r.end(), 0);
    for (ll c : vec) r[c]++;
    partial_sum(r.begin(), r.end(), r.begin());
    for (ll k = SA.size() - 1, i = SA[k]; k >= 1; k--, i = SA[k]) {
        if (i >= 1 and !sl[i-1]) SA[--r[vec[i-1]]] = i-1;
    }
}

vector<ll> SA_IS(const vector<ll> &vec, ll val_range) {
    const ll n = vec.size();
    vector<ll> SA(n), lms_idx;
    vector<bool> sl(n);
    sl[n-1] = false;
    for (ll i = n-2; i >= 0; i--) {
        sl[i] = (vec[i] > vec[i + 1] || (vec[i] == vec[i + 1] and sl[i + 1]));
        if (sl[i] and !sl[i + 1]) lms_idx.push_back(i + 1);
    }
    reverse(lms_idx.begin(), lms_idx.end());
    induced_sort(vec, val_range, SA, sl, lms_idx);
    vector<ll> new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());
    for (ll i = 0, k = 0; i < n; i++) {
        if (!sl[SA[i]] and SA[i] >= 1 and sl[SA[i] - 1]) new_lms_idx[k++] = SA[i];
    }
    ll cur = 0;
    SA[n-1] = cur;
    for (size_t k = 1; k < new_lms_idx.size(); k++) {
        ll i = new_lms_idx[k-1], j = new_lms_idx[k];
        if (vec[i] != vec[j]) {
            SA[j] = ++cur;
            continue;
        }
        bool flag = false;
        for (ll a = i + 1, b = j + 1;; a++, b++) {
            if (vec[a] != vec[b]) {
                flag = true;
                break;
            }
            if ((!sl[a] and sl[a - 1]) || (!sl[b] and sl[b - 1])) {
                flag = !((!sl[a] and sl[a - 1]) and (!sl[b] and sl[b - 1]));
                break;
            }
        }
        SA[j] = (flag ? ++cur : cur);
    }
    for (size_t i = 0; i < lms_idx.size(); i++) lms_vec[i] = SA[lms_idx[i]];
    if (cur + 1 < (ll)lms_idx.size()) {
        auto lms_SA = SA_IS(lms_vec, cur + 1);
        for (size_t i = 0; i < lms_idx.size(); i++) new_lms_idx[i] = lms_idx[lms_SA[i]];
    }
    induced_sort(vec, val_range, SA, sl, new_lms_idx);
    return SA;
}

vector<ll> suffix_array(const string &s, const ll LIM = 128) {
    vector<ll> vec(s.size()+1);
    copy(begin(s), end(s), begin(vec));
    vec.back() = '$';
    auto ret = SA_IS(vec, LIM);
    ret.erase(ret.begin());
    return ret;
}

struct SuffixArray {
    ll n;
    string s;
    vector<ll> sa, rank, lcp, lg;
    vector<vector<ll>> t;
    SuffixArray() {}

    SuffixArray(string _s) {
        n = _s.size();
        s = _s;
        sa = suffix_array(s);
        rank.resize(n);
        for (ll i = 0; i < n; i++) rank[sa[i]] = i;
        costruct_lcp();
        prec();
        build();
    }

    void costruct_lcp() {
        ll k = 0;
        lcp.resize(n-1, 0);
        for (ll i = 0; i < n; i++) {
            if (rank[i] == n-1) {
                k = 0;
                continue;
            }
            ll j = sa[rank[i] + 1];
            while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
            lcp[rank[i]] = k;
            if (k) k--;
        }
    }

    void prec() {
        lg.resize(n, 0);
        for (ll i = 2; i < n; i++) lg[i] = lg[i / 2] + 1;
    }

    void build() {
        ll sz = n-1;
        t.resize(sz);
        for (ll i = 0; i < sz; i++) {
            t[i].resize(LG);
            t[i][0] = lcp[i];
        }
        for (ll k = 1; k < LG; k++) {
            for (ll i = 0; i + (1 << k) - 1 < sz; i++) {
                t[i][k] = min(t[i][k-1], t[i + (1 << (k-1))][k-1]);
            }
        }
    }
    
    ll query(ll l, ll r) { // minimum of lcp[l], ..., lcp[r]
        ll k = lg[r - l + 1];
        return min(t[l][k], t[r - (1 << k) + 1][k]);
    }

    ll get_lcp(ll i, ll j) { // lcp of suffix starting from i and j
        if (i == j) return n-i;
        ll l = rank[i], r = rank[j];
        if (l > r) swap(l, r);
        return query(l, r - 1);
    }

    ll lower_bound(string &t) {
        ll l = 0, r = n-1, k = t.size(), ans = n;
        while (l <= r) {
            ll mid = l + r >> 1;
            if (s.substr(sa[mid], min(n - sa[mid], k)) >= t) ans = mid, r = mid-1;
            else l = mid+1;
        }
        return ans;
    }

    ll upper_bound(string &t) {
        ll l = 0, r = n-1, k = t.size(), ans = n;
        while (l <= r) {
            ll mid = l+r >> 1;
            if (s.substr(sa[mid], min(n-sa[mid], k)) > t) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }

    // occurrences of s[p, ..., p + len - 1]
    pair<ll, ll> find_occurrence(ll p, ll len) {
        p = rank[p];
        pair<ll, ll> ans = {p, p};
        ll l = 0, r = p - 1;
        while (l <= r) {
            ll mid = l+r >> 1;
            if (query(mid, p-1) >= len) {
                ans.first = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        l = p+1, r = n-1;
        while (l <= r) {
            ll mid = l+r >> 1;
            if (query(p, mid - 1) >= len) {
                ans.second = mid;
                l = mid+1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s; cin >> s;
    ll n = s.size();
    SuffixArray sa(s);
    
    for (ll i = 0; i < n; i++) cout << sa.sa[i] << ' ' << s.substr(sa.sa[i]) << "\n";

    sa.costruct_lcp();
    for (auto &u : sa.lcp) cout << u << " ";
}