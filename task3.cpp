#include <iostream>
using namespace std;

void print_Board(char board[3][3]) 
{
    for(int i=0;i<3;++i) 
    {
        for(int j=0;j<3;++j) 
        {
            cout<<board[i][j];
            if(j<2)cout<<" | ";
        }
        cout<<endl;
        if(i<2) 
        {
            cout<<"---------"<<endl;
        }
    }
}

char check_the_draw(char board[3][3]) 
{
    for (int i=0;i<3;++i)
    {
        for (int j=0;j<3;++j) 
        {
            if (board[i][j]==' ')
            {
                return ' ';
            }
        }
    }
    return 'D';
}

char check_the_winear(char board[3][3],char player) 
{
    for (int i=0;i<3;++i) 
    {
        if (board[i][0]==player && board[i][1]==player && board[i][2]==player)
        {
            return player;
        }
        if (board[0][i]==player && board[1][i]==player && board[2][i]==player)
        {
            return player;
        }
    }
    if (board[0][0]==player && board[1][1]==player && board[2][2]==player)
    {
        return player;
    }
    if (board[0][2]==player && board[1][1]==player && board[2][0]==player)
    {       
        return player;  
    }
    return ' ';
}

bool playAgain() 
{
    char choice;
    cout<<"Do you want to play again? (y/n): ";
    cin>>choice;
    return(choice=='y' || choice=='Y');
}

int main() 
{
    do 
    {
        char board[3][3] ={{' ',' ',' '}, {' ',' ',' '},{' ',' ',' '}};
        char currentPlayer='X';
        char result;
        while (true)
        {
            print_Board(board);
            int row,column;
            cout<<"Enter row (1, 2, or 3) for your move: ";
            cin>>row;
            cout<<"Enter column (1, 2, or 3) for your move: ";
            cin>>column;
            if(row>=1&&row<=3&&column>=1&&column<=3&&board[row-1][column-1]==' ')
            {
                board[row-1][column-1]=currentPlayer;
                result=check_the_winear(board,currentPlayer);
                if (result!=' ') 
                {
                    print_Board(board);
                    if (result=='D')
                    {
                        cout<<"It's a draw!"<<endl;
                    } 
                    else 
                    {
                        cout<<"Player "<<result<<" wins!"<<endl;
                    }
                    break;
                }
                result=check_the_draw(board);
                if (result!=' ') 
                {
                    print_Board(board);
                    cout<<"It's a draw!"<<endl;
                    break;
                }
                if (currentPlayer=='X') 
                {
                    currentPlayer='O';
                } 
                else
                {
                    currentPlayer='X';
                }
            } 
            else 
            {
                cout<<"Invalid move. Try again."<<endl;
            }
        }
    } 
    while (playAgain());

    cout << "Thanks for playing!" << endl;
    return 0;
}