//
//  WordFunctions.cpp
//  AcronymList
//
//  Created by Gus Maturana on 5/28/22.
//

#include "WordFunctions.hpp"
#include <iostream>
using namespace std;


// Function counts and returns the number of letter that are use in a sentence
void wordfunctions::letterCount (string str){
    int cnt = 0;
    // loop from a = 97 to z = 122
    for (int i = 97; i <= 122; i++){
        wordfunctions::formatOutput(cnt);
        // char(i-32) capitazlize letter
        cout << char(i - 32) << ": " <<wordfunctions::singleLetterCount(str, char(i))<< " ";
        cnt++;
    }
    cout << endl;
}
// Function is used to output letterCount
void wordfunctions::formatOutput(int n){
    if (n % 5 == 0)
    {
        cout << endl;
    }
    else
    {
        cout << "\t\t";
    }
}
// count the number of letters in a sentence
int wordfunctions::singleLetterCount(string str, char ltr){
    int cnt = 0;

    for (int i = 0; i < str.length(); i++){
        if (int(str[i]) == int(ltr) || int(str[i]) == int(toupper(ltr)) || (int(str[i])== (int(ltr) +32))){
            cnt++;
        }
    }
    return cnt;
}
// check if the character is a letter
bool wordfunctions::isLetter(char letter){
    bool rslt = false;
    int x = int(letter);
    // from 65-90 Capital Letters, from 97-122 small letters
    if((x >= 65 && x <= 90)||(x >= 97 && x <= 122)){
        rslt = true;
    }
    return rslt;
}
// it will count the number of times a word appears in a sentence, paragraph or file.
int wordfunctions::wordFind(string str, string word){
    int cnt = 0;
    string tmpWord = "";
    for (int i = 0; i < str.length(); i++){
        if(wordfunctions::isLetter(str[i])){
            tmpWord+=str[i];
        }
        else{
            string tmp = wordfunctions::toSmallLetters(tmpWord);
            tmpWord = "";
            if(tmp.compare(wordfunctions::toSmallLetters(word)) == 0){
                cnt++;
            }
        }
    }
    return cnt;
}
// Capitalizes all small letters
char wordfunctions::toCapLtr(char ltr){
    int tmp = 0;
    if(int(ltr)>= 97 && int(ltr) <=122)
        tmp =  int(ltr) - 32;
    if( int(ltr)>= 65 && int(ltr) <= 90)
        tmp = int(ltr);
    
    return char(tmp);
}
// It converts capital letters into small letters
char wordfunctions::toSmallLtr(char ltr){
    int tmp = 0;
    if(int(ltr) >= 97 && int(ltr) <= 122)
        tmp = int(ltr);
    if(int(ltr) >= 65 && int(ltr) <= 90)
        tmp = int(ltr) + 32;
    return char(tmp);
}
// It turns all capital letter in a word to small
string wordfunctions::toSmallLetters(string word){
    string rsl = "";
    for(int i = 0; i < word.length(); i++){
        rsl+=wordfunctions::toSmallLtr(word[i]);
    }
    return rsl;
}
// It capitalize all letters in a word
string wordfunctions::toCapLetters(string word){
    string rsl = "";
    for(int i = 0; i < word.length(); i++){
        rsl+=wordfunctions::toCapLtr(word[i]);
    }
    return rsl;
}
// short letters alpabetically (bubble sort algortihtm is used)
string wordfunctions::sortLetters(string word){
    int i, j;
    char tmp;
    for (i = 0; i < word.length(); i++)
    {
        // Last i elements are already in place
       for (j = i+1; j < word.length(); j++)
       {
           if (int(word[j]) < int(word[i])){
               tmp = word[i];
               word[i] = word[j];
               word[j] = tmp;
           }
       }
    }
    return word;
}
// Returns the smallest value word when it compares two words
string wordfunctions::wordCompare(string str1, string str2){
    string word;
    string w1 = "";
    string w2 = "";
    double size_ = 0;
    // compare two words and find out which one is greater
    if (str1 == str2){
        word = str1;
    }
    if (str1 != str2){
        if(str1.length() > str2.length()){
            size_ = str2.length();
        }
        else{
            size_ = str1.length();
        }
        // compares character by character
        for(int i = 0; i < size_; i++){
            // in case the characters are not equal
            if (int(str1[i]) != int(str2[i])){
                if(int(str1[i]) < int(str2[i])){
                    word = str1;
                    break;
                }
                else{
                    word = str2;
                    break;
                }
            }
            if (w1 == w2){
                if(str1.length() < str2.length()){
                    word = str1;
                    break;
                }
                else{
                    word = str2;
                    break;
                }
            }
            else {
                continue;
            }
            w1 += str1[i];
            w2 += str2[i];
        }
    }
    return word;
}
// to access wordCompare function since it is protected
string wordfunctions::wordCompareResult(string s1, string s2){
    return wordfunctions::wordCompare(s1,s2);
}
// Function return T or F depending if str1 is less than str2
bool wordfunctions::wordsLessThan(string str1, string str2){
    bool rsl = false;
    string word;
    string w1 = "";
    string w2 = "";
    double size_ = 0;
    // compare two words and find out which one is lower
    if (str1 == str2){
        rsl = true;
    }
    if (str1 != str2){
        if(str1.length() > str2.length()){
            size_ = str2.length();
        }
        if (str1.length() < str2.length()){
            size_ = str1.length();
        }
        if (str1.length() == str2.length()){
            size_ = str1.length();
        }
        // compares character by character
        for(int i = 0; i < size_; i++){
            // in case the characters are not equal
            if (int(str1[i]) != int(str2[i])){
                if(int(str1[i]) < int(str2[i])){
                    rsl = true;
                    break;
                }
                else{
                    rsl = false;
                    break;
                }
            }
            if ((w1 == w2) && (i+1 == size_)){
                if(str1.length() < str2.length()){
                    rsl = true;
                    break;
                }
                else{
                    rsl = false;
                    break;
                }
            }
            if(w1 != w2){
                continue;
            }
            if(int(str1[i]) == int(str2[i])){
                continue;
            }
            w1 += str1[i];
            w2 += str2[i];
        }
    }
    return rsl;
}
// counts how many word are there in a string
int wordfunctions::wordCount(string str){
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(int(' ') == int(str[i]) ){
            cnt++;
        }
    }
    return cnt + 1;
}
// use bubble sort to address sort the words alphabetically
// functions breaks the sentence into an array of strings and
// compares all words until it organize the words alphabetically
string wordfunctions::wordSort(string list){
    int cnt = 0;
    int size = wordfunctions::wordCount(list);
    string word[size];
    string tmp = "";
    
    // assigns the words to the array
    // length of list + 1 since we have to get the null char at the end of the string
    for (int i = 0; i < list.length()+1; i++){
        if(wordfunctions::isLetter(list[i])){
            tmp += list[i];
        }
        else{
            if(tmp != ""){
                word[cnt] = tmp;
                tmp = "";
                cnt++;
            }
        }
    }
    // loops through the whole aray and compare words
    for (int i = 0; i < size; i++) {
        // Last i elements are already in place
       for (int j = i+1; j < size; j++)
       {
           // wordsLessThan return true if word1 is less than word2
           if (wordfunctions::wordsLessThan(word[j], word[i])){
               tmp = word[i];
               word[i] = word[j];
               word[j] = tmp;
           }
       }
    }
    list = "";
    for (int i = 0; i < size; i++){
        list += word[i] + "\n";
    }
    return list;
}
// printlinked list class

