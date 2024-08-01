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

struct cdata
{

		char* name;
		char* ascii;
		float lat;
		float lon;
		char* country;
		char* abbrev1;
		char* abbrev2;
		char* admin;
		int pop;
		char* ID;
};


class city
{
	public:
		city();
		~city();
		bool match(char key[]);//returns true if the city's name matches the key arg, false otherwise;
		bool display();//outputs data to user;
		bool incopy(cdata &origin);//copies args contents into itself;
		bool matchid(char ID[]);//returns true if ID arg matches ID field;	
		bool outcopy(cdata &dest);//copies private data into empty cdata arg;
		
		city* next;
	
	private:

		cdata data;	
};



class table
{
	public:
	
		table();
		~table();
		bool search(char key[], cdata* &empty);
		bool add(cdata& toadd);
		bool remove(char key[]);		
		bool retrieve(char key[], cdata* &empty);	
		bool IDsearch(int ID);	
		bool load();
		bool save();
		
	private:
		
		city** hashtable;
		int size = 1997;	
		int hashfxn(char key[]);
		void displayall();
		void efficiency();
};

