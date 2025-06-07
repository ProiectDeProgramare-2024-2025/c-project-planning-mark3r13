#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

#define questions_nr 15
#define answers_nr 4
#define name_length 50

// Colors

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// typedef struct {
//     char question[256];
//     char answers[answers_nr][100];
//     int correct_index;
// } Question;

class Question {
    public:
        char question[256];
        char answers[answers_nr][100];
        int correct_index;
};

// typedef struct {
//     char name[name_length];
//     float score;
// } Player;

class Player {
    public:
        char name[name_length];
        float score;
};

ofstream score("scores.txt", ios::app);

void loadQuestions(Question questions[]) {
    // Set 1
    strcpy(questions[0].question, "Which of these names is not in the title of a Shakespeare play?");
    strcpy(questions[0].answers[0], "Hamlet");
    strcpy(questions[0].answers[1], "Romeo");
    strcpy(questions[0].answers[2], "Macbeth");
    strcpy(questions[0].answers[3], "Darren");  // Correct
    questions[0].correct_index = 3;

    // Set 2
    strcpy(questions[1].question, "In the United States, what is traditionally the proper way to address a judge?");
    strcpy(questions[1].answers[0], "Sir");
    strcpy(questions[1].answers[1], "Your Honor");  // Correct
    strcpy(questions[1].answers[2], "Your Eminence");
    strcpy(questions[1].answers[3], "You da man!");
    questions[1].correct_index = 1;

    // Set 3
    strcpy(questions[2].question, "Which of these pairs of apps offers roughly the same type of service?");
    strcpy(questions[2].answers[0], "Snapchat and Instagram");
    strcpy(questions[2].answers[1], "Whatsapp and ShareIt");
    strcpy(questions[2].answers[2], "Tiktok and Spotify");
    strcpy(questions[2].answers[3], "lyft and Uber");// Correct
    questions[2].correct_index = 3;

    // Set 4
    strcpy(questions[3].question, "What is the chemical symbol for gold?");
    strcpy(questions[3].answers[0], "Au");  // Correct
    strcpy(questions[3].answers[1], "Ag");
    strcpy(questions[3].answers[2], "Pb");
    strcpy(questions[3].answers[3], "Fe");
    questions[3].correct_index = 0;

    // Set 5
    strcpy(questions[4].question, "Which character is from the anime 'Naruto'?");
    strcpy(questions[4].answers[0], "Konohamaru");// Correct
    strcpy(questions[4].answers[1], "Zoro");
    strcpy(questions[4].answers[2], "Vegeta");
    strcpy(questions[4].answers[3], "Ash");
    questions[4].correct_index = 0;

    // Set 6
    strcpy(questions[5].question, "What is the capital of Moldova");
    strcpy(questions[5].answers[0], "Zalau");
    strcpy(questions[5].answers[1], "Teleorman");
    strcpy(questions[5].answers[2], "Chisinau");  // Correct
    strcpy(questions[5].answers[3], "Galati");
    questions[5].correct_index = 2;

    // Set 7
    strcpy(questions[6].question, "How many continents are there on Earth?");
    strcpy(questions[6].answers[0], "5");
    strcpy(questions[6].answers[1], "6");
    strcpy(questions[6].answers[2], "7");  // Correct
    strcpy(questions[6].answers[3], "8");
    questions[6].correct_index = 2;

    // Set 8
    strcpy(questions[7].question, "Which of the following cities is GTA 5 based on?");
    strcpy(questions[7].answers[0], "Liberty City");
    strcpy(questions[7].answers[1], "Vice City");
    strcpy(questions[7].answers[2], "Los Angeles"); // Correct
    strcpy(questions[7].answers[3], "Los Santos");
    questions[7].correct_index = 2;

    // Set 9
    strcpy(questions[8].question, "Who painted the Mona Lisa?");
    strcpy(questions[8].answers[0], "Vincent van Gogh");
    strcpy(questions[8].answers[1], "Pablo Picasso");
    strcpy(questions[8].answers[2], "Leonardo da Vinci");  // Correct
    strcpy(questions[8].answers[3], "Michelangelo");
    questions[8].correct_index = 2;

    // Set 10
    strcpy(questions[9].question, "Which is the largest ocean on Earth?");
    strcpy(questions[9].answers[0], "Atlantic Ocean");
    strcpy(questions[9].answers[1], "Indian Ocean");
    strcpy(questions[9].answers[2], "Pacific Ocean");  // Correct
    strcpy(questions[9].answers[3], "Arctic Ocean");
    questions[9].correct_index = 2;

    // Set 11
    strcpy(questions[10].question, "Who plays the role of Iron Man in the Marvel Cinematic Universe?");
    strcpy(questions[10].answers[0], "Robert Downey Jr.");// Correct
    strcpy(questions[10].answers[1], "Chris Hemsworth");
    strcpy(questions[10].answers[2], "Tom Holland");
    strcpy(questions[10].answers[3], "Ryan Renolds");
    questions[10].correct_index = 0;

    // Set 12
    strcpy(questions[11].question, "Which gas do plants primarily use for photosynthesis?");
    strcpy(questions[11].answers[0], "Oxygen");
    strcpy(questions[11].answers[1], "Carbon dioxide");  // Correct
    strcpy(questions[11].answers[2], "Nitrogen");
    strcpy(questions[11].answers[3], "Hydrogen");
    questions[11].correct_index = 1;

    // Set 13
    strcpy(questions[12].question, "Who wrote the 'One piece' manga series?");
    strcpy(questions[12].answers[0], "Masashi Kishimoto");
    strcpy(questions[12].answers[1], "Eiichiro Oda");  // Correct
    strcpy(questions[12].answers[2], "Akira Toriyama");
    strcpy(questions[12].answers[3], "Hirohiko Araki");
    questions[12].correct_index = 1;

    // Set 14
    strcpy(questions[13].question, "What is the fastest land animal?");
    strcpy(questions[13].answers[0], "Cheetah");  // Correct
    strcpy(questions[13].answers[1], "Lion");
    strcpy(questions[13].answers[2], "Horse");
    strcpy(questions[13].answers[3], "Greyhound");
    questions[13].correct_index = 0;

    // Set 15
    strcpy(questions[14].question, "How many sides does a hexagon have?");
    strcpy(questions[14].answers[0], "5");
    strcpy(questions[14].answers[1], "6");  // Correct
    strcpy(questions[14].answers[2], "7");
    strcpy(questions[14].answers[3], "8");
    questions[14].correct_index = 1;
}

