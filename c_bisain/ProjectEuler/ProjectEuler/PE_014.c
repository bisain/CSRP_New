//
//  PE_014.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/27/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"


// n --> n/2 (n is even)
// n --> n*3 + 1 (n is odd)

// which starting number under one million produces the longest chain?

/*
    Returns the number of sequences (starting number inclusive) for the Collatz Sequence
 */
int numChains(long num) {
    int chains = 1;
    long bigNum = num;
    
    while (bigNum != 1) {
        // EVEN
        if(bigNum%2 == 0) {
            bigNum = bigNum/2;
            chains++;
        }
        // ODD
        else {
            bigNum = bigNum*3+1;
            chains++;
        }
    }
    
    return chains;
}

// let's start with a function that returns the longest chain from numbers 1 to 10
long getLongestChain(long max) {
    long myNum = 0;
    
    long temp;
    
    for(int i=1; i<max; i++) {
        temp = numChains(i);
        
        if(temp > myNum) {
            myNum = temp;
            printf("Current num: %d\n", i);
        }
    }
    
    return myNum;
}