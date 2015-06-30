//
//  PE_010.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/22/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"

// find the sum of all primes below two million
// first generate list of primes below 2 million
// return the sum of those primes
// use long

long sumOfPrimes(long max) {
    long sum = 0;
    
    long temp = 0;
    
    while(temp < max) {
        
        if(isPrime(temp)) {
            sum += temp;
        }
        
        temp++;
    }
    
    return sum;
}