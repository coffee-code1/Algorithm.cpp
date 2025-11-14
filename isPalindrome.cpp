#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(int x){
    int original=x,reversed=0;
    while(original>0){
        reversed=reversed*10+original%10;  //判断回文数，通过一位一位的数学运算实现逆转；
        original/=10;
    }
    return reversed == x;
}
int main(){
    int a,b,ai;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(isPalindrome(i)) cout<<i<<endl;
}
}