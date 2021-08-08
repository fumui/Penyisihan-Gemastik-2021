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
    int number_of_case = 2;    
    string handle_input = "";

    vector<vector<int>> input;
    vector<int> index;

    for(int i = 0; i < number_of_case; i++) {
        input.push_back(index);
        getline(cin, handle_input, '\n');        
        vector<string> row = split(handle_input, " ");
        for(std::size_t j = 0; j < row.size(); j++) {
            stringstream ss;
            int num; 

            ss << row[j];
            ss >> num;
            input[i].push_back(num);   
        }
    }  

    return input; 
}

int calculateProfit(vector<vector<int>> data) {
    for(std::size_t i = 0; i < data.size(); i++) {        
        int profit = 0;
        for(std::size_t j = 0; j < data[i].size(); j++) {    
            if(data[i][j+1]) {        
                if((j == data[i].size() - 1) && j > i ) {
                    break;
                }
                if(data[i][j] > data[i][j+1]) {
                    continue;
                } else {
                    int day = data[i][j+1] - data[i][j];
                    profit = profit + day;                       
                }
            }
        }

        if(i == data.size() - 1) {
            return profit;
        }
    }    
}



int main() {
    vector<vector<int>> data = define_case();
    int max_number = pow(10, 6);

    if((data[0][0] > max_number) || data[0].size() > max_number) {
        cout << "false";
        return 0;
    }

    int profit = calculateProfit(data);
    cout << profit << endl;
    return 0;
}

