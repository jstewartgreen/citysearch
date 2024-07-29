//Stewart Green
//CS 163
//Program 3 Header
//7/29/24
//This is the header for program 3.
//It includes the class interfaces for cities and the hash table.

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

class city
{
	public:
		city();
		~city();
		bool match(char key[]);//returns true if the city's name matches the key arg, false otherwise;
		bool display();//outputs data to user;
		bool copy(city &empty);//copies its contents into arg;
		bool matchid(int ID);//returns true if ID arg matches ID field;	
		char* ascii;//name in ASCII
		city* next;

	private:
		char* name;
		char lat[13];
		char lon[13];
		char* country;
		char* abbrev1;
		char* abbrev2;
		char* admin;
		int code;
		char capital;
		int pop;
		int ID;
};



class table
{
	public:
	
		table(int size);
		~table();
		bool search(char key[], city &empty);
		bool add(city $toadd);
		bool remove(char key[]);		
		bool retrieve(city &empty);	
		bool IDsearch(int ID);	
	private:
		city** hashtable;
		int hash(char key[]);
		void displayall();
		
};


