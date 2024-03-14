#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

/*
    // Finns färgen "black"?
    bool blackExists = any_of(colors.begin(), colors.end(), [](string c) { return c == "black"; });
    cout << "\nFinns färgen 'black'?" << endl;
    blackExists ? cout << "JA\n" << endl : cout << "NEJ\n" << endl;

    // Hur många färger har 5 bokstäver?
    int fiveLetterColors = count_if(colors.begin(), colors.end(), [](string c) { return c.size() == 5; });
    cout << "\nHur många färger har 5 bokstäver?\n" << fiveLetterColors << endl;

    // Skriv ut alla färger före sortering
    cout << "\n\nAlla färger före sortering: \n" << endl;
    for_each(colors.begin(), colors.end(), [](string c) { cout << c << endl; });

    // Sortera alla färger i ordlängd (descending)
    sort(colors.begin(), colors.end(), [](string c1, string c2) { return c1.size() > c2.size(); });

    // Skriv ut alla färger efter sortering
    cout << "\n\nAlla färger efter sortering (ordlängd, descending):\n" << endl;
    for_each(colors.begin(), colors.end(), [](string c) { cout << c << endl; });

    // Gör om alla färger till versaler i en ny vector
    transform(colors.begin(), colors.end(), back_inserter(colors2), [](string str) {
        string copy = str;
        transform(copy.begin(), copy.end(), copy.begin(), [](char c){ return toupper(c); });
        return copy;
    });

    // Sortera båda vektorerna i bokstavsordning (ascending)
    sort(colors.begin(), colors.end(), [](string c1, string c2) { return c1 < c2; });
    sort(colors2.begin(), colors2.end(), [](string c1, string c2) { return c1 < c2; });


    // Skriv ut båda vektorerna
    cout << "\nFärger som gemener (sorterade i bokstavsordning, ascending): \n" << endl;
    for_each(colors.begin(), colors.end(), [](string c) { cout << c << endl; });
    cout << "\nFärger som versaler (sorterade i bokstavsordning, ascending): \n" << endl;
    for_each(colors2.begin(), colors2.end(), [](string c) { cout << c << endl; });


*/


using namespace std;

enum class SensorType
{
	Altitude,
	SpeedInKmh,
	FuelConsumption
};

class SensorData
{
	float value;
	SensorType sensorType;
	time_t time;
public:
	SensorType GetSensorType() { return sensorType; }
	float GetValue() { return value; }
	void SetValue(float v) { value = v; }
	time_t GetTime() { return time; }
	SensorData(SensorType sensorType, float value, time_t time)
	{
		this->value = value;
		this->sensorType = sensorType;
		this->time = time;
	}
};


void FillData(vector<SensorData> &v);
time_t CreateTime(int year, int month, int day, int hour, int minute, int second);

int main()
{
	vector<SensorData> sensorData;
	FillData(sensorData);

	//SKRIV DIN KOD HÄR!!!!
    system("clear");

    // Skriver ut hela vektorn

/*     for_each(sensorData.begin(), sensorData.end(), [](SensorData sd) {
        if (sd.GetSensorType == SensorType::Altitude)
        {
            cout << "Altitude" << " - " << sd.GetValue() << " - " << sd.GetTime() << endl;
        }
        else if (sd.GetSensorType == SensorType::SpeedInKmh)
        {
            cout << "SpeedInKmh" << " - " << sd.GetValue() << " - " << sd.GetTime() << endl;
        }
        else if (sd.GetSensorType == SensorType::FuelConsumption)
        {
            cout << "FuelConsumption" << " - " << sd.GetValue() << " - " << sd.GetTime() << endl;
        }
        else 
        {
            cout << "Sensor type" << " - " << sd.GetValue() << " - " << sd.GetTime() << endl;
        }
    }); */
    
    /* 
        #1  Skriv kod som räknar hur många sensordataregistreringar som gjorts för Altitude - den 2012-01-02
    */

    time_t targetDate = CreateTime(2012, 1, 2, 0, 0, 0);

    // Testar altitudeCount genom att lägga till sensordata i vektorn som uppfyller villkoren
    // SensorData test = SensorData(SensorType::Altitude, 99999999.0f, targetDate);
    // sensorData.push_back(test);
    
    int altitudeCount = count_if(sensorData.begin(), sensorData.end(), [targetDate](auto sd) { 
        return sd.GetSensorType() == SensorType::Altitude && sd.GetTime() == targetDate; 
    });
    cout << "\nAntal sensormätningar för 'Altitude' den 2012-01-02:\n" << altitudeCount << endl;   


    /*
        #2  Finns det nån SpeedInKmh-registrering med hastighet över 99.9 så skriv till 
            consolen "Maxhastighet uppnådd" annars skriv "Ingen maxhastighet uppnådd" 
    */

   // Skriv ut alla values
   // for_each(sensorData.begin(), sensorData.end(), [](SensorData sd) { cout << sd.GetValue() << endl; });

   bool maxSpeedReached = any_of(sensorData.begin(), sensorData.end(), [](auto sd) { return sd.GetValue() > 99.9f; });
   maxSpeedReached ? cout << "\nMaxhastighet uppnådd\n\n" : cout << "\nIngen maxhastighet uppnådd\n\n";

    /*
        #3  Det har uppdagats att fabriken mixrat med FuelConsumption-sensorn. 
            Skriv kod som uppdaterar alla såna poster så att FuelConsumption ökas med 75%.
    */

   for_each(sensorData.begin(), sensorData.end(), [](auto sd) {
        if (sd.GetSensorType() == SensorType::FuelConsumption)
            { sd.SetValue(sd.GetValue() * 1.75f); }
   });



    /*
        #4  Skapa en Bankomat med MAP
            NYCKEL: Kontonummer
            VALUE: saldo
            Skapa en meny där man kan skapa konto. Logga in på konto. Ta ut och sätta in pengar.
            Skriv all kod i en och samma fil,
            KLISTRA IN HELA FILEN DU SKRIVIT NEDAN
    */

}

void FillData(vector<SensorData>& v)
{
	srand(time(NULL));

	time_t tid = CreateTime(2012, 1, 1, 1, 1, 1 );
	for (int i = 0; i < 100000; i++)
	{
		SensorType type = static_cast<SensorType>(rand() % 3);
		float value = 0.0f;
		if (type == SensorType::Altitude)
			value = rand() % 1000;
		else if (type == SensorType::FuelConsumption)
			value = rand() * 3.0f;
		else if (type == SensorType::SpeedInKmh)
			value = rand() % 110;
		else
		{
			value = 99;
		}
		v.push_back(SensorData(type,value,tid));
		tid = tid + rand() % 10 + 1;
	}
}

time_t CreateTime(int year, int month, int day, int hour, int minute, int second)
{
	struct tm tid = { 0 };
	tid.tm_year = year-1900;
	tid.tm_mon = month - 1;
	tid.tm_mday = day;
	tid.tm_hour = hour;
	tid.tm_min = minute;
	tid.tm_sec = second;
	return mktime(&tid);
}