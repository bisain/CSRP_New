//
//  PE_012.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/22/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"

// calculate triangle numbers
// 1 + 2 + 3 + ... + n = n*(n+1)/2

// for-loop that finds the factors (and the number of factors) for each triangle number
int triangleNumber(int divisors) {
    int myNum = 0;
    int tempIndex = 1;
    int temp = 1;
    bool done = false;
    
    while(!done) {
        
        temp = tempIndex*(tempIndex+1)/2;
        
        int numFactors = 2;
        
        // find number of factors for each triangle number
        for(int i=2; i<temp/i; i++) {
            if(temp%i==0) {
                numFactors += 2;
            }
        }
        
        tempIndex++;
        
        if (numFactors > divisors) {
            myNum = temp;
            done = true;
        }
    }
    
    return myNum;
}