#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// declare global variables
char board[3][3]; // 2D Array for game board
const char PLAYER = 'X';
const char COMPUTER = 'O';

// declare function prototypes
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    char winner = ' ';
    char response;

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();

        while(winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                printf("Break at player\n");
                break;
            }

            computerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                printf("Break at computer\n");
                break;
            }
        }

        printBoard();
        printWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);
    } while (response == 'Y');

    printf("Thanks for playing!");

    return 0;
}

void resetBoard()
{
    for(int rows = 0; rows < 3; rows++)
    {
        for(int columns = 0; columns < 3; columns++)
        {
            board[rows][columns] = ' ';
        }
    }
};

void printBoard()
{
    printf("  %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n----|---|----\n");
    printf("  %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n----|---|----\n");
    printf("  %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
};

int checkFreeSpaces()
{
    int freeSpaces = 9;
    for(int rows = 0; rows < 3; rows++)
    {
        for(int columns = 0; columns < 3; columns++)
        {
            if(board[rows][columns] != ' ')
            {
                freeSpaces--;
            };
        }
    }
    return freeSpaces;
};

void playerMove()
{
    int row;
    int column;

    do {
        printf("Enter row number #(1-3): ");
        scanf("%d", &row);
        row--;

        printf("Enter column number #(1-3): ");
        scanf("%d", &column);
        column--;

        if(board[row][column] != ' ')
        {
            printf("Invalid move\n");
        }
        else
        {
            board[row][column] = PLAYER;
            break;
        }
    } while (board[row][column] != ' ');

};

void computerMove(){
    // create a seed based on current time for a random number
    srand(time(0));
    int row;
    int column;

    if(checkFreeSpaces() > 0)
    {
        do{
            row = rand() % 3;
            column = rand() % 3;
        } while (board[row][column] != ' ');

        board[row][column] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
};

char checkWinner()
{
    // check rows
    for(int rows = 0; rows < 3; rows++)
    {
        if(board[rows][0] == board[rows][1] && board[rows][0] == board[rows][2])
        {
            return board[rows][0];
        }
    }

    // check columns
    for(int columns = 0; columns < 3; columns++)
    {
        if(board[0][columns] == board[1][columns] && board[0][columns] == board[2][columns])
        {
            return board[0][columns];
        }
    }

    // check diagonals
    // check top left to bottom right
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    // check bottom left to top right
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) 
    {
        return board[0][2];
    }

    return ' ';
};

void printWinner(char winner){
    if(winner == PLAYER)
    {
        printf("YOU WIN!");
    }
    else if (winner == COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("IT'S A TIE");
    }
};