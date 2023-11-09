#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int hours, minutes, seconds;
    char meridian[3];

    // using sscanf to extract values from the input string
    sscanf(s.c_str(), "%d:%d:%d%2s", &hours, &minutes, &seconds, meridian);

    // adjusting hours based on meridian
    if (strcmp(meridian, "PM") == 0 && hours != 12) {
        hours += 12;
    } else if (strcmp(meridian, "AM") == 0 && hours == 12) {
        hours = 0;
    }

    // using stringstream to format the output
    stringstream time24hr;
    time24hr << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds;

    return time24hr.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
