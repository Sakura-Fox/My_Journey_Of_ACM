/*
    source: http://codeforces.com/contest/1513/problem/B
    题意： 给n个数，求这n个数符合某个条件的排列的数量，具体条件见题目，和与运算有关
    思路：
        当有一串数a1&a2&..&an的时候，对于每一个位，其不被改变的充要条件是：
            该位为0，或n个数该位都为1
        所以，若n个数有某个数该位为0，若存在一个不改变的数，这个数该位必为0
        反之该位为1

        由条件一 a1 = a2&...an
        条件n a1&...an-1 = an 
        得出 a1,an不被改变
        于是所有等式的值都是a1==an

        问题等价于 取两个不会改变的数，其他任意
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int ansbit[maxn];
map<int, int> mp;
ll fac[maxn];
void init()
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 2e5; i++)
        fac[i] = fac[i - 1] * i, fac[i] %= mod;
}
ll A(ll n)
{
    return n*(n-1);
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t,n;
    cin >> t;
    init();
    while (t--)
    {
        cin >> n;
        memset(ansbit, 0, sizeof ansbit);
        mp.clear();
        int tmp;
        for(int j=0;j<n;j++)
        {
            cin >> tmp;
            mp[tmp]++;
            for (ll i = 0; i < 32; i++)
            {
                if ((1 << i) & (tmp))
                    ansbit[i]++;
            }
        }
        int tar = 0;
        for (int i = 0; i < 32; i++)
        {
            if (ansbit[i] == n)
                tar |= (1 << i);
        }
        ll ans = A(mp[tar]);
        ans %= mod;
        ans *= fac[n - 2];
        ans %= mod;
        cout << ans << endl;
    }
}