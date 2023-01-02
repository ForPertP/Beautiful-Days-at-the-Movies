#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int beautifulDays(int i, int j, int k)
{
    int count = 0;
    int number = 0;
    int reverse = 0;

    for (; i <= j; ++i)
    {
        number = i;
        reverse = 0;
        
        while (number != 0)
        {
            reverse = (reverse * 10) + (number % 10);
            number = number / 10;
        }
        
        if (abs(i - reverse) % k == 0)
        {
            count++;
        }
    }
    
    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int i = stoi(first_multiple_input[0]);

    int j = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    int result = beautifulDays(i, j, k);

    fout << result << "\n";

    fout.close();

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
