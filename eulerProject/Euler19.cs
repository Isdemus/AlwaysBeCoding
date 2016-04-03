/*
Problem 19:

You are given the following information, but you may prefer to do some research for yourself.
1 Jan 1900 was a Monday.
Thirty days has September, April, June and November.
All the rest have thirty-one, Saving February alone, Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

input:
Void

output:
The date is 1900.01.07, Sun
The date is 1901.09.01, Sun
The date is 1901.12.01, Sun
The date is 1902.06.01, Sun
The date is 1903.02.01, Sun
The date is 1903.03.01, Sun
The date is 1903.11.01, Sun
The date is 1904.05.01, Sun
The date is 1905.01.01, Sun
The date is 1905.10.01, Sun
The date is 1906.04.01, Sun
The date is 1906.07.01, Sun
The date is 1907.09.01, Sun
The date is 1907.12.01, Sun
The date is 1908.03.01, Sun
The date is 1908.11.01, Sun
The date is 1909.08.01, Sun
The date is 1910.05.01, Sun
The date is 1911.01.01, Sun
The date is 1911.10.01, Sun
The date is 1912.09.01, Sun
The date is 1912.12.01, Sun
The date is 1913.06.01, Sun
The date is 1914.02.01, Sun
The date is 1914.03.01, Sun
The date is 1914.11.01, Sun
The date is 1915.08.01, Sun
The date is 1916.10.01, Sun
The date is 1917.04.01, Sun
The date is 1917.07.01, Sun
The date is 1918.09.01, Sun
The date is 1918.12.01, Sun
The date is 1919.06.01, Sun
The date is 1920.02.01, Sun
The date is 1920.08.01, Sun
The date is 1921.05.01, Sun
The date is 1922.01.01, Sun
The date is 1922.10.01, Sun
The date is 1923.04.01, Sun
The date is 1923.07.01, Sun
The date is 1924.06.01, Sun
The date is 1925.02.01, Sun
The date is 1925.03.01, Sun
The date is 1925.11.01, Sun
The date is 1926.08.01, Sun
The date is 1927.05.01, Sun
The date is 1928.01.01, Sun
The date is 1928.04.01, Sun
The date is 1928.07.01, Sun
The date is 1929.09.01, Sun
The date is 1929.12.01, Sun
The date is 1930.06.01, Sun
The date is 1931.02.01, Sun
The date is 1931.03.01, Sun
The date is 1931.11.01, Sun
The date is 1932.05.01, Sun
The date is 1933.01.01, Sun
The date is 1933.10.01, Sun
The date is 1934.04.01, Sun
The date is 1934.07.01, Sun
The date is 1935.09.01, Sun
The date is 1935.12.01, Sun
The date is 1936.03.01, Sun
The date is 1936.11.01, Sun
The date is 1937.08.01, Sun
The date is 1938.05.01, Sun
The date is 1939.01.01, Sun
The date is 1939.10.01, Sun
The date is 1940.09.01, Sun
The date is 1940.12.01, Sun
The date is 1941.06.01, Sun
The date is 1942.02.01, Sun
The date is 1942.03.01, Sun
The date is 1942.11.01, Sun
The date is 1943.08.01, Sun
The date is 1944.10.01, Sun
The date is 1945.04.01, Sun
The date is 1945.07.01, Sun
The date is 1946.09.01, Sun
The date is 1946.12.01, Sun
The date is 1947.06.01, Sun
The date is 1948.02.01, Sun
The date is 1948.08.01, Sun
The date is 1949.05.01, Sun
The date is 1950.01.01, Sun
The date is 1950.10.01, Sun
The date is 1951.04.01, Sun
The date is 1951.07.01, Sun
The date is 1952.06.01, Sun
The date is 1953.02.01, Sun
The date is 1953.03.01, Sun
The date is 1953.11.01, Sun
The date is 1954.08.01, Sun
The date is 1955.05.01, Sun
The date is 1956.01.01, Sun
The date is 1956.04.01, Sun
The date is 1956.07.01, Sun
The date is 1957.09.01, Sun
The date is 1957.12.01, Sun
The date is 1958.06.01, Sun
The date is 1959.02.01, Sun
The date is 1959.03.01, Sun
The date is 1959.11.01, Sun
The date is 1960.05.01, Sun
The date is 1961.01.01, Sun
The date is 1961.10.01, Sun
The date is 1962.04.01, Sun
The date is 1962.07.01, Sun
The date is 1963.09.01, Sun
The date is 1963.12.01, Sun
The date is 1964.03.01, Sun
The date is 1964.11.01, Sun
The date is 1965.08.01, Sun
The date is 1966.05.01, Sun
The date is 1967.01.01, Sun
The date is 1967.10.01, Sun
The date is 1968.09.01, Sun
The date is 1968.12.01, Sun
The date is 1969.06.01, Sun
The date is 1970.02.01, Sun
The date is 1970.03.01, Sun
The date is 1970.11.01, Sun
The date is 1971.08.01, Sun
The date is 1972.10.01, Sun
The date is 1973.04.01, Sun
The date is 1973.07.01, Sun
The date is 1974.09.01, Sun
The date is 1974.12.01, Sun
The date is 1975.06.01, Sun
The date is 1976.02.01, Sun
The date is 1976.08.01, Sun
The date is 1977.05.01, Sun
The date is 1978.01.01, Sun
The date is 1978.10.01, Sun
The date is 1979.04.01, Sun
The date is 1979.07.01, Sun
The date is 1980.06.01, Sun
The date is 1981.02.01, Sun
The date is 1981.03.01, Sun
The date is 1981.11.01, Sun
The date is 1982.08.01, Sun
The date is 1983.05.01, Sun
The date is 1984.01.01, Sun
The date is 1984.04.01, Sun
The date is 1984.07.01, Sun
The date is 1985.09.01, Sun
The date is 1985.12.01, Sun
The date is 1986.06.01, Sun
The date is 1987.02.01, Sun
The date is 1987.03.01, Sun
The date is 1987.11.01, Sun
The date is 1988.05.01, Sun
The date is 1989.01.01, Sun
The date is 1989.10.01, Sun
The date is 1990.04.01, Sun
The date is 1990.07.01, Sun
The date is 1991.09.01, Sun
The date is 1991.12.01, Sun
The date is 1992.03.01, Sun
The date is 1992.11.01, Sun
The date is 1993.08.01, Sun
The date is 1994.05.01, Sun
The date is 1995.01.01, Sun
The date is 1995.10.01, Sun
The date is 1996.09.01, Sun
The date is 1996.12.01, Sun
The date is 1997.06.01, Sun
The date is 1998.02.01, Sun
The date is 1998.03.01, Sun
The date is 1998.11.01, Sun
The date is 1999.08.01, Sun
The date is 2000.10.01, Sun
The answer is 171
*/

