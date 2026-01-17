#include <bits\stdc++.h>
using namespace std;

// Friends Pairing Problem    (GOLDMAN SACHS)
int findFriendsPair(int n){
    if(n==1 || n==2) return n;
    return findFriendsPair(n-1) + ((n-1) * findFriendsPair(n-2));
}

int main(){
    cout << findFriendsPair(3);
    return 0;
}

