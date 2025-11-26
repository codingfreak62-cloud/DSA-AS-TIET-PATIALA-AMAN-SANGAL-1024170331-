#include <iostream>
using namespace std;

class PQ{
public:
    int a[100];
    int sz;
    PQ(){sz=0;}
    void push(int v){
        a[sz]=v;
        int i=sz;
        sz++;
        while(i>0){
            int p=(i-1)/2;
            if(a[p]<a[i]){
                int t=a[p];
                a[p]=a[i];
                a[i]=t;
                i=p;
            }else break;
        }
    }
    void heapify(int i){
        int l=2*i+1,r=2*i+2,m=i;
        if(l<sz&&a[l]>a[m]) m=l;
        if(r<sz&&a[r]>a[m]) m=r;
        if(m!=i){
            int t=a[i];
            a[i]=a[m];
            a[m]=t;
            heapify(m);
        }
    }
    void pop(){
        if(sz==0) return;
        a[0]=a[sz-1];
        sz--;
        heapify(0);
    }
    int top(){
        if(sz==0) return -1;
        return a[0];
    }
};

int main(){
    PQ pq;
    int ch,v;
    cin>>ch;
    switch(ch){
        case 1:
            cin>>v;
            pq.push(v);
            cout<<pq.top();
            break;
        case 2:
            pq.pop();
            if(pq.sz) cout<<pq.top();
            break;
        case 3:
            cout<<pq.top();
            break;
    }
}
