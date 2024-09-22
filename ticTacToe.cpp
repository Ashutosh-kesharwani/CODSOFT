#include<iostream>
#include<vector>
#include<limits>
using namespace std;
void displayGameBoard(vector<vector<char>> &gameBoard){
   cout<<"\n";
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cout<<" "<<gameBoard[i][j]<<" ";
      if(j<2) cout<<"|";
    }
    cout<<"\n";
    if(i<2) cout<<"---|---|---\n";
   }
   cout<<"\n";
   return;
}
bool checkWin(vector<vector<char>>&gameBoard,char currentPlayer){
   // Check If Same Row Is Filled || If Same Col Is Filled By One Of The Player
   for(int i=0;i<3;i++){
    if(gameBoard[i][0]==currentPlayer && gameBoard[i][1]==currentPlayer && gameBoard[i][2]==currentPlayer || 
    gameBoard[0][i]==currentPlayer && gameBoard[1][i]==currentPlayer && gameBoard[2][i]==currentPlayer) return true;
   }
   // Check If Either Of The Diaginal Is Filled By One Of The Player 
   if(gameBoard[0][0]==currentPlayer && gameBoard[1][1]==currentPlayer && gameBoard[2][2]==currentPlayer ||
      gameBoard[0][2]==currentPlayer && gameBoard[1][1]==currentPlayer && gameBoard[2][0]==currentPlayer) return true;

      return false;
}
bool checkDraw(vector<vector<char>> &gameBoard){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(gameBoard[i][j]!='X' && gameBoard[i][j]!='O') return false;
    }
  }
  return true;
}
char switchPlayer(char currentPlayer){
  return (currentPlayer=='X') ? 'O': 'X';
}
void resetGameBoard(vector<vector<char>> &gameBoard){
    char pos='1';
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        gameBoard[i][j]=pos++;
      }
    }
    return;
}
void playGame(){

  cout<<"Welcome For The Tic Tac Toe Game  (: \n";
  vector<vector<char>> gameBoard(3,vector<char>(3));

  resetGameBoard(gameBoard); // Reset The Game Board For Next Game 
  
  char currentPlayer='X';
  string Player1,Player2;
  cout<<"Player 1 Enter Your Name : ";
  cin>>Player1;

  cout<<"Player 2 Enter Your Name : ";
  cin>>Player2;
  cout<<"\n";
  // Tell Player Their Symbol Of Game 
  cout<<"Player 1 : "<<Player1<<"\tYour Symbol For Game Is  X \n";
  cout<<"Player 2 : "<<Player2<<"\tYour Symbol For Game Is  O \n";
  cout<<"\n";
  bool isGameWin= false, isGameDraw=false;
  while(!isGameWin && !isGameDraw){
    displayGameBoard(gameBoard);

    int move;
    if(currentPlayer=='X')  cout<<"Player :  "<<Player1<<"\tEnter Your Move (1 to 9 ) :   ";
    else  cout<<"Player :  "<<Player2<<"\tEnter Your Move (1 to 9 ) :   ";
    while(!(cin>>move) || move<1 || move>9){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"Invalid Move | Please Enter B/w [1 to 9] :  ";
    }

    int row=(move-1)/3;
    int col= (move-1)%3;
    if(gameBoard[row][col]!='X' && gameBoard[row][col]!='O'){
      gameBoard[row][col]=currentPlayer;

      isGameWin=checkWin(gameBoard,currentPlayer);
      if(isGameWin){
        displayGameBoard(gameBoard);
        if(currentPlayer=='X') cout<<"Player : "<<Player1<<"\tWins !! \n";
        else cout<<"Player : "<<Player2<<"\tWins !! \n";
         cout<<"Congratulations !!!! (:  \n";

      }
      else{
        isGameDraw= checkDraw(gameBoard);
        if(isGameDraw){
          displayGameBoard(gameBoard);
          cout<<"It's A Draw !! \n";
        }
        else{
          currentPlayer= switchPlayer(currentPlayer);
        }
      }
    }
    else{
      cout<<"Invalid !!! |  That Place Is Already Filled \n";
    }
  }
  
}
int main(){
  char playAgain;
  do{
    playGame();
    cout<<"Do You Want to Play Again !!! | Please Press (y/Y->Yes & n/N-> No)   :  ";
    cin>>playAgain;
    while(playAgain!='y' && playAgain!='Y' && playAgain!='n' && playAgain!='N'){
      cout<<"Invalid I/P !!! | Please Press (y/Y->Yes & n/N-> No) :   ";
      cin>>playAgain;
    }
  }while(playAgain=='y' || playAgain=='Y');
  cout<<"Thank For Playing ! (:  \n";
  return 0;
}