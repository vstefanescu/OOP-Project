#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <chrono>

#define dollarExchangeRate 4.49
#define figureNumber 125
#define namesFromDB 1000
#define defaultBusPrice 4300
#define max 1000

using namespace std;

template <typename randomNumberGenerator>
randomNumberGenerator random(randomNumberGenerator x)
{
    return rand() % x;
}

void readNameDataBase(string x[namesFromDB][2])
{
    ifstream nameDataBase;
    nameDataBase.open("nameDataBase.csv");

    char divider1('n');
    char divider2('\n');

    cout << "Opening nameDataBase.csv..." << endl;

    try
    {
        if(!nameDataBase.is_open())
            throw '1';
        else
        {
            for(unsigned int i = 0; i < namesFromDB; i++)
            {
                getline(nameDataBase, x[i][0], divider1);
                getline(nameDataBase, x[i][1], divider2);
            }

            cout << "Database opened.\n" << endl;
        }
    }
    catch(char err)
    {
        if(err == '1')
        {
            cout << "An error occured and the file was not opened." << endl;
        }
    }
}

class RandomStringGenerator
{
    public:
        string diet[3] = {"Omnivore", "Vegan", "Flexitarian"};
        string type[5] = {"Vampire", "Werewolf", "Siren", "Clairvoyant"};
    
        string randomDiet(string x[3]){
            return x[random(3)];
        }

        string randomType(string x[5]){
            return x[random(5)];
        }

        string randomFigureName(string x[1000][2]){
            return x[random(1000)][0] + " " + x[random(1000)][1];
        }
};

class DataBase
{
    public:
        string x[max];
        string y[max];
        
        string figure[figureNumber];
        unsigned int castInitialNumber;
        unsigned int actorNumber;

        // ADD DESTRUCTOR
};

class DataBaseReader
{
    public:
        unsigned int x2(string a[max], string b[max])
        {
            ifstream castDataBase;
            castDataBase.open("wednesdayCast.csv");

            char divider1(';');
            char divider2('\n');

            unsigned int index = 0;

            try
            {
                if(!castDataBase.is_open())
                    throw '1';
                else
                {
                    while(!castDataBase.eof())
                    {
                        getline(castDataBase, a[index], divider1);
                        getline(castDataBase, b[index], divider2);

                        index++;
                    }
                    index--;
                }
            }
            catch(char err)
            {
                if(err = '1')
                {
                    cout << "An error occured and the file was not opened." << endl;
                }
            }
            return index;
            
        }
};

class DataBaseWrite
 {
    public:
        RandomStringGenerator randomStringGenerator;
        unsigned int x4(string a[max], string b[max], string c[figureNumber], unsigned int indexx)
        {
            string names[namesFromDB][2];
            readNameDataBase(names);

            ofstream dataBaseWrite;
             dataBaseWrite.open("castDetailed.csv");

            char divider1(';');
            char divider2('\n');

            unsigned int index = 0; 

            try
            {
                if(!dataBaseWrite.is_open())
                    throw '1';
                else
                {
                    cout << "Writing actors in the file..." << endl;
                    
                    for(unsigned int i = 0; i < indexx; i++)
                    {
                        if(b[i].find("actor/actress") != string::npos)
                        {
                            dataBaseWrite << a[i];
                            dataBaseWrite << divider1;

                            dataBaseWrite << "actor";
                            dataBaseWrite << divider1;

                            dataBaseWrite << randomStringGenerator.randomDiet(randomStringGenerator.diet); //dataBaseWrite << "CIBO";
                            dataBaseWrite << divider1;
                            dataBaseWrite << randomStringGenerator.randomDiet(randomStringGenerator.type); //dataBaseWrite << "RUOLO";
                            dataBaseWrite << divider2;
                            index++;
                        }
                    }

                    cout << "Writing figures in the file..." << endl;

                    for(unsigned int i = 0; i < figureNumber; i++)
                    {
                        dataBaseWrite << randomStringGenerator.randomFigureName(names);
                        dataBaseWrite << divider1;

                        dataBaseWrite << "Figure";
                        dataBaseWrite << divider1;
                        dataBaseWrite << randomStringGenerator.randomDiet(randomStringGenerator.diet);
                        dataBaseWrite << divider1;

                        dataBaseWrite << randomStringGenerator.randomType(randomStringGenerator.type);
                        dataBaseWrite << divider2;
                    }
                    cout << "Writing the rest in the file..." << endl;

                    for(unsigned int i = 0; i < indexx; i++)
                    {
                        if(b[i].find("actor/actress") == string::npos)

                        {
                            dataBaseWrite << a[i];
                            dataBaseWrite << divider1;

                            dataBaseWrite << b[i];
                            dataBaseWrite << divider2;
                        }
                    }
                    dataBaseWrite.close();
                }
            }
            catch(char err)
            {
                if(err == '1')
                {
                    cout << "An error occured and the file was not opened." << endl;
                }
            }
            return index;
        }
};

