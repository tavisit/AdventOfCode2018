#include <fstream>
#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
ifstream in("data.in");
char c[100000];
int main(){
    int len;
    in.getline(c,100000);
    ///Part One
    /*
    len=strlen(c);
    int i=0;
    while(i<len){
        if(fabs(c[i+1]-c[i])==32){
            strcpy(c+i,c+i+2);
            len-=2;
            i=0;
        }
        i++;
    }
    cout<<strlen(c)<<endl;
    */
    ///Part two
    int minx=100000;
    char ic[100000];
    for(char ch='a';ch<='z';ch++){
        cout<<ch<<endl;
        strcpy(ic,c);
        for(int j=0;j<=strlen(ic);j++){
            while(ic[j]==ch||ic[j]==char(ch-32)){
                strcpy(ic+j,ic+j+1);
                len--;
            }
        }
        len=strlen(ic);
        int i=0;
        while(i<len){
            if(fabs(ic[i+1]-ic[i])==32){
                strcpy(ic+i,ic+i+2);
                len-=2;
                i=0;
            }
            i++;
        }

        if(minx>strlen(ic)){
            minx=strlen(ic);
        }

    }

    cout<<minx;
    return 0;
}
