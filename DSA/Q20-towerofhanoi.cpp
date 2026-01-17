#include <iostream>
using namespace std;

// You have 3 towers and N disks of different sizes which can slide on to any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e.,each disk sits on top of an even larger one).You have the following constraints:(1)Only one disk can be moved at a time . (2)A disk is slid off the top of one to werontoanothertower.(3)Adiskcannotbeplacedontopofasmallerdisk.WriteaprogramtomovethedisksfromthefirsttowertothelastusingStacks
void towerOfHanoi(int n, string src, string helper, string dest){
    if(n==1){
        cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;
        return;
    }
    towerOfHanoi(n-1, src, dest, helper);
    cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;

    towerOfHanoi(n-1, helper, src, dest);  
}

int main(){
    int n = 4;
    towerOfHanoi(n, "S", "H", "D");
    return 0;
}