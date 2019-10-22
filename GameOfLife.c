#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

const int dimension = 25;

struct Board
{
    int grid[25][25];
    int width;
    int height;
};

void drawBoard(struct Board newBoardState)
{
    for(int i = 1; i < dimension; i++)
    {
        for(int j = 1; j < dimension; j++)
        {
            /*printf("%i", newBoardState.grid[i][j]);*/
            if(newBoardState.grid[i][j] == 0)
            {
                printf("[ ]");                
            }else if(newBoardState.grid[i][j] == 1)
            {
                printf("[*]");
            }
        }
        printf("\n");
    }
    /*system("cls");*/
}

int countNeighbours(struct  Board currentBoardState, int i , int j)
{
    /*  [i-1][j-1]  [i-1][j]    [i-1][j+1]
        [i][j-1]    [i][j]      [i][j+1]
        [i+1][j-1]  [i+1][j]    [i+1][j+1]  */
    int liveNeighbours = 0;
    for(int k = -1; k < 2; k++)
    {
        for (int l = -1; l < 2; l++)
        {
            if(currentBoardState.grid[i + k][j+l] == 1)
            {
                liveNeighbours++;
            }
        }
    }
    if(currentBoardState.grid[i][j] == 1)
    {
        liveNeighbours--;
    }
    return liveNeighbours;    
}

int nextCellState(int liveNeighbours, int liveCell)
{
    int newState;    
    if(liveCell == 0)
    {
        if(liveNeighbours == 3)
        {
            newState = 1;
        }
        else
        {
            newState = 0;
        }        
    }
    else
    {
        if(liveNeighbours < 2 || liveNeighbours > 3)
        {
            newState = 0;
        }
        else
        {
            newState = 1;
        }        
    }
    return newState;
}

struct Board updateBoard(struct Board currentBoardState)
{
    /*system("cls");*/
    int liveNeighbours = 0;
    struct Board newState;
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            if(i == 0 || i == dimension-1 || j == 0 || j == dimension-1)
            {
                newState.grid[i][j] = 0;
            }
            else
            {
                /* Conway's GOL Alg*/
                /*Count adjacent live cells*/
                liveNeighbours = countNeighbours(currentBoardState, i, j);

                /*Next cell state determination*/
                newState.grid[i][j] = nextCellState(liveNeighbours, currentBoardState.grid[i][j]);
            }     
        }
    }
    return newState;
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
            }
            else if(n == 1)
            {
                newBoard.grid[i][j] = 1;
            }
            

            /*Erase all outter edges*/
            if(i == 0 || i == dimension-1 || j == 0 || j == dimension-1)
            {
                newBoard.grid[i][j] = 0;
            }
        }
    }
    /*Glider testing
    newBoard.grid[4][4] = 1;    
    newBoard.grid[5][5] = 1;    
    newBoard.grid[6][3] = 1;    
    newBoard.grid[6][4] = 1;    
    newBoard.grid[6][5] = 1;
    */

    /*init board*/
    printf("Generation: \n");
    drawBoard(newBoard);

    /*begin loop of updates */
    for (int i = 1; i < 100; i++)
    {
        system("cls");
        printf("\n After %d iteration(s): \n", i);
        newBoard = updateBoard(newBoard);
        drawBoard(newBoard);
        Sleep(50);
        
    }   
    return 0;
}

