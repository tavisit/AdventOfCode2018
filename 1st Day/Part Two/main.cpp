#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("data.in");
long long n,a[1000],d,s[100000];
long k;
bool ok=0;
int main()
{
    while(in>>n)
    {
        a[++d]=n;
    }
    cout<<d<<endl;
    while(ok==0)
    {for(int i=1;i<=d;i++)
    {
    k++;
    s[k]=s[k-1]+a[i];
    cout<<s[k]<<" ";
    for(int j=1;j<k;j++)
        if(s[k]==s[j])
            {ok=1;
            cout<<endl<<s[k]<<" "<<k<<endl;
            break;
            }
        if(ok==1)
            break;
    }
    }
    cout<<endl;
    sort(s+1,s+k+1);
    for(int i=1;i<=k;i++)
        if(s[i]==s[i+1])
            cout<<s[i]<<" ";
    return 0;
}
