#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define questions_nr 15
#define answers_nr 4
#define name_length 50

// Question Struct
typedef struct {
    char question[256];
    char answers[answers_nr][100];
    int correct_index;
} Question;

// Player Struct
typedef struct {
    char name[name_length];
    float score;
} Player;

// Funcții principale
void loadQuestions(Question questions[]) {
    // 1
    strcpy(questions[0].question, "Which of these names is not in the title of a Shakespeare play?");
    strcpy(questions[0].answers[0], "Hamlet");
    strcpy(questions[0].answers[1], "Romeo");
    strcpy(questions[0].answers[2], "Macbeth");
    strcpy(questions[0].answers[3], "Darren");  // Correct
    questions[0].correct_index = 3;

    // 2
    strcpy(questions[1].question, "In the United States, what is traditionally the proper way to address a judge?");
    strcpy(questions[1].answers[0], "Sir");
    strcpy(questions[1].answers[1], "Your Honor");  // Correct
    strcpy(questions[1].answers[2], "Your Eminence");
    strcpy(questions[1].answers[3], "You da man!");
    questions[1].correct_index = 1;

    // 3
    strcpy(questions[2].question, "Which of these pairs of apps offers roughly the same type of service?");
    strcpy(questions[2].answers[0], "Snapchat and Instagram");
    strcpy(questions[2].answers[1], "Whatsapp and ShareIt");
    strcpy(questions[2].answers[2], "Tiktok and Spotify");
    strcpy(questions[2].answers[3], "lyft and Uber");// Correct
    questions[2].correct_index = 3;

    // 4
    strcpy(questions[3].question, "What is the chemical symbol for gold?");
    strcpy(questions[3].answers[0], "Au");  // Correct
    strcpy(questions[3].answers[1], "Ag");
    strcpy(questions[3].answers[2], "Pb");
    strcpy(questions[3].answers[3], "Fe");
    questions[3].correct_index = 0;

    // 5
    strcpy(questions[4].question, "Which character is from the anime 'Naruto'?");
    strcpy(questions[4].answers[0], "Konohamaru");// Correct
    strcpy(questions[4].answers[1], "Zoro");
    strcpy(questions[4].answers[2], "Vegeta");
    strcpy(questions[4].answers[3], "Ash");
    questions[4].correct_index = 0;

    // 6
    strcpy(questions[5].question, "What is the capital of Moldova");
    strcpy(questions[5].answers[0], "Zalau");
    strcpy(questions[5].answers[1], "Teleorman");
    strcpy(questions[5].answers[2], "Chisinau");  // Correct
    strcpy(questions[5].answers[3], "Galati");
    questions[5].correct_index = 2;

    // 7
    strcpy(questions[6].question, "How many continents are there on Earth?");
    strcpy(questions[6].answers[0], "5");
    strcpy(questions[6].answers[1], "6");
    strcpy(questions[6].answers[2], "7");  // Correct
    strcpy(questions[6].answers[3], "8");
    questions[6].correct_index = 2;

    // 8
    strcpy(questions[7].question, "Which of the following cities is GTA 5 based on?");
    strcpy(questions[7].answers[0], "Liberty City");
    strcpy(questions[7].answers[1], "Vice City");
    strcpy(questions[7].answers[2], "Los Angeles");
    strcpy(questions[7].answers[3], "Los Santos");// Correct
    questions[7].correct_index = 3;

    // 9
    strcpy(questions[8].question, "Who painted the Mona Lisa?");
    strcpy(questions[8].answers[0], "Vincent van Gogh");
    strcpy(questions[8].answers[1], "Pablo Picasso");
    strcpy(questions[8].answers[2], "Leonardo da Vinci");  // Correct
    strcpy(questions[8].answers[3], "Michelangelo");
    questions[8].correct_index = 2;

    // 10
    strcpy(questions[9].question, "Which is the largest ocean on Earth?");
    strcpy(questions[9].answers[0], "Atlantic Ocean");
    strcpy(questions[9].answers[1], "Indian Ocean");
    strcpy(questions[9].answers[2], "Pacific Ocean");  // Correct
    strcpy(questions[9].answers[3], "Arctic Ocean");
    questions[9].correct_index = 2;

    // 11
    strcpy(questions[10].question, "Who plays the role of Iron Man in the Marvel Cinematic Universe?");
    strcpy(questions[10].answers[0], "Robert Downey Jr.");// Correct
    strcpy(questions[10].answers[1], "Chris Hemsworth");
    strcpy(questions[10].answers[2], "Tom Holland");
    strcpy(questions[10].answers[3], "Ryan Renolds");
    questions[10].correct_index = 0;

    // 12
    strcpy(questions[11].question, "Which gas do plants primarily use for photosynthesis?");
    strcpy(questions[11].answers[0], "Oxygen");
    strcpy(questions[11].answers[1], "Carbon dioxide");  // Correct
    strcpy(questions[11].answers[2], "Nitrogen");
    strcpy(questions[11].answers[3], "Hydrogen");
    questions[11].correct_index = 1;

    // 13
    strcpy(questions[12].question, "Who wrote the 'One piece' manga series?");
    strcpy(questions[12].answers[0], "Masashi Kishimoto");
    strcpy(questions[12].answers[1], "Eiichiro Oda");  // Correct
    strcpy(questions[12].answers[2], "Akira Toriyama");
    strcpy(questions[12].answers[3], "Hirohiko Araki");
    questions[12].correct_index = 1;

    // 14
    strcpy(questions[13].question, "What is the fastest land animal?");
    strcpy(questions[13].answers[0], "Cheetah");  // Correct
    strcpy(questions[13].answers[1], "Lion");
    strcpy(questions[13].answers[2], "Horse");
    strcpy(questions[13].answers[3], "Greyhound");
    questions[13].correct_index = 0;

    // 15
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

void saveScore(Player player) {
    FILE *file = fopen("scores.txt", "a");
    if (file == NULL) {
        printf("  |    Error saving score!\n");
        printf("  |________________________________\n");

        return;
    }
    fprintf(file, "%s %.2f\n", player.name, player.score);
    fclose(file);
    printf("  |                                \n");
    printf("  |  Score saved for %s!\n", player.name);
    printf("  |________________________________\n");
}

void displayLeaderboard() {
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("  |  No scores found!\n");
        printf("  |________________________________\n");

        return;
    }

    Player players[100];
    int count = 0;
    while (fscanf(file, "%s %f", players[count].name, &players[count].score) != EOF) {
        count++;
    }
    fclose(file);


    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (players[i].score < players[j].score) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
        printf("  |           Leaderboard          \n");
    for (i = 0; i < count; i++) {
        printf("  |     %d. %s - %.2f points  \n", i + 1, players[i].name, players[i].score);
    }
        printf("  |                                \n");
        printf("  |________________________________\n");
}

