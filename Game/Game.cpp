#include <iostream>
#include <string>
#include "functions.h"
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    bool flag_jade = false;
    bool flag2 = false;
    bool flag3 = false;
    bool flag4 = false;
    bool flag5 = false;
    bool flag6 = false;
    bool flag7 = false;
    int checkpoint = 0;
    bool know = false;
    string gamestart;
    Player player("Jade");
    Character tot("Tot");
    Character hunter("Hunter");
    Character professor("Professor");
    Character chief("Chief");
    Character archaea("Archaea");
    bool init = false;

    while (!init) {
        switch (checkpoint) {
        case -1: return 0;
        case 0: title : title();  /// title screen
            gamestart = userinput();
            if (gamestart == "1") {
                checkpoint = 1;
                break;
            }
            else if (gamestart == "2") {
                checkpoint = -1;
                break;
            }
            else if (gamestart == "debug") {
                cout << "Choose chapter." << endl;
                cin >> checkpoint;
                break;
            }
            else {
                cout << "Enter a valid number....game restarting.";
                break;
            }
        case 1: cityscape(); // Intro Chapter
            textdisplay("(You awaken, surrounded by unfamiliar scenery. You are lying on a sidewalk, in what appears to be the downtown area of a city. You see no people. In fact, no signs of life are visible anywhere. The city is pristine, save the broken cars and novel-looking debris that line the streets."); textdisplayblue("[When you see a green dash, press ENTER to continue!]");
            ignoreinput();
            textdisplayreg("(You try to think of who you are and what your connection is to this city and your situation, but nothing comes to mind. After thinking a while, you rise to your feet as you decide to explore the city.)");
            textdisplay("(After 10 minutes of walking through generic buildings and empty shops, you notice the first sign of civilization since you woke up. You see a car with a large number 4 painted on its side. Investigate the car?)"); textdisplayblue("1. Yes |  2. Ignore it [Enter a number to choose!]");
            string choice1 = userinput(); //first decision, slightly changes dialogue, serves as an example of how decisions work in the game
            if (choice1 == "1") { 
                textdisplayreg("(You move closer to the car to investigate it. You try pulling the door open. It's locked. Suddenly, you hear the sound of someone's voice from behind you.)");
                yellowtext("Patroller: ");  textdisplayreg("Hey! What are you doing to that car!");
            }
            else if (choice1 == "2") {
                textdisplayreg("(You choose to ignore the car. As you turn around, you hear the sound of someone calling to you.)");
                yellowtext("Patroller: ");  textdisplayreg("Hey, who are you?");
            }
            textdisplayreg("(You turn around and see a young woman dressed in police gear holding a submachine gun. Any identifying information on her gear is scratched off, replaced with patches with the number 4.)");
            yellowtext("Patroller: ");  textdisplayreg("Hmmm? You don't have a patch on you. Ah, did you just wake up?");
            textdisplayreg("(You nod your head.)");
            yellowtext("Patroller: ");  textdisplayreg("So that's how it is. Well this might sound weird, but do you remember anything about your life? Like... your name, maybe?");
            textdisplayreg("(Your name....)");
            textdisplay("(You think about what your name was. From the back of your mind, something unexpectedly comes up. Your name is....)"); textdisplayblue("ENTER YOUR NAME:");
            string name;
            getline(cin, name); // second decision, decides your name. if left empty, Tot will name you.
            if (name.empty()) {
                textdisplayreg("(No matter how hard you think, you can't remember your name.");
                youtext2(); textdisplayreg("I... cant remember.");
                yellowtext("Patroller: ");  textdisplayreg("Well, that's to be expected. Do you remember.. anything?");
                textdisplayreg("(You shake your head.)");
                yellowtext("Patroller: ");  textdisplayreg("That's a problem. If you have no memories, it makes it harder to assign you a position. (Her face lights up as if she just realized something.) Hey, how about I name you?");
                textdisplayreg("(You have no reason to refuse, but her excitement worries you.)");
                youtext2(); textdisplayreg("That's fine.");
                yellowtext("Patroller: ");  textdisplayreg("Wonderful! A name huh.... (She takes a long look at you. You feel a bit embarrassed.) How about... " + player.name + "?");
                textdisplayreg("(" + player.name + ".... that's not as bad as you expected.)");
                youtext2(); textdisplayreg("Why that name?");
            }
            else {
                player.name = name;
                youtext2(); textdisplayname("My name is...", player.name); textdisplayreg(".");
                textdisplayreg("(You notice her face change in surprise at your answer.)");
                yellowtext("Patroller: ");  textdisplayreg("Wait, you actually remember your name? Thats... unexpected. Most of us don't remember our names when we wake up. If you remember your name, do you remember anything else? Like your job, family, friends, or any other memories?");
                textdisplayreg("(You are visibly overwhelmed by her questioning)");
                yellowtext("Patroller: ");  textdisplayreg("Oh, sorry. I'm asking a lot from someone who just spawned in aren't I? But this is really important, I promise.");
                textdisplayreg("(You think about it again, but like the last time, its useless. You really can't remember anything besides your name.)");
                youtext2(); textdisplayreg("Sorry. I can't remember anything at all.");
                textdisplayreg("(She is visibly disappointed.)");
                yellowtext("Patroller: ");  textdisplayreg("Oh. Well, thats still better than most of us. Ah, I guess I should explain everything to you now. For about a month now, people have been suddenly appearing in streets around the city without their memories, just like you. Of course, that include me as well.");
                yellowtext("Patroller: ");  textdisplayreg("Usually people manage to remember basic things about themselves, like their skills and past jobs. But never their names. Which is why I was surprised when you remembered yours. " + player.name + ", huh. That's a nice name. (She smiles at you.)");
            }
            yellowtext("Patroller: ");  textdisplayreg("Oh, by the way, people who just spawn in are given a job based on their skills. My job as patrol is to find newly spawned people and return them to the university. There, they recieve a name based on their skills, a job, and a dorm room. We are not paid money, but we all work together to survive.");
            yellowtext("Patroller: ");  textdisplayreg("Of course, you don't have to come with me. If you're good with guns, you also have the choice to become a soldier and defend the city from the monsters beyond the highway. So what will you choose?");
            textdisplayreg("(A new life in this unfamiliar city...... According to her, a society has been formed despite this strange situation. Also... did she just say monsters!?)");
            yellowtext("Patroller: ");  textdisplayreg("(???) So, What are you gonna do?");
            textdisplay("(Her confused stare forces you to choose. You choose to...)"); textdisplayred("[CHOICES IN RED WILL DRASTICALLY CHANGE THE STORY. CHOOSE WISELY] 1. Stay with her  | 2. Head for the highway and become a soldier");
            string choice2 = userinput();
        }

    }
    return 0;
}