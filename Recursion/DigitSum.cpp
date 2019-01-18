//
//  DigitSum.cpp
//  getDigitSum(x) - return sum of each digit of number x
//
//  Created by Daheen Lee on 18/01/2019.
//  Copyright © 2019 Daheen Lee. All rights reserved.
//

#include <stdio.h>

// add digit from the back of the number x
int getDigitSum(int x) {
    // base condition : if x is one digit(0~9)
    if(x >= 0 && x < 10 )
        return x;
    else
        return getDigitSum(x / 10) + x % 10;
}

int main() {
    int x;
    
    scanf("%d", &x);
    
    printf("Digint Sum of %d is %d\n", x, getDigitSum(x));
}
