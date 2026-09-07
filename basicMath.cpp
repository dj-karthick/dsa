#include <iostream>  // For input and output
#include <cmath>
#include <algorithm>
#include <vector>  
using namespace std;

void extractDigit(){
    int n;
    cin >> n;
    int digit = n;
    while(digit > 0){
        int lastDigit = digit % 10;
        digit = digit / 10;
        cout << lastDigit << endl;
    }
}

void countDigits(){
    int n;
    cin >> n;
    int count = 0;
    int sum = 0;
    while(n > 0){
        int lastDigit = n % 10;
        n = n/ 10;
        sum = sum + lastDigit;
        count++;
    }
    cout << "Count is :" << count << endl;
    cout << "Sum is :" << sum;
}

void reverseNumber(){
    int n;
    cin >> n;
    int rNum = 0;
    while(n > 0){
        int lastDigit = n % 10;
        n = n / 10;
        rNum = rNum * 10 + lastDigit;
    }
    cout << rNum;
}

void palindrome(){
    int n;
    cin >> n;
    int duplicate = n;
    int rNum = 0;
    while(duplicate > 0){
        int lastDigit = duplicate % 10;
        duplicate = duplicate / 10;
        rNum = rNum * 10 + lastDigit;
    }
    if(n == rNum) cout << n <<" is a palindrome.";
    else cout << n << " is not a Palindrome.";
}

void armstrongNum(){
    int n;
    cin >> n;
    int duplicate = n;
    int sum = 0;
    int count = (int)log10(n) + 1;
    while(n > 0){
        int lastDigit = n % 10;
        n = n / 10;
        sum = sum + pow(lastDigit, count);
        // cout << sum << endl;
    }
    if(sum == duplicate) cout << sum << ": It is Armstrong Number";
    else cout << sum << ": It is Not a Armstrong Number";
}

void printDivisors(){
    int n;
    cin >> n;
    vector<int> v;
    cout << "Divisors are: "<< endl;
//O(sqrt(n))
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
            if(n/i != i){
                v.push_back(n/i);
            }
        }
    }
//O(n logn) - n -> no of divisors or factors.
    sort(v.begin(), v.end());
//n -> O(n) - n -> no fo divisors or factors.
    for(auto it: v) cout << it << endl;
}

void primeNumber(){
    int n;
    cin >> n;
    int count = 0;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            count++;
            if(n/i != i){
                count++;
            }
        }
    }   
    if(count == 2) cout << "It is Prime Number.";
    else cout << "It is not a Prime Number.";
}

void gcdLinear(){
    int n1, n2;
    cin >> n1 >> n2;
    for(int i = min(n1, n2); i >= 1; i--){
        if(n1 % i == 0 && n2 % i ==0){
            cout << i;
            break;
        }
    }
}//O(min(n1, n2))

void gcdEquilateral(){
    int n1, n2;
    cin >> n1 >> n2;
    while(n1 > 0 && n2 > 0){
        if(n1 > n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }
    if(n1 == 0) cout << "GCD is : " << n2;
    else cout << "GCD is :" << n1;
}//O(log of pie of min(a, b))

int main() {
    // Your code here
    gcdEquilateral();
    return 0;
}

