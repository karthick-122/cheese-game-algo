#include<iostream>
using namespace std;
#include<String>
#include<vector>


class chess_validator
{
    
    public:vector<vector<string>> array;
    chess_validator()
    {
        vector<vector<string>> ss = {{"BR","BN","BB","BQ","BK","BB","BN","BR"},
                              {"BP","BP","BP","BP","BP","BP","BP","BP"},
                              {"--","--","--","--","--","--","--","--"},
                              {"--","--","--","--","--","--","--","--"},
                              {"--","--","--","--","--","--","--","--"},
                              {"--","--","--","--","--","--","--","--"},
                              {"WP","WP","WP","WP","WP","WP","WP","WP"},
                              {"WR","WN","WB","WQ","WK","WB","WN","WR"} };
        array = ss;
        cout<<"board created"<<endl;
    }

    bool is_rook_ok_there(string from, string to)
    {
        int from_row = '8'-from[0];
        int from_col = from[1]-'A';
        int to_row = '8'-to[0];
        int to_col = to[1]-'A';
         if(array[from_row][from_col][0]==array[to_row][to_col][0])
        return 0;
        //either row or collum should be same
        if(from_row!=to_row && from_col!=to_col)
        {
           // cout<<" ********** wrong move **********"<<endl;
            return 0;
        }
        
        if(from_col == to_col)
        {
            for(int i=from_row+1;i<to_row;i++)
            {
                if(array[i][to_col]!="--")
                {
                   // cout<<"********** there is a coin in betwin *********"<<endl;
                    return 0;
                }
            }
        }
        else
        {
            for(int i=from_col+1;i<to_col;i++)
            {
                if(array[to_row][i]!="--")
                {
                  //  cout<<"********** there is a coin in betwin *********"<<endl;
                    return 0;
                }
            }
        }
       
        return 1;
    }
    bool is_bishop_ok_there(string from, string to)
    {
        cout<<from<<to<<endl<<endl;

        int from_row = '8'-from[0];
        int from_col = from[1]-'A';
        int to_row = '8'-to[0];
        int to_col = to[1]-'A';

        if(array[from_row][from_col][0]==array[to_row][to_col][0])
        {
            
             return 0;
             
        }

        
        // -- botom to leftmtop

        for(int row = from_row-1,col = from_col-1;row>=0 && col>=0;row--,col--)
        {
           
            
                if(row == to_row && col ==to_col)
                return 1;
                if(array[row][col]!="--")
                {
                    
                     break;
                }
               
        }

        // ++ top to right botom

        for(int row = from_row+1,col = from_col+1;row<8 && col<8;row++,col++)
        {
            
                if(row == to_row && col ==to_col)
                return 1;
                if(array[row][col]!="--")
                break;
        }
        //-+ center to top top riht

        for(int row = from_row-1,col = from_col+1;row>=0 && col<8;row--,col++)
        {
            
                if(row == to_row && col ==to_col)
                return 1;
                if(array[row][col]!="--")
                break;
        }
        //+- center to left botom
        for(int row = from_row+1,col = from_col-1;row<8 && col>=0;row++,col--)
        {
            
                if(row == to_row && col ==to_col)
                return 1;
                if(array[row][col]!="--")
                break;
        }
       // cout<<" ********** wrong move **********"<<endl;
        return 0;



    }
    bool is_queen_ok_there(string from, string to)
    {
        return is_rook_ok_there(from,to) ||  is_bishop_ok_there(from,to);
    }

    bool is_king_ok_there(string from, string to)
    {
        int from_row = '8'-from[0];
        int from_col = from[1]-'A';
        int to_row = '8'-to[0];
        int to_col = to[1]-'A';
         if(array[from_row][from_col][0]==array[to_row][to_col][0])
        return 0;

         if(from_row==to_row || from_col==to_col)
        {
            return 1;
        }
        if(from_row+1 ==to_row || from_col+1 ==to_col ||from_row-1 ==to_row || from_col-1 ==to_col)
        {
             return 1;
        }
        return 0;
       
    }

    bool is_Knight_ok_there(string from, string to)
    {

        int x = '8'-from[0];
        int y= from[1]-'A';
        int to_row = '8'-to[0];
        int to_col = to[1]-'A';
         if(array[x][y][0]==array[to_row][to_col][0])
        return 0;


        if(x+2==to_row && (y+1==to_col|| y-1==to_col))
        return 1;
        if(x+1==to_row && (y+2==to_col|| y-2==to_col))
        return 1;
        if(x-1==to_row && (y+2==to_col|| y-2==to_col))
        return 1;
        if(x-2==to_row && (y+1==to_col|| y-1==to_col))
        return 1;

        return 0;

    }

    bool is_pawn_ok_there(string from, string to)
    {
        int from_row = '8'-from[0];
        int from_col = from[1]-'A';
        int to_row = '8'-to[0];
        int to_col = to[1]-'A';
        char ch = array[from_row][from_col][0];

        if(array[from_row][from_col][0]==array[to_row][to_col][0])
        {
            
             return 0;
             
        }
       

        if(from_col==to_col)//abcd
        {
            if(ch =='B' )
            {
                //cout<<"IN PAWN"<<endl;;
                 if(from_row+1 == to_row)
                  return 1;
                  if(from_row ==1 && from_row +2 == to_row)
                return 1;
            }
            if(ch=='W')
            {
                if(from_row-1 == to_row)
                return 1;
                if(from_row ==6 && from_row-2 == to_row)
                return 1;
            }
             
        }
        else
        {
            if(array[to_row][to_col]=="--")
            return 0;
           
                if(ch =='B' )
            {
                  if(from_row+1==to_row && (from_col+1 ==to_col || from_col-1==to_col))
               return 1;
                  
            }
            if(ch=='W')
            {  if(from_row-1==to_row && (from_col+1 ==to_col || from_col-1==to_col))
               return 1;
            }
            if(from_col+1==to_col || from_col-1==to_col)
             return 0;
        }
         return 0;
    }
    bool swap(string from, string to)
    {
        int from_row = '8'-from[0];
        int from_col = from[1]-'A';
        int to_row = '8'-to[0];
        int to_col = to[1]-'A';
       
        array[to_row][to_col]  = array[from_row][from_col];
        array[from_row][from_col] = "--";
      

    }

    void print_the_position()
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cout<<array[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
/*
int main()
{
    chess_validator chess;
    chess.print_the_position();
}*/