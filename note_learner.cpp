#include <iostream>
#include <ctime>
#include <math.h>
#include <string>
using namespace std;

// TREBLE CLEF
char TREB(int n, char D[])
{
    char treble[11]; // for treble: G to D -- 11 notes

    // loop to fill up treble cleff with notes
    for (int i = 0, x = 3; i < 11; i++)
    {
        treble[i] = D[x];
        x++;
        if (x > 6)
        {
            x = 0;
        }
    }
    return treble[n];
}

// BASS CLEF
char BASS(int n, char B[])
{
    char bass[11]; // for treble: G to D -- 11 notes
    // char B[7];

    // loop to fill up treble cleff with notes
    for (int i = 0, x = 5; i < 11; i++)
    {
        bass[i] = B[x];
        x++;
        if (x > 6)
        {
            x = 0;
        }
    }
    return bass[n];
}
void noteprinter(int r)
{
    // initialize variables to print notes
    char line[5] = {'-', '-', '-', '-', '-'};
    char space[5] = {' ', ' ', ' ', ' ', ' '};
    char clef[11][5] = {{' ', ' ', ' ', ' ', ' '}, {'-', '-', '-', '-', '-'}, {' ', ' ', ' ', ' ', ' '}, {'-', '-', '-', '-', '-'}, {' ', ' ', ' ', ' ', ' '}, {'-', '-', '-', '-', '-'}, {' ', ' ', ' ', ' ', ' '}, {'-', '-', '-', '-', '-'}, {' ', ' ', ' ', ' ', ' '}, {'-', '-', '-', '-', '-'}, {' ', ' ', ' ', ' ', ' '}};
    char note = 'O';
    clef[10 - r][2] = 'O'; // set middle character of 'r' row to O to represent note
    // print random note
    cout << endl;
    for (int i = 0; i < 11; i++) // 11 NEEDS TO BE MODIFIED HERE IF WANT EXPANDED STAFF
    {
        for (int j = 0; j < 5; j++)
        {
            cout << clef[i][j];
        }
        cout << endl;
    }
}

int main()
{
    char notes[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int notes1[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // inititalize variables for game
    char guess = ' '; // store user guess
    char ans = ' ';   // store correct answer
    int count = 0;    // store number of correct guesses
                   // run the game
    while (guess == ans)
    {
        srand(time(NULL));
        int c = rand() % 2;
        int r = rand() % 11;
        // cout << "c = " << c << endl;
        if (c == 0) // TREBLE CLEFFA
        {
            cout << endl
                 << "TREBLE CLEF";
            ans = TREB(r, notes);
        }
        else // BASS CLEFF
        {
            cout << endl
                 << "BASS CLEF";
            ans = BASS(r, notes);
        }
        // cout << "r = " << r << endl;
        // cout << "ans = " << ans << endl; //PRINT OUT ANSWER
        noteprinter(r);
        cout << endl
             << "Please enter the note shown above: ";
        cin >> guess;
        // clef[r][2] = clef[r][1]; //reset the middle character value of note to original character for next note generated
        // clef[r][2] = clef[r][1]; //reset the middle character value of note to original character for next note generated
        count++;
    }
    cout << endl;
    cout << "GAME OVER!" << endl;
    cout << "The correct answer was: " << ans << endl;
    cout << "You correctly identified " << count - 1 << " notes." << endl
         << endl;
}