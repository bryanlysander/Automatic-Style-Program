#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string removeLeadingSpaces(string line);
int countChar(string line, char c);
int countCharstep(string line, char j);
bool tester (string line);

int main(){ //Declaring our main function
    string line; //declaring a string variable named line
    int total = 0;
    int open_parantheses = 0;
    int closed_parantheses = 0;
    char c = '{';
    char j = '}';
    int indent = 0;
    int backup = 0;
    int numbers = 0;
    int i = 0; //declaring our increment starting from 0
    while (getline(cin, line)){
        string line_by_line = removeLeadingSpaces(line); //call the function removeLeadingSpace and store the value in line by line
        closed_parantheses = countCharstep(line, j);
        numbers = numbers + closed_parantheses;
        open_parantheses = countChar(line, c);
        backup = backup + open_parantheses;
        if (closed_parantheses != 0){
            if (open_parantheses == closed_parantheses){
                if (tester(line)){
                    total = indent - numbers;
                }
                else
                    total = backup - numbers;
            }
            else if (open_parantheses > 1){
                total = backup - numbers - 1;
            }
            else
                total = indent - numbers;
        }
        else
            total = indent - numbers;
        
        if (i == 0){ //if its the first line, then set total to 0
            total = 0;
        }
        
        for (int h = 0; h < total; h++){ //using loop and the value in total to print the amount of tab we need
            cout << '\t';
        }
        cout << line_by_line << endl; //after printing the tab from our loop we print out the string stored in line_by_line
        indent = indent + open_parantheses;
        i++;
    }
}

string removeLeadingSpaces(string line){//declaring our removeleadingspaces function
    int i = 0; //declaring an integer variable named i that stores the value 0
    int length = line.length(); //declaring an integer variable named length that stores the value of length from line
    while (isspace(line[i]) != 0){ //using the while loop to see if the first letter is space
        //if not ignore this loop
        //if it is execute the body loop
        i++; //increasing the value of i by 1
    }
    int ending = length - i; //delcaring an integer variable named ending that store the value of length minus final value of i
    return line.substr(i, ending); //return the line starting from index i, and ending of ending
}

int countChar(string line, char c){
    int length_1 = line.length(); //declaring an integer variable named length_1 that stores the value of length from line
    int number_1 = 0; //declaring an integer variable named number_1 and stores the value 0
    for (int i = 0; i < length_1; i++){ //using loop to see through the full string
        if (line[i] == c){ //if there is any character that matches the char stored in c in this string increment number by 1
            number_1++;
        }
    }
    return number_1; //return whatever value is stored in numero after we run the loop
}

int countCharstep(string line, char j){
    int length_2 = line.length(); //declaring an integer variable named length_2 that stores the value of length from line
    int number_2 = 0; //declaring an integer variable named number_2 and stores the value 0
    for (int i = 0; i < length_2; i++){ //using loop to see through the full string
        if (line[i] == j){ //if there is any character that matches the char stored in c in this string increment number by 1
            number_2++;
        }
    }
    return number_2; //return whatever value is stored in numero after we run the loop
}

bool tester(string line){
    int length_3 = line.length();
    int open_parantheses_counter = 0;
    for (int i = 0; i < length_3; i++){
        if (line[i] == '}'){
            open_parantheses_counter++;
            break;
        }
        else if (line[i] == '{'){
            break;
        }
    }
    if (open_parantheses_counter == 1){
        return true;
    }
    else
        return false;
}
