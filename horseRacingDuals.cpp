#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
    int N;// number of horses
    cin>>N;
    int horses[N];
    int diff = 10000000;
    for (int i = 0; i < N; i++)
    {
        cin>>horses[i];  
    }

    /*for (int i = 0; i < N-1; i++)too slow
    {
        for (int j = i+1; j < N; j++)
        {
            if (abs(horses[i]-horses[j]) < diff)
            {
               diff = abs(horses[i]-horses[j]);
            }
            
        }
        
    }*/
    sort(horses, horses+N);
    for (int i = 0; i < N-1; i++)
    {
        if((horses[i+1]-horses[i]) < diff)
            diff = horses[i+1]- horses[i];
    }
    
    cout<<diff<<endl;
}