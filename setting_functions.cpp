#include "long_count.h"

bool valid (string expression){
    return true;
    bool operation = false, no_letters = true, two_nums = false, first = false;
    char ch;
    for ( long long i = 0; expression[i] != '\0'; i++){
        ch = expression[i];
        if ( ch  == '+' || ch == '-' || ch == '*' || ch == '/'){
            operation = true;
        }
        else if ((ch > '9' || ch < '0') && ch != ' ' && ch != '\0' ){
            no_letters = false;
        }
        else if (ch < '9' && ch > '0'){
            if (operation)
                two_nums = true;
            else
                first = true;
        }
    }
    return operation && no_letters && two_nums && first;
}



string first_num(string expression){

    string first = "";
    long long i = 0;
    while( expression[i] != '\0'){

        if (expression[i]  == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '\0'){
            break;
        }
        if (expression[i] <= '9' && expression[i] >= '0' && expression[i] != ' '){
            first += expression[i];

        }
        if( expression[i] == '('){
            cout << " char ( detected " << endl;
            i++;
            while(expression[i] != ')'){
                if(expression[i] != ' '){
                    first += expression[i];
                }
                i++;
            }
            break;
        }
        i++;
    }
    return first;

}

string second_num(string expression){

    string second = "";
    for (long long i =0; expression[i] != '\0'; i++){
    if (expression[i]  == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' ){
        second = first_num(itc_slice_str(expression, i + 1, itc_len(expression)));
    }
    if(expression[i] == '('){

            while(expression[i] != ')'){
                i++;
            }
        }
    }
    return second;

}

string operation_id(string expression){

    string res = "";
    long long i = 0;
    while(expression[i] != '\0'){
        if (expression[i]  == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
            res += expression[i];

            return res;
        }
        if(expression[i] == '('){

            while(expression[i] != ')'){
                i++;
            }
        }
        i++;
    }
}

string rm_zeros(string num){
    string sign ="";
    if(num[0] == '-'){
        sign  = "-";
        num = itc_slice_str(num, 1, itc_len(num));
    }
    long long i = 0;
    while(num[i] == '0'){
        i++;
    }
    return sign + itc_slice_str(num, 0, i -1);
}


string baron(string first, string second, string operation){
    string answer ="SOMETHING WENT WRONG!!!";
   if(operation == "+")answer = summation(first, second);
   if(operation == "-")answer = subtraction(first, second);
   if(operation == "*")answer = multiplication(first, second);
   return answer;

}


