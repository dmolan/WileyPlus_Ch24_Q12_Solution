// Solution to WileyPlus Problem 12/13 of Homework Chapter 24 by dmolan

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265;



int main() {
    // Here one may test that cos() works in radians
    // cout << cos(PI/4) << '\n';
    
    // Let R = 1, e = 1, k = 1
    
    for (int i = 3; i <= 20; ++i)
    {
        int N = i;
        double U_1 = 0, U_2 = 0;
    
        /* --------------- */
        /* CIRCLE CASE (1) */
        /* --------------- */
        // One charges's interaction with all others
        for (int j = 1; j <= N-1; ++j)
        {
            U_1 += 1/(sqrt(2 * (1 - (cos(2*PI/N*j)))));
        }
        // When counting all interaction for each charge, every ineraction is counted twice, thus dividor of 2 is introduced
        U_1 = U_1 * N / 2;
        
        
        
        
        /* ------------------------- */
        /* CIRCLE AND A DOT CASE (2) */
        /* ------------------------- */
        // Similar to circle case (1) but for now exclude the dot, so N-2 instead of N-1 in cycle range etc.
        for (int j = 1; j <= N-2; ++j)
        {
            U_2 += 1/(sqrt(2 * (1 - (cos(2*PI/(N-1)*j)))));
        }
        // Again, similarly to circle case (1)
        U_2 = U_2 * (N-1) / 2;
        
        // Here finally account for the central's dot potential
        U_2 += (N-1);
        
        
    
        /* ------ */
        /* OUTPUT */
        /* ------ */
        cout << "N = " << N << ", U_(CIRCLE) - U_(CIRCLE AND A DOT) = " << U_1 - U_2 << "\n";
    }
    
    cout << "\nLet all constants be 1 (i.e. radius is also 1). Then in the case of N = 4 the distances to other electrons are:\n";
    
    int N = 12;
    int counterOfElectronsCloserThanRadius = 0;
    for (int i = 1; i <= N-2; ++i)
    {
        cout << "Distance for i = " << i << " is " << sqrt(2 * (1 - (cos(2*PI/(N-1)*i)))) << '\n';
        if (sqrt(2 * (1 - (cos(2*PI/(N-1)*i)))) < 1) ++counterOfElectronsCloserThanRadius;
    }
    cout << "For N = " << N << " there are " << counterOfElectronsCloserThanRadius << " electrons closer to some electron than the central one.\n";
    
    return 0;
}