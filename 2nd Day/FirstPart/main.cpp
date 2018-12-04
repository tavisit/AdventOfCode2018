#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
ifstream in("data.in");
char c[1000];
int checkSum=0,two,three;
int f[30],n;
int main()
{
    while(in.getline(c,100)){
        for(char ch='a';ch<='z';ch++)f[ch]=0;
        n=strlen(c);
        for(int i=0;i<=n;i++)
            f[c[i]]++;
        int ok1=1,ok2=1;
        for(char ch='a';ch<='z';ch++)
        {
            if(f[ch]==2&&ok1==1){two++;ok1=0;}
            if(f[ch]==3&&ok2==1){three++;ok2=0;}
        }
    }
    checkSum=two*three;
    cout<<checkSum;
    return 0;
}
