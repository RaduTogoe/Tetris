#ifndef PIECES
#define PIECES

class Pieces
{
    public:
    int getBlockType(int pPiece, int pRotation, int pX, int pY); // returns the type of the block at [px, py] in the matrix (0-free, 1-part of the piece itself, 2-rotation point of the piece)
    int getXPosition(int pPiece, int pRotation); // returns the x position of the piece
    int getYPosition(int pPiece, int pRotation); // returns the y position of the piece
};

#endif