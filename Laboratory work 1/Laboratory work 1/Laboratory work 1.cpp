
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

int get_s(string id, string ind, int n, string Names, string name)
{
	int i = 0, position = 0;
	string buff;
	bool flag = false;

	int t = get_m(id, ind, Length, Names) - 1;
	buff = root[t].ListOfPlayers;
	ifstream fin(buff);
	while (!fin.eof())
	{
		getline(fin, rootp[i].Name);
		if (rootp[i].Name == name)
		{
			flag = true;
			position = i;
		}
		getline(fin, rootp[i].Role);
		getline(fin, rootp[i].Nickname);
		i++;
	}
	if (flag)
		return position;
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

	ofstream fin1(temp, ios::app);
	fin1 << tempr->Name << endl;
	fin1 << tempr->Role << endl;
	fin1 << tempr->Nickname << endl <<endl;
	fin1.close();

}

int main()
{
	string List = "DisciplinesNameList";
	string Names = "DisciplinesInfo";
	string p, s;
	int a = 1;
	int r, o, u;
	while (a != 0)
	{
		cout << "\nAdd discipline(1)\nAdd player(2)\nGet discipline(3)\nGet player(4)\nDelete discipline(5)\nDelete player(6)\nUpdate discipline(7)\nExit(0)\n";
		cin >> a;
		switch (a)
		{
		case 1:
			insert_m(List, Names);
			break;
		case 2:
			insert_s(List, Names);
			break;
		case 3:
			cout << "Discipline Name: ";
			cin >> s;
			r = get_m(s, List, Length, Names) - 1;
			cout <<"Count of players: "<< root[r].CountOfPlayers << endl;
			cout <<"File with players: " <<  root[r].ListOfPlayers << endl;
			break;
		case 4:
			cout << "Discipline Name: ";
			cin >> s;
			o = get_m(s, List, Length, Names) - 1;
			cout << "\nPlayer Name: ";
			cin >> p;
			u = get_s(s, List, Length, Names, p);
			cout <<"Nickname: "<< rootp[u].Nickname << endl;
			cout <<"Role: " << rootp[u].Role << endl;
			break;

		}
	}
}
