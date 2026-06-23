#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int m,n,k;
const int N=510;
int mp[N][N];
struct pick{
    int x,y,sum;
}stu[N*N];

int cmp(struct pick a,struct pick b)
{
    return a.sum>b.sum;
}
int main()
{
    cin>>m>>n>>k;
    int pn=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]>0)
            {
                stu[++pn].sum=mp[i][j];
                stu[pn].x=i;
                stu[pn].y=j;
            }
        }
    }
    sort(stu+1,stu+pn+1,cmp);

    int fx=0,fy=stu[1].y;
    int ans=0;
    
    for(int i=1;i<=pn;i++)
    {
        int ex=stu[i].x;
        int ey=stu[i].y;

        int dict=abs(fx-ex)+abs(fy-ey);

        if(dict+1+ex<=k)
        {
            k-=(dict+1);
            ans+=mp[ex][ey];
            fx=ex;
            fy=ey;
        }
        else{
            break;
        }
    }
    cout<<ans;
    return 0;
}
