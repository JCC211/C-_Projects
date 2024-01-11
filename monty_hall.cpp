#include <iostream>
#include <math.h>
#include <ctime>
#include "time.h"
using namespace std;

int main()
{
    srand(time(NULL));
    int switchwin = 0;
    int noswitchwin = 0;
    const int n = 1000;
    // switch door
    for (int i = 0; i < n; i++)
    {
        int winningdoor = rand() % 3 + 1;
        int guessdoor = rand() % 3 + 1;
        int opendoor = 1;
        int remainingdoor = 1;
        int switchdoor = 1;
        while (opendoor == winningdoor || opendoor == guessdoor)
        {
            opendoor += 1;
        }
        while (remainingdoor == opendoor || remainingdoor == guessdoor)
        {
            remainingdoor += 1;
        }

        guessdoor = remainingdoor;

        if (guessdoor == winningdoor)
        {
            switchwin += 1;
        }
    }
    cout << endl;
    cout << "By switching doors you won " << (double(switchwin) / n) * double(100) << "% of the time." << endl;

    // don't switch door
    for (int i = 0; i < n; i++)
    {
        int winningdoor = rand() % 3 + 1;
        int guessdoor = rand() % 3 + 1;
        int opendoor = 1;
        int remainingdoor = 1;
        int switchdoor = 1;
        while (opendoor == winningdoor || opendoor == guessdoor)
        {
            opendoor += 1;
        }
        while (remainingdoor == opendoor || remainingdoor == guessdoor)
        {
            remainingdoor += 1;
        }
        if (guessdoor == winningdoor)
        {
            noswitchwin += 1;
        }
    }
    cout << endl;
    cout << "By not switching doors you won " << (double(noswitchwin) / n) * double(100) << "% of the time." << endl;
    cout << endl;
}