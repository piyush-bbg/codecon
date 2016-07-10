#include <iostream>
using namespace std;

#define N 16
#define M 16

int mat[N][M];
int i = 0;
int j = 0;
int no_of_flips = 0;


bool check_down(int m, int n)
{
  if (m > 0)
    return mat[m-1][n] == 1;
  else
    return true;
}

bool check_up(int m, int n)
{
  if ( m < i -1)
    return mat[m+1][n] == 1;
  else
    return true;
}

bool check_right(int m, int n)
{
  if ( n < j -1)
    return mat[m][n+1] == 1;
  else
    return true;
}

bool check_left(int m, int n)
{
  if ( n > 0)
    return mat[m][n-1] == 1;
  else
    return true;
}

void flip_down(int m, int n)
{
  if (m > 0)
    {
      mat[m-1][n] = mat[m-1][n]? 0 : 1;
    }
}

void flip_up(int m, int n)
{
  if ( m < i - 1)
    {
      mat[m+1][n] = mat[m+1][n]? 0 : 1;
    }
}

void flip_right(int m, int n)
{
  if ( n < j - 1)
    {
      mat[m][n+1] = mat[m][n+1]? 0 : 1;
    }
}

void flip_left(int m, int n)
{
  if ( n > 0)
    {
      mat[m][n-1] = mat[m][n-1]? 0 : 1;
    }
}

void flip_self(int m, int n)
{
  mat[m][n] = mat[m][n]? 0 : 1;
}


bool match_pattern( int row, int col)
{
  if ( mat[row][col] == 1)
    {
      if (check_left(row,col) && check_right(row,col) && check_down(row,col) && check_up(row,col))
	{
	  cout << "mat["<<row<<"]["<<col<<"]"<<"\n";
	  flip_self(row,col);
	  flip_left(row,col);
	  flip_right(row,col);
	  flip_down(row,col);
	  flip_up(row,col);
	  no_of_flips++;
	  return true;
	}
      else if (check_left(row,col) && check_right(row,col) && check_down(row,col) && !check_up(row,col) && row > 0 && col > 0 && col < j -1)
	{
	  cout << "up: mat["<<row<<"]["<<col<<"]"<<"\n";
	  mat[row+1][col] = 1;
	  if (row+2 < i)
	    {
	      if (match_pattern(row+2, col))
		{
		  no_of_flips++;
		  match_pattern(row, col);
		  no_of_flips++;
		}
	      else
		mat[row+1][col] = 0;
	    }
	}
      else if (check_left(row,col) && check_right(row,col) && check_up(row,col) && !check_down(row,col) && row < i -1 && col > 0 && col < j -1)
	{
	  cout << "down : mat["<<row<<"]["<<col<<"]"<<"\n";
	  mat[row-1][col] = 1;
	  if (row - 2  > 0)
	    {
	      if (match_pattern(row-2, col))
		{
		  no_of_flips++;
		  match_pattern(row, col);
		  no_of_flips++;
		}
	      else
		mat[row-1][col] = 0;
	    }
	}
      else if (check_left(row,col) && check_down(row,col) && check_up(row,col) && !check_right(row,col) && col > 0 && row > 0 && row < i -1)
	{
	  cout << "right : mat["<<row<<"]["<<col<<"]"<<"\n";
	  mat[row][col+1] = 1;
	  if (col + 2  < j)
	    {
	      if (match_pattern(row, col+2))
		{
		  no_of_flips++;
		  mat[row][col+1] = 1;
		  match_pattern(row, col);
		  no_of_flips++;		  
		}
	      else
		mat[row][col+1] = 0;
	    }
	}
      else if (check_right(row,col) && check_down(row,col) && check_up(row,col) && (!check_left(row,col)) && col < j-1 && row > 0 && row < i -1)
	{
	  cout << "left : mat["<<row<<"]["<<col<<"]"<<"\n";
	  mat[row][col+1] = 1;
	  if (col - 2  > 0)
	    {
	      if (match_pattern(row, col-2))
		{
		  no_of_flips++;
		  match_pattern(row, col);
		  no_of_flips++;		  
		}
	      else
		mat[row][col+1] = 0;
	    }
	}

      return false;
    } 
  return false;
}

