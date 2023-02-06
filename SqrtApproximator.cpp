#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long double approximator(long double num, long long decimals){
    long long integerNumLength, integerFinalLength;
    long double finalNum = 0;
    int operations = 0;
    
    if (num >= 1) {
        integerNumLength = to_string(int(num)).length();
        integerFinalLength = (integerNumLength - 1) / 2 + 1;
    }
    else {
        integerFinalLength = 0;
        integerNumLength = 0;
    }
    
    
    cout.precision(integerFinalLength+decimals);
    
    for (long long i = integerFinalLength; i >= -1*decimals; i--){
        long double multiplier = pow(10, i-1);
        
        for (long long d = 9; d > 0; d--){
            operations++;
            if (num >= pow(finalNum + d*multiplier, 2)){
                finalNum += d*multiplier;
                break;
            }
            if (abs(pow(finalNum, 2) - num) < pow(10, -1*(decimals + integerFinalLength))) break;
        }
    }
    cout << "Operations: " << operations << "\n";
    return finalNum;
}

int main() {
    long double num; long long decimals;
    cin >> num;
    //cin >> decimals;
    //cout << approximator (num, decimals);
    for (long long decimals = 0; decimals < 25; decimals++){
        cout << approximator(num, decimals) << "\n";
    }
}