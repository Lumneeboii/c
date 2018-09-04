/* 

Author   : Prahlad J Shenoy.(Lumnee boii)
Mentor   : ShivaShankaran.
College  : Jaya Engneering College.
category : Game.

*/
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int my_number[25],pc_number[25];         

void instruction();                      //instruction for how to Play.
void get(char name[]);                   //get input number from user .
int checking(int my_number[],int i);     //checking section (duplicat number & limitation of number).
void pc_get();                           // by useing random funtion fill the table of pc player.
bool toss();                             //to know who start the game.
void i_play();                           //Starting playing by user .    
void pc_play();                          //Starting playing by pc .
void dash();                             //cuting the number.    
void display(int my_count,int pc_count); //Display the table of both player for cross checking.
void finish(int i);                      //to Display that the use is win or loss.

void main()
{
	int choise;
	char name[30];

    clrscr();
    
    gotoxy(18,6);printf("|------------------------------------------|");
    gotoxy(18,7);printf("|          Lets Play BINGO                 |");
    gotoxy(18,8);printf("|------------------------------------------|");
    printf("\nWELCOME");
    
    printf("\nPress.... \n\t 1 :: How to play ?? (instruction)\n \t 2 :: PLAY..!! \n \t 3 :: Exit :-( \n");
    scanf("%d",&choise);
    
    
    getch();
    
  if(choise == 1)
    instruction();
  else if(choise == 3)
    exit(0);
    
    printf("\nEnter your Name ");
    scanf("%s",name);
    
	get(name);
	
	pc_get();
    
    if(toss())
        i_play();
    else
        pc_play();
    
}

void instruction()
{
    clrscr();
    
    gotoxy(18,6);printf("|------------------------------------------|");
    gotoxy(18,7);printf("|            How to PLAY..??               |");
    gotoxy(18,8);printf("|------------------------------------------|\n\n");
    
    printf("  ** INSTRUCTION ** \n\n\n");
    
    printf("  *Enter 25 number randomly From : 1 To :25 . \n  *The number which you have entered is cut and that number is convert as 0 . \n  *If all number in that row (or) coloume (or) diagonal becomes 0 ,then counted as - B. \n  *You should complete -B I N G O .\n  * First who completes, as BINGO there are  winner .\n ");
    
    printf("\n\n\t** Press Enter For  main menu  **");
    
    getch();
	
	main();
}

void get(char name[])
{
     clrscr();
    int i;//i are varible for for loop
    
    printf("\nHi,%s ......!\f Lets Play Bingo ..........,\n",name);
    printf("\nYou have to number randomly from 1 to 25(plz don't repeat the same number)\n");
    
    for(i=0;i<25;i++)
    {
        printf("\nEnter the [%d] ",i+1);
        scanf("%d",&my_number[i]);
        i=checking(my_number,i);
    }
   
    for(i = 0 ; i < 25 ; i++)
    {
        if ((i%5) == 0 )
            printf("\n-----------------------------\n");
            
        printf("| %d |",my_number[i]);
  
    }
    
    printf("\n-----------------------------\n");
}

int checking(int my_number[],int i)
{
     int k  ;//k are varible for for-loop
     
    
     int arry[25]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    
    if ( my_number[i] > 25 || my_number[i] <= 0)//if they enter any  number above or below the limit 
    { 
        printf("\n***  You have cross your limit  ** \n your limit is from : 1 to : 25\n\n");
        
        return --i;//to avoid processing of checking  duplication  i.e,if number beyond the limit then no need for checking duplication.
    }
        
    for(k=0 ; k<i ; k++)//check wheather their is any duplication in given numbers
    {
        if(my_number[i] == my_number[k])
        {
            printf("\n***   You have enter the duplication numbers  ***\n");
            for(int a=0 ; a<25 ; a++)
            {
                for ( int b=0 ; b < i ; b++)
                {
                    if ( arry[a] == my_number[b] )
                    {
                        arry[a] = NULL;// to remove the Entered number
                           
                        break;
                    }
                }
            }
            
            printf("\nRemaining number are : ");
            
            for(int a=0 ; a<25 ; a++)
                {
                 if (arry[a] == NULL) // to display the Remaining number
                    continue;
                    
                 printf(" %d ,",arry[a]);   
                 }
            
            printf("\n");
           
           return --i;
        }
        
    }
   
    
    return i;
}

void pc_get()
{
    int i,k;
    for(i=0;i<25;i++)
    {
        pc_number[i] = (rand() % 25)+1 ;
        
        
        for( k=0;k<i;k++)//check wheather their is any duplication in given numbers
        {
        if(pc_number[i] == pc_number[k])
            --i;
        }
    
    }
   
}


