#include <iostream>
using namespace std;

bool canPlace(int board[][20], int n, int x, int y)
{
    //checking if there is a queen along the column
    for(int k = 0; k < x; k++)
        {
            if(board[k][y] == 1)
            {
                return false;
            }
        }
    //left diagonal
    int i = x;
    int j = y;
    while(i >= 0 and j >= 0)
        {
            if(board [i][j] == 1)
            {
                return false;
            }
            i--;
            j--;
        }

    //right diagonal
    i = x;
    j = y;
    while( i >= 0 and j>=0)
        {
            if(board [i][i] == 1)
            {
                return false;
            }
            i--;
            j++;
        }
    return true;
}

void printBoard(int n, int board [][20])
{
    for(int i = 0; i < n; i++)
        {
            for(int j =0; j < n; j++)
                {
                    cout << board[i][j] << " ";
                }
            cout << endl;
        }
    cout << endl;
}
bool solveNQueen(int n, int board[][20], int i)
{
    if(i == n)
    {
        printBoard(n, board);
        return true;
    }
    for(int j = 0; j < n; j++)
        {
            if(canPlace(board,n,i,j))
            {
                board[i][j] = 1;
                bool success = solveNQueen(n,board,i+1);
                if(success)
                {
                    return true;
                }
                board[i][j] = 0;
            }
        }
    return false;
}
int main() {
int board [20][20] = {0};
    int n;
    cin >> n;
    solveNQueen(n, board, 0);
    return 0;
}