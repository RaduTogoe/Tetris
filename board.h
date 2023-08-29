#ifndef BOARD
#define BOARD

#include "pieces.h";

#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5

class Board // 
{
    public:

    int getXPosInPixels(int pPos); // returns the x position of a piece in pixels
    int getYPosInPixels(int pPos); // returns the x position of a piece in pixels
    bool isFreeBlock(int pX, int pY); // checks if a block is free on the board
    bool isPossibleMovement(int pX, int pY, int pPiece, int pRotation); // checks if a piece can move a certain direction
    void storePiece(int pX, int pY, int pPiece, int pRotation); // stores a piece on the board
    void deletePossibleLines(); // deletes all the lines that are completed
    bool isGameOver(); // checks if the game is over (if the first line has any occupied block)

    private:

    void initBoard(); // initializes the board
    void deleteLine(int pY); // deletes a completed line

    enum{POS_FREE = 0, POS_FILLED = 1};
    int mBoard[BOARD_WIDTH][BOARD_HEIGHT];
    Pieces *mPieces;
    int mScreenHeight;
};

#endif