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
vector<pair<string,bool>> tasks;
int com=0;
void Add(){
    fflush(stdout);
    cout <<"Enter task description: ";
    string t;
    getline(cin,t);
    getline(cin,t);
    tasks.push_back({t,false});
    cout<<"Task added successfully!\n";
}
void Remove(){
    if(tasks.size()==0) {
        cout << "NO tasks to remove!\n";
        return;
    }
    int t;
    cout<<"Enter task ID to remove: ";
    cin >> t;
    if(t<1||t>tasks.size()) {
        cout<<"Try Again!\n";
        Remove();
    }
    else{
        tasks.erase(tasks.begin()+t-1);
        cout<<"Task removed successfully!\n";
    }
}
void View(){
    int op;
    cout<<"1. All Tasks\n"
        <<"2. Completed Tasks\n"
        <<"3. Incompleted Tasks\n";
    cout << "Select an option: ";
    cin >> op;
    if(op<1||op>3) {
        cout<<"Try Again!\n";
        View();
    }
    else{
        if(tasks.size()==0||(op==2&&com==0)||(op==3&&com==tasks.size())) {
            cout << "NO tasks to view!\n";
            return;
        }
        cout<<left<<setw(10)<<"Task ID" << setw(50) << "Task Description" << setw(15) <<"Is Colmpleted" <<endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            if(op==1||(op==2&&tasks[i].second)||(op==3&&!tasks[i].second)){
                cout<<left<<setw(10)<< i+1 << setw(50) << tasks[i].first << setw(15) ;
                if(tasks[i].second)cout<<"YES"<<endl;
                else cout <<"NO"<<endl;
            }
        }
        
    }
}
void Mark(){
    if(tasks.size()==0) {
        cout << "NO tasks to Mark!\n";
        return;
    }
    int t;
    cout<<"Enter task ID to mark as completed: ";
    cin >> t;
    if(t<1||t>tasks.size()) {
        cout<<"Try Again!\n";
        Mark();
    }
    else{
        tasks[t-1].second=true;
        com++;
        cout<<"Task marked successfully!\n";
    }
}
int32_t main(){
    
    cout << "Minions Task Manager\n"
         <<"1. Add Task\n"
         <<"2. View Tasks\n"
         <<"3. Remove Task\n"
         <<"4. Mark Task As Completed\n"
         <<"5. Exit\n";
    int op;
    cout << "Select an option: ";
    while (cin>>op)
    {
        if(op>5||op<1)  cout<<"Try Again!\n";
        else if(op==5) return cout<<"Exiting Minions Task Manager. Have a great day!"<<endl,0;
        else if(op==1) Add();
        else if(op==2) View();
        else if(op==3) Remove();
        else if(op==4) Mark();
        cout << "Select an option:";
    }
    
    return 0;
}