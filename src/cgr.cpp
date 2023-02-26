#include "cgr.h"

using namespace std;

int** cgr(string seq, char order[], int k)
{
    int len = seq.length();
    int pw = pow(2,k);
    int** out = new int*[pw];

    for(int i=0;i<pw;i++)
    {
        out[i]=new int[pw];
        for(int j=0;j<pw;j++)
        {
            out[i][j]=0;
        }
    }
    int x = pow(2,k-1);
    int y = pow(2,k-1);
    for(int i=0;i<len;i++)
    {
        char ch = seq[i];
        x = x/2;
        y = y/2;
        if(ch == order[2] || ch == order[3])
        x = x + pow(2,k-1);
        if(ch == order[0] || ch == order[3])
        y = y + pow(2,k-1);
        if(i>=k-1)
        out[y][x] = out[y][x]+1;
    }

    return out;
}
