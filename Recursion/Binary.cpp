//
//  Binary.cpp
//  printBinary(x) : print bianry number of x
//
//  Created by Daheen Lee on 18/01/2019.
//  Copyright © 2019 Daheen Lee. All rights reserved.
//

#include <stdio.h>

void printBinary(int x) {
    if(x == 0 || x == 1)
        printf("%d", x);
    else {
        printBinary(x / 2);
        printf("%d", x % 2);
    }
}

int main() {
    int x;
    
    scanf("%d", &x);
    
    printBinary(x);
}

