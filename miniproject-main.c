#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>


void guess();
void hangman();

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
    printf("   6. QUIT\n\n");
    printf("   • ENTER AN OPTION:");
    scanf("%d",&x);
    
    switch(x){
        case 1:printf("the code for tic tac toe\n");
        break;
        
        case 2: guess();
        break;

        case 3: hangman();
        break;

        case 6:
        printf("\n\t Thank you"); 
        return 0;
        
        default : printf("enter a vaid option");
    }
    return 0;
}


void guess(){
    int number, guess;
    int no_of_guess = 1;
    srand(time(0));
    number = rand()%100 + 1; // Generates a number between 1 to 100
    do
    {
        printf("Guess a number between 1 to 100: ");
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

}

void hangman()
{
int i,j,c,count=0,ans=0,flag=0,index;
char a[10][10]={"sahil","java","python","haskell","brainfuck","javascript"};
char b[10],alpha;
char d='_';

srand(time(0));
index = rand()%6;
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
 if(ans==c) printf("\n\n\n\t you won");
 else printf("\n\n\n\t\t  u lose.\n\n \t\t **SORRY  U R HANGED**");

getch();

}