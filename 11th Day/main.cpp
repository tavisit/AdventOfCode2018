#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
long a[301][301];
int main() {

    int maxx=-100;

    long input = 5153;

    for(int i=1;i<=300;i++){//x
        for(int j=1;j<=300;j++){//y
            long rackId=i+10;
            a[i][j]=rackId*j;
            a[i][j]+=input;
            a[i][j]*=rackId;
            a[i][j]=(a[i][j]/100)%10;
            a[i][j]-=5;
        }
    }
    int xmax=0,ymax=0,maxsizez;
    for(int sizes=0;sizes<300;sizes++){
        if(sizes%50==0)cout<<sizes<<endl;
        for(int i=1;i<=300-sizes;i++){//x
            for(int j=1;j<=300-sizes;j++){//y
                int sum=0;
                for(int col=i;col<=i+sizes;col++)
                    for(int l=j;l<=j+sizes;l++)
                        sum+=a[col][l];

                if(sum>maxx){
                    maxx=sum;
                    xmax=j;ymax=i;
                    maxsizez=sizes;
                }
                }
            }
    }
    cout<<ymax<<","<<xmax<<","<<maxsizez+1;

    return 0;
}
