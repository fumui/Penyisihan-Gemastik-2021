#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

vector<vector<int>> define_case() {
    int number_of_case = 0;    
    string handle_input = "";

    vector<vector<int>> input;
    vector<int> index;

    cin >> number_of_case;
    cin.ignore();

    for(int i = 0; i < number_of_case; i++) {
        input.push_back(index);
        getline(cin, handle_input, '\n');        
        vector<string> row = split(handle_input, " ");
        for(std::size_t j = 0; j < row.size(); j++) {
            stringstream ss;
            int num; 
            ss << row[j];
            ss >> num;
            if(row[j] == "a") {
                num = -1;
            } else if(row[j] == "b") {
                num = -2;
            } else if(row[j] == "c") {
                num = -3;
            } 
            input[i].push_back(num);   
        }
    }  

    return input; 
}

int checkPrefixAndSuffixFirstMethod(string t)
{  
    int textLength = t.length();

    int counter = 0;
    for(int i = 0; i < textLength; i++) {
        char firstWord = t[i];
        char lastWord = t[textLength - 1 - i];       

        if(textLength % 2 != 0) {
            if(i < textLength / 2) {
                if(firstWord == lastWord) {
                    counter++;
                } else {
                    counter--;
                }
            }
        } else {
            if(firstWord == lastWord) {
                counter++;
            } 
        }
    }
    if(counter > 1) {
        return counter;
    } else {
        return 0;
    }
}


void prefixAndSuffix(vector<vector<int>> data, string text) {

    for(std::size_t i = 0; i < data.size(); i++) {        
        for(std::size_t j = 0; j < data[i].size(); j++) {    
           
            if(data[i][0] == 0 && j == 0) {
                string text2 = text.substr(data[i][1], data[i][2] + 1);
                int textLength = checkPrefixAndSuffixFirstMethod(text2);

                cout << textLength << endl;
                break;
            }
            if(data[i][0] == 1) {
                char word = 'z';
                if(data[i][2] == -1) {
                    word = 'a';
                }
                if(data[i][2] == -2) {
                    word = 'b';
                }
                if(data[i][2] == -3) {
                    word = 'c';
                }
                if(word != 'z') {
                    text[data[i][1]] = word;
                    continue;
                }
            }
        }
    }    
}



int main() {

    string text = "";
    cin >> text;
    vector<vector<int>> data = define_case();   

    int max_number = pow(10, 6);

    if((data[0][0] > max_number) || data[0].size() > max_number) {
        cout << "false";
        return 0;
    }
    cout << text << endl;
    prefixAndSuffix(data, text);

    return 0;
}

