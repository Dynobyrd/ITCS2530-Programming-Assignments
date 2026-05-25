// ITCS 2530 - Week 01 Assignment
// Deven Shumney

#include <iostream>
using namespace std;

int main()
{
    // Define variables
    string favHerb;
    string favCarn;
    string dinoRide;

    // Display prompts and request user input
    cout << "Let's talk about dinosaurs!" << endl << endl;

    cout << "What is your favorite dinosaur that eats plants?" << endl;
    cin >> favHerb;
    cout << "\nWhat is your favorite dinosaur that eats meat?" << endl;
    cin >> favCarn;
    cout << "\nIf you could ride on the back of any dinosaur, what would it be?" << endl;
    cin >> dinoRide;

    // Display paragraph with user-defined strings
    cout << "\nYour favorite herbivore appears to be the " << favHerb << ". That's awesome!" << endl;
    cout << "On the topic of carnivores, you like " << favCarn << ". I wouldn't want to run into that guy!" << endl;
    cout << "I'm picturing you saddled on top of a " << dinoRide << " now and it sounds like a blast!" << endl;
    cout << "Imagine trying to befriend and ride a " << favCarn << "...no thank you! I'll keep my limbs!" << endl;

    return 0;
}
