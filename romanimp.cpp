
//Roman Number Implementation file

#include <iostream> 
#include <string>
#include "roman.h"
 
using namespace std;


romanType::romanType(){
    num = 1;
    romanNum = "I";
}

romanType::romanType(string roman){
    setRoman(roman);
}

romanType::romanType(int value){
    setRoman(value);
}

void romanType::setRoman(string roman){
    romanNum = roman;
    romanToPositiveInteger();
}

void romanType::setRoman(int value){
    num = value;
    romanNum = intToRoman(num);
}

void romanType::romanToPositiveInteger(){
    int newNum = 0;

    for(int i = 0; i < romanNum.length(); i++){
        if(romanNum[i] == 'M'){
            newNum += 1000;
        }
        if(romanNum[i] == 'C' && romanNum[i+1] == 'M'){
            newNum += 900;
            i++;
        }
        if(romanNum[i] == 'D'){
            newNum += 500;
        }
        if(romanNum[i] == 'C' && romanNum[i+1] == 'D'){
            newNum += 400;
            i++;
        }
        if(romanNum[i] == 'C'){
            newNum += 100;
        }
        if(romanNum[i] == 'X' && romanNum[i+1] == 'C'){
            newNum += 90;
            i++;
        }
        if(romanNum[i] == 'L'){
            newNum += 50;
        }
        if(romanNum[i] == 'X' && romanNum[i+1] == 'L'){
            newNum += 40;
            i++;
        }
        if(romanNum[i] == 'X'){
            newNum += 10;
        }
        if(romanNum[i] == 'I' && romanNum[i+1] == 'X'){
            newNum += 9;
            i++;
        }
        if(romanNum[i] == 'V'){
            newNum += 5;
        }
        if(romanNum[i] == 'I' && romanNum[i+1] == 'V'){
            newNum += 4;
            i++;
        }
        if(romanNum[i] == 'I'){
            newNum += 1;
        }
    }
    
    num = newNum;
}

void romanType::printPositiveInteger() const{
    cout << num << endl;
}

void romanType::printRoman() const{
    cout << romanNum << endl;
}

string romanType::getRoman(){
    return romanNum;
}

int romanType::getValue(){
    return num;
}

void romanType::inc(){
    num++;
    romanNum = intToRoman(num);
}

void romanType::dec(){
    num--;
    romanNum = intToRoman(num);
}

    void romanType::add(romanType r){
        num += r.getValue();
        romanNum = intToRoman(num);
    }

void romanType::add(int n){
    num += n;
    romanNum = intToRoman(num);
}

string romanType::intToRoman(int n){
    string result = "";

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for(int j = 0; j < 13; j++){
        while(n >= values[j]){
            result.append(numerals[j]);
            n -= values[j];
        }
    }

    return result;
}