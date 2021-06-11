#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int power(int base, int pow){
    int result = 1;
    while(pow > 0) {
        if(pow % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base);
        }
        base = (base * base);
        pow = pow / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}
int main()
{
    int R;
    cin >> R; cin.ignore();
    int V;
    cin >> V; cin.ignore();
    int C;
    int N;
    int vtime[20];//the time needed for each vault
    for (int i = 0; i < V; i++) {

        cin >> C >> N; cin.ignore();
        vtime[i] = power(10,N) * power(5,C-N);//determine time needed for each vault
    }

    
    int robbers[R];
    for (int i = 0; i < R; i++)
    {
        robbers[i] = vtime[i];
        //cout << "robbers" << i << " " << robbers[i] << endl;
    }

    for (int i = R; i < V; i++)
    {
        sort(robbers, robbers+R);
        robbers[0]+=vtime[i];
    }

    sort(robbers, robbers+R);
    cout <<robbers[R-1]<< endl;  
}