// ITCS 2530 - Week 06 Assignment
// Deven Shumney
// Andy Rizo (Introduced Enums and Arrays + added a new minigame)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;

// ENUMERATION FOR MENU CHOICE
enum menuChoice { MOVIES, FEATURES, SOUNDS, RATINGGAME, VIEW, SAVE, EXIT };



// Defined functions 

// Change console color - change the color of the text that is printed in console
void changeColor(int color) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Minigame: higher or lower guessing game.
int ratingGame(string movies[], int ratings[], int size) 
{
    //Variables
    int score = 0;
    string answer;

    //Start
    cout << endl;
    cout << endl;
    cout << "Guess if the next movie has a HIGHER or LOWER rating.";
    cout << endl;
    cout << endl;


    for (int i = 0; i < size - 1; i++)  //This loop will run 6 times in total
    {
        cout << "Does ";

        changeColor(10);
        cout << movies[i + 1];
        changeColor(15);

        cout << " have a higher or lower rating than ";

        changeColor(10);
        cout << movies[i];
        changeColor(15);
        
        cout << " ???";

        cout << endl;
        cout << endl;
        changeColor(10);
        cout << "Rating to go off of: " << ratings[i] << "/100";
        changeColor(15);

        do // Do while Error Handler
        {
            cout << endl;
            cout << endl;
            cout << "Higher or Lower: ";
            cin >> answer;

            while (answer != "Higher" && answer != "higher" && answer != "Lower" && answer != "lower") 
            {
                cout << "Invalid answer. Please enter Higher or Lower.\n";
                cin >> answer;
            }

        } while (answer != "Higher" && answer != "higher" && answer != "Lower" && answer != "lower");


        bool correct = false; // From here we check the user input to see if its correct or wrong


        if (ratings[i + 1] > ratings[i]) 
        {
            if ((answer == "Higher") || (answer == "higher")) 
            {
                correct = true;
            }
        }
        else 
        {
            if ((answer == "Lower") || (answer == "lower")) 
            {
                correct = true;
            }
        }

        if (correct) //Add 1 to score or nothing
        {
            cout << endl;
            cout << "   ";
            cout << "Correct!";
            score++;
            cout << endl;
            cout << endl;
        }
        else 
        {
            cout << endl;
            cout << "   ";
            cout << "Incorrect!";
            cout << endl;
            cout << endl;
        }
    }
    // After the for loop
    cout << "Minigame Completed.";
    cout << endl;
    cout << "Final Score: " << score << "/" << size - 1 << "";
    cout << endl;
    cout << endl;

    return score;
}

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

void getMenuChoice(int& menuChoice)
{
    switch (menuChoice)
    {
    case 1:
        menuChoice = MOVIES;
        break;

    case 2:
        menuChoice = FEATURES;
        break;

    case 3:
        menuChoice = SOUNDS;
        break;

    case 4:
        menuChoice = RATINGGAME;
        break;

    case 5:
        menuChoice = VIEW;
        break;

    case 6:
        menuChoice = SAVE;
        break;

    case 7:
        menuChoice = EXIT;
        break;
    }
}

// Display the menu
int displayMenu() {

    int choice;

    cout << "===== MAIN MENU =====\n";
    cout << "1. Movie Guesses\n";
    cout << "2. Dinosaur Features\n";
    cout << "3. Dinosaur Sounds\n";
    cout << "4. Rating Game\n";
    cout << "5. View Response Summary\n";
    cout << "6. Save Response Summary\n";
    cout << "7. Exit\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    return choice;
}

// Save the report
void saveReport(int movies, int diff, string feat, string sound, int score) {

    ofstream outFile;
    outFile.open("report.txt");

    outFile << "------------------------------------------\n";
    outFile << "              RESPONSE SUMMARY           \n";
    outFile << "------------------------------------------\n";

    outFile << left << setw(16) << "Movies Guessed:" << movies << endl;
    outFile << left << setw(30) << "Guess Difference from Actual:" << diff << endl;
    outFile << left << setw(22) << "Coolest Dino Feature:" << feat << endl;
    outFile << left << setw(16) << "Dinosaur Sound:" << sound << endl;
    outFile << left << setw(22) << "Rating Game Score:" << score << "/6" << endl;

    outFile << "------------------------------------------" << endl;

    outFile.close();
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


    //New Variables + Arrays
    int ratingScore = 0;
    bool playedRatingGame = false;

    string movieNames[]{ "Jurassic Park", "The Lost World: Jurassic Park", "Jurassic Park III", "Jurassic World", "Jurassic World: Fallen Kingdom", "Jurassic World: Dominion", "Jurassic World: Rebirth"};

    int movieRatings[] { 91, 57, 49, 72, 47, 28, 50}; //Each one corresponds to movieNames in order. (Rotten Tomatoe Ratings)

    int movieCount = 7;// This one is used for the array length in the for loop


    // Introduction
    changeColor(10);
    displayIntro();

    // Display program menu choices
    do {

        changeColor(10);
        menuChoice = displayMenu();

        getMenuChoice(menuChoice);

        switch (menuChoice) {

        case MOVIES: // Jurassic Park movies, calculate difference

            changeColor(12);
            dinoMovies = movieGuess();
            movieDiff = calcMovies(dinoMovies, actMovies);
            break;

        case FEATURES: // Dinosaur features, calculate full word

            changeColor(12);
            dinoFeat = featChoice();
            actFeat = calcFeat(dinoFeat);
            break;

        case SOUNDS: // Dinosaur sounds

            changeColor(12);
            dinoSound = makeSound();
            break;

        case RATINGGAME:

            changeColor(15);

            ratingScore = ratingGame(movieNames, movieRatings, movieCount);

            playedRatingGame = true;

            break;

        case VIEW: // Display response table

            if ((dinoMovies == 0) || (actFeat == "none") || (dinoSound == "none") || (playedRatingGame == false)) {

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
                cout << left << setw(22) << "Rating Game Score:" << ratingScore << "/6" << endl;

                cout << "------------------------------------------" << endl;
            }
            break;

        case SAVE: // Save response table

            changeColor(10);
            saveReport(dinoMovies, movieDiff, actFeat, dinoSound, ratingScore);
            cout << "\nReport saved!\n" << endl;
            break;

        case EXIT: // Exit

            changeColor(10);
            cout << "\nThank you for visiting the Dinosaur Directory!" << endl;
            break;

        default: // Loop menu on invalid input

            changeColor(4);
            cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (menuChoice != EXIT); // Changed to ENUM

    return 0;
}