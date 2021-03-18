#include "Class.h"

void Class::LoadPage()
{
	ifstream in;
	string str;
	string temp;
	int i = 0;

	in.open("music.txt");
	if (!in)
	{
		cout << "Error";
		return;
	}
	while(!in.eof())
	{	
		getline(in, temp);
		str += temp + '\n';
		i++;
		if (i == 40)
		{
			vec.push_back(str);
			i = 0;
			str = "";
		}
	}
}

void Class::Menu()
{
	cout << "\ns - переход на следующую страницу\n";
	cout << "w - переход на предыдущую страницу\n";
	cout << "z - Убрать символы латинского алфавита\n";
	cout << "x - Убрать символы кириллицы\n";
	cout << "c - Убрать символы пунктуации\n";
	cout << "v - Убрать цифры\n";
	cout << "Чтобы убрать изменения нажмите повторно на ту же клавишу\n";
	cout << "Чтобы выйти нажмите Esc\n";
}

void Class::DeleteDigit(string &copy)
{
	replace_if(copy.begin(), copy.end(), isdigit, ' ');
}

void Class::DeleteLatin(string &copy)
{
	replace_if(copy.begin(), copy.end(), [copy](char s) { if (s >= 'A' && s <= 'z') 
	                                                      { 
		                                                      return true; 
	                                                      } 
	                                                      else 
		                                                      return false; }, ' ');
}

void Class::DeleteCyrillic(string &copy)
{
	replace_if(copy.begin(), copy.end(), [copy](char s) { if (s == 'ё' || s == 'Ё' || s >= 'А' && s <= 'я' )
	                                                      {
		                                                      return true;
	                                                      }
	                                                      else
	                                                          return false; }, ' ');
}

void Class::DeletePunct(string &copy)
{
	replace_if(copy.begin(), copy.end(), ispunct, ' ');
}

void Class::Filters(int key)
{
	switch (key)
	{
	case Z: 
	case z:
		filters[Latin] = !filters[Latin];
		break;
	case X: 
	case x:
		filters[Cyrillic] = !filters[Cyrillic];
		break;
	case C: 
	case c:
		filters[Punct] = !filters[Punct];
		break;
	case V:
	case v:
		filters[Digit] = !filters[Digit];
		break;
	}
}

void Class::Modification(int key, string page)
{
	Filters(key);
	string copy = page;
	for (int i = 0; i < 4; i++)
	{
		if (filters[i])
		{
			mod[i](copy);
		}
	}
	cout << copy;
}

void Class::PrintPage()
{
	LoadPage();
	vector<string>::iterator it(vec.begin());
	cout << *it;
	while (true)
	{
		Menu();
		int key = _getch();
		system("cls");
		if ((key == W || key == w) && page > 1)
		{
			cout << *--it;
			page--;
		}
		else if ((key == S || key == s) && page < vec.size())
		{
			cout << *++it;
			page++;
		}
		else if (key == Z || key == z || key == X || key == x ||
		         key == C || key == c || key == V || key == v)
		{
			Modification(key, *it);
		}
		else if (key == Esc)
		{
			return;
		}
	}
}