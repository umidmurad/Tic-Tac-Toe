#include <iostream>

using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard( char[][3]);
void makeAMove(char[3][3], char);
int inputChecker(int n);

bool isWon(char mark, char board[3][3])
{
    int r=0,c=0;
    //to win one of these have to happen 1.left to right diagonal check / 2.right to left diagonal check
    //3. Row 0 top to bottom/ 4. Row 1 top to bottom/5. Row 2 top to bottom
    //6. Col 0 left to right/ 7. Col 1 left to right / 8. Col 2 left to right.
    if((mark==board[r][c] && mark==board[r+1][c+1] && mark==board[r+2][c+2]) || (mark==board[r+2][c] && mark==board[r+1][c+1] && mark==board[r][c+2])
       ||(mark==board[r][c] && mark==board[r][c+1] && mark==board[r][c+2])|| (mark==board[r+1][c] && mark==board[r+1][c+1] && mark==board[r+1][c+2]) || (mark==board[r+2][c]&&mark==board[r+2][c+1]&&mark==board[r+2][c+2])
       ||(mark==board[r][c]&& mark==board[r+1][c] &&mark==board[r+2][c]) || (mark==board[r][c+1]&& mark==board[r+1][c+1] &&mark==board[r+2][c+1]) || (mark==board[r][c+2]&& mark==board[r+1][c+2] &&mark==board[r+2][c+2]) )
        {return true;}
    return false;
}

bool isDraw(char board[3][3])
{
    // if there is no empty space left then games is over, if nobody won by then.
    for(int r=0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            if(board[r][c] == ' ')
            { //if it has empty space, game is not finished yet
                return false;
            }
        }

    }
    return true;
}


void displayBoard(char board[3][3])
{   //prints the board
    cout <<"-------------" <<endl;
    cout <<"| " << board[0][0]   <<" | " << board[1][0] <<" | " << board[2][0] <<" |" <<endl;
    cout <<"-------------" <<endl;
    cout <<"| " << board[0][1]   <<" | " << board[1][1] <<" | " << board[2][1] <<" |" <<endl;
    cout <<"-------------" <<endl;
    cout <<"| " << board[0][2]   <<" | " << board[1][2] <<" | " << board[2][2] <<" |" <<endl;
    cout <<"-------------" <<endl;
}
void makeAMove(char board[3][3], char mark)
{
    int row, col;
    //row amount
    cout <<"Enter a row (0, 1, 2) for player " << mark <<"   : ";
    cin >> row;
    row = inputChecker(row); //checks for value to be 0,1,2
    //col amount
    cout <<"Enter a column (0, 1, 2) for player " << mark <<"   : ";
    cin >> col;
    col = inputChecker(col);
    while(board[col][row] != ' ') //if the space is taken, then reasks to enter another position
    {   cout<<"This cell is already occupied. Try a different cell. \n";
        cout <<"Enter a row (0, 1, 2) for player " << mark <<"   : ";
        cin >> row;
        row = inputChecker(row);
        //col amount
        cout <<"Enter a column (0, 1, 2) for player " << mark <<"   : ";
        cin >> col;
        col = inputChecker(col);
    }
    board [col][row] = mark; //inputs the value to the given location
}

int inputChecker(int n){ //this function checks the values for it to be 0, 1, or 2.
    while(n<0 || n >2){
        cin.ignore();
        cout <<"Input has to be between 0 and 2. Try again: ";
        cin >> n;
    }
    return n;
}

int main() {
    //
    //	PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);

    while (true) {

        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);

        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}