unsigned int loading(string db1[max], string db2[max])
{
    cout << "Loading..." << endl;
    DataBaseReader dataBase1;
    unsigned int index;

    index = dataBase1.x2(db1, db2);
    if(index != 0)
    {
        cout << "\nLoading finished." << endl;
        cout << "Press any key to continue..." << endl;

        getch();
        //system("cls");

        return index;
    }
    return 0;
}

unsigned int generateFirstCSV(string db1[max], string db2[max], string figure[figureNumber], unsigned int indexx)
{
    cout << "Generating cast members CSV...\n\n";

    DataBaseWrite dataBase1;
    unsigned int index;

    index = dataBase1.x4(db1, db2, figure, indexx);
    if(index!=0)
    {
        cout << "\nLoading finished." << endl;
        cout << "Press any key to continue..." << endl;

        getch();
        //system("cls");

        return index;
    }
    return 0;
}

void readFirstCSV(unsigned int count[5], unsigned int castTotal)
{
    ifstream dataBaseRead;
    dataBaseRead.open("castDetailed.csv");

    char divider1(';');
    char divider2('\n');
    string s[2];

    try
    {
        if(!dataBaseRead.is_open())
            throw '1';
        else
        {
            for(unsigned int i = 0; i < castTotal; i++)
            {
                getline(dataBaseRead, s[0], divider1);
                getline(dataBaseRead, s[0], divider1);
                getline(dataBaseRead, s[0], divider1);
                getline(dataBaseRead, s[1], divider2);
                if(s[1] == "Vampire")
                    count[0]++;
                else
                    if(s[1] == "Werewolf")
                        count[1]++;
                    else
                        if(s[1] == "Siren")
                            count[2]++;
                        else
                            if(s[1] == "Clairvoyant")
                                count[3]++;
                            else
                                if(s[1] == "Human")
                                    count[4]++;
            }
            dataBaseRead.close();
        }
    }
    catch(char err)
    {
        if(err == '1')
        {
            cout << "An error occured and the file was not opened." << endl;
        }
    }
}

void verifyFirstCSVDiet(unsigned int count[3], unsigned int castTotal)
{
    ifstream dataBaseRead;
    dataBaseRead.open("castDetailed.csv");

    char divider1(';');
    char divider2('\n');
    string s[2];

    try
    {
        if(!dataBaseRead.is_open())
            throw '1';
        else
        {
            for(unsigned int i = 0; i < castTotal; i++)
            {
                getline(dataBaseRead, s[0], divider1);
                getline(dataBaseRead, s[0], divider1);
                getline(dataBaseRead, s[1], divider1);
                getline(dataBaseRead, s[0], divider2);
                if(s[1] == "Omnivore")
                    count[0]++;
                else
                    if(s[1] == "Vegan")
                        count[1]++;
                    else
                        if(s[1] == "Flexitarian")
                            count[2]++;
            }
            dataBaseRead.close();
        }
    }
    catch(char err)
    {
        if(err == '1')
        {
            cout << "An error occured and the file was not opened." << endl;
        }
    }
}

void prepareSecondCSV()
{
    ofstream dataBaseWrite;
    dataBaseWrite.open("castPrices.csv");

    char divider1(';');
    char divider2('\n');

    try
    {
        if(!dataBaseWrite.is_open())
            throw '1';
        else
        {
            dataBaseWrite << "Days";
            dataBaseWrite << divider1;

            dataBaseWrite << "30";
            dataBaseWrite << divider1;

            dataBaseWrite << "45";
            dataBaseWrite << divider1;

            dataBaseWrite << "60";
            dataBaseWrite << divider1;
            
            dataBaseWrite << "100";
            dataBaseWrite << divider2;
        }
    }
    catch(char err)
    {
        if(err == '1')
        {
            cout << "An error occured and the file was not opened." << endl;
        }
    }
}

void generateSecondCSV(unsigned int price[4], string sInput)
{
    ofstream dataBaseWrite ;
    dataBaseWrite.open("castPrices.csv",ios::app);

    char divider1(';');
    char divider2('\n');

    try
    {
        if(!dataBaseWrite.is_open())
            throw '1';
        else
        {
            dataBaseWrite << sInput;
            dataBaseWrite << divider1;
            for(unsigned int i = 0; i < 3; i++)
            {
                dataBaseWrite << price[i];
                dataBaseWrite << divider1;
            }
            dataBaseWrite << price[3];
            dataBaseWrite << divider2;
        }
    }
    catch(char err)
    {
        if(err == '1')
        {
            cout << "An error occured and the file was not opened." << endl;
        }
    }
}

void calculatePrice(unsigned int dayPrice, unsigned int totalPrice[4], unsigned int day[4])
{
    totalPrice[0] = dayPrice * day[0];
    totalPrice[1] = dayPrice * day[1];
    totalPrice[2] = dayPrice * day[2];
    totalPrice[3] = dayPrice * day[3];
}

