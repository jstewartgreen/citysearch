//Stewart Green
//CS 163
//Program 3 Header
//7/29/24
//
//

#include "prog3.h"

using namespace std;

city::city()
{
	next = nullptr;
	data.name = nullptr;
	data.ascii = nullptr;
	data.country = nullptr;
	data.abbrev1 = nullptr;
	data.abbrev2 = nullptr;
	data.admin = nullptr;
	data.ID = nullptr;	
	data.lat = 0;
	data.lon = 0;
	data.pop = 0;
}


city::~city()
{
		
		delete [] data.name;
		delete [] data.ascii;	
		data.lat = 0;
		data.lon = 0;
		delete [] data.country;
		delete [] data.abbrev1;
		delete [] data.abbrev2;
		delete [] data.admin;
		data.pop = 0;
		delete [] data.ID;
}


//returns true if the city's name matches the key arg, false otherwise;
bool city::match(char key[])
{
	
	if(strcmp(key, data.ascii) != 0) return false;
	return true;
}

//outputs data to user;
bool city::display()
{
	cout << endl << "Name: " << data.name << endl
		<< "ASCII Name: " << data.ascii << endl
		<< "Latitude: " << data.lat << endl
		<< "Longitude: " << data.lon << endl
		<< "Abbreviation 1: " << data.abbrev1 << endl
		<< "Abbreviation 2: " << data.abbrev2 << endl
		<< "Admin: " << data.admin << endl
		<< "Population: " << data.pop << endl
		<< "ID #: " << data.ID << endl << endl;
	return true;
}



//copies arg contents into itself;
bool city::incopy(cdata &origin)
{
	data.name = new char[strlen(origin.name)+1];
	strcpy(data.name, origin.name);
	
	data.lat = origin.lat;

	data.lon = origin.lon;

	data.ascii = new char[strlen(origin.ascii)+1];
	strcpy(data.ascii, origin.ascii);

	data.country = new char[strlen(origin.country)+1];
	strcpy(data.country, origin.country);	

	data.abbrev1 = new char[strlen(origin.abbrev1)+1];
	strcpy(data.abbrev1, origin.abbrev1);	
	
	data.abbrev2 = new char[strlen(origin.abbrev2)+1];
	strcpy(data.abbrev2, origin.abbrev2);	
	
	data.admin = new char[strlen(origin.admin)+1];
	strcpy(data.admin, origin.admin);	

	data.pop = origin.pop;
	
	data.ID = new char[strlen(origin.ID)+1];
	strcpy(data.ID, origin.ID);
	
	return true;

}

//returns true if ID arg matches ID field;	
bool city::matchid(char ID[])
{
	if(strcmp(ID, data.ID) != 0) return false;

	return true;
}


bool city::outcopy(cdata &dest)
{

	dest.name = new char[strlen(data.name)+1];
	strcpy(dest.name, data.name);
	
	dest.lat = data.lat;

	dest.lon = data.lon;

	dest.ascii = new char[strlen(data.ascii)+1];
	strcpy(dest.ascii, data.ascii);

	dest.country = new char[strlen(data.country)+1];
	strcpy(dest.country, data.country);	

	dest.abbrev1 = new char[strlen(data.abbrev1)+1];
	strcpy(dest.abbrev1, data.abbrev1);	
	
	dest.abbrev2 = new char[strlen(data.abbrev2)+1];
	strcpy(dest.abbrev2, data.abbrev2);	
	
	dest.admin = new char[strlen(data.admin)+1];
	strcpy(dest.admin, data.admin);	

	dest.pop = data.pop;
	
	dest.ID = new char[strlen(data.ID)+1];
	strcpy(dest.ID, data.ID);
	
	return true;
}
