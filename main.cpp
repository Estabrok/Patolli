#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <cstdlib>

using namespace std;

struct alreadyOnTheBoard         // use to see if the player already picked their piece on the board
{
    bool playedA = false, playedB = false, playedC = false, playedD = false, playedE = false, playedF = false;
    bool played1 = false, played2 = false, played3 = false, played4 = false, played5 = false, played6 = false;
    bool finishedA = false, finishedB = false, finishedC = false, finishedD = false, finishedE = false, finishedF = false;
    bool finished1 = false, finished2 = false, finished3 = false, finished4 = false, finished5 = false, finished6 = false;


};


struct gamePieces
{
    char symbol;
    int coords[2] = {19,17};
    bool played = false;
    bool onlyOnce = false;
    bool finished = false;
};

void SetColor(int ForgC)         // function found online from someone else to add color to text
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}


void printBoard(string board[33][33],int &scoreP1, int &scoreP2)
{

    for (int i = 0; i < 33; i++)          // output board
    {
        for (int j = 0; j < 33; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << "Player 1 score: " << scoreP1 << endl;
    cout << "Player 2 score: " << scoreP2 << endl << endl;

}


void checkWinPlayer1(string board[33][33],gamePieces player1[6], int &oldX, int &scoreP1)
{
    if(player1[0].coords[0] == 17 && player1[0].coords[1] <= 19 && oldX >= 19)
    {
        if ( player1[0].finished == false)
        {

            cout << "Player 1 HAS FINISHED PIECE A" << endl;
            scoreP1++;
            player1[0].finished = true;
        }
    }

    if(player1[1].coords[0] == 17 && player1[1].coords[1] <= 19 && oldX >= 19)
    {
        if ( player1[1].finished == false)
        {

            cout << "Player 1 HAS FINISHED PIECE B" << endl;
            scoreP1++;
            player1[1].finished = true;
        }
    }

    if(player1[2].coords[0] == 17 && player1[2].coords[1] <= 19 && oldX >= 19)
    {
        if ( player1[2].finished == false)
        {

            cout << "Player 1 HAS FINISHED PIECE C" << endl;
            scoreP1++;
            player1[2].finished = true;
        }
    }
    if(player1[3].coords[0] == 17 && player1[3].coords[1] <= 19 && oldX >= 19)
    {
        if ( player1[3].finished == false)
        {

            cout << "Player 1 HAS FINISHED PIECE D" << endl;
            scoreP1++;
            player1[3].finished = true;
        }
    }
    if(player1[4].coords[0] == 17 && player1[4].coords[1] <= 19 && oldX >= 19)
    {
        if ( player1[4].finished == false)
        {

            cout << "Player 1 HAS FINISHED PIECE E" << endl;
            scoreP1++;
            player1[4].finished = true;
        }
    }
    if(player1[5].coords[0] == 17 && player1[5].coords[1] <= 19 && oldX >= 19)
    {
        if (player1[5].finished == false)
        {
            cout << "Player 1 HAS FINISHED PIECE F" << endl;
            scoreP1++;
            player1[5].finished = true;
        }
    }
}



void checkWinPlayer2(string board[33][33],gamePieces player2[6], int &oldY, int &scoreP2)
{
    if(player2[0].coords[0] == 15 && player2[0].coords[1] >= 13 && oldY <= 13)
    {

        if ( player2[0].finished == false)
        {

            cout << "Player 2 HAS FINISHED PIECE 1" << endl;
            scoreP2++;
            player2[0].finished = true;
        }
    }

    if(player2[1].coords[0] == 15 && player2[1].coords[1] >= 13 && oldY <= 13)
    {
        if ( player2[1].finished == false)
        {

            cout << "Player 2 HAS FINISHED PIECE 2" << endl;
            scoreP2++;
            player2[1].finished = true;
        }
    }

    if(player2[2].coords[0] == 15 && player2[2].coords[1] >= 13 && oldY <= 13)
    {
        if ( player2[2].finished == false)
        {

            cout << "Player 2 HAS FINISHED PIECE 3" << endl;
            scoreP2++;
            player2[2].finished = true;
        }
    }
    if(player2[3].coords[0] == 15 && player2[3].coords[1] >= 13 && oldY <= 13)
    {
        if ( player2[3].finished == false)
        {

            cout << "Player 2 HAS FINISHED PIECE 4" << endl;
            scoreP2++;
            player2[3].finished = true;
        }
    }
    if(player2[4].coords[0] == 15 && player2[4].coords[1] >= 13 && oldY <= 13)
    {
        if ( player2[4].finished == false)
        {

            cout << "Player 2 HAS FINISHED PIECE 5" << endl;
            scoreP2++;
            player2[4].finished = true;
        }
    }
    if(player2[5].coords[0] == 15 && player2[5].coords[1] >= 13 && oldY <= 13)
    {
        if (player2[5].finished == false)
        {
            cout << "Player 2 HAS FINISHED PIECE 6" << endl;
            scoreP2++;
            player2[5].finished = true;
        }
    }
}

void checkOutOfBounds(string board[33][33], int &posX, int &posY, int &p2X, int &p2Y, bool &outOfMap, int &oldX, int &oldY, int &roll,alreadyOnTheBoard &piece, gamePieces player1[6], int &scoreP1)
{
    if (posX > 31)
    {
        int blocksOverFlow = (posX - 31) / 2;
        posX = 31;
        posY = 15;
        posX -= (blocksOverFlow - 1) * 2;
    }

    else if (posX < 17 && oldX >= 17 && oldY == 15)
    {
        int blocksOverFlow = (posX - 17) / 2;
        posX = 17;
        posY = 15;
        posY = posY + (blocksOverFlow) * 2;

    }

    else if (posY < 1)
    {
        int blocksOverFlow = (posY - 1) / 2;
        posX = 15;
        posY = 1;
        posY = posY - (blocksOverFlow+1) * 2;
    }


    else if (posY > 15 && oldY < 15 && posX == 15)
    {
        int blocksOverFlow = (posY - 15) / 2;
        posX = 15;
        posY = 15;
        posX = posX - (blocksOverFlow) * 2;
    }

    else if (posX < 1 && oldX < 15)
    {
        int blocksOverFlow = (posX - 1) / 2;
        posY = 17;
        posX = 1;
        posX = posX + ((blocksOverFlow+1)*-1) * 2;
    }
    else if (posX >= 15 && oldX <= 15 && posY == 17 )
    {
        int blocksOverFlow = (posX - 15) / 2;
        posX = 15;
        posY = 15;
        posY = posY + (blocksOverFlow+1)  * 2;
    }
    else if (posY > 31)
    {
        int blocksOverFlow = (posY - 31) / 2;
        posY = 31;
        posX = 17;
        posY = posY - (blocksOverFlow-1) * 2;
    }
    checkWinPlayer1(board,player1,oldY,scoreP1);


}


void checkOutOfBoundsPlayer2(string board[33][33], int &p2X, int &p2Y, bool &outOfMap, int &oldp2X, int &oldp2Y, int &roll,alreadyOnTheBoard &piece, gamePieces player2[6], int &scoreP2)
{
    if (p2X > 31)
    {
        int blocksOverFlow = (p2X - 31) / 2;
        p2X = 31;
        p2Y = 15;
        p2X -= (blocksOverFlow - 1) * 2;
    }

    else if (p2X < 17 && oldp2X >= 17 && oldp2Y == 15)
    {
        int blocksOverFlow = (p2X - 17) / 2;
        p2X = 17;
        p2Y = 15;
        p2Y = p2Y + (blocksOverFlow) * 2;

    }

    else if (p2Y < 1)
    {
        int blocksOverFlow = (p2Y - 1) / 2;
        p2X = 15;
        p2Y = 1;
        p2Y = p2Y - (blocksOverFlow+1) * 2;
    }


    else if (p2Y > 15 && oldp2Y < 15 && p2X == 15)
    {
        int blocksOverFlow = (p2Y - 15) / 2;
        p2X = 15;
        p2Y = 15;
        p2X = p2X - (blocksOverFlow) * 2;
    }

    else if (p2X < 1 && oldp2X < 15)
    {
        int blocksOverFlow = (p2X - 1) / 2;
        p2Y = 17;
        p2X = 1;
        p2X = p2X + ((blocksOverFlow+1)*-1) * 2;
    }
    else if (p2X >= 15 && oldp2X <= 15 && p2Y == 17 )
    {
        int blocksOverFlow = (p2X - 15) / 2;
        p2X = 15;
        p2Y = 15;
        p2Y = p2Y + (blocksOverFlow+1)  * 2;
    }
    else if (p2Y > 31)
    {
        int blocksOverFlow = (p2Y - 31) / 2;
        p2Y = 31;
        p2X = 17;
        p2Y = p2Y - (blocksOverFlow-1) * 2;
    }
    else if (p2X == 17 && oldp2Y >=17 && p2Y <=17)
    {
        int blocksOverFlow = (p2Y - 17) / 2;
        p2X =  17;
        p2Y = 17;
        p2X = p2X - (blocksOverFlow) * 2;
    }
    //        if (p2X == 15 && p2Y >= 13 && oldp2Y <= 13 ){   // finished player 2 fix later

    checkWinPlayer2(board,player2,oldp2Y,scoreP2);





}

void rollPlayer1(int &posX, int &posY, int &roll)
{
    if ( posY == 17)            // if posY != to left side of board, we go down on the board 15 is the left side of the board on bottom half or top half
        posX = posX + roll * 2;  // * 2 because the board itself counts as an element in the array, not just blank spaces
    else if (posY == 15 )
        posX = posX - roll * 2;
    else if (posX == 17)
        posY = posY - roll * 2;
    else if (posY >= 17 && posX == 15)
        posY = posY + roll * 2;
    else if (posX == 15)
        posY = posY + roll * 2;

}

void rollPlayer2(int &p2X, int &p2Y, int &roll)
{

    if ( p2Y == 17)            // if posY != to left side of board, we go down on the board 15 is the left side of the board on bottom half or top half
        p2X = p2X + roll * 2;  // * 2 because the board itself counts as an element in the array, not just blank spaces
    else if (p2Y == 15 )
        p2X = p2X - roll * 2;
    else if (p2X == 17)
        p2Y = p2Y - roll * 2;
    else if (p2Y >= 17 && p2X == 15)
        p2Y = p2Y + roll * 2;
    else if (p2X == 15)
        p2Y = p2Y + roll * 2;

}


void gameLogic(string board[33][33], int &posX, int &posY, int &p2X, int &p2Y, alreadyOnTheBoard &piece, int &roundNumber, bool &outOfMap, int &oldX, int &oldY, int &oldp2X,
               int &oldp2Y, int &roll,gamePieces player1[6], gamePieces player2[6], int &scoreP1, int &scoreP2)
{

    for (int x = 0; x < 33; x ++)   // row
    {
        for (int y = 0; y < 33; y ++)     // column
        {
            if (y > 13 && y < 19 && x % 2 == 0)       // prints out  ----- in the middle of the board
            {
                board[x][y] = "-";
            }
            else if (y == 14 || y == 16 || y == 18 && x % 2 == 1)    // prints out top half and botAAtom  half barriers ->  | | |
            {
                board[x][y] = "|";
                if (x == 15 || x == 16)
                    board[x][y] = " ";
            }
            else if ((x == 15 && y % 2 == 0) || (x == 15 && y % 2 == 1 && board[x][y] == " " && posX == 300000) )    // prints second line of mid board | | | | | etc.
            {
                board[x][y] = "|";
                board[15][14] = "|";      // not sure why these three don't work with the else if  statement above... :@
                board[15][16] = "|";
                board[15][18] = "|";
            }
            else if (x == 14)          // prints 1rst line of mid board ------------------ etc.
            {
                board[x][y] = "-";
            }
            else if (x == 16)      // prints 3rd line of mid board ------------------- etc.
            {
                board[x][y] = "-";
            }
            else if ((x == 17 && y % 2 == 0) || (x == 17 && y % 2 == 1 && board[x][y] == " " && posX == 5755756) )    // prints 3rth line of mid board | | | | | etc. **THIS DOESNT WORK**
            {
                board[x][y] = "|";                       // if check statement works here but not on line 84??? why??? i have to manually set board = to |             **WHAT IS WRONG?**
            }
            else if (x == 18)
            {
                board[x][y] = "-";
            }

            else
            {
                board[x][y] = " ";
            }
        }
    }


    for (int i = 0; i < 6; i++)
    {
        player1[i].symbol = 'A' + i;
        player2[i].symbol = i +  49;

    }

    // used to hold value of dice
    roll = rand() % 6; // random 0-5, this roll is set for player 1
    outOfMap = false; // check this to determine how position X and Y will be moved

    cout << "Round number - " << roundNumber + 1 << endl;


    cout << "Player 1 rolled a " << roll << endl;


    cout << "Player 1 choose your piece: (A, B, C, D, E, F) L (skip turn) " << endl;    // PLAYER 1 PICK #################
    string choosePiece;
    cin >> choosePiece;
    if (choosePiece == "L")
        cout << "Player 1 skipped their  turn" << endl;

    int p1Index = choosePiece[0] - 'A';
    gamePieces *player1GamePiece = &player1[p1Index];


    board[player1GamePiece->coords[0]][player1GamePiece->coords[1]] = player1GamePiece->symbol;     // posX posY set to default player 1 starting spot
    player1GamePiece->played = true;   // player cannot play the piece again



    if (player1GamePiece->finished == false)
    {
        if (player1GamePiece->played == true && roundNumber > 0)
        {
            board[player1GamePiece->coords[0]][player1GamePiece->coords[1]] = " ";

            oldX = player1GamePiece->coords[0];
            oldY = player1GamePiece->coords[1];

            rollPlayer1(player1GamePiece->coords[0],player1GamePiece->coords[1],roll);
            checkOutOfBounds(board,player1GamePiece->coords[0],player1GamePiece->coords[1],p2X,p2Y,outOfMap,oldX,oldY,roll,piece,player1,scoreP1); // if board is above 31, it is out of bounds, move left one, roll - 1 then posX = posX - roll

            board[player1GamePiece->coords[0]][player1GamePiece->coords[1]] = player1GamePiece->symbol;

        }

    }


    if (player1[0].played == true)                       // if player 1 piece is played, place it on the board
    {

        board[player1[0].coords[0]][player1[0].coords[1]] = player1[0].symbol;
        if (player1[0].onlyOnce == false)
        {

        }
    }
    if (player1[1].played == true)
    {
        board[player1[1].coords[0]][player1[1].coords[1]] = player1[1].symbol;
        if (player1[1].onlyOnce == false)
        {

        }
    }
    if (player1[2].played == true)
        board[player1[2].coords[0]][player1[2].coords[1]] = player1[2].symbol;
    if (player1[3].played == true)
        board[player1[3].coords[0]][player1[3].coords[1]] = player1[3].symbol;
    if (player1[4].played == true)
        board[player1[4].coords[0]][player1[4].coords[1]] = player1[4].symbol;
    if (player1[5].played == true)
        board[player1[5].coords[0]][player1[5].coords[1]] = player1[5].symbol;





    player1GamePiece = &player1[p1Index];








    roll = rand() % 6; // set roll again to make sure  they get different values                   // PLAYER 2 STARTS HERE
    cout << "Player 2 rolled a " << roll << endl;
    cout << "Player 2 choose your piece: (1, 2, 3, 4, 5, 6,) L (skip turn) " << endl;        // PLAYER 2 PICK #################
    cin >> choosePiece;

    if (choosePiece == "L")
        cout << "Player 2 skipped their turn." << endl;


    int p2Index = choosePiece[0] - '1';

    gamePieces *player2GamePiece = &player2[p2Index];

    board[player2GamePiece->coords[0]][player2GamePiece->coords[1]] = player2GamePiece->symbol;     // posX posY set to default player 1 starting spot
    player2GamePiece->played = true;   // player cannot play the piece again




    if (player2GamePiece->finished == false)
    {
        if (player2GamePiece->played == true && roundNumber > 0)
        {
            board[player2GamePiece->coords[0]][player2GamePiece->coords[1]] = " ";

            oldp2X = player2GamePiece->coords[0];
            oldp2Y = player2GamePiece->coords[1];

            rollPlayer2(player2GamePiece->coords[0],player2GamePiece->coords[1],roll);
            checkOutOfBoundsPlayer2(board,player2GamePiece->coords[0],player2GamePiece->coords[1],outOfMap,oldp2X,oldp2Y,roll,piece,player2,scoreP2); // if board is above 31, it is out of bounds, move left one, roll - 1 then posX = posX - roll

            board[player2GamePiece->coords[0]][player2GamePiece->coords[1]] = player2GamePiece->symbol;

        }
    }

    if (player2[0].played == true)                                                   //  // if player 2 piece is played already, place it on the board
        board[player2[0].coords[0]][player2[0].coords[1]] = player2[0].symbol;
    if (player2[1].played == true)
        board[player2[1].coords[0]][player2[1].coords[1]] = player2[1].symbol;
    if (player2[2].played == true)
        board[player2[2].coords[0]][player2[2].coords[1]] = player2[2].symbol;
    if (player2[3].played == true)
        board[player2[3].coords[0]][player2[3].coords[1]] = player2[3].symbol;
    if (player2[4].played == true)
        board[player2[4].coords[0]][player2[4].coords[1]] = player2[4].symbol;
    if (player2[5].played == true)
        board[player2[5].coords[0]][player2[5].coords[1]] = player2[5].symbol;




    roundNumber++;


    if (player1[0].finished == true)                   // SET PLAYER 1 COORD TO EMPTY IF WE REACH END .
        board[player1[0].coords[0]][player1[0].coords[1]] = " ";

    if (player1[1].finished == true)
        board[player1[1].coords[0]][player1[1].coords[1]] = " ";

    if (player1[2].finished == true)
        board[player1[2].coords[0]][player1[2].coords[1]] = " ";

    if (player1[3].finished == true)
        board[player1[3].coords[0]][player1[3].coords[1]] = " ";

    if (player1[4].finished == true)
        board[player1[4].coords[0]][player1[4].coords[1]] = " ";

    if (player1[5].finished == true)
        board[player1[5].coords[0]][player1[5].coords[1]] = " ";


    if (player2[0].finished == true)           // SET PLAYER 2 COORD TO EMPTY IF WE REACH END .
        board[player2[0].coords[0]][player2[0].coords[1]] = " ";

    if (player2[1].finished == true)
        board[player2[1].coords[0]][player2[1].coords[1]] = " ";

    if (player2[2].finished == true)
        board[player2[2].coords[0]][player2[2].coords[1]] = " ";

    if (player2[3].finished == true)
        board[player2[3].coords[0]][player2[3].coords[1]] = " ";

    if (player2[4].finished == true)
        board[player2[4].coords[0]][player2[4].coords[1]] = " ";

    if (player2[5].finished == true)
        board[player2[5].coords[0]][player2[5].coords[1]] = " ";



}


int main()
{
    srand (time(NULL));  // set seed
    string board[33][33];   // 2D array for board
    gamePieces player1[6];  // A B C D E F
    gamePieces player2[6];   // 1 2 3 4 5 6
    int posX = 19, posY = 17;    // posX++ = down posX-- = up :  posY++ = right   posY-- = left
    int p2X = 13, p2Y = 15;      // player 2 X and Y coord

    for (int i = 0; i < 6; i ++ )     // INITIALIZE PLAYER 2 COORD
    {
        player2[i].coords[0] = 13;
        player2[i].coords[1] = 15;
    }
    int roundNumber = 0;

    int oldX = 19;
    int oldY = 17;
    int oldp2X = 13;
    int oldp2Y = 15;
    int scoreP1 = 0; // track score player 1
    int scoreP2 = 0; // track score player 2
    int roll = rand() % 6;



    alreadyOnTheBoard piece; // used to determine if the player already has the piece on the board


    bool gameOver = false;
    bool outOfMap = false;
    SetColor(10);

    while (!gameOver)
    {

        printBoard(board,scoreP1,scoreP2);
        gameLogic(board,posX,posY,p2X,p2Y,piece,roundNumber,outOfMap,oldX,oldY,oldp2X,oldp2Y,roll,player1,player2,scoreP1,scoreP2);

        if  (scoreP1 == 6)
        {
            cout << "--PLAYER 1 WINS--" << endl;
            gameOver = true;
        }
        else if (scoreP2 == 6)
        {
            cout << "--PLAYER 2 WINS--" << endl;
            gameOver = true;
        }
        system("CLS");


    }


}
