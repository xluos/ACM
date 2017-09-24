#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
ll Mult(ll a, ll n)
{
    ll s = 1;
    while(n)
    {
        if(n & 1)s = (s%Mod)*(a%Mod)%Mod;
        a=(a%Mod)*(a%Mod)%Mod;
        n>>=1;
    }
    return s;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        ll p, q, k;
        scanf("%lld%lld%lld", &p, &q, &k);
        ll fz = (Mult(p, k) % Mod + Mult((p - 2 * q), k) % Mod) % Mod;
        ll f = Mult(p, k) % Mod;
        ll fm = Mult(2 * f, Mod - 2) % Mod;
        printf("%lld\n", (fz * fm) % Mod);
    }

    return 0;
}
