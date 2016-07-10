#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int i;
std::map<string, int> names;

bool is_palindrome(std::string str)
{
  for(int j = 0; j < str.length()/2 ; j++)
    {
      if (str[j] != str[str.length() - j -1])
	return false;
    }
  return true;
}


int main()
{
  cin >> i;
  std::string input;
  std::map<string, int>::iterator it;
  int no_of_pairs = 0;

  for (int count = 0; count < i ; count ++)
    {
      cin >> input;
      if (!is_palindrome(input))
	{
	  it = names.find(input);
	  
	  std::pair<std::map<string,int>::iterator,bool> ret;
	  if (it == names.end())
	    {
	      std::reverse(input.begin(),input.end());
	      ret = names.insert(std::pair<string, int>(input,1));
	      if (ret.second == false)
		{
		  ret.first->second++;
		}
   
	      it->second++;
	    }
	  else
	    {
	      it->second--;
	      no_of_pairs++;
	    }
	}
    }
  

  for (it = names.begin(); it!= names.end(); ++it)
    {
      if (it->second != 0)
	{
	  no_of_pairs = -1;
	  break;
	}
    }
  cout << no_of_pairs <<endl;
  return 0;
}
