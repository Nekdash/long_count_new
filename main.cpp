#include <iostream>
#include "long_count.h"
using namespace std;

int main()
{

    string expression = "", answer, ans, first, second, operation;
    //cout << "Enter the expression : <first number>< + or - or * or / ><second number>" << endl;
    cin << first;
    while(true){
    getline(cin, expression);
    ///  raise the error if letters
     if (valid(expression)){
        /// divide to numbers and identify operator
        first = "0" + first_num(expression);
        second = "0" + second_num(expression);
        operation = operation_id(expression);
        /// identify signs of numbers -> call the function
        if(operation == "+") answer = sum_first(first, second);
        if(operation == "-")answer = sub(first, second);
        if(operation == "*") answer = mult(first, second);
        /// print out the answer;
        cout << "ANSWER: " << rm_zeros(answer) << endl;

     }else{
        cout << "!!! INVALID EXPRESSION !!!" << endl;
        break;
     }}
    return 0;
}
