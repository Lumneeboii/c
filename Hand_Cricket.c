/* 

Author : Prahlad J Shenoy.(Lumnee boii)
Mentor : ShivaShanker.
College: Jaya Engneering College.

*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void instruction();
int batting(int player);
int bowlling(int  player);

int main()
{
    clrscr();
    
    srand(time(0));
    
    int toss,toss_result,uresult,cresult,ball,run,total_run,a,my_run,pc_run,player;
    
    printf("----------------------------------------------------------------");
    printf("\n\t\t $$$  Welcome to Hand cricket game  $$$\n");
    printf("----------------------------------------------------------------\n");
    
    int get ;
    
    printf("Press..\f 1 :: Play.\n\t2 :: How to play??.. \n\t3 :: exit.\n");
    scanf("%d",&get);
    
    if (get == 1)
        goto start;
    
    else if (get == 2)
         instruction();
    
    else if (get == 3)
        exit(1);

	
    start:
        
        printf("\nEnter the number of player's : ");
        scanf("%d",&player);
        
        loop:
        
            printf("\n ####   TOSS   ###  \f Choose head(0) or tail(1)........");
          
            scanf("%d",&toss);
        
            if( (toss != 0) && (toss !=1) )  
            {
                printf("\n * you enter wrong chioose. * \t(Press 0 for head and 1 for tail)\n");
                goto loop;
            }
        
        toss_result=rand()%1;
      
        printf("\nThe result is :%d\n",toss_result);
        
        if (toss_result == toss)
            printf("\nYou Won the toss..:-)\n");
        else
        {
            printf("\nYou Loss the toss..:-(\n");
            getch();
        }
        
        
        if(toss==toss_result)
            {
                printf("Chose battind(0) or bowling(1) ");
                scanf("%d",&uresult);
                cresult=uresult;
                goto flow;
            }
        else
            {
                cresult=rand()%1;
                goto flow;
            }
        flow:
            {
                if(cresult==0)
                 {
                   my_run=batting(player);
                   total_run=0;
                   pc_run=bowlling(player);
                  }
                else
                {
                    pc_run=bowlling(player);
                    total_run=0;
                    my_run=batting(player);
                } 
                if (my_run>pc_run)
                 printf("\n\nYou was WIN  by %d run\n \t well played buddy",my_run-pc_run);
                else
                 printf("\n\nYou was Loss by %d run\n \t well played buddy",pc_run-my_run);
                 
            }
        getch();
}

void instruction()
{
    int get;
    clrscr();
    gotoxy(18,6);printf("|------------------------------------------|");
    gotoxy(18,7);printf("|            How to PLAY..??               |");
    gotoxy(18,8);printf("|------------------------------------------|\n\n");
    
    printf("  ** INSTRUCTION ** \n\n\n");
    
    printf("* Select number of player do you want to play.\n* Choose head or tail in toss section.\n* If you win the toss then select batting or bowling.\n* During batting enter the number between 0 to 6 ,that your run .\n* And same process in bowling.\n* At end the maxming score will win the match.\n\n");
   
   loop:
       
        printf("\n\n\t** Press 1 For  main menu  **");
        scanf("%d",&get);
         
         if (get ==1)
              main();
         else
         {
            printf("\n * you enter wrong chioose. * \n");
            goto loop;
         }
        
 
}
int batting(int player)
{
    srand(time(0));
    
        int run,ball,total_run=0,count=1;
        clrscr();
        
        printf("\n *****************************");
        printf("\n Your are batting .....!");
        printf("\n *****************************\n");
        printf("Start batting \t");
        while (player)
        {
            while (1)
            {
                scanf("%d",&run);
                if(run==0 || run==1 || run==2 || run==3 || run==4 || run==5 || run==5 || run==6)
                {
                    ball=rand()%7;
                    if(run==0 && count>4)
                        {
                             run=ball;
                             goto ball ;
                             ++count;
                         }
                    if(run==ball)
                        {
                            printf("\n###############################");
                            printf("\n Oii....You are out!");
                            printf("\n###############################\n");
                            break;
                        }
                    else
                        {
                            ball:
                                
                                total_run+=run;
                                printf("\n*  %d  and total run  %d *\n",run,total_run);
                        }
                        
                }
                
                else
                    printf("** out of limt   **\t [Limit is From : 0 To : 6]\n");
            
            }
            --player;
            printf("\n:::::::::::::::::::::::::::::::::::::::::::");
            printf("\n Ho no only %d player is remained",player);
            printf("\n:::::::::::::::::::::::::::::::::::::::::::\n");
            
        }
        printf("\n------------------------------\n");
        printf("Your Total run is : %d .\n",total_run);
        printf("\n------------------------------\n");
        
        return total_run;
}

int bowlling(int  player)
{
    srand(time(0));
    
    int run,ball,total_run=0,count=1;
     
    clrscr();
     
    printf("\n *****************************");
    printf("\n You are bowling.....!");
    printf("\n *****************************\n");
    printf("Start bowling \t");
    
    while(player)
    {
        while(1)
            {
                scanf("%d",&ball);
                if(ball==0 || ball==1 || ball==2 || ball==3 || ball==4 || ball==5 || ball==5 || ball==6)
                {
                    run=rand()%7;
                    
                    if(ball==0 && count>4)
                         {
                             ball=run;
                             goto run;
                             ++count;
                         }
                    
                    if(run==ball)
                        {
                            printf("\n###############################");
                            printf("\n\tha ha ha.. Blowed..!");
                            printf("\n###############################\n");
                            break;
                        }
                        else
                        {
                            run:
                            total_run+=run;
                            printf("\n * %d and total run  %d  *\n",run,total_run);
                            
                        }
            
                } 
                else
                    {
                        printf("\n** No Ball **");
                        total_run++;
                    }
                    
            }
            
            --player;
            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::");
            printf(" \nyes! yes! yes! only %d player is remained",player);
            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            
    }
    printf("\n------------------------------");
    printf("\nTotal RUN of pc: %d",total_run);
    printf("\n------------------------------\n");
    return total_run;
}



