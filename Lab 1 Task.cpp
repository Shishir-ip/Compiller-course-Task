/*
Lab Task-1

Q1. Write a program to determine whether the given input is a numeric constant or not.
    Examples: 100, 991, 1810 are numeric constants; ABCD and A1B2 are not numeric.

Q2. Write a program to determine whether the given input contains operators or not.
    Arithmetic operators: +, -, *, /, %, =
    Example: 2+3=5
    Output:
    operator1: +
    operator2: =

Q3. Write a program to determine whether the given input is a comment line or not.
    Examples: // single-line comment and /* multiple-line comment */

Q4. Write a program to determine whether the given input is an identifier or not.
    Conditions:
    a) The first character must be an alphabet character or underscore.
    b) Following characters may be alphabetic, numeric, or underscore.

Q5. Find the average value of the elements of an array.

Q6. Find the minimum and maximum value of the elements of an array.

Q7. Take first and last names and concatenate them into a full name.
    Example: First name = XX, Last name = YY, output = full name = XX YY
*/

#include <iostream>
#include <string>
using namespace std;

bool isNumeric(string a) {
    if (a.length() == 0)
        return false;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] < '0' || a[i] > '9')
            return false;
    }
    return true;
}

void checkOperators(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=') {
            count++;
            cout << "operator" << count << ":  " << c << endl;
        }
    }
    if (count == 0)
        cout << "No operator found" << endl;
}

void checkComment() {
    string line;
    getline(cin, line);
    if (line.length() >= 2 && line[0] == '/' && line[1] == '/') {
        cout << "Single line comment" << endl;
        return;
    }
    if (line.length() >= 2 && line[0] == '/' && line[1] == '*') {
        string text = line.substr(2);
        while (text.find("*/") == string::npos) {
            if (!getline(cin, line)) {
                cout << "Not a comment" << endl;
                return;
            }
            text = text + "\n" + line;
        }
        cout << "Multiple line comment" << endl;
        return;
    }
    cout << "Not a comment" << endl;
}

bool isIdentifier(string s) {
    if (s.length() == 0)
        return false;
    char f = s[0];
    if (!((f >= 'A' && f <= 'Z') || (f >= 'a' && f <= 'z') || f == '_'))
        return false;
    for (int i = 1; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || (c >= '0' && c <= '9')))
            return false;
    }
    return true;
}

double findAverage(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return (double)sum / n;
}

int findMin(int arr[], int n) {
    int mn = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < mn)
            mn = arr[i];
    }
    return mn;
}

int findMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

string fullName(string first, string last) {
    return first + " " + last;
}

int main() {
    string s;

    cout << "Q1. Enter input: ";
    cin >> s;
    if (isNumeric(s))
        cout << "numeric constant" << endl;
    else
        cout << "not numeric" << endl;

    cout << "Q2. Enter expression: ";
    cin >> s;
    checkOperators(s);

    cout << "Q3. Enter comment: ";
    cin.ignore(1000, '\n');
    checkComment();

    cout << "Q4. Enter input: ";
    cin >> s;
    if (isIdentifier(s))
        cout << "Identifier" << endl;
    else
        cout << "Not an identifier" << endl;

    int n;
    int arr[100];
    cout << "Q5 & Q6. Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Average = " << findAverage(arr, n) << endl;
    cout << "Minimum = " << findMin(arr, n) << endl;
    cout << "Maximum = " << findMax(arr, n) << endl;

    string first, last;
    cout << "Q7. Enter first name: ";
    cin >> first;
    cout << "Enter last name: ";
    cin >> last;
    cout << "full name = " << fullName(first, last) << endl;

    return 0;
}
