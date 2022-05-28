//
//  WordFunctions.hpp
//  AcronymList
//
//  Created by Gus Maturana on 5/28/22.
//

#ifndef WordFunctions_hpp
#define WordFunctions_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class wordfunctions{
public:

    void letterCount (string str);
    int singleLetterCount(string phrase, char ltr);
    bool isLetter(char letter); // identifies if the character is a letter
    int wordFind(string str, string word); // Number of times a word is found in a string
    string toSmallLetters(string word); // converts all letters to small
    string toCapLetters(string word); // copitalize all letters
    string sortLetters(string word);  // sorts letters alpabetically
    string sortWords(string list); // sorts a list of words alpabetically
    string wordCompareResult(string s1, string s2); // to access protected function wordCompare
    string wordSort(string list); // sorts words alphabeitcally
    int wordCount(string str); // returns the number of words in a string
private:
    // implementation needed
    
protected:
    char toCapLtr(char ltr);
    char toSmallLtr(char ltr);
    void formatOutput(int n);
    void split(string str, char split);
    string wordCompare(string str1, string str2);
    // compare two words and return T or F is the first word is less than the second word
    bool wordsLessThan(string str1, string str2);
};

#endif /* WordFunctions_hpp */
