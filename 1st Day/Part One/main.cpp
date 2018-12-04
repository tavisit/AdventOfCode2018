#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream in("data.in");
char c[1];
long long s=0,a,n;
int main()
{
    while(in.getline(c,10000)){
        a=0;
        n=strlen(c);
        for(int i=1;i<n;i++){

            a=a*10+c[i]-48;
        }
        if(c[0]=='-'){
            s-=a;
        }else s+=a;
    }
    cout<<s;
    return 0;
}
