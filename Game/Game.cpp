#include <iostream>
#include <string>
#include "functions.h"
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    bool flag_jade = false; //flag that unlocks special dialogue if no name is chosen. Has no effect on endings.
    bool flag_train = false;// flag that unlocks Tot ending
    bool flag_airfield = false; // flag that unlocks the Hunter ending
    bool flag_airfield_complete = false;
    bool flag_shower = false; // useless flag lol
    int checkpoint = 0; //checkpoint system
    bool know = false; //flag for optional "true" ending
    string gamestart;
    string firstname;
    string password;
    string password2;
    string choice1;
    string choice2;
    string choice3a;
    string choice4a;
    string choice5a;
    string choice6a;
    string choice7a;
    string choice3b;
    string choice4b;
    string choice5b;
    string choice6b;
    string choice7b;
    string choice8b;
    string name;
    Player player("Jade");
    Character tot("Tot");
    Character hunter("Hunter");
    Character professor("Professor");
    Character chief("Chief");
    Character aki("Archaea");
    Character riot("Riot");
    Character secretary("Secretary");
    bool init = false;

    while (!init) {
        switch (checkpoint) {
        case -1: return 0;
        case 0: title: title();  /// title screen
            gamestart = userinput();
            if (gamestart == "1") {
                checkpoint = 1;
                break;
            }
            else if (gamestart == "2") {
                checkpoint = -1;
                break;
            }
            else if (gamestart == "debug") { // if "debug" is typed in title screen, lets user change choose chapter
                cout << "Choose chapter." << endl;
                cin >> checkpoint;
                break;
            }
            else if (gamestart == "remember") { // if "remember" is typed in title screen, unlocks true ending
                know = true;
                cout << "True ending flag unlocked." << endl;
                break;
            }
            else {
                cout << "Enter a valid number....game restarting.";
                break;
            }
        case 1: cityscape(); // Intro:  Chapter 1
            if (know) {
                textdisplay("(You awaken, surrounded by unfamiliar scenery. Actually, thats a lie. You remember this place. You are lying on a sidewalk, in the downtown area of the city. You see no people. In fact, no signs of life are visible anywhere. Just like last time, the city is pristine, save the broken cars and novel-looking debris that line the streets.");
                ignoreinput();
                textdisplayreg("(You remember your name. It was " + player.name + ". You decide to move. You have a job to do.");
            }
            else {
                textdisplay("(You awaken, surrounded by unfamiliar scenery. You are lying on a sidewalk, in what appears to be the downtown area of a city. You see no people. In fact, no signs of life are visible anywhere. The city is pristine, save the broken cars and novel-looking debris that line the streets."); textdisplayblue("[When you see a green dash, press ENTER to continue!]");
                ignoreinput();
                textdisplayreg("(You try to think of who you are and what your connection is to this city and your situation, but nothing comes to mind. After thinking a while, you rise to your feet as you decide to explore the city.)");
            }
            textdisplay("(After 10 minutes of walking through generic buildings and empty shops, you notice the first sign of civilization since you woke up. You see a car with a large number 4 painted on its side. Investigate the car?)"); textdisplayblue("1. Yes |  2. Ignore it [Enter a number to choose. Entering a number other than those listed will defualt the choice to the last one.]");
            choice1 = userinput(); //first decision, slightly changes dialogue, serves as an example of how decisions work in the game
            if (choice1 == "1") {
                textdisplayreg("(You move closer to the car to investigate it. You try pulling the door open. It's locked. Suddenly, you hear the sound of someone's voice from behind you.)");
                yellowtext("Patroller: ");  textdisplayreg("Hey! What are you doing to that car!");
            }
            else {
                textdisplayreg("(You choose to ignore the car. As you turn around, you hear the sound of someone calling to you.)");
                yellowtext("Patroller: ");  textdisplayreg("Hey, who are you?");
            }
            textdisplayreg("(You turn around and see a young woman dressed in police gear gripping a submachine gun. Any identifying information on her gear is scratched off, replaced with patches sewn with the number 4. Her stressed face calms when she looks at your face for some reason.)");
            yellowtext("Patroller: ");  textdisplayreg("Hmmm? You don't have a patch on you. Ah, did you just wake up?");
            textdisplayreg("(You nod your head.)");
            yellowtext("Patroller: ");  textdisplayreg("So that's how it is. Well this might sound weird, but do you remember anything about your life? Like... your name, maybe?");
            textdisplayreg("(Your name....)");
            textdisplay("(You think about what your name was. From the back of your mind, something unexpectedly comes up. Your name is....)"); textdisplayblue("ENTER YOUR NAME:");
            getline(cin, name); // second decision, decides your name. if left empty, Tot will name you.
            if (name.empty()) { //Special dialogue 1
                textdisplayreg("(It's no use. No matter how hard you think, you can't remember your name.");
                youtext2(); textdisplayreg("I... can't remember.");
                yellowtext("Patroller: ");  textdisplayreg("Well, that's to be expected. Do you remember... anything at all?");
                textdisplayreg("(You shake your head.)");
                yellowtext("Patroller: ");  textdisplayreg("That's a problem. If you have no memories, it makes it harder to assign you a position. (Suddenly, her face lights up as if she just realized something.) Hey, how about I give you a name?");
                textdisplayreg("(You have no reason to refuse, but her excitement worries you.)");
                youtext2(); textdisplayreg("That's fine.");
                yellowtext("Patroller: ");  textdisplayreg("Wonderful! A name huh.... (She takes a long look at you. You feel a bit embarrassed.) How about... " + player.name + "?");
                flag_jade = true;
                textdisplayreg("(" + player.name + ".... that's not as bad as you expected.)");
                youtext2(); textdisplayreg("Why that name?");
                yellowtext("Patroller: ");  textdisplayreg("It's the color of your hair. " + player.name + "... It's a nice name isn't it?. (She smiles at you.)");
                textdisplayreg("(You grab a strand of hair from your shoulder and take a look at it. You didn't notice, but she was right.)");
                yellowtext("Patroller: ");  textdisplayreg("Ah, I guess I should explain everything to you now. For about a month now, people have been suddenly appearing in streets around the city without their memories, just like you. Of course, that includes me as well.");
                yellowtext("Patroller: ");  textdisplayreg("Usually people manage to remember basic things about themselves, like their skills and past jobs. It's a bit strange to see someone who doesn't remember anything at all. At least, that what I was told when I spawned. I didn't remember anything either. It's nice seeing someone who's just like me. (She seems pleased to have found a comrade.)");
                textdisplayreg("(You were about to thank her and ask her name before she suddenly interrupts.)");
                player.name = name;
                if (!know) {
                    name = firstname; // If the flag for true ending is not unlocked, name will not be remembered next playthrough
                }
            }
            else {
                player.name = name;
                if (!know) {
                    name = firstname; // If the flag for true ending is not unlocked, name will not be remembered next playthrough
                }
                youtext2(); textdisplayname("My name is...", player.name); textdisplayreg(".");
                textdisplayreg("(You notice her face change in surprise at your answer.)");
                yellowtext("Patroller: ");  textdisplayreg("Wait, you actually remember your name? Thats... unexpected. Most of us don't remember our names when we wake up. If you remember your name, do you remember anything else? Like your job, family, friends, or any other memories?");
                textdisplayreg("(You are visibly confused by her constant questioning.)");
                yellowtext("Patroller: ");  textdisplayreg("Oh, sorry. I'm asking a lot from someone who just spawned in aren't I? But this is really important, I promise.");
                textdisplayreg("(You think about it again, but like the last time, its useless. You really can't remember anything besides your name.)");
                youtext2(); textdisplayreg("Sorry. I can't remember anything at all.");
                textdisplayreg("(She is visibly disappointed.)");
                yellowtext("Patroller: ");  textdisplayreg("Oh. Well, thats still better than most of us. Ah, I guess I should explain everything to you now. For about a month now, people have been suddenly appearing in streets around the city without their memories, just like you. Of course, that include me as well.");
                yellowtext("Patroller: ");  textdisplayreg("Usually people manage to remember basic things about themselves, like their skills and past jobs. But never their names. Which is why I was surprised when you remembered yours. " + player.name + ", huh. That's a nice name. (She smiles at you.)");
            }
            yellowtext("Patroller: ");  textdisplayreg("By the way, people who just spawn in are given a job based on their skills. My job as patrol is to find newly spawned people and return them to the university. There, they recieve a name based on their skills, a job, and a dorm room. We are not paid money, but we all work together to survive.");
            yellowtext("Patroller: ");  textdisplayreg("Of course, you don't have to come with me. If you're good with guns, you also have the choice to become a Highway Guard and defend the city from the monsters beyond the highway. So what will you choose?");
            textdisplayreg("(A new life in this unfamiliar city...... According to her, a society has been formed despite this strange situation. Wait... did she just say monsters!?)");
            yellowtext("Patroller: ");  textdisplayreg("(???) So, what are you gonna do?");
            textdisplay("(Her confused stare forces you to choose. You choose to...)"); textdisplayred("[CHOICES IN RED WILL DRASTICALLY CHANGE THE STORY. CHOOSE WISELY] 1. Stay with her  | 2. Head for the highway and become a Highway Guard");
            choice2 = userinput(); //MAIN CHOICE 
            if (choice2 == "1") {
                checkpoint = 2;
                break;
            }
            else {
                checkpoint = 7;
                break;
            }
        case 2: youtext2(); textdisplayreg("I want to stay with you."); //Chapter 2a:
            textdisplayreg("(She gives you a wide smile.)");
            yellowtext("Patroller: ");  textdisplayreg("Good choice! Then, " + player.name + ", follow me! I'll lead you to the University. From there, you'll get assigned a job and become a functioning member of our little society.");
            textdisplayreg("(She starts walking in the direction of the University. You stop for a bit, confused.)");
            youtext2(); textdisplayreg("Aren't we taking the car?");
            yellowtext("Patroller: ");  textdisplayreg("The car? That thing doesn't work. We have the keys for it, so it's used for supplies. But there's no gas.");
            youtext2(); textdisplayreg("That's disappointing.");
            yellowtext("Patroller: ");  textdisplayreg("(She starts walking again.) Well, not like there's anywhere to go. We're locked inside the city. Beyond the highways are where the monsters live. They're called mimics, because they look like people without the face.");
            youtext2(); textdisplayreg("That sounds terrifying.");
            yellowtext("Patroller: ");  textdisplayreg("Well that's what we're for. And the Highway Guards, of course.");
            yellowtext("Patroller: ");  textdisplayreg("Oh, I never told you my name did I? How rude of me. My name is Tot.");
            youtext2(); textdisplayreg("Were you a toddler in your past life?");
            chartext(tot);  textdisplayreg("Of course not! I think. Since I didn't remember my name, I had the Professor name me. He named me that because I'm one of the youngest here.");
            textdisplayreg("(She's had it rough, huh.)");
            chartext(tot);  textdisplayreg("Look, we're already here. (She points at the University. It's big enough to be a small town on it's own.)");
            chartext(tot);  textdisplayreg("Let's go in.");
            textdisplayreg("(You follow Tot into the University square. There are stalls, some full of food and others with supplies. You see a flashy man dressed in a lab coat talking to a woman dressed in a patrol medic uniform, also patched with the number 4.)");
            chartext(tot);  textdisplayreg("Hey! Professor! I got one!");
            textdisplayreg("('Am I a fish?', you think to yourself.)");
            yellowtext("Medic: ");  textdisplayreg("Hmmm? What's this~  Oh, you found someone?");
            chartext(tot);  textdisplayreg("Yea. I was hoping we could add them to the team.");
            chartext(professor);  textdisplayreg("Tot. We can't just add anyone we want to the unit. They have to prove themselves. You. What's your name?");
            youtext2(); textdisplayreg("My name is " + player.name + ".");
            chartext(professor);  textdisplayreg("Huh? You actually have a name? How?");
            if (flag_jade) {
                chartext(tot);  textdisplayreg("I named them.");
                chartext(professor);  textdisplayreg("Again? Tot. I've already told you. Don't-");
                chartext(tot);  textdisplayreg("(Her face is suddenly serious.) I know. I'm not an idiot.");
            }
            else {
                youtext2(); textdisplayreg("I remembered my name.");
                chartext(professor);  textdisplayreg("(He's clearly surprised.) What? You remembered? Hmmmm.. interesting.");
            }
            chartext(professor);  textdisplayreg("Well whatever. I'll allow it. They can join you in your assignment tomorrow.");
            textdisplayreg("(The professor walks away.)");
            checkpoint = 3;
            break;

        case 3:yellowtext("Medic: ");  textdisplayreg("Good for you, Tot. And you, " + player.name + ".");
            chartext(tot);  textdisplayreg("Thanks, Aki.");
            yellowtext("Medic: ");  textdisplayreg("Come on, I already told you not to call me that. " + player.name + ", don't pay any attention to her. My name is Archaea. I was a microbiology student in my past life. I came up with the name myself!");
            chartext(tot);  textdisplayreg("That name isn't cute at all.");
            chartext(aki); textdisplayreg("I don't want to hear that from someone named Tot.");
            textdisplayreg("(Tot glares at her, unable to come up with a clever comeback.)");
            chartext(aki); textdisplayreg("Anyway, welcome to the team, " + player.name + ". We're Patrol Unit 4. It's a small unit, but we help out where we can.");
            chartext(aki);  textdisplayreg("It's getting late. We should head to the dorms for now. We'll gear you up tomorrow.");
            textdisplayreg("(You begin walking to the dorms with the 2 girls. They seem to get along well, which is impressive for people who only met a month ago. You feel a bit jealous.)");
            textdisplayreg("(You enter the dorm building. It's nicer than it looks on the outside. You climb some stairs and reach the second floor.)");
            chartext(aki); textdisplayreg("We're here. Our room is room 270.");
            youtext2(); textdisplayreg("Our? Are you two roommates?");
            chartext(aki); textdisplayreg("Yup. We're roommates.");
            chartext(tot);  textdisplayreg("Roommates!");
            textdisplayreg("(They are roommates.)");
            chartext(aki); textdisplayreg("(She opens the door.) Come on in. I think we have enough room for one more.");
            youtext2(); textdisplayreg("Thank you.");
            textdisplayreg("(The room is decently spacious. There are 2 beds in the room, a desk near the window, and a sleeping bag on the floor.)");
            chartext(aki); textdisplayreg("Alright. You can sleep on the bed with Tot.");
            chartext(tot);  textdisplayreg("Huh?");
            textdisplay("(Tot is making a face you can't quite make out. Is she excited or is she mad? You choose to....)"); textdisplayblue("1. Sleep on the bed | Sleep on the floor   ");
            choice3a = userinput();
            if (choice3a == "1") {
                youtext2(); textdisplayreg("Ok. I'll sleep on the bed.");
                chartext(tot);  textdisplayreg("!!!");
                chartext(aki); textdisplayreg("Good going, Tot. Someone's actually nice to you.");
                chartext(tot);  textdisplayreg("Uhhhh, thank you!!!???");
            }
            else {
                youtext2(); textdisplayreg("I think I'll just sleep on the floor, thank you.");
                textdisplayreg("(You feel Tot's glare from behind you. You refuse to look back.)");
            }
            chartext(aki); textdisplayreg("Anyway, let's go shower. These outfits really aren't very breathable. You're coming too, " + player.name + ". You look like you spawned 10 feet underground.");
            textdisplayreg("(You follow the girls to the dorm bathroom. The showers are individual. What were you expecting, hmmmm?)");
            flag_shower = true;
            textdisplayreg("(After finishing up, you meet up with the girls back at the dorm. As soon as you open the door, they start staring at you.)");
            chartext(aki); textdisplayreg("Wow, you're quite the cutie aren't you " + player.name + "? Right, Tot?");
            chartext(tot);  textdisplayreg("(Tot flinches.) Oh, umm yeah! You're really pretty, " + player.name + "!");
            textdisplayreg("(You are unsure how to respond. You're not used to recieving compliments. Or anything. You're a day old for all you know, after all.)");
            youtext2(); textdisplayreg("Ummm, thanks.");
            chartext(aki); textdisplayreg("Let's get some rest. I heard Professor's planning something big tomorrow.");

            if (choice3a == "1") {
                textdisplayreg("(You climb in bed with Tot.)");
                chartext(tot);  textdisplayreg("You're really sleeping here, huh...");
                youtext2(); textdisplayreg("Tot.");
                chartext(tot);  textdisplayreg("...yes?");
                youtext2(); textdisplayreg("Thanks for finding me.");
                chartext(tot);  textdisplayreg("...no problem.");
                textdisplayreg("(You drift off to sleep, thinking of the challenges tomorrow will bring.)");
            }
            else {
                textdisplayreg("(You climb into the sleeping bag on the floor.)");
                textdisplayreg("(You drift off to sleep, thinking of the challenges tomorrow will bring.)");
            }
            checkpoint = 4;
            break;

        case 4: textdisplayreg("(You wake up from the sound of someone talking in their sleep. Unexpectedly, it's Archaea.)");
            chartext(aki); textdisplayreg("........Tot..........Tater tot......... Totanic........");
            textdisplayreg("(Annoying.... You throw a shoe at her.)");
            chartext(aki); textdisplayreg("Gyah! ...what the hell?");
            chartext(aki); textdisplayreg("Tot! Wait no, " + player.name + "!? So that's how it is, huh. Think fast!");
            textdisplayreg("(She launches the shoe back at you, but you dodge it with your inhuman reflexes.)");
            chartext(aki); textdisplayreg("Tch.... asshole. What time is it anyway? (She checks her watch, which was left on the desk.)");
            chartext(aki); textdisplayreg("It's about time to leave. C'mon Tot, wake up.");
            textdisplayreg("(She rolls Tot into a burrito and rolls her on the floor. She rolls quite far.)");
            chartext(aki); textdisplayreg("A burrito is perfect for a potato like you. Wake up already.");
            textdisplayreg("(She gets irritated in the mornings, huh. Not that you're one to talk.)");
            chartext(tot);  textdisplayreg("...huh? Oh! (She rises incredibly fast!)");
            chartext(tot);  textdisplayreg("Good morning you two!");
            chartext(aki); textdisplayreg("We're leaving. Get ready, both of you.");
            yellowtext("Tot "); cout << "and "; youtext(player); textdisplayreg("Got it.");
            textdisplayreg("(You get ready and decide meet at the square. You are the first to arrive. You see the Professor approach you.)");
            chartext(professor); textdisplayreg(player.name + ". I want to talk to you about something.");
            youtext2(); textdisplayreg("What is it?");
            chartext(professor); textdisplayreg("I think you're perfect for my plan today. Someone new like you shouldn't have any attachement to the temporary government. The thing is, I want to overthrow the Chief.");
            youtext2(); textdisplayreg("And what do you want me to do?");
            chartext(professor); textdisplayreg("I want you to explore the library. There's something in there I want. I had forgotten about it, but I suddenly remembered when I saw you. There's an unused room in there full of maps. Check them for something useful. That's your assignment. Of course, Archaea and Tot will join you. I would do it myself, if I was capable of fighting those monsters");
            textdisplayreg("(You don't have the power nor care enough to refuse his offer.)");
            youtext2(); textdisplayreg("Ok. Got it.");
            chartext(professor); textdisplayreg("Good. Ah, here they come. I'll speak to you again in the evening. (He leaves as Archaea and Tot arrive.)");
            chartext(tot); textdisplayreg("You were talking with professor? About what?");
            youtext2(); textdisplayreg("Politics.");
            chartext(tot); textdisplayreg("Sounds boring. Let's go to the library!");
            textdisplayreg("(That's not a phrase you expected to come out of her mouth so easily.)");
            checkpoint = 5;
            break;

        case 5: lib: textdisplayreg("(You gear up and arrive at the library. It's a nice looking but abandoned building.)");
            chartext(aki); textdisplayreg("Let's go in. We'll follow behind you.");
            chartext(tot);  textdisplayreg("Also, watch out for mimics. Aki's a medic, but she can't heal those disgusting wounds.");
            chartext(aki); textdisplayreg("True. And shoot for the chest. That's where their brains are.");
            textdisplayreg("(You walk into the building. Immediately, you see a strange room. It must be the room Professor was talking about. You enter the room.)");
            chartext(tot); textdisplayreg("Is that a ... map? (She points at a piece of paper.)");
            textdisplayreg("(You grab the piece of paper she pointed at. It's a map.)");
            youtext2(); textdisplayreg("Train routes... and a password?");
            textdisplayreg("(On the map, an 'x' is marked, labeled 'TRAIN STATION'. There is also a password at the bottom. It reads: 'csci1370'.)");
            youtext2(); textdisplayreg("Welp, thats it. We got what we came for. Let's go back.");
            chartext(tot);  textdisplayreg("Wait really? That was so boring!");
            youtext2(); textdisplayreg("Boring is best after al-");
            textdisplayreg("(Before you can finish your sentence, a mimic attacks! You shoot it.....)"); textdisplayblue("1. In the head | 2. In the chest");
            choice4a = userinput();
            if (choice4a == "1") {
                textdisplayreg("(You shoot the mimic in the head. But it's unbothered! It leaps towards you and stabs you in the chest.)");
                chartext(tot);  textdisplayreg(player.name + "! No..... please.....");
                textdisplayreg("(You see Archaea kill the mimic and rush to your aid, but it's too late. You lose consciousness. Is this really how it ends?)");
                gameover();
                if (userinput() == "1") {
                    goto lib;
                }
                else goto title;
            }

            else {
                textdisplayreg("(You shoot the mimic in the chest twice. It dies instantly.)");
                chartext(tot);  textdisplayreg("Wow, impressive.");
                chartext(aki); textdisplayreg("Let's leave before more come.");
                chartext(tot);  textdisplayreg("Understood, chief.");
            }
            textdisplayreg("(You return to the square. The professor comes up and asks you to visit the capitol with your team to ask the chief a final time about leaving. You agree, and take off toward the capitol.)");
            checkpoint = 6;
            break;



        case 6: capitolbreak: textdisplayreg("(You arrive at the capitol, a fancy building close to the University. In front are armed guards, who let you in when you say you have a message for the professor.)");
            chartext(tot);  textdisplayreg("Even the inside is fancy.");
            textdisplayreg("You climb some stairs and reach the chief's office.");
            chartext(chief); textdisplayreg("Hmmm? What do you want?");
            youtext2(); textdisplayreg("We're here to discuss leaving the city.");
            chartext(chief); textdisplayreg("This again? I keep telling that professor that it's not gonna work.");
            chartext(secretary); textdisplayreg("Yea, you guys should really listen to her.");
            textdisplayreg("(Who?)");
            youtext2(); textdisplayreg("Well, we have real evidence this time.");
            chartext(chief); textdisplayreg("I don't care what evidence you have. It's simply not gonna work.");
            youtext2(); textdisplayreg("There's a train. If we take it, we can leave. We also have the password for it.");
            chartext(secretary); textdisplayreg("Lemme take a look at that.");
            textdisplayreg("(The secretary takes a long look at it before speaking.)");
            chartext(secretary); textdisplayreg("Haha. That's not the train password. That the password to the memory unlocker on Chief's computer, you idiots!..... oops.");
            chartext(chief); textdisplayreg("You dumbass!!!");
            textdisplayreg("(You and Archaea share a moment of complete understanding as you turn to look at each other. You......)"); textdisplayblue("1. Make a run for the computer  | 2. Don't do anything  ");
            choice5a = userinput();
            if (choice5a == "1") {
                textdisplay("(You both make a run for the computer. The secretary tries to stop you, but Archaea holds her back. The chief is too stunned to even try. The computer lights up. On it, a simple phrase: "); textdisplayblue("[ENTER PASSWORD]:");
                password2 = userinput();
                if (password2 == "csci1370") {
                    textdisplayreg("(Password Successful!)");
                    textdisplayreg("(For a moment, the world turns bright. You.... suddenly remember your past life. Or rather.... your lack of one.)");
                    textdisplayreg("(You look around the room. The atmosphere has gotten deathly cold. It seems everyone felt the same. You hear Tot say something.)");
                    chartext(tot);  textdisplayreg("We need to leave. The train. Now.");
                    chartext(aki); textdisplayreg("I agree. Let's get the hell out of here.");
                    textdisplayreg("(You run away without looking back. Just what did they remember?)");
                    textdisplayreg("(After running for what felt like forever, you arrive at the train station.)");
                    textdisplayreg("(You get in with Tot and Archaea. The train moves without a conductor, as if it was magic. Somehow, the sky seems to clear as well. Before you know it, the city behind you disappears.)");
                    chartext(tot);  textdisplayreg("We.... really left. Alive.");
                    chartext(aki); textdisplayreg("We really did.......");
                    know = true;
                    textdisplayreg("(You escaped.... alive. Whatever it was that they remembered, they probably won't tell you. But it doesn't matter. You survived.....right?)");
                    textdisplayreg("(You turn and look at the people who helped you escape. Tot..... you remember her. Not as a person, but an entity. A higher power? You're not sure. Not yet......)");
                    if (flag_jade) {
                        chartext(tot);  textdisplayreg("Hey, " + player.name + ".");
                        textdisplayreg("(She grabs your hand and leans closer to you.)");
                        chartext(tot);  textdisplayreg("You won't leave me too, will you?");
                        textdisplayreg("You don't know the answer to that question.");

                    }
                    textdisplayred("TOT: ESCAPE END | TRUE ENDING UNLOCKED"); //true ending unlocked
                    gameend();
                    if (userinput() == "1") {
                        goto capitolbreak;
                    }
                    else goto title;

                }

                else {
                    textdisplayreg("(You.... don't remember the password!?)");
                    chartext(chief); textdisplayreg("You idiots.");
                    textdisplayreg("(The Chief menacingly walks up to you casually stabbing you in the chest!)");
                    chartext(chief); textdisplayreg("You just don't do that here.");
                    textdisplayreg("(You fall to the floor. The secretary blows a raspberry at you as bleed out and die.)");
                    gameover();
                    if (userinput() == "1") {
                        goto capitolbreak;
                    }
                    else goto title;
                }
            }

            else {
                textdisplayreg("(You run, to the surprise of everyone in the room. Why? You don't know. Maybe it was just a bad feeling)");
                textdisplayreg("(As you run, you hear the rumbling sound of patrol units nearby. You don't care what they're doing. You just want to be happy. With Tot. And Aki. Unfortunately for you, your life is about to get a whole lot harder.)");
                textdisplayred("TOT: STAY END");
                gameend();
                if (userinput() == "1") {
                    goto capitolbreak;
                }
                else goto title;
            }


        case 7:chapter2b: youtext2(); textdisplayreg("I'll head for the highway to become a Guard."); //Chapter 2b: 
            textdisplayreg("(She gives you a disappointed look.)");
            yellowtext("Patroller: ");  textdisplayreg("Oh. Umm... are you sure? That's a dangerous path you're taking.");
            youtext2(); textdisplayreg("I'm sure.");
            yellowtext("Patroller: ");  textdisplayreg("Then you'll have to travel east. (She points in a direction you assume is east.) You'll see a campground on top of the highway. You can't miss it.");
            youtext2(); textdisplayreg("Got it. (You begin to walk east.)");
            yellowtext("Patroller: ");  textdisplayreg("Wait.");
            textdisplayreg("(She walks up to you and hands you a handgun.)");
            yellowtext("Patroller: ");  textdisplayreg("Take this. If you encounter one of those monsters, kill them with this. They are quick, if you hesitate for even a second you'll die. I'll ask you one more time. Are you sure you want to go?");
            youtext2(); textdisplayreg("Yes.");
            yellowtext("Patroller: ");  textdisplayreg("Then, be careful. And don't talk to anyone until you reach the highway.");
            youtext2(); textdisplayreg("(You giver her a nod and begin walking east.)");
            if (flag_jade) { // Special dialogue 2
                textdisplayreg("(You hear the patroller's voice from the distance. Her tone is unexpectedly sad.)");
                yellowtext("Patroller: ");  textdisplayreg("Please don't die...." + player.name + ".");
            }
            textdisplay("(After walking a while, you see someone standing in the middle of the road. You can't see them clearly, but they give you a strange feeling. Something about them seems... off.)"); textdisplayblue("1. Walk up to them | 2. Take a detour ");
            choice3a = userinput();
            if (choice3a == "1") { // Game over 1
                textdisplayreg("(You walk up to the strange-looking person. Upon closer inspection, you notice blood stains on their shirt.)");
                youtext2(); textdisplayreg("Hey, are you alright?");
                textdisplayreg("(No response. You take a closer look at their face. It's.... empty!!!)");
                textdisplayreg("(As soon as you realize it, the monster suddenly attacks you! It seems this is what the patroller was warning you about. You pull out your handgun and fire!)");
                textdisplayreg("(But it's too fast! It leaves your field of vision, and you suddenly feel a sharp burning pain in your back. The creature was wielding a knife.)");
                textdisplay("(You try to fight back, but it's useless. Your body weakens as slowly lose consciousness. Your blood covers your torso as you fall to the floor. Your final thoughts are of the patroller, who had warned you of the danger of your decision. You didn't even get her name....."); gameover();
                if (userinput() == "1") {
                    goto chapter2b;
                }
                else goto title;
            }
            else {
                textdisplayreg("(You trust your gut and ignore them. You take a detour and continue traveling east toward the highway.)");
                textdisplayreg("(Eventually, you reach the foot of the highway and see the highway camp in full view.");
                textdisplayreg("In the front of the camp are armored guards talking to a young man dressed in a military uniform with a sniper rifle hanging from his back. He and the guards all have large patches sewn with a strange insignia. You walk up to them. The man in the uniform notices you as you interrupt his conversation.");
                yellowtext("Man in Uniform: ");  textdisplayreg("Huh? Who are you?");
                textdisplayreg("(He walks up to you.)");
                yellowtext("Man in Uniform: ");  textdisplayreg("You're patchless. Did you just spawn?");
                youtext2(); textdisplayreg("Yes. I came here to train.");
                yellowtext("Man in Uniform: ");  textdisplayreg("Then I can assume you know what's going on. One of us, huh... (His lips curl into a smile.) Alright, you're in. We can always use some new recruits. (He begins walking up the stairs to the camp.)");
                yellowtext("Man in Uniform: ");  textdisplayreg("Just don't pussy out when you meet the mimics.");
                youtext2(); textdisplayreg("Mimics?");
                yellowtext("Man in Uniform: ");  textdisplayreg("The monsters that spawn beyond the highway that surrounds the inner city. I'm sure you've heard of them. They spawn in, just like us. They look like normal humans too, until you see their faces at least. They have no facial features at all. Their real heads are actually lower in their bodies.");
                textdisplayreg("(You pause upon hearing that information. You feel as though you dodged a bullet.)");
                yellowtext("Man in Uniform: ");  textdisplayreg("So, wanna shoot some stuff?");
                youtext2(); textdisplayreg("Sure, but weren't you busy?");
                yellowtext("Man in Uniform: ");  textdisplayreg("Not at all. One the guards was just bragging to me about his new girlfriend. Things have been real slow lately. The mimics spawn less and aren't as dangerous as they used to be. Mostly thanks to the Chief's leadership. Honestly, if it weren't for her, we'd all be dead right now.");
                textdisplayreg("(You both reach a makeshift firing range.)");
                yellowtext("Man in Uniform: ");  textdisplayreg("Anyway, my name is " + hunter.name + ". You have a name?");
                youtext2(); textdisplayreg("It's " + player.name + ".");
                textdisplayreg("(Hunter gives you a strange look.)");
                chartext(hunter);  textdisplayreg("That's... an unusual name. What kind of job is that?");
                if (flag_jade) { //Special dialogue 3
                    youtext2(); textdisplayreg("It's not a job. I couldn't remember my name or past job. A patrol member named me before I came here.");
                    chartext(hunter);  textdisplayreg("Ah, I heard there was someone like that in the patrol. They gave you a fitting name. Take this.");
                }
                else {
                    youtext2(); textdisplayreg("It's not a job. It's my real name. I remembered it when I woke up. Nothing else though.");
                    chartext(hunter);  textdisplayreg("That's incredible. Since you're so special, surely you can handle one of these.");
                }
                textdisplayreg("(Hunter hands you a hunting rifle.)");
                chartext(hunter);  textdisplayreg("Try shooting that target about 20 meters away.");
                textdisplayreg("(You grab the rifle, get in position, and fire at the target with a 20 labeled on it. Bullseye.)");
                chartext(hunter);  textdisplayreg("Nice job. Now shoot the other ones too.");
                textdisplayreg("(You repeatedly shoot all targets as far as 250 meters. You don't miss a single shot. Hunter is clearly impressed.)");
                chartext(hunter);  textdisplayreg("Wow! You know, I was actually thinking of putting you on cafeteria duty, but seeing that just changed my mind. You're going on lookout.");
                youtext2(); textdisplayreg("Lookout?");
                chartext(hunter);  textdisplayreg("You're gonna watch over the city stationed on a tall building, shooting those mimic bastards when you see them. You can even live on that building if you want. It's not a bad job. You're not afraid of heights are ya?");
                youtext2(); textdisplayreg("I don't think so.");
                chartext(hunter);  textdisplayreg("Perfect. Then for tonight, you can stay sleep in tent 2. In the morning, you'll get geared up and sent to your station. Don't disappoint me!");
                textdisplayreg("(He pats you on the back and takes off toward his tent. It's getting late. After walking around the campground for a few minutes, you decide to follow Hunter's instructions and sleep for the night.)");
                textdisplayreg("(You reach tent 2. You go inside and see a large, middle-aged man eating a granola bar.)");
                yellowtext("Large Man: ");  textdisplayreg("You the new recruit?");
                youtext2(); textdisplayreg("Yea. My name's " + player.name + ".");
                yellowtext("Large Man: ");  textdisplayreg(player.name + "? Well, I won't pry. My name is Riot. I'm Captain Hunter's second in command. I was a cop or something in my past life. I'll be escorting you to your station along with Hunter. Mimics like to hide in buildings sometimes.");
                youtext2(); textdisplayreg("Thanks, but why is Hunter coming?");
                chartext(riot);  textdisplayreg("Boredom, I'd assume. You can't leave the city because of those mimics, but lately they've rarely come inside. Most of our issues now are with food supplies, which Hunter has no control over. In fact, none of us do.");
                youtext2(); textdisplayreg("Food supplies? Wait, if you can't leave the city, how can you get food? All the stores on the way here were empty!");
                chartext(riot);  textdisplayreg("They get dropped to us from the sky in the middle of the night. No one knows who does it, or where the stuff comes from. The problem recently, is that while the population grows, our supplies stay consistant. There's already been fights breaking out at the University over who gets what. Basically, if we can't find a way to leave the city, we're screwed.");
                textdisplayreg("(Supplies falling from the sky.... It sounds ridiculous, but you have no reason to believe otherwise from what you've seen.)");
                chartext(riot);  textdisplayreg("If you ask me, I think this is a game. We're probably being watched by some sick bastard who enjoys suffering. Either that, or we're in hell. And right now's the best it's gonna get.");
                textdisplayreg("(Riot starts getting ready to sleep. You think about his words as you tuck yourself into your sleeping bag.)");
                chartext(riot);  textdisplayreg("Get some good rest. We're waking up early tomorrow. (He turns the lights off.)");
                textdisplayreg("(You close your eyes, and think about your day. You drift to sleep, wondering what challenges tomorrow will bring.)\n ***************************************************************************************************************");
                checkpoint = 8;
                break;
            }
        case 8: textdisplayreg("(You awaken, surrounded by.... familiar scenery. And the extremely loud sound of Riot's alarm. You hear loud groans coming from Riots sleeping bag before he finally wakes up.)");
            chartext(riot);  textdisplayreg("Alright. Let's do this. (He says while half asleep.)");
            textdisplayreg("(You both get up and leave the tent. You hear the faint sounds of gunshots in the distance as you walk to Hunter's tent. You see Hunter, already awake.)");
            chartext(hunter);  textdisplayreg("Finally awake, huh? We're leaving in an hour. Go freshen up in the barracks. (He hands you some clothes.)");
            youtext2(); textdisplayreg("Where's that?");
            textdisplayreg("(Hunter points at a hotel building near the side of the highway. A bridge leading to one of the top floor windows has been made, converting it into a door.)");
            youtext2(); textdisplayreg("A hotel, huh. Nice. Wait, why didn't we just sleep in there!?");
            chartext(hunter);  textdisplayreg("Hey, sleeping in a tent builds character. Also, we killed some mimics in there. Their bodies rot and smell horrible if we don't dispose of them properly. You can guess what happened in there. Luckily, the water and power still work. Now hurry up.");
            textdisplayreg("(You walk across the bridge into the hotel. He was right. The stench was terrible. You hold your nose and run to the shower room. The shower room? Do hotels have shower rooms? You choose not to think about it.");
            textdisplayreg("(The shower room was just that. You see half-naked men walking around, getting ready for their day. Because this is the only room with running water, the women and men have seperate shower times. Now was the men's time.)");
            if (flag_shower) {
                textdisplayreg("(Of course, these showers are not individual. You feel conflicted.)");
            }
            textdisplayreg("(You begin to take off whatever it was you were wearing before noticing people's eyes on you.)");
            chartext(riot);  textdisplayreg("Hey, kid. I don't know what your deal is, but you sure you're fine showing that to everyone?");
            textdisplayreg("(You give him a confused look.)");
            chartext(riot);  textdisplayreg("You really don't know do you. Look in the mirror.");
            textdisplayreg("(You look at yourself in the mirror. For the first time, you see what you look like. Your shoulder-length green hair is messy and your face is covered in dirt. You are also quite short compared to everyone else. But you notice what Riot was talking about. In the middle of your torso is a large scar that wraps around your entire chest.)");
            chartext(riot);  textdisplay("You alright?"); textdisplayblue("1. I may be dying | 2. I'm fine ");
            choice4b = userinput();
            if (choice4b == "1") {
                youtext2(); textdisplayreg("I may be dying.");
                chartext(riot);  textdisplayreg("If you can joke around like that, you're fine. Now clean yourself up.");
            }
            else {
                youtext2(); textdisplayreg("Yea. It doesn't hurt at all.");
                chartext(riot);  textdisplayreg("That's good to hear. Can't have you slacking on the job, even if it's painful.");
            }
            textdisplayreg("(You finish washing up and start walking to the campground with Riot.)");
            chartext(riot);  textdisplayreg("You know, you look like a completely different person cleaned up like that. Can you even pick up a gun with those arms?");
            youtext2(); textdisplayreg("I can use a gun just fine, thank you.");
            textdisplayreg("(Hunter walks up to you and stares at you for a few seconds before speaking.)");
            chartext(hunter);  textdisplayreg("Huh. Can't judge a book by it's cover I guess. Alright, lets get moving.");
            textdisplayreg("(You grab your gear and start walking following Hunter, who's leading you to your station. After about 5 minutes of walking, you reach the place.  It's a tall building.)");
            chartext(hunter);  textdisplayreg("Ok. Go in, we'll follow you.");
            youtext2(); textdisplayreg("But I've never been in this building.");
            chartext(hunter);  textdisplayreg("Me neither.");
            youtext2(); textdisplayreg("Then why choose it? (You give him a piercing stare.)");
            chartext(hunter);  textdisplayreg("Cuz it's tall. Come on, you can handle it.");
            checkpoint = 9;
            break;

            //Lookout Building chapter
        case 9: Lookout: youtext2(); textdisplay("You walk inside the building. A large lobby greets you. There's an elevator that obviously doesn't work. There are stairs, and a strange room near the back."); textdisplayred("You choose the.... 1. The strange room | 2. The stairs ");
            choice5b = userinput();
            if (choice5b == "1") {
                textdisplay("You start walking toward the room, with Riot and Hunter following closely behind. You open the door, to see a office room. It has a desk in the middle. It seems this building was an office building.");
                chartext(riot);  textdisplayreg("What's that on the desk? (He points at a piece of paper on the desk.)");
                textdisplayreg("(You grab the paper and take a look at it.)");
                youtext2(); textdisplayreg("It's a map of the city! It's marked too....");
                textdisplay("On the map is are two x's labled 'AIRFIELD' and 'DETONATOR'. The 'x' labed AIRFIELD is north of the University. The other x is on the highway, near the camp.");
                chartext(hunter);  textdisplayreg("Detonator..... that 'x' is distubingly close to our camp.");
                chartext(riot);  textdisplayreg("Airfield... you think there's planes in there? That could be our way out.");
                chartext(hunter);  textdisplayreg("I'll send some guys to take a look at it later. As for the detonator, we'll check it out when we leave. Let's continue.");
                textdisplayreg("(You return to the lobby and take the stairs.)");
                flag_airfield = true;
            }
            else {
                textdisplayreg("You ignore the room and take the stairs.");
            }
            textdisplayreg("Along the staircase are a few doors, all of them locked until you reach to top floor.");
            textdisplayreg("The top floor is a spacious office. It was probably the workplace of a very wealthy person.");
            chartext(hunter);  textdisplayreg("This is it. You're gonna stay here for lookout. (He hands you a bag full of rations, ammo, and other supplies.)");
            if (choice5b == "1") { chartext(hunter);  textdisplayreg("Well, at least we found something useful. I'll go inform my men. See you later.(He begins walking back with Riot, when a noise is suddenly heard.)"); }
            else { chartext(hunter);  textdisplayreg("Well, thats it. Can't say there was anything interesting in this place. See you later, " + player.name + ". (He begins walking back with Riot, when suddenly, a noise is heard.)"); }
            chartext(hunter);  textdisplayreg("Crap. That's a mimic screech. Everyone, get ready to fight!");
            textdisplayreg("(You grab your weapons as three mimics appear from the staircase. Each of them attacks a different person. You see a mimic run up to you.)");
            textdisplayblue("You pull the trigger and fire at the mimic's.... 1. Chest | 2. Head ");
            choice6b = userinput();
            if (choice6b == "1") {
                textdisplayreg("(You remember what Hunter told you. You shoot at the mimics chest. The monster wriggles in pain, and you shoot it once more to end it. Hunter and Riot had killed theirs as well.)");
                chartext(hunter);  textdisplayreg("Man, these things are a huge pain in the ass. Still, good going, " + player.name + ". Looks like I can trust you to keep lookout. Anyway, well see you later! (He and Riot wave and walk out of the room with bloody clothes.)");
                textdisplayreg("(You are now alone. You look out the open window. You notice the city is surrounded by a thick fog. Under normal circumstances, this view would be incredible. At least you think it would be. Not like you remember anything.)");
                textdisplayreg("(About an hour passes. Suddenly, you hear the sound of someone talking. It's coming out of your bag!)");
                chartext(hunter);  textdisplayreg("Yo " + player.name + "! can you hear me?");
                textdisplayreg("(You rummage through your bag and find a walkie-talkie.)");
                youtext2(); textdisplayreg("Yea, loud and clear.");
                if (flag_airfield) {
                    chartext(hunter);  textdisplayreg("Good news! We found the airfield. And there's planes in it with fuel! One of our mechanics is currently flying one and confirming it works. If things go smoothly, we could even explore outside the city!");
                    youtext2(); textdisplayreg("That's amazing.");
                    chartext(hunter);  textdisplayreg("We also explored the area marked 'Detonator'. We found a bunch of strange boxes under the highway that I could've sworn weren't there before. There was also a button that I assume blows everything up. No idea what good blowing up our base would do, but I don't feel like finding out.");
                    chartext(hunter);  textdisplayreg("Also, one more thing. You're done for the day.");
                }
                else {
                    chartext(hunter);  textdisplayreg("Good news! We found an airfield. And there's planes in it with fuel! One of our mechanics is currently flying one and confirming it works. If things go smoothly, we could even explore outside the city!");
                    youtext2(); textdisplayreg("That's amazing."); chartext(hunter);
                    textdisplayreg("Also, one more thing. You're done for the day.");
                }
                youtext2(); textdisplayreg("What? It's barely noon.");
                chartext(hunter);  textdisplayreg("Apparently there's trouble at the university. Someone's started a riot. Most of my men are busy playing around at the airfield, those useless kids. Go check it out and report back in the evening.");
                youtext2(); textdisplayreg("Got it.");
                textdisplayreg("(Hunter hangs up. You pack your things and leave the building. You find a bike leaning on the side of a building. From reading the map, you remember where the University is. You take the bike and ride it.)");
                checkpoint = 10;
                goto universityhunter;
            }
            else {
                textdisplayreg("You shoot at the mimic's head. You hear Riot yell at you.");
                chartext(riot);  textdisplayreg(player.name + "! You idiot!");
                textdisplayreg("Riot rushes to help you, but it's too late. The mimic had already stabbed your chest. Shooting it in the head did nothing. It's bloody 'face' didn't bother it at all. You fall to the ground. 'Is this really the end?' you think, as you bleed to death.");
                gameover(); // game over 2b
                if (userinput() == "1") {
                    goto Lookout;
                }
                else goto title;
            }
        case 10: universityhunter:textdisplayreg("(You reach the University. It's a large area, almost like it could be it's own town. From the distance you hear gunshots, along with screams. You hurry to the main square.)");
            textdisplayreg("(Once there, you see what's happening. A patrol member is point his gun at people and yelling.)");
            yellowtext("Patrol member: "); textdisplayreg("YEEEEAAAA!!!! WE'RE TAKING THIS BITCH OVEEERRRRR!!!!!");
            textdisplayreg("(?????????????)");
            youtext2(); textdisplayreg("What the hell's going on here?");
            yellowtext("Patrol member: "); textdisplayreg("Huh? Oh, a highway guard. (He scoffs at you.) You guys wouldn't get it. That Chief bitch treats you like her babies. She doesn't give a crap about any of us in the Patrol. We're starving, and we've had enough. Tonight, we're raiding the capitol.");
            yellowtext("???: "); textdisplayreg("Hold it.");
            textdisplayreg("(You turn around and see a man dressed in a lab coat.)");
            yellowtext("Patrol member: "); textdisplayreg("Professor?");
            chartext(professor); textdisplayreg("Why are you telling this to a Guard, you moron?");
            yellowtext("Patrol member: "); textdisplayreg("Oh crap, sorry!?");
            chartext(professor); textdisplayreg("Whatever. This one doesn't look like it'd do much anyway.");
            textdisplayreg("(This guy is starting to piss you off.)");
            chartext(professor); textdisplayreg("Come on. We're going now.");
            yellowtext("Patrol member: "); textdisplayreg("YESSSSSSSSSSSSSSSSS SIRR!!!");
            if (know) {
                textdisplayreg("(The Professor..... so this is how it turns out if you don't intervene.)");
            }
            checkpoint = 11;
            break;


        case 11: capitolhunter:
            textdisplayreg("(You decide to follow them to the capitol. It's a large, fancy building. You remember passing it on your way to the highway.)");
            textdisplayreg("(Once there, you notice a huge crowd has gathered. It seems the people share a common sense of rebellion.)");
            chartext(professor); textdisplayreg("Open fire.");
            yellowtext("Capitol guard: "); textdisplayreg("Hey, what the hell are you- Ugh!-");
            textdisplayreg("(The patrol members all fire, killing the guards. They're serious...)");
            textdisplayreg("(After all the guards are wiped out they storm the building.)");
            textdisplayreg("(You decide to follow them for some reason.)");
            textdisplayreg("(Inside the building, you hear a distressed female voice.)");
            chartext(chief); textdisplayreg("What!? You idiots! I told you, there's no way out of the city!");
            chartext(professor); textdisplayreg("You're hiding something, I know it. I heard you talking about a password. Spit it out. (He points a gun at her.)");
            chartext(secretary); textdisplayreg("Chief!!!");
            chartext(chief); textdisplayreg("Goddamn it... fine. There's a password that if entered into that computer, will unlock everyone's memories.");
            chartext(professor); textdisplayreg("Memories? That's it?");
            chartext(chief); textdisplayreg("That's it I swear!");
            chartext(professor); textdisplayreg("Alright, whats the password?");
            chartext(chief); textdisplayreg("I..... don't know.");
            chartext(professor); textdisplayreg("HUH? It's your computer isn't it? (He puts his finger on the trigger.)");
            chartext(chief); textdisplayreg("Please, don't. I really don't know the password.");
            chartext(professor); textdisplayreg("Then, does anybody here know it? Speak up or Chief dies.");
            chartext(secretary); textdisplayreg("Mmph!");
            chartext(professor); textdisplayreg("(He grabs the secretary.) This one too.");
            textdisplayreg("(The password..... you think about it for a second. The password is.....)"); bluetext("[ENTER PASSWORD]: ");
            getline(cin, password);
            if (password == "csci1370" && know) {
                textdisplay("(Thats it! You remember the password.)");
                youtext2(); textdisplayreg("csci1370");
                chartext(professor); textdisplayreg("What?");
                youtext2(); textdisplayreg("The password. Get on it.");
                textdisplayreg("(The professor quickly types the password in. It works. For a moment, the world turns bright. Everyone.... suddenly remembers their past lives.)");
                textdisplayreg("(You look around the room. The atmosphere has gotten deathly cold. It's a familiar feeling.)");
                chartext(professor); textdisplayreg("Holy crap.... my... my kids....we ...we need to leave!");
                textdisplayreg("(Everyone has the same thought, except for the Chief.)");
                chartext(chief); textdisplayreg("Not so fast. (She prepares to lunge at you and the professor, but you are quicker.)");
                textdisplayreg("(You know exactly what she is. You point your gun straight at her chest. After all, you're the same.)");
                chartext(secretary); textdisplayreg("Wait! Don't hurt her!");
                textdisplayreg("(Before you can shoot, the secretary rushes to protect the Chief.)");
                chartext(chief); textdisplayreg("You.....");
                chartext(secretary); textdisplayreg("Please! Shoot me if you want, but not her!");
                youtext2(); textdisplayreg("Whatever. We need to leave. Hunter!!! (You call him on your radio.)");
                chartext(hunter); textdisplayreg("You want me to blow the highway up, right? I'm 2 steps ahead of you.");
                textdisplayreg("(You hear a giant boom.)");
                youtext2(); textdisplayreg("The train... We need the train!");
                chartext(tot); textdisplayreg("Already got it.");
                youtext2(); textdisplayreg("Huh! Tot?");

                chartext(tot); textdisplayreg("Yo. What's up, " + player.name + "?");
                if (player.name != firstname) {
                    chartext(tot); textdisplayreg("Or should I call you " + firstname + "?");
                }
                chartext(tot); textdisplayreg("The train's already moving. Hurry! Everyone!");
                textdisplayreg("(Everyone rushed to the train. Including the Chief and her secretary. For a moment, everyone forgot about killing eachother. The sky was bright, as if 16 hours had passed in a flash.)");
                textdisplayreg("(You arrive at the train station and enter, along with nearly everyone in the city. Others boarded the planes in the airfield. You take a seat with Tot and Aki.)");
                chartext(tot); textdisplayreg("We made it.");
                chartext(aki); textdisplayreg("We really did it.");
                chartext(tot); textdisplayreg(player.name + ", thank you... for sticking with me that one time.");
                youtext2(); textdisplayreg("You remember that!?");
                chartext(tot); textdisplayreg("Yup. alot more, too.");
                textdisplayreg("(She holds both you and Aki's hands and turns towards you.)");
                chartext(tot); textdisplayreg("Congratulations. For surviving. My warrior.");
                textdisplayreg("(An entity..... You realize what you were feeling and respond the only way you know how. The way you were programmed to.)");
                youtext2(); textdisplayreg("No problem.");
                youtext2(); textdisplayreg("Master.");
                textdisplay("TRUE END | COMPLETE");
                gameend();
                if (userinput() == "1") {
                    goto capitolhunter;
                }
                else goto title;
                
            }
            else {
                textdisplayreg("(It's no use. You don't know the password.)");
                chartext(professor); textdisplayreg("Well, that's about what I expected.");
                textdisplayreg("(You hear two loud bangs. One of them killing the chief, and the other killing the secretary.)");
                chartext(professor); textdisplayreg("Well boys, we did it.");
                textdisplayreg("(You hear the loud cheering of the patrol members.)");
                chartext(professor); textdisplayreg("Finally, we are free from the tyranny of the old chief! From now on, I'll be in charge, along with my cabinet. I'll rule for the people, and find a way out of this hell!");
                textdisplayreg("(The cheering grows louder. You decide to leave, and notify Hunter.)");
                chartext(hunter); textdisplayreg("They killed the Chief!? Jesus, I didn't think that professor was that crazy. But as shitty as that is, I have more bad news to tell you. Mimics can fly. And take down planes. We can't leave the city. Just one thing after another, isn't it?");
                youtext2(); textdisplayreg("What!?");
                textdisplayreg("(Your mind races for anything you can do to improve the situation.)");
                if (flag_airfield) {
                    textdisplayreg("(Then, an idea comes to mind.)");
                    youtext2(); textdisplayreg("I got it.");
                    chartext(hunter); textdisplayreg("Got what?");
                    youtext2(); textdisplayreg("Blow up the campground.");
                    chartext(hunter); textdisplayreg("What!? Are you insane?");
                    youtext2(); textdisplayreg("It'll work, trust me. It's the only thing that will stop the mimics.");
                    textdisplayreg("(You weren't completely sure how that made sense, but then again, nothing here does. From everything you've experienced thus far, this was the only logical conclusion you could come to.)");
                    chartext(hunter); textdisplayreg("Hmmm.... well screw it. They'll probably destroy it anyway. I trust you. I'll do it.");
                    youtext2(); textdisplayreg("Thank you. After that, lets leave by plane.");
                    chartext(hunter); textdisplayreg("Sure, if it works. See ya.");
                    textdisplayreg("(Hunter hangs up. You wait a few minutes roaming the streets, the sounds of cheering and gunshots in the distance. Eventually, you hear a familiar voice in the distance.)");
                    yellowtext("Patroller: "); textdisplayreg(player.name + "?");
                    textdisplayreg("(You turn around and see the patroller you met when you woke up.)");
                    yellowtext("Patroller: "); textdisplayreg(player.name + ", you're okay... thank god....");
                    textdisplayreg("(You hear a loud explosion, and for a second the evening sky lights up as if it was sunny the whole time. All the fog surrounding the city is completely gone.)");
                    chartext(hunter); textdisplayreg("Woooo! Now that's an explosion.");
                    yellowtext("Patroller: "); textdisplayreg("The highway! You... why?");
                    youtext2(); textdisplayreg("Sorry, but I'm leaving here alive. See you someday.");
                    flag_airfield_complete = true;
                    textdisplayreg("(You ride your bike towards the airfield. From the corner of your eye, you see the patroller dumbfounded. But you have no time to waste.)");
                    textdisplayreg("(You reach the airfield and see Hunter and Riot standing near a helicopter. They're geared up and ready to go.)");
                    chartext(hunter); textdisplayreg("You ready to go?");
                    youtext2(); textdisplayreg("More than I'll ever be.");
                    chartext(hunter); textdisplayreg("Then, lets get moving.");
                    textdisplayreg("(Your board the heli. The blades of the chopper spin, and before you know it, you're 400 meters above ground. The city looks truly beautiful as you fly into a uncertain future. Was this the right decision? Could things have turned out differently? It didn't matter. You're alive.)");
                    textdisplayred("HUNTER: ESCAPE END"); //Ending 3: Hunter escape end
                    gameend();
                    if (userinput() == "1") {
                        goto capitolhunter;
                    }
                    else goto title;
                }
                else {
                    textdisplayreg("(But you think of nothing.)");
                    chartext(hunter); textdisplayreg("I'm staying. I'll try to convince Professor to let me live. I'm an asset aren't I? Haha.");
                    textdisplayreg("(You think it's amazing how Hunter can laugh at a time like this.)");
                    youtext2(); textdisplayreg("I'll back you up.");
                    chartext(hunter); textdisplayreg("Thanks, " + player.name + ".");
                    youtext2(); textdisplayreg("Still. Thank you Hunter. You're amazing.");
                    chartext(hunter); textdisplayreg("Huh? Ummm.. yeah I guess, haha. (Awkward silence.) Anyway, I'll see you later.");
                    textdisplayreg("(You walk back to the capitol and meet Hunter. Somehow you two manage to stay alive, despite Hunter's reputation for being a suck-up to the Chief. You stay in the city, battling the mimics and starvation with Hunter and his squad, who were made into Patrol members after the Highway Guards were dissolved. Your earn a reputation as a marksman and quickly climb the ranks of the patrol. This is your life now. Could it have been better? You don't know. But you're alive.)");
                    textdisplayred("HUNTER: STAY END"); //Ending 4: Hunter stay end
                    gameend();
                    if (userinput() == "1") {
                        goto capitolhunter;
                    }

                    else goto title;
                }
            }
        }
    
   }
        return 0;
}