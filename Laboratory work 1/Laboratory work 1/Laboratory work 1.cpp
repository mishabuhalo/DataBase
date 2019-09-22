
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int Length = 80;
const int SizeOfUsers = 10;

struct Discipline
{
	string Name;
	string CountOfPlayers;
	string ListOfPlayers;
};

struct Players 
{
	string Name;
	string Role;
	string Nickname;
};

Discipline *root = new Discipline[SizeOfUsers];
Players *rootp = new Players[SizeOfUsers];

int get_m(string id, string ind, int n, string disciplines)
{
	int i = 0, position = 0;
	string s;
	bool flag = false;

	ifstream fin(ind);
	while (!fin.eof())
	{
		fin >> i;
		fin >> s;

		if (s == id)
		{
			flag = true;
			position = i;
		}
	}
	fin.close();

	if (flag)
	{
		i = 0;
		ifstream fin(disciplines);
		while (!fin.eof())
		{
			getline(fin, root[i].Name);
			getline(fin, root[i].CountOfPlayers);
			getline(fin, root[i].ListOfPlayers);
			i++;
			getline(fin, s);
		}
		return position;
	}
	else return -1;
}

void insert_m(string List, string Names)
{
	Discipline *tmp = new Discipline;
	cout << "Name: ";
	cin >> tmp->Name;
	cout << "\nCount of players: " << endl;
	cin >> tmp->CountOfPlayers;
	string s1 = tmp->Name;
	s1 += "Players";
	tmp->ListOfPlayers = s1;

	int i = 0, position = 0;
	string s;
	bool flag = false;

	ifstream fin(List);
	if (!fin.fail())
	{
		while (!fin.eof())
		{
			fin >> i;
			fin >> s;
		}
		fin.close();
	}

	
	i += 1;

	ofstream fin1(Names, ios::app);
	fin1 << tmp->Name << endl;
	fin1 << tmp->CountOfPlayers << endl;
	fin1 << tmp->ListOfPlayers;
	fin1 << "\n";
	fin1 << "\n";
	fin1.close();

	ofstream fin2(List, ios::app);
	fin2 << i << " " << tmp->Name << endl;
}
void insert_s(string List, string Names)
{
	int i, r;
	string s;
	cout << "List of disciplines:" << endl;
	ifstream fin(List);
	if (!fin.fail())
	{
		while (!fin.eof())
		{
			fin >> i;
			fin >> s;
			cout << i << " " << s << endl;
		}
		cout << endl;
	}
	cout << "Choose discipline by name : ";
	cin >> s;
	r = get_m(s, List, Length, Names) - 1;
	string temp = root[r].ListOfPlayers;

	Players *tempr = new Players;
	cout << "Name: ";
	cin >> tempr->Name;
	cout << endl;
	cout << "Role: ";
	cin >> tempr->Role;
	cout << endl;
	cout << "Nickname: ";
	cin >> tempr->Nickname;
	cout << endl;
	cout << endl;

	ofstream fin1(temp, ios::app);
	fin1 << tempr->Name << endl;
	fin1 << tempr->Role << endl;
	fin1 << tempr->Nickname << endl;
	fin1.close();

}

int main()
{
	string List = "DisciplinesNameList";
	string Names = "DisciplinesInfo";
	int a = 1;
	while (a != 0)
	{
		cout << "Add discipline(1)\n Add player(2)\n Get discipline(3)\n Get player(4)\n Delete discipline(5)\n Delete player(6)\n Update discipline(7)\n Exit(0)\n";
		cin >> a;
		switch (a)
		{
		case 1:
			insert_m(List, Names);
			break;
		case 2:
			insert_s(List, Names);
			break;
		}
	}
}
