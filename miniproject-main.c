#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void red()
{
    printf("\033[1;31m");
}

void green()
{
    printf("\033[0;32m");
}

void blue()
{
    printf("\033[1;34m");
}

void yellow()
{
    printf("\033[0;33m");
}

void purple()
{
    printf("\033[0;35m");
}

void reset()
{
    printf("\033[0m");
}

void guess_num();
void hangman();
void tictactoe();
void rockpaper();

int main()
{
    char x;
    reset();
    printf("\n\n");
    printf("****ARCADE GAMES******\n\n");
    printf("   LIST OF GAMES\n\n");
    blue();
    printf("   1. TIC TAC TOE\n");
    green();
    printf("   2. GUESS THE NUMBER\n");
    red();
    printf("   3. HANGMAN\n");
    yellow();
    printf("   4. ROCK-PAPER-SCISSOR\n");
    purple();
    printf("   5. QUIT\n\n");
    reset();
    printf("   ENTER AN OPTION: ");
    x = getche();

    switch (x)
    {
    case '1':
        system("cls");
        tictactoe();
        break;

    case '2':
        system("cls");
        guess_num();
        break;

    case '3':
        system("cls");
        hangman();
        break;

    case '4':
        system("cls");
        rockpaper();
        break;

    case '5':
        purple();
        printf("\n\n\t Thank you");
        printf("\n\t\t\t ~ Made by Sahil, Lance and Allan");
        getch();
        return 0;

    default:
        system("cls");
        red();
        printf("\nENTER A VALID OPTION");
    }

    main();
    return 0;
}

void guess_num()
{
    green();
    int number, guess;
    int no_of_guess = 1;
    char choice;

    srand(time(0));
    number = rand() % 100 + 1;
    do
    {
        printf("\n\nGuess a number between 1 to 100: ");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("Guess Lower!\n");
        }
        else if (guess < number)
        {
            printf("Guess Higher!\n");
        }
        else
        {
            printf("You have guessed the number in %d attempts\n", no_of_guess);
        }
        no_of_guess++;
    } while (guess != number);

    printf("Press Y to play again and N to exit: ");
    choice = getche();

    if (tolower(choice) == 'y')
    {
        system("cls");
        guess_num();
    }

    system("cls");
    reset();
}

void hangman()
{
    red();
    int i, j, c, count = 0, ans = 0, flag = 0, index;
    char a[][20] = {"algorithms", "java", "haskell", "javascript", "assembly", "pascal", "swift", "django"};
    char b[10], alpha, choice;
    char d = '_';

    srand(time(0));
    index = rand() % 8;
    c = strlen(&a[index][0]);
    printf("\n\n\t\t\t ** HANGMAN ** \n");
    printf("\n\t\t\t**************\t\t\t");
    printf("\n\t\t\t..............\n\n\t\t\t  ");
    for (j = 0; j < c; j++)
    {
        printf("%c ", d);
        b[j] = d;
    }
    printf("\n\n\t\t\t..............\t\t\t");
    printf("\n\n\t\t\t**************");

    while (count < 6)
    {
        flag = 0;
        printf("\n\n\n\n\n\n\t Enter a char: ");
        alpha = getch();
        system("cls");
        for (i = 0; i < c; i++)
        {
            if (alpha == a[index][i])
            {
                b[i] = a[index][i];
                a[index][i] = '0';
                flag = 1;
                ans++;
            }
        }

        printf("\n\n\t\t\t ** HANGMAN ** \n");
        printf("\n\t\t\t**************\t\t\t");
        printf("\n\t\t\t..............\n\n\t\t\t  ");
        for (i = 0; i < c; i++)
            printf("%c ", b[i]);
        printf("\n\n\t\t\t..............\t\t\t");
        printf("\n\n\t\t\t**************");

        if (flag == 0)
        {
            count++;
            printf("\n\n\n\n\t\t%c is a wrong guess", alpha);
            printf("\n\n\t\t (You have %d more guesses)", 6 - count);
        }

        else
        {
            printf("\n\n\t\t You are correct!!!");
            printf("\n\t\t( You have %d more words to go)", c - ans);
        }

        if (ans == c)
            break;
    }
    if (ans == c)
        printf("\n\n\n\t YOU WON!!!\n");
    else
        printf("\n\n\n\t\t  You lose.\n\n \t\t **SORRY  YOU ARE HANGED**");

    printf("\n\n\n\t Press Y to play again and N to exit: ");
    choice = getche();

    if (tolower(choice) == 'y')
    {
        system("cls");
        hangman();
    }
    system("cls");
    reset();
}

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board();
void reset_board(char *);

void tictactoe()
{
    blue();
    int player = 1, i, choice;

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid move ");

            player--;
        }
        i = checkwin();

        player++;
    } while (i == -1);

    board();

    if (i == 1)
        printf("==> Player %d wins ", --player);
    else
        printf("==> It is a draw");

    printf("\n\n\nPress Y to play again and N to exit: ");
    choice = getche();
    reset_board(square);
    if (tolower(choice) == 'y')
    {
        system("cls");

        tictactoe();
    }

    system("cls");
}



int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}
void reset_board(char square[])
{
    for (int i = 0; i <= 10; i++)
        square[i] = i + 48;
}

void win(char, char);

void rockpaper()
{
    yellow();
    int x, a, z;
    char comp, player, choice;
    srand(time(0));
    x = rand() % 3;
    char arr[][10] = {"rock", "paper", "scissor"};

    if (x == 0)
    {
        comp = 'r';
    }
    if (x == 1)
    {
        comp = 'p';
    }
    if (x == 2)
    {
        comp = 's';
    }

    printf("\n\tWelcome to the Rock Paper Scissors\n");
    printf("\t----------------------------------\n\n");
    printf("Press 1 for Rock, Press 2 for Paper, Press 3 for Scissors: ");
    scanf("%d", &a);
    printf("\n ----------------------\n");
    printf("|   You chose: %s |\n", arr[a - 1]);
    printf(" ----------------------\n\n");
    printf("\tComputer's turn\n");
    printf(" ------------------------\n");
    printf("| Computer chose: %s |\n", arr[x]);
    printf(" ------------------------\n\n");

    if (a == 1)
    {
        player = 'r';
    }
    if (a == 2)
    {
        player = 'p';
    }
    if (a == 3)
    {
        player = 's';
    }

    win(comp, player);
    printf("\n\nPress Y to play again and N to exit: ");
    choice = getche();

    if (tolower(choice) == 'y')
    {
        system("cls");
        rockpaper();
    }
    system("cls");
}

void win(char comp, char player)
{
    if (comp == 'p' && player == 'r')
    {
        printf("COMPUTER WINS");
    }
    if (comp == 'r' && player == 's')
    {
        printf("COMPUTER WINS");
    }
    if (comp == 's' && player == 'p')
    {
        printf("COMPUTER WINS");
    }
    if (comp == 'r' && player == 'p')
    {
        printf("YOU WIN!");
    }
    if (comp == 'p' && player == 's')
    {
        printf("YOU WIN!");
    }
    if (comp == 's' && player == 'r')
    {
        printf("YOU WIN!");
    }
    if (comp == player)
    {
        printf(" IT IS A DRAW!");
    }

