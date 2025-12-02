#include <iostream>
#include <vector>
#include <string>
#include "TicTacToeGame.hpp"
using namespace std;

TicTacToeGame::TicTacToeGame()
{
    tttBoard=TicTacToeBoard();
}


  TicTacToeGame::TicTacToeGame( int size)
  {
    tttBoard=TicTacToeBoard(size);
  }
  void TicTacToeGame::runRepeat()
  {
    string ans;
    do
    {
        tttBoard.clear();
        start();
        cout << "Do you want to continue (yes/no): ";
        cin >> ans;

    }while(ans=="Y"||ans == "y");

  }

  //start to play the game
  void TicTacToeGame::start()
  {
    int counter=1;
    do
    {
    cout<<tttBoard.to_string()<<endl;
    
    if(counter%2==1)
    {
      humanPlay();
      
    }
    else
    {
      computerPlay();
      
    }
    counter++;
  }while(!isGameOver());


  }

  bool TicTacToeGame::isGameOver() const
  {
  
    if(tttBoard.tie())
    {
      cout<<"It is a tie."<<endl;
      return true;
        

    }
    if(tttBoard.getValue(currRow,currCol)=='X'||tttBoard.win(currRow,currCol))
    {
      cout<<"Human wins. Yay!!!."<<endl;
      return true;
    }
    if(tttBoard.getValue(currRow,currCol)=='O'||tttBoard.win(currRow,currCol))
    {
      cout<<"Computer wins. Yuck."<<endl;
      return true;
        

    }
    return false;

  }

  //This is how the user plays:
  //Enter row and col such that
  //1. row is in [0, size -1]
  //2. col is in [0, size -1]
  //3. the corresponding cell in the board is available
  // (hint: call board.getValue(row, col) to check the return is 0 ornot).
  //As long as the input row or col is not valid
  //begin
  // prompt what error(s) are, for example ,
  // * row is not in [0, size -1]
  // * col is not in [0, size -1]
  // * the corresponding cell in board is not available
  // prompt user to re-enter.
  //end
  //
  //Once we exit the above repetition loop,
  //row and col are valid ,
  //mark the corresponding cell in the board by HUMAN_ID.
  void TicTacToeGame::humanPlay()
  {
    int r;
    int c;
    do{
    
    cout<<"Enter row"<<endl;
    while (true) {
   
    if (cin >> r) {
        if (r >= 0 && r < tttBoard.size()) {
            break; 
        } else {
            cout << "invalid, re enter,number in range" << endl;
        }
    } else {
        cout << "invalid, re enter int" << endl;
        cin.clear();             
        cin.ignore(1000, '\n');  
    }
}
   
    cout<<"Enter col"<<endl;
    while (true) {
   
    if (cin >> c) {
        if (c >= 0 && c < tttBoard.size()) {
            break; 
        } else {
            cout << "invalid, re enter,number in range" << endl;
        }
    } else {
        cout << "invalid, re enter int" << endl;
        cin.clear();             
        cin.ignore(1000, '\n');  
    }
}
    }while(!tttBoard.isAvailable(r,c));
    currCol=c;
    currRow=r;
     
    tttBoard.mark(r,c,HUMAN_ID);

  }

  //computer play
  //Computer checks the board from the first row to the last row.
  //In each row, the computer checks from the first column to the lastcolumn.
  //A more sophisticated approach is to use "mark first; if unfit , thenremove mark"
  //1. Try to win first.
  // Mark an available cell by computerId ,
  // if this leads to win by computer ,
  // take this cell and return ,
  // otherwise , do not take this cell (that is, set this cell to beavailable).
  //2. Try to block the opponent from winning.
  // This approach is adopted after the try-to-win approach fails.
  // Mark an available cell by userId (that is, suppose this cell istaken by userId),
  // if this leads to win by user,
  // mark this cell by computerId , and return.
  // otherwise , do not take this cell (that is, set this cell to beavailable).
  //3. If neither one of the above two approaches works
  // (that is, the computer does not take a cell yet),
  // then mark the first available cell.
  void TicTacToeGame::computerPlay()
  {
    int tr,tc;
    bool tag=false;
   
    for(int i=0;i<tttBoard.size();i++)
    {
      for(int j=0;j<tttBoard.size();j++)
      {
        if(!tag)
        {
          if(tttBoard.isAvailable(i,j))
          {
            tag=true;
            tr=i;
            tc=j;
          }
        }

        tttBoard.mark(i,j,COMPUTER_ID);
          if(tttBoard.win(i,j))
          {
            return;
          }

          tttBoard.mark(i,j,HUMAN_ID);
          if(tttBoard.win(i,j))
          {
            tttBoard.mark(i,j,COMPUTER_ID);
            return;
          }
          tttBoard.mark(i,j,' ');
          
          

      }
      
    }
    currCol=tc;
    currRow=tr;
    tttBoard.mark(tr,tc,COMPUTER_ID );


  }