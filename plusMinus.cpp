/*
 * Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero.
 * Print the decimal value of each fraction on a new line with  places after the decimal.*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

/*THIS CODE PASSES ALL TEST CASES COMPLETED ON 11/7/2023 AT 12:22AM*/
void plusMinus(vector<int> arr) {
    double pos{0.0}; //initializing variables to 0.0
    double neg{0.0};
    double zero{0.0};

    // checking for 3 cases
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0){ // if num in arr is positive
            pos++;
        } else if(arr[i] < 0){ //if num in arr is negative
            neg++;
        } else {  // if num is a zero
            zero++;
        }
    }

    //setting the size of the array into a variable
    int total = arr.size();

    // preforming arithmetic at the end of to get the correct ratios
    cout << setprecision(6) << pos / total << endl;
    cout << setprecision(6) << neg / total << endl;
    cout << setprecision(6) << zero / total << endl;

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
