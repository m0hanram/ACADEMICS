#include <iostream>
using namespace std;


class Check{
public:
    int *arr;
    int N,X;
    void getArray();
    void checkgrade();
};
void Check::getArray(){
    cout<<"Enter the no of elements in the array : ";
    cin>>N;
    cout<<endl<<"Enter the X value (no.of distinct elements) : ";
    cin>>X;
    cout<<endl;
    arr=new int[N];
    cout<<endl<<"Enter the elements of the array : "<<endl<<endl;
    int i;
    for(i=0;i<N;i++){
        cin>>arr[i];
    }
}
void Check::checkgrade(){
    int dis=1,i,j,flag=true;
    for(i=1;i<N;i++){
        for(j=0;j<i;j++){
            if(arr[i]==arr[j]){
                flag=false;
                break;
            }
        }
        if(flag){
            dis++;
        }
        flag=true;
    }
    cout<<endl<<"No of distinct elements : "<<dis<<" ,so the array is ";
    if(dis==X){
        cout<<"Good"<<endl;
    }
    else if(dis<X){
        cout<<"Bad"<<endl;
    }
    else{
        cout<<"Average"<<endl;
    }
}
int main(){
    Check ob;
    ob.getArray();
    ob.checkgrade();
}
