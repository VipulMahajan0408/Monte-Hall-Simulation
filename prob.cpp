// g++ prob.cpp -o prob
// .\prob.exe --num_doors <value> --num_doors_opened_by_host <value> --num_simulations <value>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

// Function to simulate the Monty Hall Problem
pair<double, double> montyHallSimulation(int numDoors, int numDoorsOpenedByHost, int numSimulations) {
    int stickWins = 0;
    int switchWins = 0;

    // Perform the simulations
    for (int i = 0; i < numSimulations; ++i) {
        // Place the prize behind a random door
        int prizeDoor = rand() % numDoors + 1;
        // cout<<prizeDoor<<"\n";

        // Contestant makes initial choice
        int initialChoice = rand() % numDoors + 1;
        // cout<<initialChoice<<"\n";

        // Host opens doors that don't have the prize and weren't chosen by the contestant
        vector<int> remainingDoors(numDoors);
        iota(remainingDoors.begin(), remainingDoors.end(), 1);
        
        // for (auto x: remainingDoors){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        remainingDoors.erase(remove(remainingDoors.begin(), remainingDoors.end(), initialChoice), remainingDoors.end());
        
        // for (auto x: remainingDoors){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        remainingDoors.erase(remove(remainingDoors.begin(), remainingDoors.end(), prizeDoor), remainingDoors.end());
        
        // for (auto x: remainingDoors){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        random_shuffle(remainingDoors.begin(), remainingDoors.end());
        for (int j = 0; j < numDoorsOpenedByHost; ++j) {
            // Open doors by host
            remainingDoors.pop_back();
        }

        // for (auto x: remainingDoors){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        if(prizeDoor != initialChoice) remainingDoors.push_back(prizeDoor);
        random_shuffle(remainingDoors.begin(), remainingDoors.end());
        // Contestant switches choice
        int switchedChoice = remainingDoors[0];
        // cout<<switchedChoice<<"\n";

        // Check if contestant wins by sticking with initial choice
        if (initialChoice == prizeDoor) {
            stickWins++;
        }

        // Check if contestant wins by switching choice
        if (switchedChoice == prizeDoor) {
            switchWins++;
        }
    }

    // Calculate win percentages
    double stickWinPercentage = (static_cast<double>(stickWins) / numSimulations) * 100;
    double switchWinPercentage = (static_cast<double>(switchWins) / numSimulations) * 100;

    return make_pair(stickWinPercentage, switchWinPercentage);
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 7) {
        cerr << "Usage: " << argv[0] << " --num_doors <value> --num_doors_opened_by_host <value> --num_simulations <value>\n";
        return 1; // Exit with error code 1
    }

    // Variables to store command-line arguments
    int numDoors = -1;
    int numDoorsOpenedByHost = -1;
    int numSimulations = -1;

    // Parse command-line arguments
    for (int i = 1; i < argc; i += 2) {
        string arg = argv[i];
        if (arg == "--num_doors") {
            numDoors = atoi(argv[i + 1]);
        } else if (arg == "--num_doors_opened_by_host") {
            numDoorsOpenedByHost = atoi(argv[i + 1]);
        } else if (arg == "--num_simulations") {
            numSimulations = atoi(argv[i + 1]);
        } else {
            cerr << "Invalid argument: " << arg << "\n";
            return 1; // Exit with error code 1
        }
    }

    // Check if all required arguments are provided
    if (numDoors == -1 || numDoorsOpenedByHost == -1 || numSimulations == -1) {
        cerr << "Please provide all required arguments.\n";
        return 1; // Exit with error code 1
    }

    // Seed random number generator
    srand(time(nullptr));

    // Perform simulations
    pair<double, double> winPercentages = montyHallSimulation(numDoors, numDoorsOpenedByHost, numSimulations);

    // Output results
    cout << "Win percentage by sticking with initial choice: " << winPercentages.first << "%" << endl;
    cout << "Win percentage by switching doors: " << winPercentages.second << "%" << endl;

    return 0;
}