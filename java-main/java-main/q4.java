import java.util.Scanner;

class InvalidDayException extends Exception
{
	int date;

	InvalidDayException(int date)
	{
		this.date = date;
	}

	public String toString()
	{
		return date +" is invalid.";
	}
}

class InvalidMonthException extends Exception
{
	int month;

	InvalidMonthException(int month)
	{
		this.month = month;
	}
	public String toString()
	{
		return month+ " is invalid.";
	}
}

class CurrentDate
{
	Scanner sc = new Scanner(System.in);
	int date,month,year;
	boolean createDate()
	{

		boolean flag = true;
		try
		{
			System.out.print("Enter date:");
			date = sc.nextInt();
			System.out.print("Enter month:");
			month= sc.nextInt();
			System.out.print("Enter year:");
			year = sc.nextInt();

			if((date<=0) || (month == 2 && (year%4==0) && date>29) || (month==2 && (year%4!=0) && date>28) || date>31)
				throw new InvalidDayException(date);

			else if(month<=0 || month >12)
				throw new InvalidMonthException(month);
			else if(month==4 ||month ==6||month==9||month==11)
				if(date>30)
					throw new InvalidDayException(date);
			else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
				if(date>31)
					throw new InvalidDayException(date);
			

		}

		catch(InvalidDayException d)
		{
			System.out.println(d);
			flag = false;
		}
		catch(InvalidMonthException m)
		{
			System.out.println(m);
			flag = false;
		}
		return flag;
		// System.out.println(flag);
		
	}

	void displayDate()
	{
		System.out.println("The date is "+date+"/"+month+"/"+year);
	}
}

class DateDemo
{
	public static void main(String[] args)
	{
		CurrentDate cd = new CurrentDate();
		if(cd.createDate())
			cd.displayDate();
	}
}

