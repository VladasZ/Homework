#include <iostream>
#include <vector>
#include <string>

using namespace std;

//В справочной автовокзала хранится расписание движения автобусов.
//Для каждого рейса указаны его номер, пункт назначения, время отправления и
//прибытия.Вывести информацию о рейсах, которыми можно воспользоваться
//для прибытия в пункт назначения раньше заданного времени.

struct Bus
{
	int number;
	string destination;
	int departureTime;
	int arrivalTime;

	Bus(){}

	Bus(int number,
		string destination,
		int departureTime,
		int arrivalTime)
	{
		this->number = number;
		this->destination = destination;
		this->departureTime = departureTime;
		this->arrivalTime = arrivalTime;
	}

	void showInfo()
	{
		cout << "Bus number: " << number << " Destination: " << destination << "\n"
			<< "Departure time: " << departureTime << " Arrival time: " << arrivalTime << endl;
	} 
};

void s_qs(vector<Bus> buses, int n)
{

	struct
	{
		int l;
		int r;
	} stack[20];

	int i, j, left, right, x, s = 0;
	Bus t;
	stack[s].l = 0; stack[s].r = n - 1;
	while (s != -1)
	{
		left = stack[s].l; right = stack[s].r;
		s--;
		while (left < right)
		{
			i = left; j = right; x = buses[(left + right) / 2].departureTime;
			while (i <= j)
			{
				while (buses[i].departureTime < x) i++;
				while (buses[j].departureTime > x) j--;
				if (i <= j) {
					t = buses[i]; buses[i] = buses[j]; buses[j] = t;
					i++; j--;
				}
			}
			if ((j - left)<(right - i))
			{
				if (i<right) { s++; stack[s].l = i; stack[s].r = right; }

					right = j;
			}
			else {
				if (left<j) { s++; stack[s].l = left; stack[s].r = j; }
				left = i;
			}
		}
	}
}

void s_puz(vector<Bus> buses, int n)
{
	int i, j;
	Bus t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (buses[j - 1].arrivalTime > buses[j].arrivalTime)
			{
				t = buses[j - 1]; 
				buses[j - 1] = buses[j]; 
				buses[j] = t;
			}
}

vector<Bus> busDepo;

void addBusses()
{
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
	busDepo.push_back(Bus(1561, "Minsk", 1530, 1700));
}

void showBusses(string destination, int arrivalTime)
{
	for (Bus bus : busDepo)
	{
		if (bus.destination == destination && bus.arrivalTime < arrivalTime)
		{
			bus.showInfo();
		}
	}
}

int main()
{
	addBusses();

	s_puz(busDepo, busDepo.size());
	s_qs(busDepo, busDepo.size());

	showBusses("Minsk", 1800);
}