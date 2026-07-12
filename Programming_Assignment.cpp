/* 
ITCS 2530 - Week 08 Assignment
Deven Shumney
Andy Rizo


Define a class that represents your overall tracker/manager for the hobby.

    At least one private data member that stores:

    An array of your struct type (e.g., Session sessions[7];), or Other meaningful data such as counts, totals, etc.

    At least one constructor which initializes the object to a safe starting state.

    At least three public member functions.
    
    You may move some of the already present functions into the class as member functions.

*/ 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;


// Enums
enum menuChoice { MOVIES, FEATURES, SOUNDS, RATINGGAME, VIEW, SAVE, EXIT };

// Defined functions 

// Change console color - change the color of the text that is printed in console
void changeColor(int color) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Display 
void displayIntro() {

    cout << "Welcome to the Dinosaur Directory!" << endl << endl;
}

// Movie 
void programTasks::moviesCreated(int actMovies, int movieDiff) {

    int difference;
    int guess;
    int numActual;

    cout << "\nHow many movies are there in the \"Jurassic Park\" series?" << endl;
    cin >> guess;

    while (guess <= 0) {

        cin.clear();
        cin.ignore(100, '\n');
        cout << endl << "Please enter a number > 0." << endl;
        cin >> guess;
    }

    if (guess > numActual) {

        difference = guess - numActual;
    }
    else {

        difference = numActual - guess;
    }

    cout << "\nFind out how close you were at the end!\n" << endl;
}

void programTasks::favoriteFeature() {
    string feature;
    char choice;
    cout << endl << "\nChoose the coolest dinosaur feature: Teeth (T), Feathers (F), Horns (H)" << endl;

    //Input for choice with error handler
    do {    
        cin >> choice;

        if ((choice != 'T') && (choice != 'F') && (choice != 'H')) {

            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nInvalid response!Please choose from the features above. * CASE SENSITIVE * " << endl;
        }
    } while ((choice != 'T') && (choice != 'F') && (choice != 'H'));

    //Converts magic letter into a word
    switch (choice) {

        case 'T':
            feature = "Teeth";
            break;

        case 'F':
            feature = "Feathers";
            break;

        case 'H':
            feature = "Horns";
            break;

        default:
            feature = "???";
        }

    cout << "\nI think that's a really awesome feature too!\n" << endl;
    
}

// Dino Sounds
void programTasks::makeSound() {

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
}

//User input of char type is turned into an enum.
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
// Minigame: higher or lower guessing game.
void programTasks::ratingGame(string movies[], int ratings[], int size)
{
    int score = 0;
    string answer;

    cout << endl;
    cout << endl;
    cout << "Guess if the next movie has a HIGHER or LOWER rating.";
    cout << endl;
    cout << endl;


    for (int i = 0; i < size - 1; i++)  //This loop will run 6 times in total unless more array entries are added.
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

        do // Do while to check for invalid inputs.
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


        if (ratings[i + 1] > ratings[i]) //This if else checks to see if one movie has a higher rating than the other and if the user input is correct for either.
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

        if (correct) //Adds 1 to score
        {
            cout << endl;
            cout << "   ";
            cout << "Correct!";
            score++;
            cout << endl;
            cout << endl;
        }
        else //Add nothing to score
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

// Save the report to a text file.
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

//classes
class programTasks {

public:
    void moviesCreated(int actMovies, int movieDiff);
    void favoriteFeature();
    void makeSound();
    void ratingGame(string movies[], int ratings[], int size);

    struct taskResults {

        int movieAmountGuessed; // For the guess how many movies there are.

        string favoriteDinoFeature;

        string imitateDinoSounds;

        int movieMinigameScore; // For the higher/lower game.

    };

private:
    int actMovies;
    int movieDiff;

};


int main()
{
    // Define variables
    int menuChoice = 0;

    
    string movieNames[]{ "Jurassic Park", "The Lost World: Jurassic Park", "Jurassic Park III", "Jurassic World", "Jurassic World: Fallen Kingdom", "Jurassic World: Dominion", "Jurassic World: Rebirth"};

    int movieRatings[] { 91, 57, 49, 72, 47, 28, 50}; //Each one corresponds to movieNames in order. (Rotten Tomatoe Ratings)

    int movieCount = 7;// This one is used for the array length in the for loop

    bool playedRatingGame = false;

    //Structs
    userData progress;

    //Classes
    programTasks tasks;



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
            progress.movieAmountGuessed = movieGuess();
            break;

        case FEATURES: // Dinosaur features, calculate full word

            changeColor(12);
            dinoFeat = featChoice();
            progress.favoriteDinoFeature = calcFeat(dinoFeat);
            break;

        case SOUNDS: // Dinosaur sounds

            changeColor(12);
            progress.imitateDinoSounds = makeSound();
            break;

        case RATINGGAME:

            changeColor(15);

            progress.movieMinigameScore = ratingGame(movieNames, movieRatings, movieCount);

            playedRatingGame = true;

            break;

        case VIEW: // Display response table

            if ((progress.movieAmountGuessed == 0) || (progress.favoriteDinoFeature == "none") || (progress.imitateDinoSounds == "none") || (playedRatingGame == false)) {

                changeColor(4);
                cout << "\nPlease complete all directory questions first.\n" << endl;
            }
            else {

                changeColor(10);
                cout << "\n------------------------------------------\n";
                cout << "              RESPONSE SUMMARY           \n";
                cout << "------------------------------------------\n";

                cout << left << setw(16) << "Movies Guessed:" << progress.movieAmountGuessed << endl;
                cout << left << setw(30) << "Guess Difference from Actual:" << movieDiff << endl;
                cout << left << setw(22) << "Coolest Dino Feature:" << progress.favoriteDinoFeature << endl;
                cout << left << setw(16) << "Dinosaur Sound:" << progress.imitateDinoSounds << endl;
                cout << left << setw(22) << "Rating Game Score:" << progress.movieMinigameScore << "/6" << endl;

                cout << "------------------------------------------" << endl;
            }
            break;

        case SAVE: // Save response table

            changeColor(10);
            saveReport(progress.movieAmountGuessed, movieDiff, progress.favoriteDinoFeature, progress.imitateDinoSounds, progress.movieMinigameScore);
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