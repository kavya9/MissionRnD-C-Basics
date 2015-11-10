/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int leap(int y)
{
	if (y % 4 == 0)
	{
		if (y % 100 != 0)return 1;
		else if (y % 100 == 0)
		{
			if (y % 400 == 0)return 1;
			else return 0;
		}
	}
	else return 0;
}
int validate(int day, int mon, int year)
{
	int flag = 0;
	if (mon<1 || mon>12)flag++;
	if ((mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) && day>31)flag++;
	else if (mon == 2 && !(leap(year)) && day>28)flag++;
	else if (mon == 2 && leap(year) && day>29)flag++;
	else if ((mon == 4 || mon == 6 || mon == 9 || mon == 11) && day>30)flag++;
	if (flag)return 0;
	else return 1;

}
int compare(int num1, int num2)
{
	if (num1<num2)return 1;
	else if (num2 < num1)return 2;
	else return -1;
}

int isOlder(char *dob1, char *dob2) {
	int year[2], mon[2], day[2], date1[10], date[10], i, ans;
	for (i = 0; i < 10; i++)
	{
		if (i == 2 || i == 5)
		{
			if (dob1[i] != '-' || dob2[i] != '-')return -1;
		}
		else
		{
			if ((dob1[i]<'0' || dob1[i]>'9') || (dob2[i]<'0' || dob2[i]>'9'))return -1;
		}
		date[i] = dob1[i] - 48;
	}
	day[0] = date[0] * 10 + date[1];
	mon[0] = date[3] * 10 + date[4];
	year[0] = date[6] * 1000 + date[7] * 100 + date[8] * 10 + date[9];

	for (i = 0; i < 10; i++)
		date[i] = dob2[i] - 48;
	day[1] = date[0] * 10 + date[1];
	mon[1] = date[3] * 10 + date[4];
	year[1] = date[6] * 1000 + date[7] * 100 + date[8] * 10 + date[9];
	if (!validate(day[0], mon[0], year[0]))return -1;
	if (!validate(day[1], mon[1], year[1]))return -1;
	ans = compare(year[0], year[1]);
	if (ans != -1)return ans;
	else
	{
		ans = compare(mon[0], mon[1]);
		if (ans != -1)return ans;
		else
		{
			ans = compare(day[0], day[1]);
			if (ans != -1)return ans;
			return 0;
		}
	}
}