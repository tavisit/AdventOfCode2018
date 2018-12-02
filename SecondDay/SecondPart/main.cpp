#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
ifstream in("data.in");
char c[1000][500],s1[100],s2[100];
int main()
{
    int n=0;
    while(in.getline(c[++n],100));
    int i=0,j=0,k=0;
    int m=strlen(c[1]);
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++)
        {

            int dif=0;
            for(k=0;k<m;k++)
                if(c[i][k]!=c[j][k])dif++;
            if(dif==1){
                strcpy(s1,c[i]);
                strcpy(s2,c[j]);
            }
        }
    }
    cout<<s1<<" "<<s2<<endl;
    for(i=0;i<m;i++)
        if(s1[i]!=s2[i]){
            for(k=i;k<m;k++)
            {
                s1[k]=s1[k+1];
                s2[k]=s2[k+1];
            }
        }
    cout<<s1;
    return 0;
}
