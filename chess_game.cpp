#include "chess-validator.cpp"
#include <bits/stdc++.h>
class chess_game
{
    chess_validator chs;
    string start;
    string end;

    public:

    bool move_from_to(string start,string to)
    {
        reverse(start.begin(), start.end());
         reverse(to.begin(), to.end());

        int from_row = '8'-start[0];
        int from_col = start[1]- 'A';

     
       char coin = chs.array[from_row][from_col][1];

        if(coin =='P')
        {
            if(chs.is_pawn_ok_there(start,to))
            {
                
                chs.swap(start,to);
                return 1;
            }
        }
        else if(coin =='R')
        {
            if(chs.is_rook_ok_there(start,to))
            {
                chs.swap(start,to);
                return 1;
            }
        }
        else if(coin=='N')
        {
            if(chs.is_Knight_ok_there(start,to))
            {
                 chs.swap(start,to);
                return 1;
            }
        }
        else if(coin =='B')
        {
            
            if(chs.is_bishop_ok_there(start,to))
            {
                
                chs.swap(start,to);
                return 1;
            }
        }
        else if(coin == 'Q')
        {
            if(chs.is_queen_ok_there(start,to))
            {
                chs.swap(start,to);
                return 1;
            }
        }
        else if(coin=='K')
        {
            if(chs.is_king_ok_there(start,to))
            {
                chs.swap(start,to);
                return 1;
            }
        }
        cout<<"---------------Wrong move------------------"<<endl;
         return 0;

        
        

    }
    bool boot_the_game()
    {
        cout<<" ------------ WELCOME TO THE GAME OF CHESS -------"<<endl<<endl;
        
        start = " hi";
        string turn = "white";
        while(start!="EXIT")
        {
            
            cout<<endl<<"player : "<<turn<<" move"<<endl;
            cout<<"ENTER YOUR MOVES START AND END AS ROW: COL num and alpa: "<<endl;
            cin>>start>>end;
            if(start=="EXIT")
               break;

           while(! move_from_to(start,end))// if wrong and to continue with same persion
           {
            cout<<" WRONG INPUT PLEASE TRY AGAIN "<<endl;
            cout<<endl<<"player : "<<turn<<" move"<<endl;
            cout<<"ENTER YOUR MOVES START AND END AS ROW: COL num and alpa: "<<endl;
            cin>>start>>end;
           }

           chs.print_the_position();
           
           if(turn=="white")
            {
                turn = "black";
            }
            else
            turn = "white";
        }
    }


};

int main()
{
    chess_game ch;
    ch.boot_the_game();
}