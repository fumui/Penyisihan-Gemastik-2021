#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <map>

void splitToIntVector(std::string s, std::vector<int> &out)
{
    std::stringstream ss(s);
    std::string word;
    while (ss >> word)
    {
        int parsed = 0;
        std::stringstream num(word);
        num >> parsed;
        out.push_back(parsed);
    }
}
int main(){
    std::string inputInitial;
    std::vector<int> initial;
    std::vector<int> shortest;
    int minDist = 99999 + 1;
    getline(std::cin, inputInitial);
    splitToIntVector(inputInitial, initial);
    for (uint i = 0; i < initial[0]; i++)
    {
        int token, dist;
        std::cin >> token;
        dist = abs((long)(token-initial[1]));
        if (minDist > dist) {
            minDist = dist;
            shortest.clear();
            shortest.push_back(token);
        } else if (minDist == dist){
            shortest.push_back(token);
        }
    }
    if (shortest.size() == 2 ){
        if (shortest[0]>shortest[1]){
            int temp = shortest[1];
            shortest[1] = shortest[0];
            shortest[0] = temp;
        }
    }
    for(auto token : shortest){
        std::cout << token << "\n";
    }
}