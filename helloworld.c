#include <stdio.h>
#include <stdlib.h>

const int dimension = 25;

struct Board
{
    int grid[25][25];
    int width;
    int height;
};

void drawBoard(struct Board currentBoardState)
{
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            /*printf("%i", currentBoardState.grid[i][j]);*/
            if(currentBoardState.grid[i][j] == 0)
            {
                printf("[ ]");                
            }else if(currentBoardState.grid[i][j] == 1)
            {
                printf("[*]");
            }
        }
        printf("\n");
    }
    /*system("cls");*/
}

void updateBoard(struct Board nextBoardState)
{
    system("cls");
    for(int i = 1; i < dimension-1; i++)
    {
        for(int j = 1; j < dimension-1; j++)
        {
            /* Conway's GOL Alg*/
            /*Count adjacent live cells

            [i-1][j-1]  [i-1][j]    [i-1][j+1]
            [i][j-1]    [i][j]      [i][j+1]
            [i+1][j-1]  [i+1][j]    [i+1][j+1]  

            */
            int liveCells;
            for(int k = 0; k <9; k++)
            {
                
            }
            
            /*Next cell state determination*/

            if(i == 0 || i == dimension-1 || j == 0 || j == dimension-1)
            {
                nextBoardState.grid[i][j] = 0;
            }
        }
    }
    drawBoard(nextBoardState);
}

int main()
{    
    /*set up board state*/
    struct Board newBoard;
    int n;
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            n = rand() % 2;
            if(n == 0)
            {
                newBoard.grid[i][j] = 0;
            }else if(n == 1)
            {
                newBoard.grid[i][j] = 1;
            } /*Erase all outter edges*/
            if(i == 0 || i == dimension-1 || j == 0 || j == dimension-1)
            {
                newBoard.grid[i][j] = 0;
            }
        }
    }
    /*init board*/
    drawBoard(newBoard);
    /*begin loop of updates*/


    return 0;
}

