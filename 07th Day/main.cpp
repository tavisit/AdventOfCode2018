#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream in("data.in");
char line[300][300],maxc,litera_max,ch[200];
int maxim,frecventa[300],linii,aparitie[300],v[300],a[300][300],nr;
int main()
{
    while(!in.eof())
    {
        in.getline(line[++linii],300);
        frecventa[line[linii][36]]++;
        if(frecventa[line[linii][36]]>maxim)
            {maxim=frecventa[line[linii][36]];
            maxc=line[linii][36];
            }
        if(line[linii][36]>litera_max)
            litera_max=line[linii][36];
        if(line[linii][5]>litera_max)
            litera_max=line[linii][5];
        a[line[linii][5]][line[linii][36]]=1;
    }
    for(int i=maxim;i>=0;i--)
        for(int j=1;j<=linii;j++)
    {
        if(frecventa[line[j][36]]==i)
            frecventa[line[j][5]]=i-1;

    }


    for(int i=-30;i<=maxim;i++)
        for(char c='A';c<=litera_max;c++)
        {
            if(frecventa[c]==i)
                ch[++nr]=c;
        }

    int ok=1;
    while(ok==1)
    {
        ok=0;
        for(int i=2;i<=nr;i++)
            if(a[ch[i]][ch[i-1]]==1)
        {
            ch[i]=ch[i]+ch[i+1];
            ch[i+1]=ch[i]-ch[i+1];
            ch[i]=ch[i]-ch[i+1];
            ok=1;
        }
    }
    for(int i=1;i<=nr;i++)
        cout<<ch[i];
    cout<<endl;
    return 0;
}
