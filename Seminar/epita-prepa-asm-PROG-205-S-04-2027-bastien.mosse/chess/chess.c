#include <stdio.h>
#include "chess.h"

// Empties the chessboard.
// All elements are set to EMPTY.
void init_board(char board[][8])
{
    for (size_t row = 0; row < 8; row++)
        for (size_t col = 0; col < 8; col++)
            board[row][col] = EMPTY;
}

// Prints the chessboard (8x8 grid).
void print_board(char board[][8])
{
    for (size_t row = 0; row < 8; row++)
    {
        for (size_t col = 0; col < 8; col++)
            printf("%c ", board[row][col]);

        printf("\n");
    }
}

// Sets the board with the rook moves.
// (row, col) = rook position.
void rook_moves(char board[][8], size_t row, size_t col)
{
	for(size_t x = 0; x < 8; x++){
		for(size_t y = 0; y < 8; y++){
			if(x == row && y == col){
				board[x][y] = CHESSMAN;
			} else if(x == row || y == col){
				board[x][y] = LEGAL_MOVE;
			} else {
				board[x][y] = EMPTY;
			}
		}
	}
}

// Sets the board with the bishop moves.
// (row, col) = bishop position.
void bishop_moves(char board[][8], size_t row, size_t col)
{
	int d_x, d_y;
	for(size_t x = 0; x < 8; x++){
		for(size_t y = 0; y < 8; y++){
			d_x = (int)x - row;
			d_y = (int)y - col;
			if(x == row && y == col){
				board[x][y] = CHESSMAN;
			} else if(d_x*d_x == d_y*d_y){
				board[x][y] = LEGAL_MOVE;
			} else {
				board[x][y] = EMPTY;
			}
		}
	}
}

// Sets the board with the queen moves.
// (row, col) = queen position.
void queen_moves(char board[][8], size_t row, size_t col)
{
	int d_x, d_y;
	for(size_t x = 0; x < 8; x++){
		for(size_t y = 0; y < 8; y++){
			d_x = (int)x - row;
			d_y = (int)y - col;
			if(x == row && y == col){
				board[x][y] = CHESSMAN;
			} else if(x == row || y == col || d_x*d_x == d_y*d_y){
				board[x][y] = LEGAL_MOVE;
			} else {
				board[x][y] = EMPTY;
			}
		}
	}
}
