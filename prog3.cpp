//Stewart Green
//CS 163
//Program 3 Header
//7/29/24
//


#include "prog3.h"


using namespace std;

int main()
{
	table hashtable(1997);
	cdata empty;
	cdata* cptr;
	char tempy[100];
	char* entry = nullptr;
	char response =  ' ';	
	if(!hashtable.load())
		cout << "LOAD ERROR." << endl;	
	while(response != '0')
	{
		cout << "Welcome to the world city database." << endl
			<< "Please choose an option below: " << endl
			<< "1. Add a city." << endl
			<< "2. Search for a city by name." << endl
			<< "3. Search for a city by ID." << endl
			<< "4. Remove a city." << endl
			<< "0. Quit." << endl << endl;
		cin >> response;
		cin.ignore(100, '\n');
		if(response == '1')
		{
			//input loop for empty cdata
			if(!hashtable.add(empty)) cout << "ERROR: CITY ALREADY EXISTS" << endl;
		
		}else if(response == '2')		
		{	
			cout << "Input the city name (case sensitive): ";	
			cin.get(tempy, 100, '\n');
			cin.ignore(100, '\n');

				
			entry = new char[strlen(tempy)+1];
			strcpy(entry, tempy);
						
			if(!hashtable.search(entry, cptr))
			       cout << "SEARCH NOT FOUND" << endl;	
			
			delete [] entry;
		}else if(response == '3')		
		{
			if(!hashtable.IDsearch(entry)) cout << "ID NOT FOUND" <<endl;
		}else if(response == '4')		
		{
			if(!hashtable.remove(entry)) cout << "CITY NOT FOUND" << endl;
		}
	}	
	return 0;
}

