//
//  main.c
//  Scratch
//
//  Created by Park, Sabin - 0559 - MITLL on 5/27/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include <stdio.h>          // input/output
#include <stdbool.h>        // includes bool
#include <string.h>         // string handling functions
#include <math.h>           // math functions
#include <stdlib.h>

int main() {

    char temp[1000];
    
    for(int i=0; i<1000; i++) {
        temp[i] = '0';
    }
    
    printf("%s", temp);
    
    return 0;
}