void viewGameHistory(char *name) {
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("  |                                \n");
        printf("  |      No game history found \n");
        printf("  |________________________________\n");
        return;
    }

    Player player;
    int found = 0;
    printf("  |       Game History for %s     \n", name);
    printf("  |                                \n");
    while (fscanf(file, "%s %f", player.name, &player.score) != EOF) {
        if (strcmp(player.name, name) == 0) {
    printf("  |       Score: %.2f      \n", player.score);
    printf("  |                                \n");
            found = 1;
        }
    }
    fclose(file);

    if (!found) {
        printf("  |     No history found for %s.\n", name);
    }
     printf("  |________________________________\n");
}

void startGame(Question questions[]) {
    Player player;
    printf("  |      Enter your name: ");
    fgets(player.name, name_length, stdin);
    player.name[strcspn(player.name, "\n")] = 0;
    player.score = 0;
    int i,j;
    for ( i = 0; i < questions_nr; i++) {
        clearScreen();
        printf("\n");
        printf("   ____________________________________________________________________\n");
        printf("  |                                 \n");
        printf("  |      Question %d: %s   \n", i + 1, questions[i].question);
        printf("  |                                                   \n");

        for ( j = 0; j < answers_nr; j++) {
            printf("  |         %d. %s                                  \n", j + 1, questions[i].answers[j]);
        }

        printf("  |                                \n");
        printf("  |       Use '50/50'? (y/n): ");
        char use5050 = getchar();
        getchar();
        printf("  |________________________________\n");
        clearScreen();
        printf("\n");
        printf("   _____________________________________________________________\n");
        printf("  |                                 \n");
        printf("  |      Question %d: %s   \n", i + 1, questions[i].question);
        printf("  |                                 \n");

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
                printf("  |         %d. %s                                  \n", optionIndex + 1, questions[i].answers[j]);
                optionIndex++;
            }
        }

        printf("  |                                 \n");
        printf("  |       Select your answer (1-%d): ", visibleCount);
        int answer;
        scanf("%d", &answer);
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
            printf("  |                                 \n");
            printf("  |             Correct!\n");
            printf("  |_____________________________________________________________\n");
            player.score += 1;
        } else {
            printf("  |                                 \n");
            printf("  |      Wrong! The correct answer was: %s\n", questions[i].answers[questions[i].correct_index]);
            printf("  |_____________________________________________________________\n");
        }
        Sleep(1000);
    }
    printf("  |                                 \n");
    printf("  |        Game Over! Your final score: %.2f\n", player.score);
    printf("  |_____________________________________________________________\n");

    saveScore(player);
}

int navigateMenu() {
    int option = 1;
    int ch;

    while (1) {
        clearScreen();
        printf("   ________________________________\n");
        printf("  |                                \n");
        printf("  | Who Wants to Be a Millionaire? \n");
        printf("  |                                \n");
        printf("  |              by                \n");
        printf("  |                                \n");
        printf("  |         Albert-Adrian          \n");
        printf("  |             Popa               \n");
        printf("  |________________________________\n");
        printf("  |                                \n");
        printf("  |           *--Menu--*           \n");
        printf("  |                                \n");
        printf("  |     %s 1. Start Game           \n", (option == 1) ? "->" : "  ");
        printf("  |                                \n");
        printf("  |     %s 2. View Leaderboard     \n", (option == 2) ? "->" : "  ");
        printf("  |                                \n");
        printf("  |     %s 3. View Game History    \n", (option == 3) ? "->" : "  ");
        printf("  |                                \n");
        printf("  |     %s 4. Exit                 \n", (option == 4) ? "->" : "  ");
        printf("  |                                \n");
        printf("  |________________________________\n");



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
                printf("  |                                \n");
                startGame(questions);
                break;
            case 2:
                printf("  |                                \n");
                displayLeaderboard();
                break;
            case 3: {
                char name[name_length];
                printf("  |                                \n");
                printf("  |       Enter player name:");
                fgets(name, name_length, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("  |\n");
                viewGameHistory(name);

                break;
            }
            case 4:
                printf("Exiting the game. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\nPress any key to continue...");
        getch();
    } while (option != 4);

    return 0;
}
