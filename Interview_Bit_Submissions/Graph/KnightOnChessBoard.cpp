/*
    Problem: Knight On Chess Board
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/knight-on-chess-board/?study_plan=study-plan-1-week&/
    Time Complexity: O(n*m) or board grid count
    Space Complexity: O(n*m)
    Problem Description:
    Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

    Knight's movements on a chess board

    The above figure details the movements for a knight ( 8 possibilities ).

    If yes, then what would be the minimum number of steps for the knight to move to the said point.

    If knight can not move from the source point to the destination point, then return -1.

    Note: A knight cannot go out of the board.



    Input Format:

    The first argument of input contains an integer A.
    The second argument of input contains an integer B.
        => The chessboard is of size A x B.
    The third argument of input contains an integer C.
    The fourth argument of input contains an integer D.
        => The Knight is initially at position (C, D).
    The fifth argument of input contains an integer E.
    The sixth argument of input contains an integer F.
        => The Knight wants to reach position (E, F).
    Output Format:

    If it is possible to reach the destination point, return the minimum number of moves.
    Else return -1.
    Constraints:

    1 <= A, B <= 500
    Example

    Input 1:
        A = 8
        B = 8
        C = 1
        D = 1
        E = 8
        F = 8
        
    Output 1:
        6

    Explanation 1:
        The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
        The minimum number of moves required for this is 6.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Common Helper functions
void manageInputOutput(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

template<class T>
void print_vector(vector<T> arr,string name = ""){
    cout<<"print_vector : "<<name<<": ";
    for(auto &i:arr){
        cout<< i <<" ";
    }
    cout<<endl;
}
template<class T>
void print_vector(set<T>st){
    cout<<"print_set : "<<": ";
    for(auto &i:st){
        cout<< i <<" ";
    }
     cout<<endl;
}

typedef pair<int,int> pii;


vector<pair<int,int>> diff = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool isValid(int x,int y,int xSize,int ySize){
    return x>=0&&y>=0&&x<xSize&&y<ySize;
}

void levelOrderTraversal( vector<pair<int,int>> levelNodes,int level,int &boardX, int &boardY,vector<vector<int>> &vis) {
    while(!levelNodes.empty()){
         vector<pair<int,int>> nextLevelNodes;
        for(auto &node:levelNodes){
            int x= node.first,y = node.second;
            for(auto &pr:diff){
                int nbrX = x+pr.first,nbrY = y+pr.second;
                if(isValid(nbrX,nbrY,boardX,boardY)&&vis[nbrX][nbrY]==-1){
                    vis[nbrX][nbrY] = level; //very important to mark node visited before moving it to queue so that it isn't included multiple times. Leads to MLE or TLE..
                    nextLevelNodes.push_back({nbrX,nbrY});
                }
            }
        }
        level++;
        levelNodes = nextLevelNodes;
    }  
}

int Solution::knight(int boardX, int boardY, int sourceX, int sourceY, int targetX, int targetY) {
    vector<vector<int>> vis(boardX,vector<int>(boardY,-1));
    
    vis[sourceX-1][sourceY-1] = 0;
    levelOrderTraversal({{sourceX-1,sourceY-1}},1,boardX,boardY,vis);
    return vis[targetX-1][targetY-1];
}

int main(){
    manageInputOutput();

}