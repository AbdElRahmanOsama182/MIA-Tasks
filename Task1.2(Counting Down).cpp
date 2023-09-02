#include <bits/stdc++.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    while (n)
    {
        cout << n-- << endl;
        Sleep((DWORD)1000);
    }
    cout<<"Blast off to the moon!";
    
}