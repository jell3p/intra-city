#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;

//Defines player and character classes
class Player {
public:
    string name;

    Player(string nam = "Jade") {
        name = nam;
    }
};

class Character {
public:
    string name;

    Character(string nam = "Npc") {
        name = nam;
    }
};

/// Text color functions
void redtext(string x) { //notes IMPORTANT DECISION / BAD ENDING
    cout << "\x1b[31m" << x << "\x1b[0m";
}

void yellowtext(string x) { //notes CHARACTER
    cout << "\x1b[93m" << x << "\x1b[0m";
}

void greentext(string x) { // notes PLAYER
    cout << "\x1b[32m" << x << "\x1b[0m";
}

void bluetext(string x) { // notes NOTE
    cout << "\x1b[94m" << x << "\x1b[0m";
}

// Player Text and Character Text, they use the color functions
void youtext(Player joe) {
    greentext(joe.name);
    cout << ": ";

}

void youtext2() {
    greentext("YOU");
    cout << ": ";

}
void chartext(Character joe) {
    yellowtext(joe.name);
    cout << ": ";

}

//User input gets line, if "exit" is typed, game instantly ends
string username() {
    string input;
    getline(cin, input);

    if (input == "exit") {
        exit(0);
    }
    else return input;
}

string userinput() {
    string input;
    getline(cin, input);

  while (input.empty()) {
            cout << "Enter something!" << endl;
            getline(cin, input);
            if (input == "exit") {
                exit(0);
            }
        }
    if (input == "exit") {
        exit(0);
    }
    else return input;
}

void textdisplay(string text) { // Displays text. Has a delay for each character.
    for (int i = 0; i < text.size(); i++) {
        cout << text[i];
        this_thread::sleep_for(chrono::milliseconds(10));
    }
    cout << endl;
}

void ignoreinput() {
    greentext("-");
    cin.ignore();
}

void textdisplayreg(string text) { //Displays text with a cin.ignore at the end, so text doesn't go on forever.
    textdisplay(text);
    ignoreinput();
}

void textdisplayblue(string text) {
    text = "\x1b[94m" + text + "\x1b[0m";
    textdisplay(text);
}

void textdisplayred(string text) {
    text = "\x1b[31m" + text + "\x1b[0m";
    textdisplay(text);
}

// ASCII art (from patorjk.com / asciiart.eu )
void cityscape() {
    cout << R"(
                  \  |  /         ___________
   ____________  \ \_# /         |  ___      |       _________
  |            |  \  #/          | |   |     |      | = = = = |
  | |   |   |  |   \\#           | |`v'|     |      |         |
  |            |    \#  //       |  --- ___  |      | |  || | |
  | |   |   |  |     #_//        |     |   | |      |         |
  |            |  \\ #_/_______  |     |   | |      | |  || | |
  | |   |   |  |   \\# /_____/ \ |      ---  |      |         |
  |            |    \# |+ ++|  | |  |~~~~~~| |      | |  || | |
  |            |    \# |+ ++|  | |  |~~~~~~| |      | |  || | |
~~|    (~~~~~) |~~~~~#~| H  |_ |~|  | |||| | |~~~~~~|         |
  |    ( ||| ) |     # ~~~~~~    |  | |||| | |      | ||||||| |
  ~~~~~~~~~~~~~________/  /_____ |  | |||| | |      | ||||||| |
                                 ~~~~~~~~~~~~~      | ||||||| |
)" << endl;
}

void gameover() {
    cout << R"(
   _____          __  __ ______    ______      ________ _____  
  / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \ 
 | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |
 | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  / 
 | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \ 
  \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\
                                                               
                                                               
      1. Resume from last chapter    2. Return to title)" << endl;
}

void gameend() {
    cout << R"(
   _____          __  __ ______   ______ _   _ _____  
  / ____|   /\   |  \/  |  ____| |  ____| \ | |  __ \ 
 | |  __   /  \  | \  / | |__    | |__  |  \| | |  | |
 | | |_ | / /\ \ | |\/| |  __|   |  __| | . ` | |  | |
 | |__| |/ ____ \| |  | | |____  | |____| |\  | |__| |
  \_____/_/    \_\_|  |_|______| |______|_| \_|_____/ 


      1. Resume from last chapter    2. Return to title                                      
                                                      )" << endl;
}


void title() {
    cout << R"(
 _____ _   _ _______ _____            _____ _____ _________     __
 |_   _| \ | |__   __|  __ \     /\   / ____|_   _|__   __\ \   / /
   | | |  \| |  | |  | |__) |   /  \ | |      | |    | |   \ \_/ / 
   | | | . ` |  | |  |  _  /   / /\ \| |      | |    | |    \   /  
  _| |_| |\  |  | |  | | \ \  / ____ \ |____ _| |_   | |     | |   
 |_____|_| \_|  |_|  |_|  \_\/_/    \_\_____|_____|  |_|     |_|  
  ver 1.1                                                                 
                 1. Start Game    2. Exit
                (Enter a number to continue)                        )" << endl;
}