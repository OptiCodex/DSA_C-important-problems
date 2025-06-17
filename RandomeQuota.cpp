#include <iostream>

#include  <vector>

#include <cstdlib>

#include <ctime>

using namespace std;

void randomeQuotaOrjoke() {
    vector < string > messages = {
        "Success is not final; failure is not fatal: It is the courage to continue that counts.",
        "Why do programmers prefer dark mode? Because light attracts bugs!",
        "Believe in yourself, even when no one else does.",
        "Why did the C++ developer go broke? Because he couldn’t 'catch' exceptions!",
        "Dream big. Start small. Act now.",
        "Code never lies, comments sometimes do.",
        "Push yourself, because no one else is going to do it for you.",
        "Why was the JavaScript developer sad? Because he didn’t know how to 'null' his feelings!"

    };

    srand(time(0));
    int randomIndex = rand() % messages.size();
    cout << "\n👉 " << messages[randomIndex] << "\n";

}

int main() {
    cout << "🎉 Welcome to Mukesh's Random Quote/Joke Generator 🎉\n";
    char choice;
    do {
        randomeQuotaOrjoke();
        cout << "\n🔁 Want another one? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nThanks for using the generator. Keep smiling! 😊\n";

    return 0;


}