void clearScreen() {
    system("cls");
}

int nameCheck(char name[]) {
    if(strlen(name) > 50)
        return -1;
    
    const char* lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i = 0; i < strlen(name); i++)
        if(!(strchr(lowercase, name[i]) || strchr(uppercase, name[i])))
            return -2;

    return 0;
}

int ynCheck(char c) {
    if(!(c == 'n' || c == 'y'))
        return -3;
    return 0;
}

void startGame(Question questions[]) {
    Player player;
    cout << YELLOW << "  |" << RESET << "      Enter your name: ";
    
    // Error handling
    try {
        char tempName[100];

        cin.getline(tempName, sizeof(tempName));
        
        int nameCh3ck = nameCheck(tempName);
        if(nameCh3ck < 0) // Error -1 and -2
            throw nameCh3ck;
        else {
        
        strcpy(player.name,tempName);
        player.score = 0;

        int i,j;
        for ( i = 0; i < 15; i++) {
            clearScreen();
            cout << endl;
            cout << YELLOW << "   ____________________________________________________________________\n";
            cout << YELLOW << "  |" << RESET << "                                 \n";
            cout << YELLOW << "  |" << RESET << "      " << BLUE << "Question " << i + 1 << ": " << questions[i].question << "   \n";
            cout << YELLOW << "  |" << RESET << "                                                   \n";

            for ( j = 0; j < answers_nr; j++) {
                cout << YELLOW << "  |" << RESET << "         " << j + 1 << ". " << questions[i].answers[j] << "                                  \n";
            }

            cout << YELLOW << "  |" << RESET << "                                \n";
            cout << YELLOW << "  |" << BLUE << "      Use '50/50'?" << RED << " (y/n): ";

            char use5050 = getchar(); // Error -3
            if(ynCheck(use5050) == -3) {
                i = questions_nr + 1;
                throw -3;
            }

            getchar();
            cout << YELLOW << "  |________________________________\n" << RESET;
            clearScreen();
            cout << "\n";
            cout << YELLOW << "   _____________________________________________________________\n" << RESET;
            cout << YELLOW << "  |" << RESET << "                                 \n";
            cout << YELLOW << "  |" << RESET << "      Question " << YELLOW << i + 1 << RESET << ": " << BLUE << questions[i].question << RESET << "   \n";
            cout << YELLOW << "  |" << RESET << "                                 \n";

            int visibleOptions[answers_nr];
            int visibleCount = answers_nr;

            for ( j = 0; j < answers_nr; j++) {
                visibleOptions[j] = j;
            }

            if (use5050 == 'y' || use5050 == 'Y') {
                int removedCount = 0;
                for ( j = 0; j < answers_nr; j++) {
                    if (j != questions[i].correct_index && removedCount < 2) {
                        visibleOptions[j] = -1;
                        removedCount++;
                        visibleCount--;
                    }
                }
                player.score +=0.5;
            }

            int optionIndex = 0;
            for ( j = 0; j < answers_nr; j++) {
                if (visibleOptions[j] != -1) {
                    cout << "  |         " << optionIndex + 1 << ". " << questions[i].answers[j] << "                                  \n";
                    optionIndex++;
                }
            }

            cout << YELLOW << "  |" << RESET << "                                 \n";
            cout << YELLOW << "  |" << RESET << "       Select your answer (1-" << YELLOW << visibleCount << RESET << "): ";

            int answer;
            cin >> answer;

            if (answer > visibleCount) {
                i = questions_nr + 1;
                throw -4;
            }

            getchar();

            int selectedIndex = -1;
            optionIndex = 0;
            for ( j = 0; j < answers_nr; j++) {
                if (visibleOptions[j] != -1) {
                    if (optionIndex + 1 == answer) {
                        selectedIndex = j;
                        break;
                    }
                    optionIndex++;
                }
            }

            if (selectedIndex == questions[i].correct_index) {
                cout << YELLOW << "  |" << RESET << "                                 \n";
                cout << YELLOW << "  |" << GREEN << "             Correct!\n" << RESET;
                cout << YELLOW << "  |_____________________________________________________________\n" << RESET;
                player.score += 1;
            } else {
                cout << YELLOW << "  |" << RESET << "                                 \n";
                cout << YELLOW << "  |" << RED << "      Wrong! The correct answer was: " << questions[i].answers[questions[i].correct_index] << RESET << endl;
                cout << YELLOW << "  |_____________________________________________________________\n" << RESET;
            }
            Sleep(1000);
        }
        cout << YELLOW << "  |" << RESET << "                                 \n";
        cout << YELLOW << "  |" << RESET << "        Game Over! Your final score: " << GREEN << fixed << setprecision(2) << player.score << RESET << endl;
        cout << YELLOW << "  |_____________________________________________________________\n" << RESET;

        score << "# ";
        score << player.name;
        score << " ";
        score << player.score;
        score << endl;

        }
    }
    catch(int error) {
        cout << RED << "Access denied " << error << RESET << " -- ";
        if(error == -1)
            cout << "name is too long!" << endl;
        else if(error == -2)
            cout << "name can contain only letters of the standard English alphabet!" << endl;
        else if(error == -3)
            cout << "please use 'n' or 'y'!" << endl;
        else if(error == -4)
            cout << "invalid answer number!" << endl;
    } 
}

