// Concepts
// Maths for Computer Science
// Basic Problems
// Check Even or Odd
// Multiplication Table
// Sum of Naturals
// Sum of Squares of Naturals
// Swap Two Numbers
// Closest Number
// Dice Problem
// Nth Term of AP
// Easy Problems
// Sum of Digits
// Reverse Digits
// Prime Testing
// Check Power
// Distance between Two Points
// Valid Triangle
// Overlapping Rectangles
// Factorial of a Number
// Pair Cube Count
// GCD or HCF
// LCM of Two Numbers
// Perfect Number
// Add Two Fraction
// Day of the Week
// Nth Fibonacci Number
// Decimal to Binary
// N-th term of 1, 3, 6, 10, 15, 21…
// Armstrong Number
// Palindrome Number
// Digit Root
// Medium Problems
// Square Root
// 3 Divisors
// Divisible by 4
// Divisibility by 11
// Divisibility by 13
// K-th Digit in a^b
// Fraction to Recurring Decimal
// Recurring Sequence in a Fraction
// Compute nPr
// Compute nCr
// Pascal’s Triangle
// All Factor (Or Divisors)
// Prime Factorization
// Largest Prime factor
// Modular Exponentiation
// nth Catalan Number
// Binomial Coefficient
// Power Set
// Next Permutation
// Hard Problems
// Sieve of Eratosthenes
// Clock Angle Problem
// Tower of Hanoi
// Rat and Poisoned
// 8 puzzle Problem
// Determinant of a Matrix
// Euler's Totient Function
// Josephus Problem
// Recommended Links

// Top Logic Building Interview Problems
// Practice Logic Building Problems
// Pattern Printing Problems
// Mathematical Algorithms

// _________________

// Concepts
// Maths for Computer Science
// Basic Problems

// Check Even or Odd

// #include <iostream>
// using namespace std;

// bool isEven(int n)
// {
//     // finding remainder of n
//     int rem = n % 2;
//     if(rem == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// int main()
// {
//     int n = 15;
//     if (isEven(n))
//         cout << "true";
//     else
//         cout << "false";

//     return 0;
// }

// #include <iostream>
// using namespace std;

// bool isEven(int n)
// {
//     // taking bitwise and of n with 1
//     if ((n & 1) == 0)
//         return true;
//     else
//         return false;
// }

// int main()
// {
//     int n = 15;
//     if (isEven(n) == true)
//         cout << "true";
//     else
//         cout << "false";

//     return 0;
// }

// Multiplication Table

// CPP program to print table of a number
// #include <iostream>
// using namespace std;

// void printTable(int n){
//     for (int i=1; i<= 10 ; ++i )
//         cout<< n<< "*"<< i<< "="<<n*i << endl ;

//         }

// int main() {
//     int n = 5;
//     printTable(n);
//     return 0;
// }

// Sum of Naturals
// m-1
// #include <iostream>
// using namespace std;

// int findSum(int n)
// {
//     int sum = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         sum = sum + i;
//     }
//     return sum;
// }
// int main()
// {
//     int n = 3;
//     cout << findSum(n);
//     return 0;
// }

// m-2
// #include <iostream>
// using namespace std;
// int findSum(int n)
// {

//     return n * (n + 1) / 2;
// }
// int main()
// {
//     int n = 5;
//     cout << findSum(n);

//     return 0;
// }

// Sum of Squares of Naturals
// Input : n = 8
// Output: 204
// Explanation :  1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2 + 7^2 + 8^2 = 204

// #include <iostream>
// using namespace std;

// int summation(int n){
//     int sum = 0;
//     for(int i=1 ; i<=n; i++){
//         sum +=(i*i);

//     }
//     return sum ;
// }

// int main(){
//     int n=2;
//     cout<< summation(n);
//     return 0;

// }

// m-2
// #include <iostream>
// using namespace std;

// int summation(int n){
//     return (n*(n+1)*(2*n+1))/6 ;
// return (n*(n+1)/2) *(2*n+1)/3 ;
// }

