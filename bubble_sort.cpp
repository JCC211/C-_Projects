#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

int main()
{
    srand(time(NULL));
    const int n = 10;
    int ball[n];

    // generate array with unique terms
    for (int i = 0; i < n; i++)
    {
        ball[i] = rand() % 75 + 1;
        // cout<<"Ball number(temporary): "<<i<<':'<<ball[i]<<"; ";
        bool redundant = true;
        while (redundant)
        {
            redundant = false; // before comparison, make boolean variable false
            for (int j = i - 1; j > -1; j--)
            {
                if (ball[i] == ball[j])
                {
                    redundant = true;
                    break;
                }
            }
            if (redundant)
            {
                ball[i] = rand() % 75 + 1;
            }
        }
        // cout<<"ball number(formal) "<<i<<':'<<ball[i]<<endl;
        cout << ball[i] << ", ";
    }
    cout << endl;

    // bubble sorting smallest to largest
    for (int k = 0; k < n - 1; k++)
    {
        for (int l = 0; l < n - k - 1; l++)
        {
            if (ball[l] > ball[l + 1])
            {
                int temp = ball[l];
                ball[l] = ball[l + 1];
                ball[l + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ball[i] << ", ";
    }
    cout << endl;
}