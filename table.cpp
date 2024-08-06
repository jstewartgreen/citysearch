//Stewart Green
//CS 163
//Program 3 Header
//7/29/24
//
//


#include "prog3.h"

using namespace std;

table::table(int size)
{
	size = size;	
	hashtable = new city*[size];
	for(int i = 0; i < size; ++i)
		hashtable[i] = nullptr;

}



table::~table()
{
	city* current;
	city* hold;

	for(int i = 0; i < size; ++i)
	{
		if (hashtable[i])
		{
			current = hashtable[i];
			while(current)
			{
				hold = current->next;
				delete current;
				current = hold;
			}
		}
	}
	delete [] hashtable;
		
}


int table::hashfxn(char key[])
{
	int hash;
	int length = strlen(key);	
	char* temp = new char[strlen(key)+1];
	strcpy(temp, key);

	for (int i = 0; i < length; ++i)
	{	
		hash += temp[i];
	}
	hash *= temp[0];//*length;
	hash %= size;
	return hash;
	
		
}



bool table::search(char key[], cdata* &empty)
{
	int hash = hashfxn(key);
	int hits {0};//number of times a city appears; 

	city* current = nullptr;

	if(!hashtable[hash]) return false;
	
	current = hashtable[hash];
	while (current)
	{
		if(current->match(key))	
		{
			cout << "Match found:" << endl;	
			current->display();
			++hits;
		}
		current = current->next;
			
	}
/*	
	empty = new cdata[hits];
	int i = 0;	
	current = hashtable[hash];

	while (current && i < hits)
	{
		if(current->match(key))	
		{
			current->outcopy(empty[i]);
			++i;		
		}
		current = current->next;
			
	}
*/	
	if(hits == 0) return false;	
	return true;

}



bool table::add(cdata &toadd)
{
	char* term = new char[0];
	int hash = hashfxn(toadd.ascii);
	city* hold = nullptr;
		

	hold = 	hashtable[hash];
	hashtable[hash] = new city;
	hashtable[hash]->incopy(toadd);
	hashtable[hash]->next = hold;
			

	delete [] term;	
	return true;
}




bool table::remove(char key[])
{
	int hash = hashfxn(key);
	city* current;
	city* prev;
	if(!hashtable[hash])
		return false;

	current = hashtable[hash];

	if(current->match(key))
	{
		hashtable[hash] = current->next;
		delete current;
	}else
	{
		while(current && !current->match(key))
		{
			prev = current;
			current = current->next;
		}
		if(!current) return false;
		else
		{
			prev->next = current->next;
			delete current;
		}
	}
			
	return true;
}
		



bool table::retrieve(char key[], cdata* &empty)
{return true;}




bool table::IDsearch(char ID[]){return true;}





void table::displayall()
{
	city* current = nullptr;
	for(int i = 0; i < size; ++i)
	{
		if(hashtable[i])
		{	
			current = hashtable[i];
			while(current)	
			{
				current->display();
				current = current->next;
			}		
		}else cout << "EMPTY INDEX: " << i << endl;
	}
}


bool table::load()
{
	ifstream filein;
	//ofstream fileout;
	cdata empty;
	char temp[100];
//	int length;	
	filein.open("world_cities_data.txt");
//	fileout.open("names.txt");	
	if(!filein)
		return false;

		

	filein.ignore(200, '\n');	
//	temp[0] = '\0';	

	while(!filein.eof())
	{
//name
		
		filein.get(temp, 100, ',');
		filein.ignore(100, ',');		
		empty.name = new char[strlen(temp)+1];
		strcpy(empty.name, temp);
		temp[0] = '\0';

//ascii
		filein.get(temp, 100, ',');
		filein.ignore(100, ',');		
		empty.ascii = new char[strlen(temp)+1];
		strcpy(empty.ascii, temp);	
		temp[0] = '\0';
	
//		length = strlen(empty.ascii);	
//		for(int i = 0; i < length; ++i)
//			empty.ascii[i] = toupper(empty.ascii[i]);


//		fileout << empty.ascii << ',';
//latitude
		filein >> empty.lat;
		filein.ignore(100, ',');
//longitude		
		filein >> empty.lon;
		filein.ignore(100, ',');

//country
		filein.get(temp, 100, ',');
		filein.ignore(100, ',');		

		empty.country = new char[strlen(temp)+1];
		strcpy(empty.country, temp);
		temp[0] = '\0';
//abbrev1
		filein.get(temp, 100, ',');
		filein.ignore(100, ',');		
	
		empty.abbrev1 = new char[strlen(temp)+1];
		strcpy(empty.abbrev1, temp);
		temp[0] = '\0';
//abbrev2
		filein.get(temp, 100, ',');	
		filein.ignore(100, ',');		
		empty.abbrev2 = new char[strlen(temp)+1];
		strcpy(empty.abbrev2, temp);
		temp[0] = '\0';

//admin
		filein.get(temp, 100, ',');	
		filein.ignore(100, ',');		
		empty.admin = new char[strlen(temp)+1];
		strcpy(empty.admin, temp);
		temp[0] = '\0';
//population		
		filein >> empty.pop;
		filein.ignore(100, ',');		
		
			
//ID# 
		filein.get(temp, 100, '\n');	
		filein.ignore(100, '\n');		
		empty.ID = new char[strlen(temp)+1];
		strcpy(empty.ID, temp);
		temp[0] = '\0';
		
		add(empty);
	
		delete [] empty.name;				
		delete [] empty.ascii;		
		delete [] empty.country;		
		delete [] empty.abbrev1;		
		delete [] empty.abbrev2;
		delete [] empty.admin;
		delete [] empty.ID;	

	}
	displayall();
	efficiency();
	filein.close();
//	fileout.close();
	return true;
}

void table::efficiency()
{
	city* current = nullptr;
	int chain {0};
	int zeroes {0};
	float max {0};
	float min {47000};
	float avg {0};	
//	float inefficiency;

	for(int i {0}; i < size; ++i)
	{
		chain = 0;
		current = hashtable[i];
			
		if(!current)
			++zeroes;
		else{
			while (current)
			{
				++ chain;
				current = current -> next;
			}
		}
		cout << i << " : " << chain << endl;
		if (chain > max)
			max = chain;
		if (chain < min)
			min = chain;	
		avg += chain;
	}
	avg /= size; 
	cout << "Table Size: " << size << endl;	
	cout << "Number of empty indices: " << zeroes << endl;
	cout << "Shortest chain: " << min << endl;
	cout << "Longest chain: " << max << endl;
	cout << "Average: " << avg << endl;
	cout << "Range: " << max - min << endl;
}

