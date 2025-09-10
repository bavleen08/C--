// FIBONACCI
// int n = 6;
// int first = 0, second = 1;
// cout << first << " "<< second<< " ";
// for(int i =2; i<n; i++){
//     int third = first + second;
//     cout << third<<" ";
//     first = second;
//     second = third;
// }
// cout << endl;

// WAF TO PRINT NTH FIBONACCI
void printNthFibonacci(int n) {
    if (n <= 0) {
        cout << "INVALID INPUT" << endl;
    }

    int a = 0, b = 1;
    if (n==1){
        cout << a << endl;
    } 
    if (n==2) {
        cout << b << endl;
    }

    int next;
    for(int i=3; i<=n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    cout << b << endl;
}