// int main (){
//     int n=10;
//     cout<<summation(n)<< endl;
//     return 0;

// }

// // Swap Two Numbers
// C++ Code to swap two numbers using third variable

// #include <iostream>
// using namespace std;

// int main() {
//     int a=2, b=3 ;
//     cout << "a="<< a<<  "b="<< b << endl ;

//     int temp =a ;
//     a=b ;
//     b= temp  ;

//     cout << "a="<< a<<  "b="<< b << endl ;
//     return 0 ;

// }

// // Closest Number

// #include <iostream>
// #include <climits>
// using namespace std;

// int closestNumber(int n, int m){
//     int closest = 0;
//     int minDifference = INT_MAX ;

//     for(int i = n-abs(m); i<=n+abs(m); ++i){
//         if(i%m==0){
//             int difference= abs(n-i);

//             if(difference < minDifference || (difference==minDifference && abs(i)> abs(closest))){
//                 closest =i;
//                 minDifference = difference;

//         }
//     }

// }
// return closest ;

// }

// int main(){
//     int n= 13 , m= 4 ;
//     cout<< closestNumber(n,m)<< endl;
//     return 0 ;

// }

// #include <iostream>
// #include <climits>
// using namespace std;

// int closestNumber(int n, int m)
// {
//     int q = n / m;
//     int n1 = m * q;

//     int n2 = (n * m) > 0 ? (m * (q + 1)) : (m * (q - 1));

//     if (abs(n - n1)  < abs(n-n2))
//         {
//             return n1;
//         }
//     return n2;
// }

// int main()
// {
//     int n = 13, m = 4;
//     cout << closestNumber(n, m) << endl;

//     return 0;
// }

// Dice Problem

// #include <iostream>
// using namespace std;

// int oppositeFaceOfDice(int n){
//     int ans;
//     if(n==1){
//         ans = 6;
//     }else if (n==2){
//         ans=5;

//     }else if(n==3){
//         ans =4;
//     }else if(n==4){
//         ans= 3;
//     }else if(n==5){
//         ans = 2;
//     }else{
//         ans=1;
//     }
//     return ans;

// }
// int main (){
//     int n=2;
//     cout<< oppositeFaceOfDice(n);
//     return 0;
// }

// #include <iostream>
// using namespace std ;
// int oppositeFaceOfDice(int n){
//     int ans=7-n;
//     return ans;

// }
// int main (){

//     int n=4 ;
//     cout << oppositeFaceOfDice(n)<<endl;

//     return 0;

// }

// Nth Term of

// Input : a1 = 1, a2 = 3, n = 10
// Output : 19
// Explanation:  The series is: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21..... Thus,10th term

// #include <iostream>
// using namespace std;

// int nthTermOfAP(int a1 ,int a2 ,int n){
//     int nthTerm= a1, d = a2-a1;
//     for(int i=1 ; i<n ; i++ ){
//         nthTerm +=d ;
//     }
//     return nthTerm;
// }

// int main(){
//   int a1=2 , a2=3 ;
//   int n=4;

//   cout<< nthTermOfAP(a1,a2,n);
//   return 0;

// }

// #include <iostream>
// using namespace std;

// int nthTermOfAP(int a1 ,int a2 ,int n){
//    return a1 + (n-1)*(a2-a1);
// }

// int main(){
//   int a1=2 , a2=3 ;
//   int n=4;
//   cout<< nthTermOfAP(a1,a2,n);
//   return 0;

// }

// ---------------->    Easy Problems     <------------------  //

// Sum of Digits

// #include <iostream>
// using namespace std;
// int sumOfDigit(int n)
// {
//     int sum = 0;
//     while (n != 0)
//     {
//         // extract the last digit
//         int last = n % 10;      // 1 % 10 = 1  // copy the last digit  
//         // add the last digit to sum
//         sum  += last;       // 

//         // remove the last digit
//         n = n / 10;              // 1 / 10 = 0    // remove the last digit 
//     }
//     return sum;
// }
// int main()
// {
//     int n = 123;
//     cout << sumOfDigit(n) << endl;
//     return 0;
// }



