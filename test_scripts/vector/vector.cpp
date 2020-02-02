#include <vector>
#include <iostream>
using namespace std;
int main(){
    vector<int> sites(5);
    sites.push_back(5);
    for(int x = 0; x < sites.size(); x++){
        cout << sites[x];
    }
    cout << endl;
    return 0;
}