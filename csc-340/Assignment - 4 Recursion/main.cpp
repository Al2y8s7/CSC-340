/*
 * Author: Alvin Nguyen
 * Assignment 4: Recursion
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/**
 * Problem # 1: Write a function that takes in a string and returns true if that string is a palindrome and false otherwise.
 * @return 
 */
bool isPalindrome(const string& input){
    string str = input;
    str.erase(remove(str.begin(),str.end(),' '),str.end());
    if (str.length() <= 1){
        return true;
    } else if (str[0] == str[str.size() -1]){
        return isPalindrome(str.substr(1, str.size() - 2));
    } else{
        return false;
    }
}

/**
 * Problem # 2: Write a function that takes an integer and returns the sum of its digits.   
 * @return 
 */

int digitSum(int input){
    int temp;
    int remainder;
    if(input >= 0 && input < 10){
        return input;
    }else{
        remainder = input % 10;
        temp = input / 10;
        return digitSum(temp) + remainder;        
    }
}

/**
 * Problem # 3: Write a function that takes a total number of stairs in the staircase and returns the number of ways to climb it.
 * @return 
 */

int waysToClimb(int numStairs){
    if(numStairs == 1){
        return 1;
    }
    if(numStairs <= 2){
        return 2;
    }else{
        return waysToClimb(numStairs - 1) + waysToClimb(numStairs - 2);
    }
}

int main() {
    //Test for problem # 1
    string input;
    cout << "Enter string: " << endl;
    getline(cin, input);
    if(isPalindrome(input)){
        cout << "String is a palindrome!" << endl;
    }else{
        cout << "String is not a palindrome!" << endl;
    }//end of test
    
    //Test for problem # 2
    int num;
    cout << "Enter integer: " << endl;
    cin >> num;
    cout << "Sum of " << num << " is " << digitSum(num) << endl;
    
    //Test of problem # 3
    int steps;
    cout << "Enter length of staircase: " << endl;
    cin >> steps;
    cout << "Ways to climb staircase: " << waysToClimb(steps);
    //end of test
    
    return 0;
}

