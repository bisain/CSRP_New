//
//  PE_006.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/21/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"

long sumOfSquares(int max) {
    long sum = 0;
    
    for(int i=1; i<= max; i++) {
        sum += i*i;
    }
    
    return sum;
}

long squareOfSums(int max) {
    long square = 0;
    
    for(int i=1; i<=max; i++) {
        square += i;
    }
    
    square *= square;
    
    return square;
}

long differenceBetween(int square, int sum) {
    return squareOfSums(square) - sumOfSquares(sum);
}