bool toss()
{
    clrscr();
	int result,choise;
	get:
		
		printf("\nToss for Decide how start the game\n");

		printf("\n\t\t  Head(1) or tail(0)..... \n");
		scanf("%d",&choise);
		            
	    result=rand()%2;
			
		if(result == choise)
		{
			printf("\nWin the toss..!");
		
			getch(); 
			
			return 1;
		}
		
		else if(result != choise && choise==1) 
		{
			printf("\nLoss the toss..!");
		
			getch();
			
			return 2;
		}
			
		else
		{
			printf("\nEnter the correct choice HEAD(1) /TAIL(0)");
		
			goto get;
        }
        
    getch();
    
}


void i_play(int _num)
{ 
    clrscr();
    
    int num;
   
    int i;
    
    for(i = 0 ; i < 25 ; i++)
    {
        if ((i%5) == 0 )
            printf("\n-----------------------------\n");
            
        printf("| %d |",my_number[i]);
  
    }
    
    printf("\n-----------------------------\n");
    
    printf("\nComputer Entered number :%d\n",_num);
    
    loop:
    
        printf("\nPress any number(From : 01 To : 25) ");
        scanf("%d",&num);
       
        if ( num > 25 || num <= 0)//if their enter number above or below the limit 
        { 
            printf("\n\n***  You have cross your limit  ** \n your limit is from : 1 to : 25\n\n");
            
            goto loop; 
        }
        
        for(int a=0;a<25;a++)
        {
            if(num == my_number[a])
            {
               for( i = 0 ; i < 25 ; i++)
                   {
                        if (my_number[i]==num)
                            my_number[i]=0;
                   
                        if (pc_number[i]==num)
                            pc_number[i]=0;
                        
                   }
                    dash();
                   
                    pc_play();

            }
        } 
    printf("\nThe number already cutted.\n");
             goto loop;
}


void pc_play()
{
    int num;
    
    loop:
    
        num=(rand()%25)+1;
        for(int a=0;a<25;a++)
        {
            if(num == my_number[a])
            {
            for(int  i=0;i<25;i++)
               {
                if (my_number[i]==num)
                    my_number[i]=0;
        
                if (pc_number[i]==num)
                    pc_number[i]=0;
               }
               
            dash();
   
            i_play(num);            
            }
             
        }
        goto loop;
    
  
}

void dash()
{
  
    int my_count=0,pc_count=0;
    
    if( (my_number[0] == my_number[5])&& ( my_number[10] == my_number[15])&&(0 == my_number[20]) )
        ++my_count;
        
    if( (my_number[1] == my_number[6]) && ( my_number[11] == my_number[16]) && (0 == my_number[21]) )
        ++my_count;
    
    if( (my_number[2] == my_number[7]) && ( my_number[12] == my_number[17] ) && (0 == my_number[22]) )
        ++my_count;
       
    if( (my_number[3] == my_number[8] ) && ( my_number[13] == my_number[18])  &&(0 == my_number[23]) )
        ++my_count;
       
    if( (my_number[4] == my_number[9]) && ( my_number[14] == my_number[19]) && (0 == my_number[24]) )
        ++my_count;
        
    if( (my_number[0] == my_number[1] ) && ( my_number[2] == my_number[3]) && (0 == my_number[4]) )
        ++my_count;
       
    if( (my_number[5] == my_number[6]) && ( my_number[7] == my_number[8]) && (0 == my_number[9]) )
        ++my_count;
      
    if( (my_number[10] == my_number[11]) && (my_number[12] == my_number[13] ) && (0 == my_number[14]) )
        ++my_count;
       
    if( (my_number[15] == my_number[16] ) && ( my_number[17] == my_number[18]) && (0 == my_number[19]) )
        ++my_count;
        
    if( (my_number[20] == my_number[21])  && ( my_number[22] == my_number[23]) && (0 == my_number[24])  )
        ++my_count;
       
    if( (my_number[0] == my_number[6] ) && ( my_number[12] == my_number[18]) && (0== my_number[24]) )
        ++my_count;

    if( (my_number[4] == my_number[8]) && (my_number[12] == my_number[16]) && (0 == my_number[20]) )
        ++my_count;
      
    if( (pc_number[0] == pc_number[5] ) && ( pc_number[10] == pc_number[15]) &&(0 == pc_number[20]) )
        ++pc_count;
      
    if( (pc_number[1] == pc_number[6]) && ( pc_number[11] == pc_number[16]) && (0 == pc_number[21]) )
        ++pc_count;
       
    if( (pc_number[2] == pc_number[7] ) && ( pc_number[12] == pc_number[17]) && (0 == pc_number[22]) )
        ++pc_count;
       
    if( (pc_number[3] == pc_number[8]) && (pc_number[13] == pc_number[18]) && (0 == pc_number[23]) )
        ++pc_count;
     
    if( (pc_number[4] == pc_number[9]) && ( pc_number[14] == pc_number[19]) && (0 == pc_number[24]) )
        ++pc_count;
       
    if( (pc_number[0] == pc_number[1]) && ( pc_number[2] == pc_number[3]) && (0 == pc_number[4]) )
        ++pc_count;
       
    if( (pc_number[5] == pc_number[6] ) && (pc_number[7] == pc_number[8]) && (0 == pc_number[9])  )
        ++pc_count;
      
    if( (pc_number[10] == pc_number[11] ) && ( pc_number[12] == pc_number[13]) && (0 == pc_number[14]) )
        ++pc_count;
    
    if( (pc_number[15] == pc_number[16] ) && ( pc_number[17] == pc_number[18]) && (0 == pc_number[19]) )
        ++pc_count;
      
    if( (pc_number[20] == pc_number[21]) && ( pc_number[22] == pc_number[23]) && (0 == pc_number[24]) )
        ++pc_count;
     
    if( (pc_number[0] == pc_number[6] ) && ( pc_number[12] == pc_number[18]) && (0 == pc_number[24]) )
        ++pc_count;
       
    if( (pc_number[4] == pc_number[8]) && ( pc_number[12] == pc_number[16] ) && (0== pc_number[20])  )
        ++pc_count;
      
    if(my_count >= 5)
    {
       display(my_count,pc_count);
       finish(1);
    }
    
     if(pc_count >= 5)
     {
            display(my_count,pc_count);
            finish(2);
     }
      
}


