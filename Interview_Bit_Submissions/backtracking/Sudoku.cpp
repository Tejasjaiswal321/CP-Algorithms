/*
    Problem: Sudoku
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/sudoku/

    Time Complexity:  O(9^81)
    Space Complexity: O(9^2)

    Author: Tejas Jaiswal
    Description : 
    Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.' 

You may assume that there will be only one unique solution.

Note: You must update the input argument A (partially completed grid of Sudoku) to submit your solved Sudoko grid.

Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

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

class Solution{
    public :
    void solveSudoku(vector<vector<char> > &A);

};

int main(){
    manageInputOutput();
    vector<string> vs = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
     vector<vector<char> > vvc = {};
     for(int i = 0;i<9;i++){
        vvc.push_back({});
        for(int j = 0;j<9;j++){
            vvc[i].push_back(vs[i][j]);
        }
    }
   
    Solution().solveSudoku(vvc);
    
}

//Code Submit



vector<unordered_set<char>> rowEntry,colEntry;
vector<vector<unordered_set<char>>>boxEntry;

pair<int,int> getNewRowCol(int row,int col){
    int newCol = (col+1)%9;
        int newRow = row;
        if(newCol ==0){
            newRow++;
        }
    return {newRow,newCol};
}

bool solve(vector<vector<char> > &A,int row,int col){
    if(row>=9){
        return true;
    }
    if(A[row][col]!='.'){
        auto newInds = getNewRowCol(row,col);
        return solve(A,newInds.first,newInds.second);
    }
    for(int ind = 1;ind<=9;ind++){
        char num = '0'+ind;
        if(rowEntry[row].find(num)!=rowEntry[row].end()||colEntry[col].find(num)!=colEntry[col].end()||boxEntry[row/3][col/3].find(num)!=boxEntry[row/3][col/3].end()){
            continue;
        }
        rowEntry[row].insert(num);
        colEntry[col].insert(num);
        boxEntry[row/3][col/3].insert(num);
        auto newInds = getNewRowCol(row,col);
        A[row][col]=num;
        // printf("A[%d][%d] = %c\n",row,col,A[row][col]);
        bool isSolved = solve(A,newInds.first,newInds.second);
        if(isSolved){
            return true;
        }
        rowEntry[row].erase(num);
        colEntry[col].erase(num);
        boxEntry[row/3][col/3].erase(num);
        A[row][col]= '.';
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    rowEntry.clear();
    colEntry.clear();
    boxEntry.clear();

    rowEntry.resize(9);
    colEntry.resize(9);
    boxEntry.resize(3);
    for(auto &e:boxEntry){//verify once;
        e.resize(3);
    }
    for(int i =0;i<9;i++){
        for(int j = 0;j<9;j++){
            auto currNum = A[i][j];
            if(currNum!='.'){
                rowEntry[i].insert(currNum);
                colEntry[j].insert(currNum);
                boxEntry[i/3][j/3].insert(currNum);
            }
            
        }
    }

    solve(A,0,0);
    // for(auto &v :A){
    //     print_vector(v);
    // }
    
    return;
}

