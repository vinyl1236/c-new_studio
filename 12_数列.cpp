#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
long long k,n,ans;
int main()
{
    cin>>k>>n;
    stack<int>s;

    while(n) s.push(n&1),n>>1;
    while(!s.empty()) ans+=s.top()*pow(k,s.size()-1),s.pop();
    cout<<ans<<endl;
    return 0;
}
