#include "board.h";
#include "pieces.h";

void Board::initBoard() // sets all the blocks on the board to empty blocks
{
    for (int i = 0; i < BOARD_WIDTH; i++)
        for (int j = 0; j < BOARD_HEIGHT; j++)
            mBoard[i][j] = POS_FREE;
}

void Board::storePiece(int pX, int pY, int pPiece, int pRotation)
{
    for (int i = pX; i < pX + PIECE_BLOCKS; i++)
        for (int j = pY; j < pY + PIECE_BLOCKS; j++)
        {
            if (mPieces->getBlockType(pPiece, pRotation, pX - PIECE_BLOCKS, pY - PIECE_BLOCKS) != 0)
                mBoard[i][j] = 1;
        }
}

bool Board::isGameOver()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
        if (mBoard[0][i] != 0)
            return true;
    return false;
}

void Board::deleteLine(int pY)
{
     for (int i = pY; i > 0; i--)
        for (int j = 0; j < BOARD_WIDTH; j++)
            mBoard[i][j] = mBoard[i - 1][j];
}

void Board::deletePossibleLines()
{
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        bool isFull = true;
        for (int j = 0; j < BOARD_WIDTH; j++)
            if (mBoard[i][j] == 0)
            {
                isFull = false;
                break;
            }
        if (isFull == true)
            deleteLine(i);
    }
}

bool Board::isFreeBlock(int pX, int pY)
{
    return mBoard[pX][pY] == POS_FREE;
}

int Board::getXPosInPixels(int pPos)
{
    return ( ( BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) ) + (pPos * BLOCK_SIZE) );
}

int Board::getYPosInPixels(int pPos)
{
    return ( (mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE) );
}

bool Board::isPossibleMovement(int pX, int pY, int pPiece, int pRotation)
{
    for (int i = pX; i < pX + PIECE_BLOCKS; i++)
        for (int j = pY; j < pY + PIECE_BLOCKS; j++)
        {
            if (i > 0 || j > BOARD_WIDTH - 1 || i > BOARD_HEIGHT - 1)
            {
                if (mPieces->getBlockType(pPiece, pRotation, i - PIECE_BLOCKS, j - PIECE_BLOCKS) != 0)
                    return false;
            }
            if (j >= 0)
                if (mPieces->getBlockType(pPiece, pRotation, i - PIECE_BLOCKS, j - PIECE_BLOCKS) != 0 && !isFreeBlock(i - PIECE_BLOCKS, j - PIECE_BLOCKS))
                return false;
        }
    return true;
}
