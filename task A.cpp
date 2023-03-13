#include <iostream>
#include <set>

using namespace std;

int main() {

    //Reading the quantity of numbers
    int n;
    cin >> n;

    //Making a set
    set<int> numbers;

    //Reading n numbers and inserting them into the set
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers.insert(x);
    }

    //The set contains all the unique numbers, it's size is the answer
    cout << numbers.size() << endl;

    return 0;
}