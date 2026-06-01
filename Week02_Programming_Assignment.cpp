// ITCS 2530 - Week 02 Assignment
// Deven Shumney

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    // Define variables
    int actMovies = 7;
    int movieDiff;
    int dinoMovies;
    char dinoFeat;
    string actFeat;
    string dinoSound;
    ofstream outFile;

    // Introduction
    cout << "Welcome to the Dinosaur Directory!" << endl << endl;

    // Display prompts and request user input, handle invalid input once per
    cout << "How many movies are there in the \"Jurassic Park\" series?" << endl;
    cin >> dinoMovies;

    if (dinoMovies <= 0) {

        cin.clear();
        cin.ignore(100, '\n');
        cout << endl << "Please enter a number > 0." << endl;
        cin >> dinoMovies;
    }

    cout << endl << "Choose the coolest dinosaur feature: Teeth (T), Feathers (F), Horns (H)" << endl;
    cin >> dinoFeat;

    if ((dinoFeat != 'T') && (dinoFeat != 'F') && (dinoFeat != 'H')) {

        cin.clear();
        cin.ignore(100, '\n');
        cout << endl << "Invalid response! Please choose from the features above. *CASE SENSITIVE*" << endl;
        cin >> dinoFeat;
    }

    cout << endl << "Type out how you think a dinosaur sounds!" << endl;
    cin >> dinoSound;

    if (dinoSound == "rawr") {

        cout << endl << "Oh, come now...I know you can do better than that! Try it again!" << endl;
        cin >> dinoSound;
    }

    // Calculate difference between movie guess and actual movies
    if (dinoMovies > actMovies) {

        movieDiff = dinoMovies - actMovies;
    }
    else {

        movieDiff = actMovies - dinoMovies;
    }

    // Calculate feature from user input
    if (dinoFeat == 'T') {

        actFeat = "Teeth";
    }
    else if (dinoFeat == 'F') {

        actFeat = "Feathers";
    }
    else if (dinoFeat == 'H') {

        actFeat = "Horns";
    }
    else {

        actFeat = "???";
    }

    // Summary table window output
    cout << "\n------------------------------------------\n";
    cout << "              RESPONSE SUMMARY           \n";
    cout << "------------------------------------------\n";

    cout << left << setw(16) << "Movies Guessed:" << dinoMovies << endl;
    cout << left << setw(30) << "Guess Difference from Actual:" << movieDiff << endl;
    cout << left << setw(22) << "Coolest Dino Feature:" << actFeat << endl;
    cout << left << setw(16) << "Dinosaur Sound:" << dinoSound << endl;

    cout << "------------------------------------------" << endl;

    // Summary table file output
    outFile.open("report.txt");

    outFile << "------------------------------------------\n";
    outFile << "              RESPONSE SUMMARY           \n";
    outFile << "------------------------------------------\n";

    outFile << left << setw(16) << "Movies Guessed:" << dinoMovies << endl;
    outFile << left << setw(30) << "Guess Difference from Actual:" << movieDiff << endl;
    outFile << left << setw(22) << "Coolest Dino Feature:" << actFeat << endl;
    outFile << left << setw(16) << "Dinosaur Sound:" << dinoSound << endl;

    outFile << "------------------------------------------" << endl;

    outFile.close();

    return 0;
}