class Fancy {
public:
    typedef long long ll;
    vector<pair<ll, pair<ll, ll>>> v;
    ll globalmult = 1;
    ll globaladd = 0;
    ll div = 1e14;
    int mod = 1e9 + 7;
    Fancy() {}
    void append(int val) { v.push_back({val % mod, {globalmult, globaladd}}); }
    void addAll(int inc) { globaladd = (globaladd + inc) % mod; }
    void multAll(int m) {
        globalmult = (globalmult * m) % mod;
        globaladd = (globaladd * m) % mod;
    }
    ll modpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int getIndex(int idx) {
        if (idx >= v.size())
            return -1;

        ll val = v[idx].first;
        ll m0 = v[idx].second.first;
        ll a0 = v[idx].second.second;

        ll num = (val - a0 + mod) % mod;
        ll mult = (globalmult * modpow(m0, mod - 2)) % mod;

        num = (num * mult) % mod;
        num = (num + globaladd) % mod;

        return num;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
