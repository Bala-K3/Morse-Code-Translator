#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(string text)
{
    for(auto i : text)
    {
        if(!((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9') || (i == ' ')))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    
    cout << "\n   --------------------------------------------------- Text to Morse code Convertor ------------------------------------------------\n";
    
    unordered_map<char, string> hash = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
        {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
        {'9', "----."}, {'0', "-----"}, {' ', "/"}
    };
    
    string text;
    cout << "\nEnter a text to covert to Morse code : ";
    getline(cin,text);
    
    
    if(text.empty())
    {
        cout << "Input cannot be empty.\n";
        return 0;
    }
    if(!isAlphaNumeric(text))
    {
        cout << "Input string must contain (alphabets or numericals or spaces).\n";
        return 0;
    }
    
    for(char &i : text)
    {
        i = toupper(i);
    }
    
    string morseCode = "";
    for(char &i : text)
    {
        if(hash.find(i) != hash.end())
        {
            morseCode += hash[i] + " ";
        }
    }
    
    if(!morseCode.empty())
    {
        morseCode.pop_back();
    }
    
    cout << "\nMorse Code : " << morseCode;
}