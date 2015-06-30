//
//  PE_003.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/21/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"

long long getLargestPrimeFactor(long long n) {
    long long myPrime = 0;
    long long i = 3;
    
    while(i*i <= (n/2)) {
        if(n%i == 0 && checkPrime(i)) {
            myPrime = i;
        }
        
        i++;
    }
    
    return myPrime;
}

bool checkPrime(long long n) {
    
    long long i;
    bool isPrime = true;
    
    for(i=2; i<n/2; i++) {
        if(n%i == 0) {
            isPrime = false;
            break;
        }
    }
    
    return isPrime;
}