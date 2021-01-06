#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a == b)
        return a;
    
    else if(a > b)
        return gcd(a-b , b);
    
    else
        return gcd(a , b-a);
}

int main(){
    int n;
    cin >> n;
    int a = n-1;
    if(a==0)
    {
    	cout<<"Enter other than 1 as 1 is not coprime"<<endl;
	}
    while(gcd(a,n) != 1){
        a--;
    }
    cout << a << " is the largest co-prime less than n-1";
}