// #include <iostream>
// using namespace std ;
// int SumOfDigit(int n ){
//     if ( n == 0){
//         return 0 ;
//     }
//     return (n%10 )+ SumOfDigit(n/10);

// }   

// int main (){
//     int n=1234 ;
//     cout<< SumOfDigit(n);
//     return 0 ;
// }


// #include <iostream>
// using namespace std ;

// int  sumOfDigit(int n){

//     string s = to_string(n);
//     int sum = 0;

//     for(char ch : s){
//         sum += ch -'0';
//     }
//     return sum;
// }


// int main (){
//     int n= 1289834;
//     cout<< sumOfDigit(n)<< "      " ;
//     return 0;
// }







// Reverse Digits

// #include<iostream>
// using namespace std ;
// int reverseDigit(int n ){

//     int revNum = 0;
//     while (n>0){
//         revNum = revNum *10 + n%10 ;     //  n% 10 --> copy the last digit 
//         n=n/10 ;   // remove the last digit 
//     }
//     return revNum ;
// }


// int main (){
//     int n=4567 ;
//     cout<< reverseDigit(n);
//     return 0;
    
// }









// Prime Testing

// #include <iostream>
// using namespace std ;
// int  isPrime(int n){       // int / bool isPrime  --> it will work for both 
//     if (n <=1 )
//         return  false ;

//     // check from  i= 2  to  n-1 
//     for (int i =2 ;i< n ;i++ ){
//         if(n%i==0 ){
//             return false ;

//         }
        
//     }
//     return true ;
  
// }

// int main (){
//     isPrime(11) ? cout<< " true\n" : cout << " false\n";
//     isPrime(3) ? cout<< " true\n" : cout << " false\n";
//     isPrime(5) ? cout<< " true\n" : cout << " false\n";
//     isPrime(15) ? cout<< " true\n" : cout << " false\n";
//     return 0;
// }



// To print a list of primes in a range -------------------> extra 
#include <iostream>
using namespace std;

bool checkPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int low, high;
    cout << "Enter lower bound: ";
    cin >> low;
    cout << "Enter upper bound: ";
    cin >> high;

    cout << "Prime numbers between " << low << " and " << high << " are:\n";

    for (int i = low; i <= high; i++) {
        if (checkPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}

// Enter lower bound: 10
// Enter upper bound: 30
// Prime numbers between 10 and 30 are:
// 11 13 17 19 23 29






// Check Power   ------------------------------------------------->


// Distance between Two Points -------------------------------->
// Valid Triangle----------------------------------------------->
// Overlapping Rectangles----------------------------------------------->
// Factorial of a Number----------------------------------------------->
// Pair Cube Count----------------------------------------------->
// GCD or HCF----------------------------------------------->
// LCM of Two Numbers----------------------------------------------->
// Perfect Number----------------------------------------------->
// Add Two Fraction----------------------------------------------->
// Day of the Week----------------------------------------------->
// Nth Fibonacci Number----------------------------------------------->
// Decimal to Binary----------------------------------------------->
// N-th term of 1, 3, 6, 10, 15, 21…
// Armstrong Number
// Palindrome Number
// Digit Root
// Medium Problems
// Square Root
// 3 Divisors
// Divisible by 4
// Divisibility by 11
// Divisibility by 13
// K-th Digit in a^b
// Fraction to Recurring Decimal
// Recurring Sequence in a Fraction
// Compute nPr
// Compute nCr
// Pascal’s Triangle
// All Factor (Or Divisors)
// Prime Factorization
// Largest Prime factor
// Modular Exponentiation
// nth Catalan Number
// Binomial Coefficient
// Power Set
// Next Permutation
// Hard Problems
// Sieve of Eratosthenes
// Clock Angle Problem
// Tower of Hanoi
// Rat and Poisoned
// 8 puzzle Problem
// Determinant of a Matrix
// Euler's Totient Function
// Josephus Problem
// Recommended Links

// Top Logic Building Interview Problems
// Practice Logic Building Problems
// Pattern Printing Problems
// Mathematical Algorithms
