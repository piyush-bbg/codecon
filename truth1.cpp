#include <iostream>
using namespace std;

int i, j;
bool is_first_assert = true;
int count_false = 0;

class species
{
public:

  species(type, serial_no):
    , _type(type)
    , _serial_no(serial_no)
  {
    
  }

  int _type;// 0, 1, 2, ,3
  int _serial_no;
  std::vector<int> _is_identical;


};

std::map<int, *species> map_species;

bool check_assert_2(int m, int n)
{
  if ( m == 1 && n == 2)
    return true;
  if ( m == 2 && n == 3)
    return true;
  if ( m == 3 && n == 1)
    return true;

  return false;
}

void is_true( int asst, int x, int y)
{

  if (x > i || y > i)
    {
      ++count_false;
      return;
    }

  std::map<int, species>::iterator it;
  std::map<int, species>::iterator it1;
  species* s1, s2;

  switch(asst)
    {
    case 1:
      if (x == y)
	{
	  return ;
	}
      
      bool is_s1_new = true;
      bool is_s2_new = true;

      it = map_species.find(x);
      if (it != map_species.end())
	{
	  s1 =static_cast<species*>(it->second);
	  is_s1_new = false;
	}
      else
	s1 = new species(0,x);
	  
      it1 = map_species.find(y);
      if (it1 != map_species.end())
	{
	  s2 =static_cast<species*>(it1->second);
	  is_s2_new = false;
	}
      else
	s2 = new species(0,y);

      if (!is_s2_new && !is_s1_new)
	{
	  // s1->_is_identical.push_back(y);
	  // s2->_is_identical.push_back(x);

	  if (s1->_type != 0 && s2->_type!=0)
	    {
	      if (s1->_type != s2->_type)
		++count_false;
	      return;
	    }
	  else if (s2->_type != 0)
	    {
	      s1->_type  = s2->_type;
	      s1->recursive_type();
	    }
	  else if (s1->_type != 0)
	    {
	      s2->_type  = s1->_type;
	      s2->recursive_type();
	    }
	  else
	    {
	      s1->_is_identical.push_back(y);
	      s2->_is_identical.push_back(x);
	    }

	  return;
	}
      
      if (!is_s1_new)
	{
	  s2->_type = s1->_type;
 	  if (s2->type !=0)
	    s2->recursive_type();
	}
      else if(!is_s2_new)
	{
	  s1->_type = s2->_type;
	  if (s1->type !=0)
	    s1->recursive_type();
	}
      else
	{
	  s1->_is_identical.push_back(s2);
	  s2->_is_identical.push_back(s1);
	  map_species.insert(std::pair<int, species*>(x,s1));
	  map_species.insert(std::pair<int, species*>(y,s2));
	}
      break;
      ////////////////////////////////////////////////////////
    case 2:
      if (x == y)
	{
	  ++count_false;
	  return ;
	}
      bool is_s1_new = true;
      bool is_s2_new = true;

      it = map_species.find(x);
      if (it != map_species.end())
	{
	  s1 =static_cast<species*>(it->second);
	  is_s1_new = false;
	}
      else
	s1 = new species(0,x);
	  
      it1 = map_species.find(y);
      if (it1 != map_species.end())
	{
	  s2 =static_cast<species*>(it1->second);
	  is_s2_new = false;
	}
      else
	s2 = new species(0,y);

      if (!is_s2_new && !is_s1_new)
	{
	  if (s1->_type !=0 &&  s2->_type !=0)
	    {
	      if (!check_assert_2(s1->_type , s2->_type))
		{
		  ++count_false;
		}

	      return;
	    }
	  else
	    {
	      ++count_false;
	      return;
	    }
	}
      if (!is_s1_new)
	{
	  
	}
      else if(is_s2_new)
	{

	}
      else
	{
	  if (is_first_assert)
	    {
	      s1

	    }

	}

	  s2->_is_identical.push_back(s1);
	  map_species.insert(std::pair<int, species*>(x,s1));
	  map_species.insert(std::pair<int, species*>(y,s2));
	  break;


      break;
    default:
      ++count_false;
      return;
    }      
}

int main()
{
  cin >> i;
  cin >> j;
  
  int a, s1 ,s2;

  for (int count = 0; count < j ; count++)
    {
      cout << "Please enter your input\n" ;
      stat.num = count;
      cin >> a >> s1 >> s2;

      is_true(a,s1,s2);
    }

  cout << false_count <<"\n";

}
