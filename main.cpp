#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

#define MAX(a,b) (a)>(b)?(a):(b)

#define N 100000
using namespace std;

void clean(int *mass)
{
    for(int i=0;i<N;++i)
        mass[i]=0;
}


void compute(int *massUp,int *massDown,int right)
{
    if(right>2) massDown[0]+=MAX(massUp[0],massUp[1]);
        else
    massDown[0]+=massUp[0];

    if(right>2) massDown[right-2]+=MAX(massUp[right-2],massUp[right-3]);

    massDown[right-1]+=massUp[right-2];

    for(int i=1;i<right-2;++i)
        massDown[i]+=MAX(MAX(massUp[i-1],massUp[i]),massUp[i+1]);
}

using namespace std;
int main()
{
    ifstream in("INPUT.TXT");
    ofstream out("OUTPUT.TXT");

    int *massUp=new int[N];
    int *massDown=new int[N];

    clean(massUp);
    clean(massDown);

    int a=-1;
    in>>a;
    int rigth=1;
    massDown[0]=a;

    int *temp;
    while(in)
    {
        clean(massUp);

        temp=massUp;
        massUp=massDown;
        massDown=temp;
        clean(massDown);
        rigth++;
        for(int i=0;i<rigth;++i)
            {
                a=-1;
                in>>a;
                if(a>=0 && a<100) //this is checking for end of file('\0') in ubuntu
                massDown[i]=a;
            }
        if(a>=0 && a<100) compute(massUp,massDown,rigth); else break;
    }
    int ans=0;
    for(int i=0;i<N;i++)
        ans=MAX(ans,massUp[i]);
    cout<<ans;
    return 0;
}
