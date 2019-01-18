//
//  Factorial.cpp
//  getFacorial - recursion function
//
//  Created by Daheen Lee on 18/01/2019.
//  Copyright © 2019 Daheen Lee. All rights reserved.
//

#include <stdio.h>

int getFactorial(int n) {
    // base condition
    if(n == 0)
        return 1;
    else
        return getFactorial(n-1) * n;
}

int main() {
    int n;
    
    printf("n! - enter n: ");
    
    scanf("%d", &n);
    
    printf("%d\n", getFactorial(n));
}
