//
//  PE_004.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/21/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"


// multiply A and B such that A and B starts at 99, but as A is kept constant, B is decremented by 1
// the product of A and B will be found and then stored as a string, at which point I will use a function to check if it is a palindrome
// once B reaches 1, I will then reset B and decrement A by one
// once A and B both reach 1, I will output the current highest palindrome

int largestPalindromeProduct() {
    int a = 999;
    int b = 999;
    
    int i, j;
    
    int largest = 0;
    int temp;
    
    for(i=1; i<=a; i++) {
        for(j=1; j<=b; j++) {
            
            temp = i*j;
            
            if(isPalindrome(temp) && temp > largest) {
                largest = temp;
            }
        }
    }
    
    return largest;
}

// check if the number is a palindrome
// store the number in a temp variable
// take 1 digit at a time from the least significant digit and store in reverse
// if there are more digits to add, multiply reverse by 10, then add the new digit
// when temp is finally equal to 0, then return reverse

bool isPalindrome(int num) {
    int temp = num;
    int reverse = 0;
    
    while(temp != 0) {
        
        reverse *= 10;
        reverse += temp%10;
        temp /= 10;
        
    }
    
    if(num == reverse)
        return true;
    else
        return false;
}
