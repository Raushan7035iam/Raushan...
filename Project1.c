#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int array[4][4];
    char str[20];
    char x;
    int a,z=1,rows,columns,move=400,temp;
    int random,i,p,q;
    int randvalues[16],m=0;
    int t,j;
	printf("Enter your name: \n");
	gets(str);
	printf("\t\t\t  RULE OF THIS GAME\n\n");
	printf("1.You can move only one step at a time by arrow key\nMove Up   : by Up arrow key\nMove Down : by Down arrow key\nMove Left :by Left arrow key\nMove Right: by Right arrow key");

	printf("2.You can move no at empty position only\n\n3.For each valid move : Your total no of move will decrease by one ");
	printf("Winning situation : number in a 4*4 matrix should be in order from 1 to 15 \n\n ");
	printf("\tWinning situation:\n");
    printf("\n--------------------\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(z>=1&&z<=15)
			printf("| %-2d  ",z);
			else
			printf("|     ");
			z++;
		}
		printf("|\n");

	}
        printf("--------------------\n");

	printf("You can exit a game any time by pressing 'E' or 'e'\n");
	printf("So Try to win in minimum no of move\n\n");
	printf("\tHappy gaming , Good luck\n\n");
	printf("Enter any to key to start.....");
	getch();
	system("cls");
	printf(" Hello ");
	puts(str);
	printf("\nMove remaining: %d\n\n",move);

        printf("\n---------------------\n");
    srand((unsigned)time(NULL));

    for(i=0;i<16;i++)     //assigning values 1 to 36
         randvalues[i]=i+1;

    for(i=0;i<16;i++)      //shuffle logic
    {
         j=i+rand()/(RAND_MAX/(16-i) + 1);
         t=randvalues[j];
         randvalues[j] = randvalues[i];
         randvalues[i] = t;
    }

    for(rows=0;rows<4;rows++) //conversion from 1-D to 2-D array and printning
    {
        for(columns=0;columns<4;columns++)
        {
            array[rows][columns] = randvalues[m++];
            if(array[rows][columns]==16)
            {
                printf("|    ");
            }
            else
            printf("|%-2d  " , array[rows][columns]);
        }
        printf("|\n");
    }
    printf("-------------------\n");
    getch();
    	system("cls");
  for(a=1;a<=move;a++)
  {
    for(rows=0;rows<4;rows++)
    {
        for(columns=0;columns<4;columns++)
          {
            if(array[rows][columns]==16)
            {
                p=rows;
                q=columns;
            }
          }
    }
 while(1)
   {
    x=getch();
    if(x==69||x==101)
        exit(0);
    if(x==75)
       {
        temp=array[p][q];
        array[p][q]=array[p][q+1];
        array[p][q+1]=temp;
        break;

       }

   else if(x==77)
        {
        temp=array[p][q];
        array[p][q]=array[p][q-1];
        array[p][q-1]=temp;
        break;
        }
   else if(x==72)
       {
        temp=array[p][q];
        array[p][q]=array[p+1][q];
        array[p+1][q]=temp;
        break;
       }
    else
        if(x==80)
       {
        temp=array[p][q];
        array[p][q]=array[p-1][q];
        array[p-1][q]=temp;
        break;
       }
     else
        break;
   }
    printf("\n------------------------\n");
   for(rows=0;rows<4;rows++) //conversion from 1-D to 2-D array and printning
    {
        for(columns=0;columns<4;columns++)
        {
            if(array[rows][columns]==16)
            {
                printf("|    ");
            }
            else
            printf("|%-2d  " , array[rows][columns]);
        }
        printf("|\n");
    }
    printf("-----------------------\n");
    getch();
    	system("cls");
    for(rows=0;rows<4;rows++)
    {
        for(columns=0;columns<3;columns++)
          {
            if(array[rows][columns]!=array[rows][columns+1])

            break;
          }
    }

    for(rows=0;rows<4;rows++)
    {
        for(columns=0;columns<4;columns++)
          {
            if(array[rows][columns]==array[3][3])
            printf("Won, Congrats ");
            break;
          }
    }
  }
}
