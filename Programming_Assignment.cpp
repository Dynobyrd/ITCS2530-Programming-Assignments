// ITCS 2530 - Week 05 Assignment
// Deven Shumney

#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;

// Define functions
// Display 
void displayIntro() {

    cout << "Welcome to the Dinosaur Directory!" << endl << endl;
}

// Movie 
int movieGuess() {

    int guess;
    cout << "\nHow many movies are there in the \"Jurassic Park\" series?" << endl;
    cin >> guess;

    while (guess <= 0) {

        cin.clear();
        cin.ignore(100, '\n');
        cout << endl << "Please enter a number > 0." << endl;
        cin >> guess;
    }

    cout << "\nFind out how close you were at the end!\n" << endl;

    return guess;
}

char featChoice() {

    char choice;
    cout << endl << "\nChoose the coolest dinosaur feature: Teeth (T), Feathers (F), Horns (H)" << endl;
    do {

        cin >> choice;

        if ((choice != 'T') && (choice != 'F') && (choice != 'H')) {

            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nInvalid response!Please choose from the features above. * CASE SENSITIVE * " << endl;
        }
    } while ((choice != 'T') && (choice != 'F') && (choice != 'H'));

    cout << "\nI think that's a really awesome feature too!\n" << endl;

    return choice;
}

string makeSound() {

    string sound;
    cout << endl << "\nType out how you think a dinosaur sounds!" << endl;
    cin >> sound;

    if ((sound == "rawr") || (sound == "roar")) {

        cout << "\nOh, come now...I know you can do better than that! Try it again!" << endl;
        cin >> sound;
        cout << "\n";
    }
    else {
        cout << "\nOh, how ravenous!\n" << endl;
    }

    for (int i = 0; i <= 2; i++) {

        cout << sound << " ";
    }

    cout << "\nAHHHHH, that's horrifying!\n" << endl;

    return sound;
}
// Perform calculations
int calcMovies(int numGuess, int numActual) {

    int diff;

    if (numGuess > numActual) {

        diff = numGuess - numActual;
    }
    else {

        diff = numActual - numGuess;
    }

    return diff;
}

string calcFeat(char feat) {

    string featWord;

    switch (feat) {
    case 'T':
        featWord = "Teeth";
        break;

    case 'F':
        featWord = "Feathers";
        break;

    case 'H':
        featWord = "Horns";
        break;

    default:
        featWord = "???";
    }

    return featWord;
}

// Display the menu
int displayMenu() {

    int choice;

    cout << "===== MAIN MENU =====\n";
    cout << "1. Movie Guesses\n";
    cout << "2. Dinosaur Features\n";
    cout << "3. Dinosaur Sounds\n";
    cout << "4. View Response Summary\n";
    cout << "5. Save Response Summary\n";
    cout << "6. Exit\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    return choice;
}

// Save the report
void saveReport(int movies, int diff, string feat, string sound) {

    ofstream outFile;
    outFile.open("report.txt");

    outFile << "------------------------------------------\n";
    outFile << "              RESPONSE SUMMARY           \n";
    outFile << "------------------------------------------\n";

    outFile << left << setw(16) << "Movies Guessed:" << movies << endl;
    outFile << left << setw(30) << "Guess Difference from Actual:" << diff << endl;
    outFile << left << setw(22) << "Coolest Dino Feature:" << feat << endl;
    outFile << left << setw(16) << "Dinosaur Sound:" << sound << endl;

    outFile << "------------------------------------------" << endl;

    outFile.close();
}

// Change console color - change the color of the text that is printed in console
void changeColor(int color) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    // Define variables
    int actMovies = 7;
    int dinoMovies = 0;
    int menuChoice = 0;
    int movieDiff = 0;
    char dinoFeat = ' ';
    string actFeat = "none";
    string dinoSound = "none";

    // Introduction
    changeColor(10);
    displayIntro();

    // Display program menu choices
    do {

        changeColor(10);
        menuChoice = displayMenu();

        switch (menuChoice) {

        case 1: // Jurassic Park movies, calculate difference

            changeColor(12);
            dinoMovies = movieGuess();
            movieDiff = calcMovies(dinoMovies, actMovies);
            break;

        case 2: // Dinosaur features, calculate full word

            changeColor(12);
            dinoFeat = featChoice();
            actFeat = calcFeat(dinoFeat);
            break;

        case 3: // Dinosaur sounds

            changeColor(12);
            dinoSound = makeSound();
            break;

        case 4: // Display response table

            if ((dinoMovies == 0) || (actFeat == "none") || (dinoSound == "none")) {

                changeColor(4);
                cout << "\nPlease complete all directory questions first.\n" << endl;
            }
            else {

                changeColor(10);
                cout << "\n------------------------------------------\n";
                cout << "              RESPONSE SUMMARY           \n";
                cout << "------------------------------------------\n";

                cout << left << setw(16) << "Movies Guessed:" << dinoMovies << endl;
                cout << left << setw(30) << "Guess Difference from Actual:" << movieDiff << endl;
                cout << left << setw(22) << "Coolest Dino Feature:" << actFeat << endl;
                cout << left << setw(16) << "Dinosaur Sound:" << dinoSound << endl;

                cout << "------------------------------------------" << endl;
            }
            break;

        case 5: // Save response table

            changeColor(10);
            saveReport(dinoMovies, movieDiff, actFeat, dinoSound);
            cout << "\nReport saved!\n" << endl;
            break;

        case 6: // Exit

            changeColor(10);
            cout << "\nThank you for visiting the Dinosaur Directory!" << endl;
            break;

        default: // Loop menu on invalid input

            changeColor(4);
            cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (menuChoice != 6);

    return 0;
}