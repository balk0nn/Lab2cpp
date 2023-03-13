#include <iostream>

using namespace std;

int main() {

    // generating all possible pairs of integers from 0 to 9 which are not the same
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i == j) {
                cout << "botva" << endl;
            } // checking if the first player wins 0 over 9
            else if (i == 0 and j == 9) {

                // first player collects the cards
                cout << i << " won over " << j << endl;

                //if the second player wins this 0 over 9
            } else if (j == 0 and i == 9){

                //second player collects the cards
                cout << i << " lost to " << j << endl;

                // if the 0 over 9 case doesn't happen and first player wins
            } else if (i > j){

                // first player collects the cards
                cout << i << " won over " << j << endl;

                // if the second player wins
            } else{

                //second player collects the cards
                cout << i << " lost to " << j << endl;
            }
        }
    }

    return 0;
};