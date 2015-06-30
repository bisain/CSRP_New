//
//  PE_007.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/21/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"

// gets the nth prime (2, 3, 5, 7, ... )
long getPrime(int n) {
    
    long i = 1;
    long myPrime = 0;
    long temp = 0;
    
    // while i haven't found the nth prime number...
    while(i <= n) {
        
        if(isPrime(temp)) {
            i++;
            myPrime = temp;
        }
        
        temp++;
    }
    
    return myPrime;
}

// returns true if the number is a prime, else false
bool isPrime(long n) {
    
    long i;
    bool isPrime = true;
    
    
    
    for(i=2; i<=n/2; i++) {
        if(n%i == 0) {
            isPrime = false;
            break;
        }
    }
    
    if(n <= 1) {
        isPrime = false;
    }
    
    return isPrime;
}

// output the first 7 primes...
/*
 for(int i=1; i<=7; i++) {
 printf("Prime %d is \t%li\n", i, getPrime(i));
 }
 */
