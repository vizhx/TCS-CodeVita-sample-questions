#include<iostream>
#include<bits/stdc++.h>
using namespace std;
static int currentcap;

int main(){
    int N,L;
    cin>>N;
    int cap[N];
    int freq[N];
    sort(cap,cap+N);
    fill(freq,freq+N,1);
    for(int i=0;i<N;++i){
        cin>>cap[i];
    }
    cin>>L;
    int matrix[N+1][L+1];
    int capM[N+1][L+1];
    for(int i=0;i<=N;++i){
        for(int j=0;j<=L;++j){
            if(i==0||j==0){
                matrix[i][j]=0;
                capM[i][j]=0;
                cout<<capM[i][j]<<" ";
                continue;
            }
            int prevf=matrix[i][j-1];
            int max=-1;
            int ind=0;
            for(int f=1;f<prevf+2;++f){
                int tempcap=cap[i-1]*(f);
                int prevInd=j-tempcap;
                if(prevInd>=0){
                    int k=capM[i-1][prevInd];                
                    
                    if((k>0||i==1)&&tempcap+k<=j){
                        if(tempcap+k>=max){
                            max=tempcap+k;
                            ind=f;
                        }
                    }
                }
            }
            if(max>0){
                capM[i][j]=max;
                matrix[i][j]=ind;
            }else{
                capM[i][j]=capM[i-1][j];
                matrix[i][j]=0;
            }
            cout<<capM[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<=N;++i){
        for(int j=0;j<=L;++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    int prev=L;
    for(int i=N-1;i>=0;--i){
        freq[i]=matrix[i+1][prev];
        prev=prev-cap[i]*freq[i];
        cout<<freq[i]<<" ";
    }
    return 0;
}