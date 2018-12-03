#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream in("data.in");
char a[10000];
int v[1001][1001]; long nr;
struct point{
    int x,y;
    int fx,fy;
}p[1500];
int k,ok[10000];
int main()
{
    k=0;
    while(in.getline(a,256))
    {
        int n=strlen(a);
        for(int i=0;i<n;i++)
        {
            if(a[i]=='@'){
                i+=2;
                k++;
                p[k].x=0;p[k].y=0;p[k].fx=0;p[k].fy=0;int lx=0,ly=0;
                while(a[i]>='0'&&a[i]<='9'){
                    p[k].x=p[k].x*10+(a[i]-48);
                    i++;
                }i++;
                while(a[i]>='0'&&a[i]<='9'){
                    p[k].y=p[k].y*10+(a[i]-48);
                    i++;
                }
                i+=2;
                while(a[i]>='0'&&a[i]<='9'){
                    lx=lx*10+(a[i]-48);
                    i++;
                }i++;
                while(a[i]>='0'&&a[i]<='9'){
                    ly=ly*10+(a[i]-48);
                    i++;
                }
                p[k].fx=lx+p[k].x;
                p[k].fy=ly+p[k].y;
                p[k].x++;
                p[k].y++;
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=p[i].y;j<=p[i].fy;j++)
            for(int l=p[i].x;l<=p[i].fx;l++){
                if(v[j][l]!=0)
                    v[j][l]=-1;
                else
                    v[j][l]=i;
            }
    }

	//part one
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=1000;j++)
            if(v[i][j]==-1)nr++;
    cout<<nr<<endl<<endl;
	//part two
	for(int i=1;i<=k;i++)
    {
        for(int j=p[i].y;j<=p[i].fy;j++)
            for(int l=p[i].x;l<=p[i].fx;l++){
                if(v[j][l] == -1)
                    ok[i]=-1;
            }
    }
    for(int i=1;i<=k;i++)
        if(ok[i]!=-1) cout<<i<<endl;

    return 0;
}
