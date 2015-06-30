//
//  PE_002.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/20/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"

long evenFibonacci(long max) {
    long sum = 0;
    long i = 0;
    bool done = false;
    
    while(!done) {
        
        long temp = fibonacci(i);
        
        if(temp > max) {
            done = true;
        }
        else if(temp % 2 == 0) {
            sum += temp;
        }
        
        i++;
    }
    
    return sum;
}

long fibonacci(long n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else if(n == 2) {
        return 2;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}