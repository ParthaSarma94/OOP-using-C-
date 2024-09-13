#include <iostream>
using namespace std;

int n, dist, fare;
float rate = 1.6;
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
    {"panbazar", 16},{"chandmari",20},{"commerceCollege",23},
    {"jonali",25},{"ganeshguri",27},{"hatigaon",30}
    };

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
    for (int i = 0; i < 11; ++i)
    {
        if (places[i].pl == sp)
            start = i;
        if (places[i].pl == dp)
            end = i;
    }
    return places[end].distance - places[start].distance;
}

int calcfare(int n, int dist, float rate)
{
    if (n == 0)
    {
        perror("Error");
    }

    if (dist <= 5)
    {
        return n * 10;
    }
    else if (dist <= 10)
    {
        return n * 15;
    }
    else if (dist <= 15)
    {
        return n * 22;
    }
    else if (dist <= 20)
    {
        return n * 25;
    }
    else
    {
        return (n * dist * rate);
    }
}


void display(string sp, string dp, int n, int dist)
{
    cout << "----------BUS FARE---------" << endl;
    cout << "\n";
    cout << sp << " TO " << dp << endl;
    cout << "Distance : " << dist << " KM" << endl;
    cout << "FULL " << n << "X" << endl;
    cout << "Fare::  Rs\033[1m" << calcfare(n, dist, rate) << "\033[0m";
}

int main()
{
    cout << "Enter start place: " << endl;
    cin >> sp;
    cout << "Enter destination: " << endl;
    cin >> dp;
    dist = findDistance(sp, dp);
    cout << "Number of person:" << endl;
    cin >> n;

    clearS();
    display(sp, dp, n, dist);

    return 0;
}

