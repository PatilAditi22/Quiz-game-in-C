#include<stdio.h>
#include<conio.h>
#include<ctype.h>

struct Question  // Holds Question, Options and right ans no
{
	char qn[150];   // Qn statement
	char options[4][100];  // four options
	int ans;   // write option no  ( 1, 2, 3, 4 )
};

struct PlayerRecord  // Holds one player record.. name , score
{
	char name[40];   // Player name
	int score;       // Player score
};

void writescore(int score, char name[40]);
void displayscore();
void rules();
void main()
{
	int  ans, score, i ,j, count;
	char choice;
	struct PlayerRecord player;

	// Basic level Question list
	struct Question Basic[5] =
	{	{"Q.1) Which one of the following OS does not support multitasking?",
		 "1. Linux ", "2. Windows 10", "3. DOS", "4. UNIX" , 3  },
		{"Q.2) Convert 10111 to Decimal number",
		 "1. 48", "2. 23", "3. 29" , "4. 3000", 2  },
		{"Q.3) Diagramatic representation of an algorithm is: ",
		 "1. Flowchart", "2. Data Flow Diagram", "3. Algorithm design" , "4. Pseudo Code", 1  },
		{"Q.4) The default standard output device for C program is:",
		 "1. Modem ", "2. Disk", "3. Printer" , "4. Monitor", 4  },
		{"Q.5) Every C program should compulsary have a function called as ",
		 "1. start() ", "2. main()", "3. Start()" , "4. Main()", 2  }
	};

	// Advance level Question list
	struct Question Advance[10] =
	{	{"Q.1) Which function does not return any data? ",
		 "1. int ", "2. float", "3. void" , "4. recursive", 3  },
		{"Q.2) A function that calls itself is known as ?",
		 "1. Inline Function ", "2. Nested Function", "3. Overloaded Function" , "4. Recursive Function", 4  },
		{"Q.3) Which one of the following is invalid identifier? ",
		 "1. typename", "2. printname", "3. papername" , "4. writename", 1  },
		{"Q.4) The life of a variable declared as automatic storage class is ____ ",
		 "1. until program complets its execution ",
		 "2. till the control remains in the function where it is declared",
		 "3. until the computer remains on" , "4. none of the above", 2  },
		{"Q.5) Pseudo code emphasize on: ",
		 "1. Development ", "2. Coding", "3. Design" , "4. Debugging", 3  },
		{"Q.6) An inline function is one that ____________ ",
		 "1. calls itself ",
		 "2. replaces the function call with the function definition",
		 "3. has no return type" , "4. none of the above", 2  },
		{"Q.7) Looping in a program means ",
		 "1. Repeating a given set of statements ",
		 "2. Branching to a specified branch or label in the program",
		 "3. Both of above" , "4. None of above", 1  },
		{"Q.8) The static storage class variable is stored in ______ ",
		 "1. compiler ", "2. nowhere", "3. CPU resisters" , "4. memory", 4  },
		{"Q.9) What is the maximum value that an signed integer constant can have ",
		 "1. 32768 ", "2. 32767", "3. 1.2014e+38" , "4. 256", 2  },
		{"Q.10) An identifier in C cannot start with? ",
		 "1. A number ", "2. An alphabet",
		 "3. A special symbol other than underscore" ,
		 "4. An capital character", 1  }
	};



mainmenu:
	clrscr();
	printf("\n\n\t\t------------------------------------------------");
	printf("\n\t\t\t\t  WELCOME");
	printf("\n\t\t\t    ****    TO   ****");
	printf("\n\t\t\t\t QUIZ GAME");
	printf("\n\t----------------------------------------------------------------");
	printf("\n\t|                                                              |");
	printf("\n\t|                                                              |");
	printf("\n\t|\t\t1. Press 'Y' to Play Quiz                      |");
	printf("\n\t|                                                              |");
	printf("\n\t|\t\t2. Press 'D' to Display High Score             |");
	printf("\n\t|                                                              |");
	printf("\n\t|\t\t3. Press 'R' for Quiz Rules                    |");
	printf("\n\t|                                                              |");
	printf("\n\t|\t\t4. Press 'Q' to QUIT game                      |");
	printf("\n\t|                                                              |");
	printf("\n\t|                                                              |");
	printf("\n\t----------------------------------------------------------------");

	choice=toupper(getch());
		if(choice=='D')
		{
			displayscore();
			goto mainmenu;
		}
		else if(choice=='R')
		{
			rules();
			goto mainmenu;
		}
		else if(choice=='Q')
		{
			exit(1);
		}
		else if(choice=='Y')
		{
			rules();
			goto basic;
		}
basic:
	count=0;
	score=0;
	clrscr();
	printf("===============================================================================\n");
	printf("Enter your name :");
	fflush(stdin);
	gets(player.name);
	printf("\nHello ! %s .. All the best.\n", player.name);
	printf("===============================================================================\n");

	printf("\n\t\t\t   B A S I C   L E V E L\n ") ;

	for( i=0; i<5; i++)
	{

		printf("\n%s\n", Basic[i].qn);
		printf("--------------------------------------------------------------------------------\n");

		for( j=0; j<4; j++)
		{
			printf("\n\t%s\n", Basic[i].options[j] );
		}
		printf("\n\t\tYour Ans : ");
		scanf("%d", &ans);

		if( ans == Basic[i].ans)
		{
			printf("\n\t\t -- Correct Answer --");
			score = score + 50;
			count++;
			getch();
		}
		else
		{
			printf("\n\t\t -- Wrong Answer -- \n");
			printf("\n\t\t\tCorrect Option is %d " , Basic[i].ans );
			getch();
		}
		clrscr();
	}
	printf("\n\n\n\n\n\t---------------------------------------------------------");
	printf("\n\n\t\tYou have given %d correct answers.",count);
	printf("\n\n\t\tYour Basic Level Score is: %d",score);

	if(count<3)
	{
		printf("\n\n\n\t\t\t!!!  SORRY  !!!");
		printf("\n\n\n\t\tYou are not eligible to play the Advance Level");
		printf("\n\n\t\tBetter Luck next time!!!");
		printf("\n\n\t---------------------------------------------------------");
		getch();
		goto mainmenu;
	}
	else
	{
		printf("\n\n\n\t\t    !!!  CONGRATULATIONS !!!");
		printf("\n\n\n\t\tYou are eligible to play Advance Level");
		printf("\n\n\t---------------------------------------------------------");
		getch();
		goto advance;
	}

advance:
	clrscr();
	printf("\n\t\t\t   A D V A N C E    L E V E L \n") ;


	for( i=0; i<10; i++)
	{

		printf("\n%s\n", Advance[i].qn);
		printf("--------------------------------------------------------------------------------\n");

		for( j=0; j<4; j++)
		{
			printf("\n\t%s\n", Advance[i].options[j] );
		}
		printf("\n\t\tYour Ans : ");
		scanf("%d", &ans);

		if( ans == Advance[i].ans)
		{
			printf("\n\t\t -- Correct Answer -- \n");
			score = score + 100;
			getch();
		}
		else
		{
			printf("\n\t\t -- Wrong Answer -- \n");
			printf("\n\t\t\tCorrect Option is %d " , Advance[i].ans );
			score = score - 20;
			getch();
		}
		clrscr();
	}

	player.score=score;
	printf("\n\nYour score is %d", player.score);
	getch();
	writescore(player.score , player.name);
	goto mainmenu;


}