class Members
{
    protected:
        unsigned int castInitialNumber;
        unsigned int actorNumber;
    public:
        Members();
        Members(unsigned int castNr, unsigned int actNr)
        {
            castInitialNumber = castNr;
            actorNumber = actNr;
        }
        unsigned int getCastNr()
        {
            return this->castInitialNumber;
        }
        unsigned int getActNr()
        {
            return this->actorNumber;
        }
};

class Prices : private Members
{
    private:
        unsigned int busPrice[4];
        unsigned int makeupPrice[4];
        unsigned int accomodationPrice[4];
        unsigned int rentPrice[4];

        unsigned int drinkPrice[4];
        unsigned int dietPrice[4];

        unsigned int day[4] = {30, 45, 60, 100};
        unsigned int nrZile;

    public:
        Prices(unsigned int castNr, unsigned int actNr) : Members(castNr, actNr)
        {
            castInitialNumber = castNr;
            actorNumber = actNr;
            cout << "Generating cost CSV...\n\n";
        }
        Prices();

        //getch();

        void getbusPrice()
        {
            unsigned int castTotal = castInitialNumber + figureNumber;
            busPrice[0] = castTotal / 50;
            if(castTotal%50 != 0)
                busPrice[0]++;
            busPrice[0] = busPrice[0] * defaultBusPrice *2 / dollarExchangeRate;

            for(unsigned int i = 1; i < 4; i++)
                busPrice[i] = busPrice[0];
            generateSecondCSV(busPrice, "Bus");
        }

        void getMakeupPrice()
        {
            unsigned int castTotal = castInitialNumber + figureNumber - actorNumber;

            unsigned int count[5] = { 0 };
            unsigned int dayPrice;
            readFirstCSV(count, castTotal);

            dayPrice = (count[0]*230 + count[1]*555 + count[2]*345 + count[3]*157 + count[4]*55)/dollarExchangeRate;

            calculatePrice(dayPrice, makeupPrice, day);

            generateSecondCSV(makeupPrice, "Makeup");
        }

        void getAccomodationPrice()
        {
            unsigned int castTotal = castInitialNumber + figureNumber;
            unsigned int count[2] = { 0 };
            unsigned int dayPrice;
            count[0] = castInitialNumber / 2;
            if(castInitialNumber%2 != 0)
                count[0]++;
            count[1] = figureNumber / 3;
            if(figureNumber%3 != 0)
                count[1]++;

            dayPrice = (count[0]*350 + count[1]*420) / dollarExchangeRate;

     
            calculatePrice(dayPrice, accomodationPrice, day);

 
            generateSecondCSV(accomodationPrice, "Accomodation");
        }

        void getrentPrice()
        {
            unsigned int dayPrice = 10000;

            calculatePrice(dayPrice, rentPrice, day);

            for(unsigned int i = 0; i < 4; i++)
                rentPrice[i] = rentPrice[i]*(1-0.02*(day[i] / 10)) / dollarExchangeRate;

         
            generateSecondCSV(rentPrice, "Rent");
        }
 
        void getDrinkPrices()
        {
            unsigned int castTotal = castInitialNumber + figureNumber;
            unsigned int dayPrice;
            unsigned int count[3] = { 0 };

            
            count[0] = castTotal *1 / 2;
            if(castTotal%2 != 0)
                count[0]++;

            count[1] = castTotal *0.5 / 1;
            if(castTotal%1 != 0)
                count[1]++;

            count[2] = castTotal *0.8 / 2;
            if(castTotal%1 != 0)
                count[2]++;

            dayPrice = (count[0] * 6 + count[1] * 30 + count[2] * 8) / dollarExchangeRate;

           
            calculatePrice(dayPrice, drinkPrice, day);

           
            generateSecondCSV(drinkPrice, "Drinks");
        }
       
        void getDietPrice()
        {
            unsigned int castTotal = actorNumber + figureNumber;
            unsigned int dayPrice;
            unsigned int count[3] = { 0 };
           
            verifyFirstCSVDiet(count, castTotal);

            dayPrice = (count[0] * 40 + count[1] * 33 + count[2] * 46) / dollarExchangeRate;
            calculatePrice(dayPrice, dietPrice, day);

       
            generateSecondCSV(dietPrice, "Diet");


            cout << "\nLoading finished." << endl;
        }
};

void listDb1(unsigned int index, string a[max], string b[max])
{
    for(unsigned int i = 0; i < index; i++)
    {
        cout << right << setw(3) << i + 1 << ") ";
        cout << right << setw(36) << a[i] << " - ";
        cout << left << setw(9) << b[i];
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));
    DataBase db1;

    db1.castInitialNumber = loading(db1.x, db1.y);
    db1.actorNumber = generateFirstCSV(db1.x, db1.y, db1.figure, db1.castInitialNumber);

    Members members(db1.castInitialNumber, db1.actorNumber);
    Prices prices(members.getCastNr(), members.getActNr());

    prepareSecondCSV();

    prices.getbusPrice();
    prices.getMakeupPrice();
    prices.getAccomodationPrice();
    prices.getrentPrice();
    prices.getDrinkPrices();
    prices.getDietPrice();

    return 0;
}