void display(int my_count,int pc_count)

{
    clrscr();

    int bingo[5]={'B','I','N','G','O'};

    printf("\n******************\n");
    printf(" Your Block \n");
    printf("******************\n");
    
    for(int i = 0 ; i < 25 ; i++)
    {
        if ((i%5) == 0 )
            printf("\n-----------------------------\n");
            
        printf("| %d |",my_number[i]);
  
    }
      printf("\n-----------------------------\n\n");
    
    for(int i=0 ;i<=my_count;i++)
          printf("%c ",bingo[i]);
    
    
    printf("\n------------------------------------------------------------------\n");
    
    printf("\n******************\n");
    printf(" Computer's Block \n");
    printf("******************\n");
    
    for(int i = 0 ; i < 25 ; i++)
    {
        if ((i%5) == 0 )
            printf("\n-----------------------------\n");
            
        printf("| %d |",pc_number[i]);

    }
    printf("\n-----------------------------\n\n");
    
    for(int i=0 ;i<=pc_count;i++)
          printf("%c ",bingo[i]);
          
    

    printf("\nPleas wait for 5 sec  "); 
    for(int a=0; a<5; a++)
            {
                 printf(".");
                 sleep(5);
            }
}

void finish( int i)
{
	int k,j;
	
	clrscr();
	
    if (i ==1)
    {
        loop:
            gotoxy(18,6);printf("|------------------------------------------|");
            gotoxy(18,7);printf("|               YOU WIN  ...!!!            |");
            gotoxy(18,8);printf("|------------------------------------------|\n\n");
            for ( i=1;i<=10;i++)
            {
                for(  k=1;k<=49-i;k++)
                       printf(" ");
                       
                int  cal=(i*2)-1;

                for(  j=1;j<=cal;j++)
                        printf("*");
                
                printf("\n");
            }
            
            printf("\nWhich angle is best ??\n");
            sleep(1);
            clrscr();
            
            gotoxy(18,6);printf("|------------------------------------------|");
            gotoxy(18,7);printf("|               YOU WIN  ...!!!            |");
            gotoxy(18,8);printf("|------------------------------------------|\n\n");
            for ( i=10;i>=1;i--)
                {
                    for( k=1;k<=49-i;k++)
                        printf(" ");
                        
                    int cal=(i*2)-1;
                    
                    for( j=1;j<=cal;j++)
                        printf("*");
                       
                    printf("\n");
                }
                
            printf("\nWhich angle is best ??\n");
            sleep(1);
            clrscr();
            
            goto loop;
    }
    printf("\nBetter Luck next time ...!\n");
}





