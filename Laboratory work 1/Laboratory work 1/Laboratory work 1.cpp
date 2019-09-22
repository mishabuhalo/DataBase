
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
	int CountOfPlayers;
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
	while (!fin.eof())			
	{
		fin >> i;
		fin >> s;
	}

	fin.close();
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

		}
	}
}
