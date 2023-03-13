#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> p1, p2; // deque to represent the cards of each player

    // reading the first player's cards
    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        p1.push_back(card);
    }

    // reading the second player's cards
    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        p2.push_back(card);
    }

    // a variable to count the amount of moves
    int move_count = 0;

    // playing the game until someone lost(empty deque(no cards left)) or the move count reached the limit
    while (!p1.empty() && !p2.empty() && move_count < 1000000) {
        int p1_card = p1.front();
        int p2_card = p2.front();
        p1.pop_front();
        p2.pop_front();

        // checking if the first player wins 0 over 9
        if (p1_card == 0 and p2_card == 9) {

            // first player collects the cards
            p1.push_back(p1_card);
            p1.push_back(p2_card);

            //if the second player wins this 0 over 9
        } else if (p2_card == 0 and p1_card == 9){

            //second player collects the cards
            p2.push_back(p1_card);
            p2.push_back(p2_card);

            // if the 0 over 9 case doesn't happen and first player wins
        } else if (p1_card > p2_card){

            // first player collects the cards
            p1.push_back(p1_card);
            p1.push_back(p2_card);

            // if the second player wins
        } else{

            //second player collects the cards
            p2.push_back(p1_card);
            p2.push_back(p2_card);
        }

        // adding 1 to the move count
        move_count++;
    }

    // printing out the answer for each possible outcome of the game
    if (move_count == 1000000) {
        cout << "botva" << endl;
    } else if (p2.empty()) {
        cout << "first " << move_count << endl;
    } else {
        cout << "second " << move_count << endl;
    }

    return 0;
}