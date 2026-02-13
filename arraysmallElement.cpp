#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    int arr[100];
    cout<<"Enter no of elemnets:"<<endl;
    cin>>n;
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<ans){
            ans=arr[i];
        } 
    }
    cout<<ans;
}