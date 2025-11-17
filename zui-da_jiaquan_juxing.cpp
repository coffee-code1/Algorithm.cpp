#include<bits/stdc++.h>
using namespace std;
int main(){  //n*n的矩形，下面n行输入权值，求最大值总和的矩形；
    int n,ai;
    int arr[121][121];//开一个数组，直接矩形的复用
    cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>ai;
                arr[i][j]=ai+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            }//这个循环就等同于n行输入权值了，并在输入的数组中直接预留出加和的数组；
        }
    int res=-99999999;
    for(int x1=1;x1<=n;x1++){//这是之所以是四层循环而不是之前的两层是因为本题并未规定是个正方形所以左上角点和右下角点均不确定，所以四层循环枚举所有可能
        for(int y1=1;y1<=n;y1++){
            for(int x2=1;x2<=n;x2++){
                for(int y2=1;y2<=n;y2++){
                    if(x2<x1||y2<y1) continue;//这里可能出现不必要的情况，即左上角点跑到右下角角点的右边，也可以在循环的起始值处修改直接不用写if
                    res=max(res,arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1]);
                }
            }
        }
    }
    cout<<res;
}