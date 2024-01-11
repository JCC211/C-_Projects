#include <iostream>
using namespace std;

int main()
{
    // Print Pascals Triangle in Terminal
    // To change number of rows of triangle, adjust const int r
    const int r = 5, c = (r * 2) + 1; // r is number of rows of pascal triangle and c array width
    int A[r][c] = {0};                // initialize all array variables to zero
    A[0][r + 1] = 1;                  // set the middle value of the first row equal to A for the first row of pascal triangle
    for (int i = 0; i < r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (A[i][j] == 0) // print out a space if array value is zero
            {
                cout << ' ';
            }
            else // print out array value if non-zero
            {
                cout << A[i][j];
            }
            A[i + 1][j] = A[i][j - 1] + A[i][j + 1]; // create values for next row of 2D array
        }
        cout << endl;
    }
}