int navigateMenu() {
    int option = 1;
    int ch;

    while (1) {
        clearScreen();
        cout << YELLOW << "   ________________________________\n" << RESET;
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "      " << BLUE << "Who Wants to Be a Millionaire?" << RESET << " \n";
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "              by                \n";
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "         " << BLUE << "Albert-Adrian          \n";
        cout << YELLOW << "  |" << RESET << "             " << BLUE << "Popa               \n";
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "               &                \n";
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "             " << RED << "Marko              \n";
        cout << YELLOW << "  |" << RESET << "             " << RED << "Bele               \n";
        cout << YELLOW << "  |________________________________\n" << RESET;
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "           " << BLUE << "*--Menu--*           \n";
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "     " << (option == 1 ? GREEN "->" RESET : "  ") << " 1. Start Game           \n";
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "     " << (option == 2 ? GREEN "->" RESET : "  ") << " 2. Exit                 \n";
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |________________________________\n" << RESET;

        ch = getch();
        if (ch == 224) { // Arrows detecting
            ch = getch();
            if (ch == 72 && option > 1) option--; // Arrow Up
            if (ch == 80 && option < 4) option++; // Arrow Down
        } else if (ch == 13) { // Enter
            return option;
        }
    }
}

int main() {
    Question questions[questions_nr];
    loadQuestions(questions);

    int option;
    do {
        option = navigateMenu();

        switch (option) {
            case 1:
                cout << "  |                                \n";
                startGame(questions);
                break;
            // case 2:
            //     printf("  |                                \n");
            //     displayLeaderboard();
            //     break;
            // case 3: {
            //     char name[name_length];
            //     printf("  |                                \n");
            //     printf("  |       Enter player name:");
            //     fgets(name, name_length, stdin);
            //     name[strcspn(name, "\n")] = 0;
            //     printf("  |\n");
            //     viewGameHistory(name);

            //     break;
            // }
            case 2:
                clearScreen();
                cout << "Exiting the game. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
        cout << "\nPress any key to continue...";
        getch();
    } while (option != 2);

    return 0;
}