//
//  PE_001.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/20/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"

int sumOfMultiples(int a, int b, int max) {
    int sum = 0;
    int i;
    
    for(i=0; i<max; i++) {
        if(i%a == 0 || i%b == 0) {
            sum += i;
        }
    }
    
    return sum;
}