#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


void guess_num();
void hangman();
void tictactoe();

int main()
{
    int x;
    printf("\n\n");
    printf("****ARCADE GAMES******\n\n");
    printf("   • LIST OF GAMES\n");
    printf("   1. TIC TAC TOE\n");
    printf("   2. GUESS THE NUMBER\n");
    printf("   3. HANGMAN\n");
    printf("   4. ROCK-PAPER-SCISSOR\n");
    printf("   5. Allan OP\n");
    printf("   6. QUIT\n\n");
    printf("   • ENTER AN OPTION: ");
    scanf("%d",&x);
    
    switch(x){
        case 1: tictactoe();
        break;
        
        case 2: guess_num();
        break;

        case 3: hangman();
        break;

        case 4:
        printf("the code for rock-paper-scissor");
        break;

        case 5:
        printf("Unknown game");
        break;

        case 6:
        printf("\n\t Thank you"); 
        return 0;
        
        default : printf("enter a vaid option");
    }

    main();
    return 0;
}


void guess_num(){
    int number, guess;
    int no_of_guess = 1;
    char choice;

    srand(time(0));
    number = rand()%100 + 1; // Generates a number between 1 to 100
    number = 50;
    do
    {
        printf("\n\nGuess a number between 1 to 100: ");
        scanf("%d", &guess);
        if(guess > number){
            printf("Guess Lower!\n");
        }
        else if(guess < number){
            printf("Guess Higher!\n");
        }
        else{
            printf("You have guessed the number in %d attempts\n", no_of_guess);
        }
        no_of_guess++;
    } while (guess != number);

    printf("Press Y to play again and N to exit: ");
    choice=getche();

    if (tolower(choice) == 'y')
    {
        guess_num();
    }
    

}

void hangman()
{
int i,j,c,count=0,ans=0,flag=0,index;
char a[10][10]={"sahil","java","python","haskell","brainfuck","javascript"};
char b[10],alpha,choice;
char d='_';

srand(time(0));
index = rand()%6;
index=2;
c=strlen(&a[index][0]);
printf("\n\n\t\t\t ** HANGMAN ** \n");
	printf("\n\t\t\t**************\t\t\t");
		printf("\n\t\t\t..............\n\n\t\t\t  ");
for(j=0;j<c;j++)
	  { printf("%c ",d);
	  b[j]=d;}
	  printf("\n\n\t\t\t..............\t\t\t");
		printf("\n\n\t\t\t**************");

while (count<6)
 {
 flag=0;
	   printf("\n\n\n\n\n\n\t enter a char: ");
		alpha=getch();

		for(i=0;i<c;i++)
		{
			if (alpha==a[index][i])
		   {	b[i]=a[index][i];
		   flag=1;
			ans++; }

		}

		printf("\n\n\t\t\t ** HANGMAN ** \n");
		printf("\n\t\t\t**************\t\t\t");
		printf("\n\t\t\t..............\n\n\t\t\t  ");
		for(i=0;i<c;i++)
		printf("%c ",b[i]);
		printf("\n\n\t\t\t..............\t\t\t");
		printf("\n\n\t\t\t**************");

		if(flag==0)
		{count++;
		printf("\n\n\n\n\t\t%c is a wrong guess",alpha);
		printf("\n\n\t\t (u have %d more guesses)",6-count);}

		else{
		printf("\n\n\t\t u r correct!!");
	   printf("\n\t\t( u have %d more words to go)",c-ans);}

		if(ans==c) break;
 }
 if(ans==c) printf("\n\n\n\t you won\n");
 else printf("\n\n\n\t\t  u lose.\n\n \t\t **SORRY  U R HANGED**");

printf("\n\n\n\t Press Y to play again and N to exit: ");
choice=getche();

if (tolower(choice) == 'y')
{
    hangman();
}

}

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();

void tictactoe()
{
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
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);
    
    board();
    
    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    printf("\n\n\nPress Y to play again and N to exit: ");
    choice=getche();

    if (tolower(choice) == 'y')
    {
        tictactoe();
    }


}

/*********************************************

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

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
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}
void board()
{
    /*system("cls");*/
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
