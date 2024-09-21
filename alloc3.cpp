#include <iostream>
using namespace std;

int n, dist, fare;
float rate = 1.00;
string sp, dp;

struct Places
{
    string pl;
    float distance;
};

Places places[11] = {
    {"jalukbari", 0},
    {"adabari", 5},
    {"maligaon", 10},
    {"machkhowa", 14},
    {"fancyBazaar", 15},
    {"panbazar", 16},
    {"chandmari", 20},
    {"commerceCollege", 23},
    {"jonali", 25},
    {"ganeshguri", 27},
    {"hatigaon", 30}};

struct RPlaces
{
    string pl;
    float distance;
};

RPlaces rplaces[11] = {
    {"hatigaon", 0},
    {"ganeshguri", 3},
    {"jonali", 5},
    {"commerceCollege", 7},
    {"chandmari", 10},
    {"panbazar", 14},
    {"fancybazaar", 15},
    {"machkhowa", 16},
    {"maligaon", 20},
    {"adabari", 25},
    {"jalukbari", 30}};

void clearS()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int findDistance(string sp, string dp)
{
    int start = -1, end = -1;
    for (int i = 0; i < 11; i++)
    {
        if (places[i].pl == sp)
        {
            start = i;
        }
        if (places[i].pl == dp)
        {
            end = i;
        }
        if (start == -1 || end == -1)
        {
            cout << "Invalid address" << endl;
            exit(1);
        }
    }
    return places[end].distance - places[start].distance;
}

int RfindDistance(string sp, string dp)
{
    int start = -1, end = -1;
    for (int i = 0; i < 11; i++)
    {
        if (rplaces[i].pl == sp)
        {
            start = i;
        }
        if (rplaces[i].pl == dp)
        {
            end = i;
        }
        if (start == -1 || end == -1)
        {
            cout << "Invalid address" << endl;
            exit(1);
        }
    }
    return rplaces[end].distance - rplaces[start].distance;
}

float calcfare(int n, int dist, float rate)
{
    if (n == 0)
    {
        perror("Error");
    }

    if (dist <= 5)
        return n * 10;

    if (dist <= 10)
        return n * 15;

    if (dist <= 15)
        return n * 22;

    if (dist <= 20)
        return n * 25;

    if (dist > 20)
        return (n * dist * rate);

    else
        return -1;
}

void display(string sp, string dp, int n, int dist)
{
    cout << "----------BUS FARE---------" << endl;
    cout << "\n";
    cout << sp << " TO " << dp << endl;
    cout << "Distance : " << dist << " KM" << endl;
    cout << "FULL " << n << "X" << endl;
    cout << "Fare::  Rs\033[1m" << calcfare(n, dist, rate) << "\033[0m" << endl;
}

int main()
{
    clearS();
    char choice, ch;
    cout << "Ongoing (jalukbari-hatigaon) or return(hatigaon-jalukbari): o/r: " << endl;
    cin >> choice;
    do
    {
        if (choice == 'o')
        {
            clearS();
            cout << "Ongoing route 39(jalukbari-hatigaon)" << endl;
            cout << "\n";
            cout << "Enter start place: " << endl;
            cin >> sp;
            cout << "Enter destination: " << endl;
            cin >> dp;
            dist = findDistance(sp, dp);
            cout << "Number of person:" << endl;
            cin >> n;

            clearS();
            display(sp, dp, n, dist);
        }
        else if (choice == 'r')
        {
            clearS();
            cout << "Returning route 39(hatigaon-jalukbari)" << endl;
            cout << "\n";
            cout << "Enter start place: " << endl;
            cin >> sp;
            cout << "Enter destination: " << endl;
            cin >> dp;
            dist = RfindDistance(sp, dp);
            cout << "Number of person:" << endl;
            cin >> n;

            clearS();
            display(sp, dp, n, dist);
        }
        else
        {
            cout << "Error" << endl;
        }
        cout << "\n";
        cout << "Enter 'y' to calculate another fare: " << endl
             << "Enter 'n' to exit and update route: ";
        cin >> ch;
        clearS();
    } while (ch == 'y');

    return 0;
}