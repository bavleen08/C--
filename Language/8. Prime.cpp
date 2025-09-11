#include <iostream>
#include <cmath>
using namespace std;

// ALL PRIME NUMBERS FROM 2 TO N
bool isPrime(int n){
    if(n==1){
        return false;
    }
    for(int i=2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void allprime(int n){
    for(int i=2; i<=n; i++){
        if (isPrime(i)){
            cout << i <<endl;
        }
    }
    
}

int main(){
    // if prime or not
    // int n;
    // cout << "enter n: ";
    // cin >> n;
    // int i;
    // for(i=2; i*i<=n; i++){ //i<=n-1 //O(underroot n approach) another way  2to n-1
    //     if(n%i==0){
    //         cout << "It is non prime";
    //         //break;
    //     } else{
    //         cout << "It is prime";
    //         //break;
    //     }
    // }

//  PRIME OR NOT
// int n;
// cin >> n;
// bool isPrime = true;
// for(int i = 2; i <= sqrt(n); i++){
//     if(n % i == 0){
//         isPrime = false;
//         break;
//     } 
// }
// if (isPrime){
//     cout << "PRIME";
// } else {
//     cout << "NOT PRIME";
// }

// PRIME
// int n;
// cin >> n;
// for(int i =2; i <= n; i++){
//     int curr = i;
//     bool isPrime = true;
//     for(int j=2; j*j<=i; j++){
//         if(curr % j ==0){
//             isPrime = false;
//         }
//     }
//     if(isPrime){
//     cout << curr << " ";
// }
// }
return 0;
}


