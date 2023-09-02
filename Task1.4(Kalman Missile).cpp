#include <bits/stdc++.h>
#include <iostream>
#include <string>
#define all(v)      ((v).begin()), ((v).end())
#define rall(v)     ((v).rbegin()), ((v).rend())
#define fori(i,x,n)   for(int i=x; i<n; i++)
#define unq(v)      sort(all(v));v.resize(distance(v.begin(),unique(v.begin(), v.end())));
#define int long long 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<float> gh(vector<float> pred,vector<float> mes,float acc){
    vector<float> h(10);
    fori(i,0,10){
        float r = mes[i]-pred[i];
        h[i] = pred[i] + acc*r;
    }
    return h;
}
int32_t main(){
    vector<float> mpu6050 = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    vector<float> bno55 = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    vector<float> predicted(10),avg(10),acc_avg(10),gh_mp(10),gh_bn(10),gh_both(10);
    float t=0.0,v0=30.0,a=46.0;
    fori(i,0,10) avg[i] = (mpu6050[i]+bno55[i])/2.0;
    fori(i,0,10) acc_avg[i] = (mpu6050[i]*0.79+bno55[i]*0.92)/(0.79+0.92);
    for (int i = 0; i < 10; i++,t+=0.5) predicted[i] = v0*sin(a*M_PI/180)*t - 0.5*t*t*9.8;
    gh_mp=gh(predicted,mpu6050,0.79);
    gh_bn=gh(predicted,bno55,0.92);
    gh_both=gh(predicted,acc_avg,(0.79+0.92)/2.0);
    cout<<left<<setw(23)<<"Normal Average: ";
    fori(i,0,10) cout<<left<<setw(10)<<avg[i]<< " ";
    cout<<endl<<endl;
    cout<<left<<setw(23)<<"Average Based On Acc: ";
    fori(i,0,10) cout<<left<<setw(10)<<acc_avg[i]<< " ";
    cout<<endl<<endl;
    cout<<left<<setw(23)<<"Predicted: ";
    fori(i,0,10) cout<<left<<setw(10)<<predicted[i]<< " ";
    cout<<endl<<endl;
    cout<<left<<setw(23)<<"GH mpu: ";
    fori(i,0,10) cout<<left<<setw(10)<<gh_mp[i]<< " ";
    cout<<endl<<endl;
    cout<<left<<setw(23)<<"GH bno: ";
    fori(i,0,10) cout<<left<<setw(10)<<gh_bn[i]<< " ";
    cout<<endl<<endl;
    cout<<left<<setw(23)<<"GH on both: ";
    fori(i,0,10) cout<<left<<setw(10)<<gh_both[i]<< " ";

}