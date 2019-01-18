//
//  Palindrome.cpp
//  isPalindrome(_string, _start, _end) - return ture if x is palindrome
//  * palindrome : a word which reads the same backward as forward, such as madam
//  Created by Daheen Lee on 18/01/2019.
//  Copyright © 2019 Daheen Lee. All rights reserved.
//

#include <stdio.h>
#include <string.h>

bool isPalindrome(char word[], int start, int end) {
    if(start == end) //if length of word is odd
        return true;
    else if(start + 1 == end) //if length of word is even
        return true;
    else
        return isPalindrome(word, start+1, end-1) &&
                    word[start] == word[end];
}

int main() {
    char word[100];
    
    scanf("%s", word);
    int len = strlen(word);
    
    if(isPalindrome(word, 0, len-1)) 
        printf("%s is palindrome.\n", word);
    else
        printf("%s is not palindrome.\n", word);
}
