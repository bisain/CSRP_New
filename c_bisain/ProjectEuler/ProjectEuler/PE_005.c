//
//  PE_005.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/21/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"


int smallestMultiple(int max) {
    int num = 1;
    int i;
    bool done = false;
    bool isMultiple;
    
    while(!done) {
        
        isMultiple = true;
        
        for(i=1; i<=max; i++) {
            if(num%i != 0) {
                isMultiple = false;
                break;
            }
        }
        
        if(isMultiple) {
            done = true;
        } else {
            num++;
        }
        
    }
    
    return num;
}