using System;

public class Test {
	public struct Date {
		public int yy;
		public int mm;
		public int dd;
		public string day;// {Mon, Tues, Wed, Thurs, Fri, Sat, Sun};
	
		public Date(int yy, int mm, int dd, string day) {
			this.yy = yy;
			this.mm = mm;
			this.dd = dd;
			this.day = day;
		}

		public void printing() {
			if(this.mm >=10 && this.dd>=10) {
				Console.WriteLine("The date is {0}.{1}.{2}, {3}", this.yy, this.mm, this.dd, this.day);
			}else if(this.mm>=10) {
				Console.WriteLine("The date is {0}.{1}.0{2}, {3}", this.yy, this.mm, this.dd, this.day);
			}else if(this.dd>=10) {
				Console.WriteLine("The date is {0}.0{1}.{2}, {3}", this.yy, this.mm, this.dd, this.day);
			}else {
				Console.WriteLine("The date is {0}.0{1}.0{2}, {3}", this.yy, this.mm, this.dd, this.day);
			}
		}
	}

	public static Date converting(int yy, int mm, int dd, string day) {
		Date date = new Date(yy, mm, dd, day);
		return date;
	}

	public static Date find_First_Sunday() {
		return converting(1900, 1, 7, "Sun");
	}

	public static bool outofarea(Date date) {
		if(date.yy > 2000 || date.yy < 1900) {
			return true;
		}else {return false;}
	}

	public static bool isLeap(Date date) {
		int year = date.yy;

		if (year%100==0) { return (year%400)==0; }
		else { return year%4==0; }
	}

	public static bool major(int m) {
		if(m==2 || m==4 || m==6 || m==9 || m==11) {
			return false;
		}else { return true; }
	}

	public static void updateYear(ref Date date) {
		if(date.mm > 12) {
			date.yy += 1;
			date.mm -= 12;
		}
	}

	public static void updateMonth(ref Date date, int maxDD) {
		if(date.dd > maxDD) {
			date.mm += 1;
			date.dd -= maxDD;
		}
	}

	public static Date nextSunday(ref Date date) {
		int month = date.mm;
		int maxDD;
		if(month==2 && isLeap(date)) {
			maxDD=29;
		}else if(month==2) {
			maxDD=28;
		}else if(major(month)) {
			maxDD=31;
		}else {
			maxDD=30;
		}
		
		date.dd += 7;
		updateMonth(ref date, maxDD);
		updateYear(ref date);
		return date;
	}

	public static bool firstofMonth(Date date) {
		if(!outofarea(date) && date.dd==1) {
			return true;
		}else { return false; }
	}

	public static bool twentith(Date date) {
		if(date.yy >= 1901 && date.yy <= 2000) {
			return true;
		}else { return false; }
	}

	public static int futureDay(Date date, int count) {
		//date.printing();
		//if(date.yy>1905) {return count;}
		if(outofarea(date)) { return count; }
		else if(firstofMonth(date) && twentith(date)) {
			count++;
			date.printing();
		
			return futureDay(nextSunday(ref date), count);
		}else { return futureDay(nextSunday(ref date), count); }
	}

	public static bool isSunday (Date date) {
		if(date.day == "Sun") {
			return true;
		}else { return false; }
	}

	public static void Main() {
		int count = 0;
		Date firstSunday = find_First_Sunday();
		firstSunday.printing();

		if(!isSunday(firstSunday)) { Console.WriteLine("Error1"); }
		int answer = futureDay(firstSunday, count);
		Console.WriteLine("The answer is {0}", answer);
	}
}