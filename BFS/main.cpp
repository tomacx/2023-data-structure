#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair <int,int> p;
int shortestPath(vector<vector<int>>&maze, pair<int,int> start, pair<int,int> destination);
int main() {
    vector<vector<int>> maze = {
            {0,0,1,0,0},
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,1,1,1,0},
            {0,0,0,0,0}
    };
    pair<int,int> start = make_pair(0,0);
    pair<int,int> destination = make_pair(4,4);

    int result = shortestPath(maze, start, destination);
    cout << "Shortest path length:" << result << endl;
    return 0;
}

int shortestPath(vector<vector<int>> &maze,pair<int,int> start,pair<int,int> destination){
    int number = 0;
    number = 5;
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,1,-1};
    queue<p> Q;
    //记录起点
    int i = start.first;
    int j = start.second;
    //记录步数
    int step[number][number];
    for(int m = 0; m < number; m++){
        for(int n = 0; n < number; n++){
            step[m][n] = -1;
        }
    }
    step[0][0] = 0;
    //把开头标记已经走过了
    maze[0][0] = 1;
    Q.push(p(0,0));
    while(!Q.empty()){
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();//删除队首坐标
        if(i == destination.first && j == destination.second){
            break;
        }
        //用BFS算法，广度遍历，找上下左右四个方向是否被问过
        for(int k = 0; k < 4; k++){
            //处理边界和墙壁
            if((i + x[k] >= 0) && (i + x[k] <= number-1) && (j + y[k] >= 0) && (j + y[k] <= number-1) && (maze[i+x[k]][j+y[k]] == 0)){
                Q.push(p(i+x[k],j+y[k]));//将坐标入队
                maze[i+x[k]][j+y[k]] = 1;
                step[i+x[k]][j+y[k]] = step[i][j] + 1;//记录到该点的步数
            }
        }
    }
    return step[destination.first][destination.second];
}