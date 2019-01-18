//
//  Power.cpp
//  getPower(n, m) - return n^m
//
//  Created by Daheen Lee on 18/01/2019.
//  Copyright © 2019 Daheen Lee. All rights reserved.
//

#include <stdio.h>

int getPower(int n, int m) {
    // base condition
    if(m == 0)
        return 1;
    else
        return getPower(n, m-1) * n;
}

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    printf("%d\n", getPower(n, m));
}
