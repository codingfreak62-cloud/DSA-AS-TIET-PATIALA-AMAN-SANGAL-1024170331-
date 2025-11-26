#include <iostream>
using namespace std;

void selection(int a[], int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]) m=j;
        }
        int t=a[i]; a[i]=a[m]; a[m]=t;
    }
}

void insertion(int a[], int n){
    for(int i=1;i<n;i++){
        int x=a[i], j=i-1;
        while(j>=0 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

void bubble(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
        }
    }
}

void mergeArr(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[100], R[100];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        mergeArr(a,l,m,r);
    }
}

int part(int a[], int l, int r){
    int p=a[r], i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<p){
            i++;
            int t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }
    int t=a[i+1]; a[i+1]=a[r]; a[r]=t;
    return i+1;
}

void quick(int a[], int l, int r){
    if(l<r){
        int pi=part(a,l,r);
        quick(a,l,pi-1);
        quick(a,pi+1,r);
    }
}

int main(){
    int n, ch;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>ch;

    switch(ch){
        case 1: selection(a,n); break;
        case 2: insertion(a,n); break;
        case 3: bubble(a,n); break;
        case 4: mergeSort(a,0,n-1); break;
        case 5: quick(a,0,n-1); break;
        default: return 0;
    }

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
