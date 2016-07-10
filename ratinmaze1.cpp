/*
Backtracking | Set 2 (Rat in a Maze)
We have discussed Backtracking and Knight’s tour problem in Set 1. Let us discuss Rat in a Maze as another example problem that can be solved using Backtracking.
 
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach destination. The rat can move only in two directions: forward and down.
In the maze matrix, 0 means the block is dead end and 1 means the block can be used in the path from source to destination. Note that this is a simple version of the typical Maze problem. For example, a more complex version can be that the rat can move in 4 directions and a more complex version can be with limited number of moves.
 
Following is an example maze.
 
 Gray blocks are dead ends (value = 0). 
*/
 
#include <stdio.h>
#include <vector>
#include <queue>
#define SIZE 9001
 
using namespace std;
 
struct node
{
  int x, y, dist;
 
  void set(int x, int y, int dist)
  {
    this->x = x;
    this->y = y;
    this->dist = dist;
  }
};
 
int m, n;
int maze[SIZE][SIZE];
bool visited[SIZE][SIZE];
queue <struct node> q;
 
void init()
{
  int i, j;
 
  for(i = 0 ; i < m ; i++)
    for(j = 0 ; j < n ; j++)
      visited[i][j] = false;
}
 
int up(struct node b)
{
  int x, y, dist;
 
  x = b.x - 1;
  y = b.y;
  dist = b.dist + 1;
  if(x == m - 1 && y == n - 1 && maze[x][y])
    return dist;
  else if(x >= 0 && maze[x][y] && !visited[x][y])
    {
      visited[x][y] = true;
      struct node p;
      p.set(x, y, dist);
      q.push(p);
    }
 
  return -1;
}
 
int down(struct node b)
{
  int x, y, dist;
 
  x = b.x + 1;
  y = b.y;
  dist = b.dist + 1;
  if(x == m - 1 && y == n - 1 && maze[x][y])
    return dist;
  else if(x < m && maze[x][y] && !visited[x][y])
    {
      visited[x][y] = true;
      struct node p;
      p.set(x, y, dist);
      q.push(p);
    }
 
  return -1;
}
 
int left(struct node b)
{
  int x, y, dist;
 
  x = b.x;
  y = b.y - 1;
  dist = b.dist + 1;
  if(x == m - 1 && y == n - 1 && maze[x][y])
    return dist;
  else if(y >= 0 && maze[x][y] && !visited[x][y])
    {
      visited[x][y] = true;
      struct node p;
      p.set(x, y, dist);
      q.push(p);
    }
 
  return -1;
}
 
int right(struct node b)
{
  int x, y, dist;
 
  x = b.x;
  y = b.y + 1;
  dist = b.dist + 1;
  if(x == m - 1 && y == n - 1 && maze[x][y])
    return dist;
  else if(y < n && maze[x][y] && !visited[x][y])
    {
      visited[x][y] = true;
      struct node p;
      p.set(x, y, dist);
      q.push(p);
    }
 
  return -1;
}
 
int calculateShortestDist()
{
  struct node b;
  int val;
 
  b.set(0, 0, 1);
  q.push(b);
  visited[0][0] = true;
 
  if(m == 1 && n == 1 && maze[0][0])
    return 1;
  else if(m == 1 && n == 1 && !maze[0][0])
    return -1;
  while(!q.empty())
    {
      b = q.front();
      val = up(b);
      if(val != -1)
	return val;
      val = down(b);
      if(val != -1)
	return val;
      val = left(b);
      if(val != -1)
	return val;
      val = right(b);
      if(val != -1)
	return val;
      q.pop();
    }
 
  return -1;
}
 
int main()
{
  int i, j, val;
 
  init();
  scanf("%d %d", &m, &n);
  for(i = 0 ; i < m ; i++)
    for(j = 0 ; j < n ; j++)
      scanf("%d", &maze[i][j]);
 
  val = calculateShortestDist();
  if(val != -1)
    printf("%d\n", val);
  else
    printf("No path exist\n");
 
  return 0;
}
