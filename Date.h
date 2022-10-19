typedef struct Date
{
	int day;
	int month;
	int year;

	void dateInput();
	void dateOutput();
	bool compareDate(Date date2);
	bool checkLeapYear();
	bool checkDate();	
}

Date;
