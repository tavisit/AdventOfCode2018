#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

struct guard{
    int id,hours;
    int fi[60],maxf;//orele
}g[10000],maxg;
char c[1000];
ifstream in("data.in");
int k,maxx=0,maxf=-100,curent;
void frequency(int inc,int f,int k){
    for(int op=inc;op<=f;op++)g[k].fi[op]++;
}
int main(){
    k=0;
    while(in.getline(c,1000)){
        if(c[25]=='#'){
            int p=0;
            int poz=26;
            while(c[poz]>='0'&&c[poz]<='9'){
                p=p*10+c[poz]-48;
                poz++;
            }

            bool ok=true;
            for(int j=1;j<=k;j++)
                if(g[j].id==p){ok=false;curent=j;}

            if(ok==true)
                g[++k].id=p;

        }else if(c[19]=='f'){
            int inc=0,f=0;
            if(c[13]=='3'){

                int poz=15;
                int p=0;
                while(c[poz]>='0'&&c[poz]<='9'){
                    p=p*10+c[poz]-48;
                    poz++;
                }
                p=60-p;
                while(c[poz]>='0'&&c[poz]<='9'){
                    inc=inc*10+c[poz]-48;
                    poz++;
                }
                inc=-p;
            }else{
                //cout<<c[15]<<endl;
                int poz=15;
                int p=0;
                while(c[poz]>='0'&&c[poz]<='9'){
                    p=p*10+c[poz]-48;
                    poz++;
                }
                inc=p;

            }
            in.getline(c,1000);
            int poz=15;
            int p=0;
            while(c[poz]>='0'&&c[poz]<='9'){
                p=p*10+c[poz]-48;
                poz++;
            }
            f=p-1;
            frequency(inc,f,curent);
            g[curent].hours+=(f-inc);
        }

    }
    ///Part One
    /*
    maxx=0;
    for(int i=1;i<=k;i++)
        if(g[i].hours>maxx){
                maxx=g[i].hours;
                maxg=g[i];
        }

    cout<<maxg.id<<endl;

    maxf=0;
    for(int i=0;i<=59;i++)
    {
        if(maxg.fi[i]>maxf){
            maxf=maxg.fi[i];
            maxg.maxf=i;
        }
    }
    cout<<maxg.maxf*maxg.id;
    */
    ///Part Two
    maxx=0;maxf=0;int sizef;
    for(int i=1;i<=k;i++){
        for(int j=0;j<=59;j++){
            if(g[i].fi[j]>=maxf){
                maxx=g[i].id;
                maxf=g[i].fi[j];
                sizef=j;
            }
        }
    }
    cout<<sizef*maxx;
    return 0;
}
