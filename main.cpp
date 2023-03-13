#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
    int n;
    cin >> n;

    // vector to keep track of applications
    vector<string> apps;

    // a string to keep track of the active application
    string active_app;

    // loop through n user actions
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        // if the command is to run an application
        if (command == "Run") {
            string app;

            // read the application name
            getline(cin >> ws, app);

            // add the application to the front of the vector
            apps.emplace(apps.begin(), app);

            // update the currently active application to the newly launched app
            active_app = app;

            // if the user action is to switch between applications
        } else {

            // extract the number of tabs from the command string
            int count = 0;

            // find the first occurrence of the substring
            unsigned long long pos = command.find("+Tab");

            // loop while the substring is found
            while (pos != string::npos) {
                count++;

                // find the next occurrence of the substring
                pos = command.find("+Tab", pos + 1);
            }
            count = count % apps.size();
            apps.emplace(apps.begin(), apps[count]);
            apps.erase(apps.begin() + count + 1); // clear the index where it was before;

            // update the currently active application to the new front of the deque
            active_app = apps.front();
        }

        // output the currently active application
        cout << active_app << endl;
    }

    return 0;
}