//
//  main.c
//  ProgrammingExercise
//
//  Created by Park, Sabin - 0559 - MITLL on 5/26/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include <stdio.h>          // input/output
#include <stdbool.h>        // includes bool
#include <string.h>         // string handling functions
#include <math.h>           // math functions
#include <stdlib.h>

char UB_in[], LB_in[], AM_in[], BM_in[];
int UB, LB, AM, BM;

bool checkInt(char input[]) {
    
    int i = 0;
    bool isInt = true;
    
    if(input[0] == '-') {
        i++;
    }
    
    while(i < strlen(input)) {
        if((int)(input[i] - '0') >= 0 && (int)(input[i] - '0') <= 9) {
            i++;
        } else {
            isInt = false;
            break;
        }
    }
    
    return isInt;
}

void takeInputs() {
    
    int input_index = 0;
    
    printf("Please input the lower bound, upper bound, alpha multiple, and beta multiple.\n\n");
    
    while (input_index == 0) {
        printf("UPPER BOUND >\t\t");
        scanf("%s", UB_in);
        
        if(checkInt(UB_in)) {
            UB = atoi(UB_in);
            
            if(UB > INT16_MAX) {
                UB = INT16_MAX;
            }
            
            input_index++;
            
        } else {
            printf("\nINVALID. PLEASE TRY AGAIN.\n\n");
        }
    }
    while (input_index == 1) {
        printf("LOWER BOUND >\t\t");
        scanf("%s", LB_in);
        
        if(checkInt(LB_in)) {
            LB = atoi(LB_in);
            
            if(LB >= UB) {
                printf("\nINVALID. LB MUST BE LOWER THAN UB\n\n");
            } else if(LB < INT16_MIN) {
                LB = INT16_MIN;
            } else {
                input_index++;
            }
            
        } else {
            printf("\nINVALID. PLEASE TRY AGAIN.\n\n");
        }
    }
    while (input_index == 2) {
        printf("ALPHA MULTIPLE >\t");
        scanf("%s", AM_in);
        
        if(checkInt(AM_in)) {
            AM = atoi(AM_in);
            input_index++;
        } else if(AM == 0) {
            printf("\nINVALID. PLEASE CHOOSE NON-ZERO VALUE");
        } else {
            printf("\nINVALID. PLEASE TRY AGAIN.\n\n");
        }
    }
    while (input_index == 3) {
        printf("BETA MULTIPLE >\t\t");
        scanf("%s", BM_in);
        
        if(checkInt(BM_in)) {
            BM = atoi(BM_in);
            input_index++;
        } else if(BM == 0) {
            printf("\nINVALID. PLEASE CHOOSE NON-ZERO VALUE");
        } else {
            printf("\nINVALID. PLEASE TRY AGAIN.\n\n");
        }
    }

    printf("\nUB = %d\nLB = %d\nAM = %d\nBM = %d\n\n", UB, LB, AM, BM);
}

void printSolution(int UB, int LB, int AM, int BM) {
    
    if(LB < UB) {
        for(int i=LB; i<= UB; i++) {
            if(i%AM == 0 && i%BM == 0) {
                printf("ALPHABETA, ");
            } else if(i%AM == 0) {
                printf("ALPHA, ");
            } else if(i%BM == 0) {
                printf("BETA, ");
            } else
                printf("%d, ", i);
        }
    }

}

int main() {
    
    takeInputs();
    
    printSolution(UB, LB, AM, BM);
    
    return 0;
}


