//
// GCD, LCM
// Euclidean Algorithm
// Input : two number
// Output : gcd & lcm of them
//

#include <iostream>
using namespace std;

int gcd1(int a, int b) {
    int r = a % b;
    
    while(r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    
    return b;
}

int gcd2(int a, int b) {
    return b ? gcd2(b, a % b) : a;
}

int lcm(int a, int b) {
    return a * b / gcd1(a, b);
}

int main() {
    
    int a, b;
    cin >> a >> b;
    
    if(a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    cout << "1) GCD " << gcd1(a, b) << endl;
    cout << "2) GCD " << gcd2(a, b) << endl;
    
    cout << "LCM " << lcm(a, b) << endl;
    
}
