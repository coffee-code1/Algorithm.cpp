#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//便于书写long long;
ll Fast_Exponentiation(ll a,ll b,ll q){//a为底数，b为指数，q为模；
    ll ans=1;
    while(b){//循环结束条件为b为零；而不是1，否则循环结束会少一个a，在循环外补上不如放在循环内
        if(b&1){  //等效于b%2！=0；判断奇数，与运算符只有二进制最后一位都是1才返回1；
            b-=1;  
            ans=(ans*a)%q;
        }
        a=(a*a)%q;
        b/=2;
    }
    return ans;
}

int main(){
    ll a,b,q;
    cin>>a>>b>>q;
    ll ans=Fast_Exponentiation(a,b,q);
    cout<<ans;
}