bool match_pattern_3( int row, int col)
{
  if ( mat[row][col] == 1)
    {
      if (check_left(row,col) && check_right(row,col) && check_down(row,col) && check_up(row,col))
	{
	  cout << "mat["<<row<<"]["<<col<<"]"<<"\n";
	  flip_self(row,col);
	  flip_left(row,col);
	  flip_right(row,col);
	  flip_down(row,col);
	  flip_up(row,col);
	  no_of_flips++;
	  return true;
	}
      else if (check_left(row,col) && check_right(row,col) && check_down(row,col) && !check_up(row,col) )
	{
	  cout << "up: mat["<<row<<"]["<<col<<"]"<<"\n";
	  //	  mat[row+1][col] = 1;
	  if (row+2 < i)
	    {
	  flip_self(row,col);
	  flip_left(row,col);
	  flip_right(row,col);
	  flip_down(row,col);
	  flip_up(row,col);
	  no_of_flips++;
	      
	      // match_pattern(row+2, col)	      
	      // 	{
	      // 	  no_of_flips++;
	      // 	  match_pattern(row, col);
	      // 	  no_of_flips++;
	      // 	}
	      // else
	      // 	mat[row+1][col] = 0;
	    }
	}
      else if (check_left(row,col) && check_right(row,col) && check_up(row,col) && !check_down(row,col) )
	{
	  cout << "down : mat["<<row<<"]["<<col<<"]"<<"\n";
	  //	  mat[row-1][col] = 1;
	  if (row - 2  > 0)
	    {

	  flip_self(row,col);
	  flip_left(row,col);
	  flip_right(row,col);
	  flip_down(row,col);
	  flip_up(row,col);
	  no_of_flips++;

	      // match_pattern(row-1, col);
	      // mat[row-1][col] = 1;

	      // if (match_pattern(row-2, col))
	      // 	{
	      // 	  no_of_flips++;
	      // 	  match_pattern(row, col);
	      // 	  no_of_flips++;
	      // 	}
	      // else
	      // 	mat[row-1][col] = 0;
	    }
	}
      else if (check_left(row,col) && check_down(row,col) && check_up(row,col) && !check_right(row,col) )
	{
	  cout << "right : mat["<<row<<"]["<<col<<"]"<<"\n";
	  //	  mat[row][col+1] = 1;
	  if (col + 2  < j)
	    {
	  flip_self(row,col);
	  flip_left(row,col);
	  flip_right(row,col);
	  flip_down(row,col);
	  flip_up(row,col);
	  no_of_flips++;

	      // match_pattern(row, col+1);

	      // mat[row][col+1] = 1;

	      // if (match_pattern(row, col+2))
	      // 	{
	      // 	  no_of_flips++;
	      // 	  mat[row][col+1] = 1;
	      // 	  match_pattern(row, col);
	      // 	  no_of_flips++;		  
	      // 	}
	      // else
	      // 	mat[row][col+1] = 0;
	    }
	}
      else if (check_right(row,col) && check_down(row,col) && check_up(row,col) && (!check_left(row,col)) )
	{
	  cout << "left : mat["<<row<<"]["<<col<<"]"<<"\n";
	  //	  mat[row][col-1] = 1;

	  if (col - 2  > 0)
	    {
	  flip_self(row,col);
	  flip_left(row,col);
	  flip_right(row,col);
	  flip_down(row,col);
	  flip_up(row,col);
	  no_of_flips++;

	      // match_pattern(row, col-1);
	      // mat[row][col-1] = 1;

	      // if (match_pattern(row, col-2))
	      // 	{
	      // 	  no_of_flips++;
	      // 	  match_pattern(row, col);
	      // 	  no_of_flips++;		  
	      // 	}
	      // else
	      // 	mat[row][col+1] = 0;
	    }
	}

      return false;
    } 
  return false;
}

int flip_pattern_4()
{
  int row = 0;
  int col = 0;

  for (row = 0; row < i ; row++)
    {
      for (col = 0;col < j; col++)
	{
	  match_pattern(row,col);	    
 	}
    }
}


int flip_pattern_3()
{
  int row = 0;
  int col = 0;

  for (row = 0; row < i ; row++)
    {
      for (col = 0;col < j; col++)
	{
	  match_pattern_3(row,col);	    
 	}
    }
}

int main() 
{
  int val = 0;

  cin>>i;
  cin>>j;

 int row = 0; 
 int col = 0;
  

  for (row = 0; row < i ; row++)
    {
      for (col = 0;col < j; col++)
	{
	  cin>>val;
	  mat[row][col] = val; 
	}
    }


  int res = flip_pattern_4();
  res = flip_pattern_3();
  res = flip_pattern_4();



  for (row = 0; row < i ; row++)
    {
      for (col = 0;col < j; col++)
	{
	  cout<< mat[row][col] << " " ;
	}
      cout<<"\n";
    }

  return 0;
}
