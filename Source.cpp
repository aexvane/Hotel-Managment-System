#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class person
{
	string name;
	int phone;
	int cnic;
public:
	person()
	{
		name = "Empty";
		phone = 0;
		cnic = 0;

	}
	void get_person()
	{
		cout << "Enter name : "; cin >> name;
		cout << "Enter phone number : "; cin >> phone;
		cout << "Enter cnic : "; cin >> cnic;  
	}

	void display_person()
	{
		cout << "Name : " << name << endl;
		cout << "Phone number : " << phone << endl;
		cout << "CNIC : " << cnic << endl;
	}
	
	void remove_person()
	{
		person();
	}
};


class room : public person
{
	int room_number;
	int floor;
	string type;
	int date;
	int days;
public:
	room ( int flr , int rnumber , string tpp)
	{
		floor = flr;
		room_number = rnumber;
		type = tpp;
		date = "Not_Booked";
		days = 0;
	}

	room ()
	{

	}


	void book_room()
	{
		get_person();
		cout << "Enter date : "; cin >> date;
		cout << "Enter days : "; cin >> days;

	}

	int get_roomNumber()
	{
		return room_number;
	}

	string get_date()
	{
		return date;
	}

	void remove_booking(int rn)
	{
		date = "Not_Booked";
		days = 0;
		remove_person();
	}

	void  display()
	{
		cout << "\t" << floor << "\t\t" << room_number << "\t\t\t" << type << "\t\t" << date << "\t\t" << days << endl;
	}
};

void main()
{
	room rhtl[9] = {room(1 , 101 , "Single_bed") , room(1 , 102 , "Single_bed") , room(1 , 103 , "double_bed") , room(2 , 201 , "Single_bed") , room(2 , 202 , "Single_bed") , room(2 , 203 , "double_bed") , room(3 , 301 , "Single_bed") , room(3 , 302 , "Single_bed") , room(3, 303 , "double_bed")};
	int rn, i , dd;
	

	while(true)
	{
		system("CLS");
		cout << "\tFloor Level\tRoom Number \t\ttype \t\t\tdate \t\t\tdays" << endl;

		for (i =0 ; i< 9 ; i++)
		{
			rhtl[i].display();
			if ((i+1)%3 == 0)
				cout << "-----------------------------------------------------------------------------------------------------" << endl;
		}
		
		dd =0;
		cout << "Press:-" << endl;
		cout << "\t | 1 | To Book Room" << endl;
		cout << "\t | 2 | To Check Room Booking Data" << endl;
		cout << "\t | 3 | To remove Booking" << endl;
		cout << "\t | 4 | To End Program" << endl;
		int choice;
		choice = getch();
		if (choice == '4')
		{
			break;
		}
		if (choice == '1')
		{
			cout << "Enter room Number : "; cin >> rn;
			for ( i = 0 ; i<9 ; i++)
			{
				if (rhtl[i].get_roomNumber() == rn && rhtl[i].get_date() == "Not_Booked")
				{
					dd=1;
					break;
				}
			}
			if (dd != 1)
			{
				cout << "Room is Not Available" << endl;
				system("pause");
			}
			else 
			{
				rhtl[i].book_room();
			}
		}
		else if (choice == '2')
		{
			cout << "Enter room Number : "; cin >> rn;
			for ( i = 0 ; i<9 ; i++)
			{
				if (rhtl[i].get_roomNumber() == rn)
				{
					dd=1;
					break;
				}
			}
			if (rhtl[i].get_date() == "Not_Booked")
			{
				cout << "Room is Empty" << endl;
			}
			else if (dd == 1)
			{
				rhtl[i].display_person();
			}
			else
			{
				cout << "Wrong input" << endl;
			}
			system("pause");
		}
		else if (choice == '3')
		{
			cout << "Enter room Number : "; cin >> rn;
			for ( i = 0 ; i<9 ; i++)
			{
				if (rhtl[i].get_roomNumber() == rn)
				{
					break;
				}
			}
			rhtl[i].remove_booking(rn);
			cout << "Booking Rmoved"<< endl;
			system("pause");
		}
		else
		{
			cout << "Wrong Input" << endl;
		}
	}
	system("pause");
}