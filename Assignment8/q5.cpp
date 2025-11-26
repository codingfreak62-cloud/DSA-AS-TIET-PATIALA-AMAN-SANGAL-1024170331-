#include <iostream>
using namespace std;

void heapify(int a[],int n,int i){
    int l=2*i+1,r=2*i+2,m=i;
    if(l<n&&a[l]>a[m]) m=l;
    if(r<n&&a[r]>a[m]) m=r;
    if(m!=i){
        int t=a[i];
        a[i]=a[m];
        a[m]=t;
        heapify(a,n,m);
    }
}

void heapsort(int a[],int n,int inc){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--){
        int t=a[0];
        a[0]=a[i];
        a[i]=t;
        heapify(a,i,0);
    }
    if(!inc){
        for(int i=0;i<n/2;i++){
            int t=a[i];
            a[i]=a[n-i-1];
            a[n-i-1]=t;
        }
    }
}

int main(){
    int n,a[100],inc;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>inc;
    heapsort(a,n,inc);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
