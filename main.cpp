#include <iostream>
#include "long_count.h"
using namespace std;

int main()
{

    string expression = "", answer, ans, first, second, operation;

    while(true){
    cout << "Enter the expression : <first number> < + or - or * or / > <second number>" << endl;
    getline(cin, expression);
    //cin >> first;
    //cin >> operation;
    //cin >> second;

    ///  raise the error if letters
     if (valid(expression)){
        /// divide to numbers and identify operator
        first =   first_num(expression);
        second =   second_num(expression);
        operation = operation_id(expression);
        cout << "FIRST:  " << first << endl;
        cout << "SECOND:  " << second << endl;

        /// identify signs of numbers -> call the function
        answer = baron(first, second, operation);
        /// print out the answer;
        cout << "ANSWER: " << answer << endl;
        //cout << " 00 + 00 " << summation( "00" , "00") << endl;

     }else{
        cout << "!!! INVALID EXPRESSION !!!" << endl;
        break;
     }}
    return 0;
}
