// 1. PATTERN PRINTING
// int n = 6;
// for(int i=1 ; i<=n; i++) {
//     for(int j=1 ; j<=n; j++){
//         cout << j;
//     }
//     cout << endl;
// }
// return 0;

// 2. PRINTING CHARACTERS
// int n = 6;
// for(int i=0 ; i<n; i++) {
//     char ch = 'A';
//     for(int j=0 ; j<n; j++){
//         cout << ch;
//         ch = ch + 1;
//     }
//     cout << endl;
// }
// return 0;

// 3. PRINTING CONTINUOUS
// int n = 4;
// int num = 1;
// for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//         cout << num << " ";
//         num++;
//     }
//     cout << endl;
// }
// cout << "after pattern:"<< num;
// return 0;

// 4. PRINTING CONTINUOUS ABC
// int n = 3;
// char ch = 'A';
// for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//         cout << ch << " ";
//         ch = ch + 1;
//     }
//     cout << endl;
// }
// cout << "after pattern:"<< ch;
// return 0;

// 5. PRINTING TRIANGLE PATTERN 
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++){
//         cout << '*';
//     }
//     cout << endl;
// }
// return 0;

// 6. PRINTING TRIANGLE PATTERN WITH NUMBERS
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++){
//         cout << (i+1);
//     }
//     cout << endl;
// }
// return 0;

// 7. PRINTING TRIANGLE PATTERN WITH CHARACTERS REPITITIVE
// int n = 4;
// for(int i=0; i<n; i++) {
//     char ch = 'A'+ i;
//     for(int j=0; j<i+1; j++){
//         cout << ch << " ";
        
//     }
//     cout << endl;
// }
// return 0;

// 8. PRINTING TRIANGLE PATTERN WITH NUMBERS 1,12,123...
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j=1; j<=i+1; j++){
//         cout << j;
//     }
//     cout << endl;
// }
// return 0;

// 9. PRINTING REVERSE TRIANGLE
// int n = 4;
// for(int i=0; i<n; i++) {
//     for(int j= i+1; j>0; j--) {
//         cout << j << " ";
//     }
//     cout << endl;
// }

// 10.  FLOYDS TRIANGLE WITH NUMBERS
// int n = 4;
// int num = 1;
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++) {
//         cout << num << " ";
//         num++;    
//     }
//     cout << endl;
// }

// 11. FLOYDS TRIANGLE WITH CHARACTERS
// int n = 4;
// char ch = 'A';
// for(int i=0; i<n; i++) {
//     for(int j=0; j<i+1; j++) {
//         cout << ch << " ";
//         ch++;    
//     }
//     cout << endl;
// }

// 12. REVERSE TRIANGLE WITH NUMBERS
// int n = 4;
// char ch ='a';
// for(int i=0; i<n; i++) {
//     char temp = ch;
//     for(int j= i+1; j>0; j--) {
//         cout << temp-- << " ";
//         //cout << temp;

//     }
//     ch++;
//     cout << endl;
// }

// 13. INVERTED TRIANGLE WITH NUMBERS
// int n = 4;
// for(int i=0; i<n; i++) {
//     //spaces
//     for(int j=0; j<i; j++) {
//         cout << " ";
//     }
//     //nums
//     for(int j=0; j<n-i; j++) {
//         cout << (i+1);
//     }
//     cout << endl;
// }

// 14. INVERTED TRIANGLE WITH CHARACTERS
// int n = 5;
// char ch = 'A';
// for(int i=0; i<n; i++) {
//     //spaces
//     for(int j=0; j<i; j++) {
//         cout << " ";
//     }
//     //nums
//     for(int j=0; j<n-i; j++) {
//         cout << ch;
//         ch++; //<-- HERE: increases in every loop (so every character changes)  
//     }
//     ch++; //<-- HERE: increases once per row (so whole row has same character)
//     cout << endl;
// }

// 15. PYRAMID PATTERN
// int n = 4;
// for(int i=0; i<n; i++) {
//     //spaces: n-i-1
//     for(int j=0; j<n-i-1; j++){
//         cout << " ";
//     }
//     //nums1: 1 to i+1
//     for(int j=1; j<=i+1; j++){
//         cout << j;
//     }
//     //nums2
//     for(int j=i; j>=1; j--){
//         cout << j;
//     }
//     cout << endl;
// }
// return 0;

// 16.HOLLOW DIAMOND PATTERN
// int n = 4;

//top part
// for(int i=0; i<n; i++){
//     // leading spaces
//     for(int j=0; j<(n-i-1); j++){ //my mistake- i wrote j<=(n-i-1) which affect the position of middle star
//         cout << " ";
//     }
//     cout << "*"; // first star //my mistake- i wrote this inside the inner loop which printed stars inside the spaces

//     if(i!=0){
//     //internal spaces
//     for(int j=0; j<(2*i-1); j++){
//         cout << " ";
        
//     }
//     cout << "*"; // second star

//     }
//     cout << endl;   
// }
// //bottom part
// for(int i=0; i<n-1; i++){ // 0 to n-2

//     //leading spaces
//     for(int j=0; j<i+1; j++){
//         cout << " ";
//     }
//     cout << '*';

//     //internal spaces
//     if(i!=n-2){ //my mistake- i wrote n-1 Ab i goes from 0 to n-2. So i != n-1 is always true in this loop. Even at the last iteration i = n-2, it's still i != n-1.
//         for(int j=0; j<(2*(n-i)-5); j++){
//             cout << " ";
//         }
//         cout << '*';
//     }
//     cout << endl;
// }
// return 0;

// 17. BUTTERFLY PATTERN
// int n = 6;

// //top part
// for(int i=0; i<n; i++){

//     // left triangle
//     for(int j=0; j<i+1; j++){
//         cout << '*';
//     }

//     // internal spaces
//     for(int j=0; j<2*(n-i)-2; j++){ //my mistake- i used 2*3-i which is not related to n so we need to related formula with n otherwise when n will n chnage this wont work. This is hardcoded for n = 4 using the number 3. That works only when n = 4, because 2 * (3 - i) gives internal spaces from 4 to 0, matching the required spacing for n=4. But this will break if n is changed, and is not scalable.
//         cout << " ";
//     }

//     // right triangle
//     for(int j=0; j<i+1; j++){
//         cout << "*";
//     }
//     cout << endl;    
// }

// //bottom part
// for(int i=0; i<n; i++){

//     // left inverted triangle
//     for(int j=0; j<n-i; j++){ // if j is initiated with 1 then only we will write j<=n-i
//         cout << "*";
//     }

//     // internal spaces
//     for(int j=0; j<2*i; j++){
//         cout << " ";
//     }
    
//     // right inverted triangle
//     for(int j=0; j<n-i; j++){
//         cout << "*";
//     }
//     cout << endl;   
// }
// return 0;

// HOLLOW RECTANGLE
// int n = 10; 
// for(int i=1; i<=n; i++){
//     cout << "*";
//     for(int j=1; j<=n-1;j++){
//         if(i == 1 || i == n){
//             cout << "*";
//         } else{
//             cout << " ";
//         }
        
//     }
//     cout << "*";
//     cout << endl;
// }

// INVERTED STAR PATTERN
// int n=4;
// for(int i=1; i<=n; i++){
//     for(int j=1; j<=n-i; j++){
//         cout << " ";
//     }
//     for(int j=1; j<=i; j++){
//         cout << "*";
//     }
//     cout << endl;
// }

// DIAMOND PATTERN
// int n = 4;
// for(int i=1; i<=n; i++){
//     for(int j=1; j<=n-i; j++){
//         cout << " ";
//     }
//     for(int j=1; j<=(2*i)-1; j++){
//         cout << "*";
//     }
//     cout << endl;
// }
// for(int i=n; i>=1; i--){
//     for(int j=1; j<=n-i; j++){
//         cout << " ";
//     }
//     for(int j=1; j<=(2*i)-1; j++){
//         cout << "*";
//     }
//     cout << endl;
// }

// int n=4;
// //top part
// for(int i=1; i<=n; i++){
//     for(int j=1; j<=i; j++){
//         cout << "*";
//     }
//     for(int j=1; j<=2*(n-i); j++){
//         cout << " ";
//     }
//     for(int j=1; j<=i; j++){
//         cout << "*";
//     }
//     cout << endl;
// }
// //bottom part
// for(int i=n; i>=1; i--){
//     for(int j=1; j<=i; j++){
//         cout << "*";
//     }
//     for(int j=1; j<=2*(n-i); j++){
//         cout << " ";
//     }
//     for(int j=1; j<=i; j++){
//         cout << "*";
//     }
//     cout << endl;
// }
//cout << next('x');

// TRIANGLE PATTERN WITH 01
// int n=5;
// bool val = true;
// for(int i=1; i<=n; i++){
//     for(int j=1; j<=i; j++){
//         cout << val;
//         val = !val;
//     }
//     cout << endl;
// }

// RHOMBUS PATTERN
// int n = 5;
// for(int i=1; i<=n; i++){
//     for(int j=1; j<=n-i; j++){
//         cout << " ";
//     }
//     for(int j=1; j<=n; j++){
//         cout << "*";
//     }
//     cout << endl;
// }

// for(int i=n; i>0; i--){
//     for(int j=1; j<=i; j++){
//         cout << " ";
//     }
//     for(int j=1; j<=n; j++){
//         cout << "*";
//     }
//     cout << endl;
// }

// PALINDROMIC PATTERN WITH NUMBERS
// int n=6; 
// for(int i=1; i<=n; i++){
//     // spaces
//     for(int j=1; j<= n-i; j++){
//         cout << " ";
//     }
//     // backward nums
//     for(int j=i; j>=1; j--){
//         cout << j;
//     }
//     // forward nums
//     for(int j=2; j<=i; j++){
//         cout << j;
//     }
//     cout << endl;
// }