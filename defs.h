#ifndef DEFS_H
#define DEFS_H

typedef unsigned long long U64;

#define NAME "CE 1.0"
#define BRD_SQ_NUM 120

//numbers for the pieces
enum {EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bK}; 

//files are A-H
enum {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE};

//ranks are 1-8
enum {RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE};

//colors
enum {WHITE, BLACK, BOTH};

//squares of the board
enum
{
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum {FALSE, TRUE};

typedef struct{
    int pieces[BRD_SQ_NUM]; //array that represents the total board with 0-119 squares (including the squares not on the board)
    U64 pawns[3]; //for one bit for each square on the 64 squares of the board the bit will be set to 1 if there is a pawn of the corresp color on that square & it will be 0 if there isn't a pawn of the corresp color; in the arr index 1 is white, 2 is black and 3 is both
    int KingSq[2];
    int side; //curr side to move
    int enPas; //enpas square if active
    int fiftyMove; //counter for fiftyMove
    int ply; //how many halfmoves in the curr search
    int hisPly; //in the total game so far how many half moves have been made
    U64 posKey; //position key
    int pceNum[13]; //num pieces on the board
    int bigPce[3]; //store based on color the num of big pieces on the board (big pieces are anything that isnt a pawn)
    int majPce[3]; //rooks and queens
    int minPce[3]; //bishops and knights
} S_BOARD;

#endif

