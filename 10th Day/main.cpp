#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <Math.h>
using namespace std;
ifstream in("data.in");
struct point{
    struct location{
        int x,y;
    }locationRealtiveToOrigin;
    struct velocity{
        int x,y;
    }velocity;
}point[10000];
int a;
int k=0;
void citire(int& k)
{

    int nr=1;
    while(in>>a)
    {
        switch (nr){
        case 1:
            point[++k].locationRealtiveToOrigin.x=a;
            nr++;
            break;
        case 2:
            point[k].locationRealtiveToOrigin.y=a;
            nr++;
            break;
        case 3:
            point[k].velocity.x=a;
            nr++;
            break;
        case 4:
            point[k].velocity.y=a;
            nr=1;
            break;
        }

    }
}
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawpixel( int  x, int y){

        gotoxy(x,y);printf("#");
}
int main()
{
    int k=0;
    citire(k);
    for(int j=1;j<=20000;j++)
    {
        int ok=0;
        for(int i=1;i<=k;i++)
        {
            point[i].locationRealtiveToOrigin.x+=point[i].velocity.x;
            point[i].locationRealtiveToOrigin.y+=point[i].velocity.y;

        }

        for(int r=1;r<k;r++){
               for(int l=r+1;l<=k;l++)
                    if(fabs(fabs(point[r].locationRealtiveToOrigin.y)-fabs(point[l].locationRealtiveToOrigin.y))==1&&fabs(fabs(point[r].locationRealtiveToOrigin.x)-fabs(point[l].locationRealtiveToOrigin.x))==0){ok=1;}
        }

        if(ok==1 && j>10100){
                system("cls");

                for(int i=1;i<=k;i++){
                    drawpixel(point[i].locationRealtiveToOrigin.x,point[i].locationRealtiveToOrigin.y);
                }
                cout<<j<<endl;
                //The time and j variable are set by direct observation of the convergence of points
                if(j>10100)Sleep(500);
                if(kbhit())Sleep(10000);
        }
    }
    return 0;
}
