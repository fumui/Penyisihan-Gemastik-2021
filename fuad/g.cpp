#include <iostream>
#include <vector>
#include <math.h>
// #include <map>
struct Point{
    int x, y;
};
std::vector<int> Sn = {1};
int getSn(int n){
    return n * (1 + n)/2;
}
std::pair<int,int> getNearestS(int step){
    int lastIndex = Sn.size() - 1;
    if (Sn[lastIndex] < step){
        Sn.push_back(getSn(lastIndex+1));
        return getNearestS(step);
    }else if (Sn[lastIndex] == step) {
        return std::pair<int,int>(Sn[lastIndex],lastIndex);
    } else if (Sn[lastIndex] > step) {
        while(Sn[lastIndex] > step){
            lastIndex--;
        }
        return std::pair<int,int>(Sn[lastIndex], lastIndex);
    } 
}
Point getPos(){
    int step;
    Point pos;
    pos.x = 0;
    pos.y = 0;
    std::cin >> step;
    auto nearest = getNearestS(step);
    bool isSN = nearest.first == step;
    int n = nearest.second;
    for (int i = 1; i <= n; i++){
        switch (i%4)
        {
        case 1:
            pos.x+=i;
            break;
        
        case 2:
            pos.y+=i;
            break;
        
        case 3:
            pos.x-=i;
            break;
        
        case 0:
            pos.y-=i;
            break;
        
        default:
            break;
        }
    }
    if (!isSN){
        int carry = step - nearest.first;
        switch ((n+1)%4)
        {
        case 1:
            pos.x+=carry;
            break;
        
        case 2:
            pos.y+=carry;
            break;
        
        case 3:
            pos.x-=carry;
            break;
        
        case 0:
            pos.y-=carry;
            break;
        
        default:
            break;
        }
    }
    return pos;
}
int main(){
    int N;
    std::cin >> N;
    std::vector<Point> points;
    for (uint i = 0; i < N; i++)
    {
        points.push_back(getPos());
    }
    for (auto point : points){
        std::cout << point.x << " " << point.y << "\n";
    }
}