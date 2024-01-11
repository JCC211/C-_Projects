#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
    // 6 lottery tickets 1~75 no repeats
    srand(time(NULL));
    const int n = 6, num = 75, nt = 10;
    int win[n], ticket[nt][n];
    cout << endl
         << "The winning balls are: ";
    // winning balls
    for (int i = 0; i < n; i++)
    {
        bool re = true;
        while (re)
        {
            re = false;
            win[i] = rand() % 75 + 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (win[i] == win[j])
                {
                    re = true;
                    break;
                }
            }
        }
        cout << win[i] << ',';
    }
    cout << endl
         << endl;

    // bought tickets
    for (int k = 0; k < nt; k++)
    {
        cout << "Ticket " << k + 1 << ": ";
        for (int i = 0; i < n; i++)
        {
            bool re = true;
            while (re)
            {
                re = false;
                ticket[k][i] = rand() % 75 + 1;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (ticket[k][i] == ticket[k][j])
                    {
                        re = true;
                        break;
                    }
                }
            }
            cout << ticket[k][i] << ',';
        }
        cout << endl;
    }
    cout << endl;

    // check the matching numbers
    for (int k = 0; k < nt; k++)
    {
        int match = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ticket[k][i] == win[j])
                    match++;
            }
        }
        cout << "Ticket " << k + 1 << " has " << match << " mathces." << endl;
    }
}