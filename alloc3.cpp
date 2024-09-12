#include <iostream>
using namespace std;

void clearS()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class fare
{
private:
    const float rate = 1.6;
    int n;
    string sp, dp;
    float dist;

public:
    void getP();
    int calcfare();
    void display();
} ep1;

int fare::calcfare()
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

void fare::getP()
{
    cout << "Enter start place: " << endl;
    cin >> sp;
    cout << "Enter destination: " << endl;
    cin >> dp;
    cout << "Distance:" << endl;
    cin >> dist;
    cout << "Number of person:" << endl;
    cin >> n;
}

void fare::display()
{
    cout << "----------BUS FARE---------" << endl;
    cout << "\n";
    cout << sp << " TO " << dp << endl;
    cout << "Distance : " << dist << " KM" << endl;
    cout << "FULL " << n << "X" << endl;
    cout << "Fare::  Rs\033[1m" << calcfare() << "\033[0m";
}

int main()
{
    clearS();
    ep1.getP();
    clearS();
    ep1.display();
    return 0;
}