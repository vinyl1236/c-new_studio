#include<iostream>
#include<cmath>
typedef long long LL;
LL n;
const int N=1e5+10;
LL c[N];
LL m,p1,s1,s2;
LL sum1=0,sum2=0,ans,newsum;
LL MIN=1e18;
using namespace std;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>c[i];

    cin>>m>>p1>>s1>>s2;
    for(int i=1;i<=m-1;i++) sum1+=c[i]*(m-i);
    for(int i=m+1;i<=n;i++) sum2+=c[i]*(i-m);
    if(p1>m) sum2+=s1*(p1-m);
    if(p1<m) sum1+=s1*(m-p1);
    
    ans=m;
    MIN=llabs(sum1-sum2);

    for(int p2=1;p2<=n;p2++)
    {
        LL newsum1=sum1;
        LL newsum2=sum2;
        if(p2<m)
        {
            newsum1+=s2*(m-p2);
        }else if(p2>m)
        {
            newsum2+=s2*(p2-m);
        }

        newsum=llabs(newsum1-newsum2);
        if(newsum<MIN)
        {
            MIN=newsum;
            ans=p2;
        }
    }
    cout<<ans;
    return 0;
}
