//
//  PE_015.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/28/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"

// This method works for relatively small numbers
// Does NOT work for 20x20
long long getNumPaths(int x, int y) {
    long long answer;
    long long xyFactorial;
    long long xFactorial;
    long long yFactorial;
    // the answer is a simple combination of (x+y) choose x
    // (x+y)! / (x!)(y!)
    
    xyFactorial = x+y;
    
    xFactorial = x;
    
    yFactorial = y;
    

        for(long long i=xyFactorial-1; i>0; i--) {
            xyFactorial *= i;
        }
        
        for(long long i=xFactorial-1; i>0; i--) {
            xFactorial *= i;
        }
        
        for(long long i=yFactorial-1; i>0; i--) {
            yFactorial *= i;
        }
        
        answer = xyFactorial/(xFactorial*yFactorial);
    
    return answer;
}

// gets the sum of the squares of each value in each row
// ie, 3rd line is "1   2   1" and the output is 1^2 + 2^2 + 1^2 = 6
// also prints pascal's triangle
long long sumPascalsTriangle(int n)
{
    long long c, i, k;
    long long sum = 0;
    
    for(i=0; i <= n; i++) {
        
        sum = 0;
        
        c = 1;
        for(k=0; k <= i; k++) {
            
            sum += c*c;
            
            printf("%3lli ", c);
            c = c * (i-k)/(k+1);
        }
        printf("\n");
    }
    
    return sum;
}