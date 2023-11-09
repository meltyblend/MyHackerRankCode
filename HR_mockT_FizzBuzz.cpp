#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void fizzBuzz(int n) {
    for(int i = 1; i <= n; i++){
        // if i is a multiple of both 3 &5
        if((i % 3 == 0) && (i % 5 == 0)){
            cout << "FizzBuzz" << endl;
            // if i is a multiple of 3(but not 5)
        } else if((i % 3 == 0) && (i % 5 != 0 )){
            cout << "Fizz" << endl;
            // if i is a multiple of 5(but not 3)
        } else if((i % 5 == 0) && (i % 3 != 0)){
            cout << "Buzz" << endl;
        } else {
            // if i is not a multipleof 3 or 5
            cout << i << endl;
        }
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    fizzBuzz(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
