#include <iostream>
using namespace std;
const int mod = 1e9+7;
const int maxn = 10005;
long long fac[maxn];
long long qpow(long long a,long long b)
{
    long long ans=1;a%=mod;
    for(long long i=b;i;i>>=1,a=a*a%mod)
        if(i&1)ans=ans*a%mod;
    return ans;
}
long long C(long long n,long long m)
{
    //return fac[n] / fac[m] / fac[n-m];
    if(m>n||m<0)return 0;
    long long s1=fac[n],s2=fac[n-m]*fac[m]%mod;
    return s1*qpow(s2,mod-2)%mod;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;

    fac[0] = 1;
    for(int i=1; i<maxn; i++) fac[i] = fac[i-1] * i % mod;
    long long  n;
    long long  m;
    cin >> n;
    cin >> m;
    printf("%lld", C(n+2*m-1, 2*m));
    return 0;
}
