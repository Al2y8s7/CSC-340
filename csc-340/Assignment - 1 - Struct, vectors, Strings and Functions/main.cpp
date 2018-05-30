#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Part I
 * @param oldDate
 * @return 
 */
string ReformatDate(string oldDate){
    string year;
    string month;
    string day;
    //get Month
    month.push_back(oldDate[0]);
    month.push_back(oldDate[1]);
    month.push_back(oldDate[2]);
    //get day
    string temp;
    int iterator = 4;
    char s = oldDate[iterator];
    while(s != ' '){
        temp.push_back(s);
        iterator++;
        s = oldDate[iterator];
        day = temp;
    }
    temp = "";
    //get year
    iterator += 1;
    char q = oldDate[iterator];
    while(q != '\0'){
        temp.push_back(q);
        iterator++;
        q = oldDate[iterator];
        year = temp;
    }
    cout << year + "-" << month + "-" << day << endl;
    
     return oldDate;
}

/**
 * Part II
 * @param a
 * @param b
 * @param c
 * @param d
 * @return 
 */
//find max time and sort
 string maxTime(int a, int b, int c, int d){
     vector <int> oldList; 
     vector <int> newList;
     bool flag = true;
     int size = oldList.size();
     int temp;
     oldList.push_back(a);
     oldList.push_back(b);
     oldList.push_back(c);
     oldList.push_back(d);
     //check 1st position for 2, 1, 0
     for(int i= 0; i < oldList.size(); i++){
         if(oldList[i] == 2){
             temp = oldList[i];
             newList.push_back(oldList[i]);
             oldList.erase(oldList.begin() + i);
             flag = true;
             i = 5;
             continue;
         }else if(oldList[i] == 1){
             temp = oldList[i];
             newList.push_back(oldList[i]);
             oldList.erase(oldList.begin() + i);
             flag = true;
             i = 5;
             continue;
         }else if(oldList[i] == 0){
             temp = oldList[i];
             newList.push_back(oldList[i]);
             i = 5;
             flag = true;
             continue;
         }else{
             flag = false;
         }
     }
         //check 2nd position for 3, 2 ,1, 0
         for(int i = 0; i < oldList.size(); i++){
             if(oldList[i] == 3){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 i = 5;
                 flag = true;
             }else if(oldList[i] == 2){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 i = 5;
                 flag = true;
             }else if(oldList[i] == 1){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 i = 5;
                 flag = true;
             }else if(oldList[i] == 0){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 i = 5;
                 flag = true;
             }else{
                 flag = false;
             }
         }
         //check 3rd position for 5, 4, 3, 2, 1, 0
         for(int i = 0; i < oldList.size(); i++){
             if(oldList[i] == 5){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 i = 5;
                 flag = true;
             }else if(oldList[i] == 4){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 flag = true;
                 i = 5;
             }else if(oldList[i] == 3){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 flag = true;
                 i = 5;
             }else if(oldList[i] == 2){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 flag = true;
                 i = 5;
             }else if(oldList[i] == 1){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 flag = true;
                 i = 5;
             }else if(oldList[i] == 0){
                 temp = oldList[i];
                 newList.push_back(oldList[i]);
                 oldList.erase(oldList.begin() + i);
                 flag = true;
                 i = 5;
             }else{
                 flag = false;
                 cout << "Not Possible!";
             }
         }
      if(flag == true){
          newList.push_back(oldList[0]);
             oldList.erase(oldList.begin());
         }
     string newTime;
     newTime.push_back('0' + newList[0]); 
     newTime.push_back('0' + newList[1]); 
     newTime.push_back(':');
     newTime.push_back('0' +newList[2]);
     newTime.push_back('0' +newList[3]);
     return newTime;
 }

int main(){
    string date;
    vector <int> oldList;
    vector <int> newList;
    cout << "Enter date: DD-MM-YYYY: ";
    getline(cin, date);
    ReformatDate(date);
    int a, b, c, d;
    cout << "Enter time: ";
    cin >> a >> b >> c >> d;
    cout << maxTime(a, b, c, d); 
    return 0;
}