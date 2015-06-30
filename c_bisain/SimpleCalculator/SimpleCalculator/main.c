//
//  main.c
//  projectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/20/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>


int getArgument(bool isLeft) {
    int vNum;
    
    if(isLeft) {
        printf("\nEnter first argument: ");
    } else {
        printf("\nEnter second argument: ");
    }
    
    scanf( "%d", &vNum );
    fpurge( stdin );
    
    return vNum;
}

int main() {
    
    int vFirstArg, vSecondArg;
    char vOperation;
    bool vFinished;
    
    // initialize the flag
    vFinished = false;
    
    // while loop...
    while(vFinished != true) {
        
        printf("What operation would you like to do?\t");
        scanf("%c", &vOperation);
        fpurge(stdin);
        
        if(vOperation == '+') {
            
            vFirstArg = getArgument(true);
            vSecondArg = getArgument(false);
            
            
            printf("\n%d + %d = %d\n\n\n", vFirstArg, vSecondArg, vFirstArg + vSecondArg);
            
        } else if(vOperation == '-') {
            
            vFirstArg = getArgument(true);
            vSecondArg = getArgument(false);
            
            printf("\n%d - %d = %d\n\n\n", vFirstArg, vSecondArg, vFirstArg - vSecondArg);
            
        } else if(vOperation == '*') {
            
            vFirstArg = getArgument(true);
            vSecondArg = getArgument(false);
            
            printf("\n%d * %d = %d\n\n\n", vFirstArg, vSecondArg, vFirstArg * vSecondArg);
            
        } else if(vOperation == '/') {
            
            vFirstArg = getArgument(true);
            vSecondArg = getArgument(false);
            
            printf("\n%d / %d = %d\n\n\n", vFirstArg, vSecondArg, vFirstArg / vSecondArg);
            
        } else
            vFinished = true;
        
    }
    
    
    printf("\n\nFinished.\n");
    
    return 0;
    
}