void rules()
{
	clrscr();
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\t\t\t  WELCOME");
	printf("\n\t\t\t     ****    TO   ****");
	printf("\n\t\t\t      QUIZ GAME RULES");
	printf("\n-------------------------------------------------------------------------------");
	printf("\nRules for playing Quiz Game are as follows:");
	printf("\n\n  >>  Quiz Game consists of two levels:\n\t1.Basic Level\n\t2.Advance Level");
	printf("\n\n  >>  Each question have four options.");
	printf("\n  >>  Basic Level consist of 5 questions of score 50 each.");
	printf("\n  >>  You have to give minimum 3 answers correct to go for Advance level.");
	printf("\n  >>  Advance Level consists of 10 questions of score 100 each.");
	printf("\n  >>  All questions are compulsory.");
	printf("\n\n  >>  Note: In Advance Level every wrong answer will reduce your score by 20.");
	printf("\n\n\t\t\t  ****   ALL THE BEST   ****");
	printf("\n\n   Press any key to continue");
	printf("\n-------------------------------------------------------------------------------");
	getch();
}

void writescore(int score, char name[40])
{
	char pname[40];
	int s;
	FILE *fp;
	clrscr();
	fp=fopen("sc.txt","r");
	fscanf(fp,"%s %d",&pname,&s);
	if(score>=s)
	{

		fclose(fp);
		fp=fopen("sc.txt","w");
		fprintf(fp,"%s \n%d",name,score);
		fclose(fp);
	}
}

void displayscore()
{
	char pname[40];
	int s;
	FILE *fp;
	clrscr();
	fp=fopen("sc.txt","r");
	fscanf(fp,"%s %d",&pname,&s);
	printf("\n\n\t\t %s has secured Highest score %d",pname,s);
	fclose(fp);
	getch();
}

