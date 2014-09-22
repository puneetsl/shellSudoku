#include <stdio.h>
#include <fcntl.h>
#include "conpsl.h"
typedef struct{
    int mat[9][9];
    int col[9][9];}play;
int main(int argc,char *argv[])
{FILE *f;
    play info,out;
    int h,i,j,r,b,su=0,chk=0,q,w,l,k=0,sud[9][9],value,key,choice,val2,help=0,du1,du2,save[9][9],gothelp[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},checker[9]={1,2,3,4,5,6,7,8,9};
    int tem[9][9][9]={9,0,0,4,0,0,0,6,0,7,0,0,0,2,0,9,0,0,0,5,8,0,0,9,0,0,0,0,6,0,0,3,2,1,7,0,0,0,0,0,5,0,0,0,0,0,8,3,6,1,0,0,2,0,0,0,0,2,0,0,8,5,0,0,0,2,0,9,0,0,0,6,0,1,0,0,0,8,0,0,7,/*1*/
        0,0,2,6,0,7,9,0,0,0,0,0,9,0,8,0,0,0,9,3,0,0,0,0,0,2,6,0,0,4,5,0,3,2,0,0,0,1,0,0,0,0,0,4,0,0,0,5,8,0,2,6,0,0,1,4,0,0,0,0,0,9,2,0,0,0,4,0,6,0,0,0,0,0,7,2,0,1,3,0,0,/*2*/
        0,0,0,0,3,7,0,8,0,9,0,0,0,8,0,3,0,5,0,0,1,0,0,0,0,0,0,7,0,0,0,5,1,6,0,0,2,0,0,7,0,4,0,0,3,0,0,3,9,2,0,0,0,1,0,0,0,0,0,0,9,0,0,3,0,4,0,9,0,0,0,6,0,2,0,4,1,0,0,0,0,/*3*/
        0,0,0,7,0,4,0,0,0,0,0,8,0,2,0,4,0,0,3,0,9,0,0,0,5,0,7,0,0,6,2,0,1,8,0,0,0,7,0,0,0,0,0,9,0,0,0,4,8,0,5,2,0,0,4,0,3,0,0,0,6,0,2,0,0,7,0,8,0,3,0,0,0,0,0,6,0,9,0,0,0,/*4*/
        0,8,0,2,0,6,0,7,0,0,0,5,0,0,0,2,0,0,4,2,0,0,0,0,0,8,3,0,0,0,7,3,8,0,0,0,9,0,0,0,0,0,0,0,8,0,0,0,4,9,2,0,0,0,1,4,0,0,0,0,0,3,9,0,0,8,0,0,0,4,0,0,0,3,0,8,0,7,0,6,0,/*5*/
        0,0,6,0,3,0,0,5,0,3,0,0,0,0,8,6,0,1,0,5,1,6,0,0,0,0,0,0,1,8,4,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,9,1,3,0,0,0,0,0,0,7,2,6,0,8,0,4,1,0,0,0,0,3,0,3,0,0,8,0,7,0,0,/*6*/
        0,0,6,4,0,8,0,3,5,0,0,0,9,0,0,8,0,1,0,0,0,0,7,6,0,0,0,0,3,0,0,0,0,1,0,6,0,0,7,0,0,0,4,0,0,8,0,9,0,0,0,0,5,0,0,0,0,5,9,0,0,0,0,3,0,8,0,0,2,0,0,0,5,4,0,1,0,3,6,0,0,/*7*/
        0,1,0,0,7,3,0,8,0,8,0,3,0,0,0,0,0,5,0,2,0,4,0,0,0,0,0,1,9,0,0,0,0,0,0,2,0,0,7,2,0,1,6,0,0,5,0,0,0,0,0,0,4,3,0,0,0,0,0,4,0,1,0,3,0,0,0,0,0,9,0,7,0,6,0,8,9,0,0,2,0,/*8*/
        1,0,0,0,0,7,0,9,0,0,3,0,0,2,0,0,0,8,0,0,9,6,0,0,5,0,0,0,0,5,3,0,0,9,0,0,0,1,0,0,8,0,0,0,2,6,0,0,0,0,4,0,0,0,3,0,0,0,0,0,0,1,0,0,4,0,0,0,0,0,0,7,0,0,7,0,0,0,3,0,0/*9*/};
    char name[50],ext[5]=".sud";
begi:
    clrscr();
    textcolor(10);
    if(argv[1]!=NULL)
        goto playn;
    gotoxy(50,1);
    gotoxy(20,19);
    printf("To check your solution press 1");
    gotoxy(20,20);
    printf("To play with computer press 2");
    gotoxy(10,21);
    printf("To play from a saved file press 3 - full editor mode");
    gotoxy(4,22);
    printf("To play from a psl corp sudoku puzzel file press 4 - restricted mode");
    
    printf("\n");
    choice=getch();
    clrscr();
    
    switch(choice-48)
    {case 1:
            // checking solution of given sudoku answer
            printf("you have chosen to check your sudoku solution from any external source is correct or not\nI hope your solution is correct\nGoodluck!!");
            getch();
            clrscr();
            for(i=0;i<9;i++)
                for(j=0;j<9;j++)
                {sud[i][j]=0;
                    //assigning values
                }
            //first printing of sudoku
            printf("\n\t\t use arrow key to move cursor\n\t\t press 'c' to chek your solution\n\n");
            printf("\t\t +-----------------------+\n");
            for(i=0;i<9;i++)
            {for(j=0;j<9;j++)
            {if(j%9==0)
                printf("\t\t | ");
                printf("%d ",sud[i][j]);
                if((j+1)%3==0)
                    printf("| ");}
                printf("\n");
                if((i+1)%3==0)
                    printf("\t\t +-----------------------+\n");}
            //printing ends
            
            
            //now insertion of matrix values from user
            for(i=0;i<9;i++)
            {for(j=0;j<9;j++)
            {value=getch();//get the input from user
                
                if(value==27)
                {val2=getch();
                    val2=getch();
                    //forward move
                    if(val2==67)
                    { if(j==8)
                        j=j-1;
                        k=0; }
                    //backward move
                    if(val2==68)
                    {
                        if(j==0)
                            j=j-1;
                        else if(j>0)
                            j=j-2;
                        k=0;
                    }
                    //up movement
                    if(val2==65)
                    { if(i>0)
                        i=i-1;
                        j=j-1;
                        k=0;
                    }
                    //down movement
                    if(val2==66)
                    { if(i<8)
                        i=i+1;
                        j=j-1;
                        k=0;
                    }
                    
                    
                }
                //quit
                else
                    if(value=='c')
                    {goto out;}
                //insertion of numbers
                    else
                        if(value-48>0&&value-48<=9)
                        {
                            sud[i][j]=value-48;
                            k=0;}
                        else
                        {k=1;
                            j=j-1;}
                //printing of sudoku showing with moving cursor
                if(i==8&&j==8)
                    j=j-1;
                clrscr();
                printf("\n\t\t use arrow key to move cursor\n\t\t press 'c' to chek your solution\n\n");
                printf("\t\t +-----------------------+\n");
                for(q=0;q<9;q++)
                {for(w=0;w<9;w++)
                {if(w%9==0)
                    printf("\t\t | ");
                    if(q==(i)&&w==(j+1))
                        printf("/ ");
                    else
                        printf("%d ",sud[q][w]);
                    if((w+1)%3==0)
                        printf("| ");}
                    printf("\n");
                    if((q+1)%3==0)
                        printf("\t\t +-----------------------+\n");}
                printf("\t\t current value at your cursor position:%d",sud[i][j+1]);
                if(k!=0)
                    printf("\ninvalid value!!\nplease try again with diffrent value");
                //printing ends
                
            }
            }
            break;
            
        case 2:
        case2:
            clrscr();
            
            // checking solution of given sudoku answer
            printf("you have chosen to play sudoku\ni know this would be tough\nBut I hope you will play fine\nchoose a number from 1-9 to choose one sudoku \nRemember as the nuber increases sudoku will become tougher to solve\nmake your choice:\n");
        rep:
            key=getch();
            if(key-48<=0||key-48>9)
            {printf("invalid!! try again\n");
                goto rep; }
            
            
            clrscr();
            for(i=0;i<9;i++)
                for(j=0;j<9;j++)
                {
                    sud[i][j]=tem[key-49][i][j];
                    info.mat[i][j]=tem[key-49][i][j];
                    if(tem[key-49][i][j]==0)
                        info.col[i][j]=15;
                    else
                        info.col[i][j]=12;
                    
                    //assigning values
                }
            //first printing of sudoku
            printf("\n\t\t use arrow key to move cursor\n\t\t press 'c' to chek your solution\n\t\t press 'x' for help \npress 's' to save your current sudoku positions to play in future\n\n");
            printf("\t\t +-----------------------+\n");
            for(i=0;i<9;i++)
            {for(j=0;j<9;j++)
            {if(j%9==0)
                printf("\t\t | ");
                printf("%d ",sud[i][j]);
                if((j+1)%3==0)
                    printf("| ");}
                printf("\n");
                if((i+1)%3==0)
                    printf("\t\t +-----------------------+\n");}
            //printing ends
            
            
            //now insertion of matrix values from user
            for(i=0;i<9;i++)
            {for(j=0;j<9;j++)
            {value=getch();//get the input from user
                
                if(value==27)
                {val2=getch();
                    val2=getch();
                    //forward move
                    if(val2==67)
                    { if(j==8)
                        j=j-1;
                        k=0; }
                    //backward move
                    if(val2==68)
                    {
                        if(j==0)
                            j=j-1;
                        else if(j>0)
                            j=j-2;
                        k=0;
                    }
                    //up movement
                    if(val2==65)
                    { if(i>0)
                        i=i-1;
                        j=j-1;
                        k=0;
                    }
                    //down movement
                    if(val2==66)
                    { if(i<8)
                        i=i+1;
                        j=j-1;
                        k=0;
                    }
                    
                    
                }
                //quit
                else
                    if(value=='c')
                    {goto out;}
                    else
                        if(value=='s')
                        {printf("\ngive a name to the file:");
                            gets(name);
                            strcat(name,ext);
                            f=fopen(name,"w");
                            fwrite(&info,sizeof(info),1,f);
                            fclose(f);
                            printf("\nfile saved!!");
                            getch();
                            j=j-1;}
                        else
                            if(value=='x')
                            {if(tem[key-49][i][j]==0)
                            {help=1;
                                du1=i;
                                du2=j;
                                goto out;
                            helpend:
                                help=0;
                                j=j-1;}
                            else
                            {k=2;
                                j=j-1;}}
                //insertion of numbers
                            else
                                if(value-48>=0&&value-48<=9)
                                {if(tem[key-49][i][j]==0)
                                {sud[i][j]=value-48;
                                    info.mat[i][j]=value-48;
                                    k=0;}
                                else
                                    k=2;
                                    if(j==8)
                                        j=j-1;}
                                else
                                {k=1;
                                    j=j-1;}
                //printing of sudoku showing with moving cursor
                if(i==8&&j==8)
                    j=j-1;
                clrscr();
                printf("\n\t\t use arrow key to move cursor\n\t\t press 'c' to chek your solution\n\t\t press 'x' for help\npress 's' to save your current sudoku positions to play in future\n\n");
                printf("\t\t +-----------------------+\n");
                for(q=0;q<9;q++)
                {for(w=0;w<9;w++)
                {if(w%9==0)
                    printf("\t\t | ");
                    if(q==(i)&&w-1==(j))
                    {textcolor(9);
                        printf("%d",sud[q][w]);
                        textcolor(0);
                        printf(" ");
                        textcolor(15);}
                    else
                    {if(tem[key-49][q][w]==0)
                    {textcolor(15);
                        printf("%d ",sud[q][w]);}
                    else
                    {textcolor(12);
                        printf("%d ",sud[q][w]);}
                        textcolor(15);
                    }
                    if((w+1)%3==0)
                        printf("| ");}
                    printf("\n");
                    if((q+1)%3==0)
                        printf("\t\t +-----------------------+\n");}
                printf("\t\t current value at your cursor position:%d",sud[i][j+1]);
                if(k==1)//error no 1
                    printf("\ninvalid value!!\nplease try again with diffrent value");
                if(k==2)//error no 2
                    printf("\nThis value is basic and cannot be changed!!\nBecause it is assigned by the computer ");
                
                //printing ends
                
            }
                
                
                
                
            }
            break;
        case 3:
            // checking solution of given sudoku answer
        playn:
            if(argv[1]!=0)
            {
                f=fopen(argv[1],"r");
                goto conti;
            }
            printf("you have chosen to play sudoku by openinig a file\n");
            puts("enter file path which u want to open:");
            gets(name);
            strcat(name,ext);
            f=fopen(name,"r");
        conti:
            if(f==NULL)
            {puts("\nCannot open source file!! sorry\nBut still you can play from our 9 sudoku puzzels");
                getch();
                goto case2;}
            else
            {
                if(argv[1]==0)
                    puts("file opened!!");
                fread(&out,sizeof(out),1,f);
                fclose(f);
                if(argv[1]==0)
                {printf("press any key to continue....");
                    getch();
                }}
            clrscr();
            for(i=0;i<9;i++)
                for(j=0;j<9;j++)
                {
                    sud[i][j]=out.mat[i][j];
                    //assigning values
                }
            //first printing of sudoku
            printf("\n\t\t use arrow key to move cursor\n\t\t press 'c' to chek your solution\n\t\t press 'x' for help \npress 's' to save your current sudoku positions to play in future\n\n");
            printf("\t\t +-----------------------+\n");
            for(i=0;i<9;i++)
            {for(j=0;j<9;j++)
            {if(j%9==0)
                printf("\t\t | ");
                printf("%d ",sud[i][j]);
                if((j+1)%3==0)
                    printf("| ");}
                printf("\n");
                if((i+1)%3==0)
                    printf("\t\t +-----------------------+\n");}
            //printing ends
            
            
            //now insertion of matrix values from user
            for(i=0;i<9;i++)
            {for(j=0;j<9;j++)
            {value=getch();//get the input from user
                
                if(value==27)
                {val2=getch();val2=getch();
                    //forward move
                    if(val2==67)
                    { if(j==8)
                        j=j-1;
                        k=0; }
                    //backward move
                    if(val2==68)
                    {
                        if(j==0)
                            j=j-1;
                        else if(j>0)
                            j=j-2;
                        k=0;
                    }
                    //up movement
                    if(val2==65)
                    { if(i>0)
                        i=i-1;
                        j=j-1;
                        k=0;
                    }
                    //down movement
                    if(val2==66)
                    { if(i<8)
                        i=i+1;
                        j=j-1;
                        k=0;
                    }
                    
                    
                }
                //quit
                else
                    if(value=='c')
                    {goto out;}
                    else
                        if(value=='s')
                        {printf("\ngive a name to the file:");
                            gets(name);
                            strcat(name,ext);
                            f=fopen(name,"w");
                            fwrite(&out,sizeof(out),1,f);
                            fclose(f);
                            printf("\nfile saved!!");
                            getch();
                            j=j-1;}
                        else
                            if(value=='x')
                            {if(out.col[i][j]!=12)
                            {help=1;
                                du1=i;
                                du2=j;
                                goto out;
                            helpend2:
                                help=0;
                                j=j-1;}
                            else
                            {k=2;
                                j=j-1;}}
                //insertion of numbers
                            else
                                if(value-48>=0&&value-48<=9)
                                {
                                    if(out.col[i][j]!=12)
                                    {sud[i][j]=value-48;
                                        out.mat[i][j]=value-48;
                                        k=0;}
                                    else
                                        k=2;
                                    if(j==8)
                                        j=j-1;}
                                else
                                    k=1;
                //printing of sudoku showing with moving cursor
                if(i==8&&j==8)
                    j=j-1;
                clrscr();
                printf("\n\t\t use arrow key to move cursor\n\t\t press 'c' to chek your solution\n\t\t press 'x' for help\npress 's' to save your current sudoku positions to play in future\n\n");
                printf("\t\t +-----------------------+\n");
                for(q=0;q<9;q++)
                {for(w=0;w<9;w++)
                {if(w%9==0)
                    printf("\t\t | ");
                    if(q==(i)&&w-1==(j))
                    {textcolor(9);
                        printf("%d",sud[q][w]);
                        textcolor(0);
                        printf(" ");
                        textcolor(15);}
                    else
                    {
                        textcolor(out.col[q][w]);
                        printf("%d ",sud[q][w]);
                        textcolor(15);
                    }
                    if((w+1)%3==0)
                        printf("| ");}
                    printf("\n");
                    if((q+1)%3==0)
                        printf("\t\t +-----------------------+\n");}
                printf("\t\t current value at your cursor position:%d\n",sud[i][j+1]);
                if(k==1)//error no 1
                    printf("\ninvalid value!!\nplease try again with diffrent value");
                if(k==2)//error no 2
                    printf("\nThis value is basic and cannot be changed!!\nBecause it is assigned by the computer ");
                
                //printing ends
                
            }
                
                
                
                
            }
            break;
        case 4:
            // checking solution of given sudoku answer
            printf("you have chosen to play sudoku by openinig a file\n");
            puts("enter file path which u want to open:");
            strcat(name,".sudpsl");
            puts(name);
            f=fopen(name,"r");
            if(f==NULL)
            {puts("\ncannot open source file!! sorry\nBut still you can play from our 9 sudoku puzzels\n");
                getch();
                goto case2;}
            else
            {puts("file opened");
                fread(save,sizeof(save),1,f);
                fclose(f);
                printf("press any ket to continue....");}
            getch();
            
            
            clrscr();
            for(i=0;i<9;i++)
                for(j=0;j<9;j++)
                {
                    sud[i][j]=save[i][j];
                    
                    //assigning values
                }
            //first printing of sudoku
            printf("\n\t\t use arrow key to move cursor\n\t\t press 'c' to chek your solution\n\t\t press 'x' for help \npress 's' to save your current sudoku positions to play in future\n\n");
            printf("\t\t +-----------------------+\n");
            for(i=0;i<9;i++)
            {for(j=0;j<9;j++)
            {if(j%9==0)
                printf("\t\t | ");
                printf("%d ",sud[i][j]);
                if((j+1)%3==0)
                    printf("| ");}
                printf("\n");
                if((i+1)%3==0)
                    printf("\t\t +-----------------------+\n");}
            //printing ends
            
            
            //now insertion of matrix values from user
            for(i=0;i<9;i++)
            {for(j=0;j<9;j++)
            {value=getch();//get the input from user
                
                if(value==224||value==0)
                {val2=getch();
                    //forward move
                    if(val2==77)
                    { if(j==8)
                        j=j-1;
                        k=0; }
                    //backward move
                    if(val2==75)
                    {
                        if(j==0)
                            j=j-1;
                        else if(j>0)
                            j=j-2;
                        k=0;
                    }
                    //up movement
                    if(val2==72)
                    { if(i>0)
                        i=i-1;
                        j=j-1;
                        k=0;
                    }
                    //down movement
                    if(val2==80)
                    { if(i<8)
                        i=i+1;
                        j=j-1;
                        k=0;
                    }
                    
                    
                }
                //quit
                else
                    if(value=='c')
                    {goto out;}
                    else
                        if(value=='s')
                        {printf("\ngive a name to the file:");
                            gets(name);
                            f=fopen(name,"w");
                            fwrite(&info,sizeof(info),1,f);
                            fclose(f);
                            printf("\nfile saved!!");
                            getch();
                            j=j-1;}
                        else
                            if(value=='x')
                            {if(save[i][j]==0)
                            {help=1;
                                du1=i;
                                du2=j;
                                goto out;
                            helpend3:
                                help=0;
                                j=j-1;}
                            else
                            {k=2;
                                j=j-1;}}
                //insertion of numbers
                            else
                                if(value-48>=0&&value-48<=9)
                                {if(save[i][j]==0)
                                {sud[i][j]=value-48;
                                    k=0;}
                                else
                                    k=2;
                                    if(j==8)
                                        j=j-1;}
                                else
                                {k=1;
                                    j=j-1;}
                //printing of sudoku showing with moving cursor
                if(i==8&&j==8)
                    j=j-1;
                clrscr();
                printf("\n\t\t use arrow key to move cursor\n\t\t press 'c' to chek your solution\n\t\t press 'x' for help\npress 's' to save your current sudoku positions to play in future\n\n");
                printf("\t\t +-----------------------+\n");
                for(q=0;q<9;q++)
                {for(w=0;w<9;w++)
                {if(w%9==0)
                    printf("\t\t | ");
                    if(q==(i)&&w-1==(j))
                        printf("/ ");
                    else
                    {if(save[q][w]==0)
                    {textcolor(15);
                        printf("%d ",sud[q][w]);}
                    else
                    {textcolor(12);
                        printf("%d ",sud[q][w]);}
                        textcolor(15);
                    }
                    if((w+1)%3==0)
                        printf("| ");}
                    printf("\n");
                    if((q+1)%3==0)
                        printf("\t\t +-----------------------+\n");}
                printf("\t\t current value at your cursor position:%d\n",sud[i][j+1]);
                printf("\t\tearlier value taken from file at this position:%d\n",save[i][j+1]);
                if(k==1)//error no 1
                    printf("\ninvalid value!!\nplease try again with diffrent value");
                if(k==2)//error no 2
                    printf("\nThis value is basic and cannot be changed!!\nBecause it is assigned by the computer ");
                
                //printing ends
                
            }
            }
            break;
            
            
        default:
            printf("not a valid choice !! try again !!");
            getch();
            goto begi;
            break;
    }
out:
    
    //here help starts
    if(help!=0)
    {//checking part started
        //horizontal checking
        su=0;
        for(h=0;h<9;h++) //j from i+1 because to avoid self comparision
        {if(sud[du1][h]!=0)
        {gothelp[su]=sud[du1][h];
            su=su+1;
        }
        }
        //vertical checking
        for(h=0;h<9;h++) //j from i+1 because to avoid self comparision
        {if(sud[h][du2]!=0)
        {gothelp[su]=sud[h][du2];
            su=su+1;
        }
        }
        
        
        
        
        //box checking ie. checking each box
        
        //case 1: when elment is 0,0 ...
        if((du1+1)%3==1&&(du2+1)%3==1)
        {
            gothelp[su]=sud[du1+1][du2+1];
            su=su+1;
            gothelp[su]=sud[du1+1][du2+2];
            su=su+1;
            gothelp[su]=sud[du1+2][du2+1];
            su=su+1;
            gothelp[su]=sud[du1+2][du2+2];
            su=su+1;
        }
        //case 2: element 0,1..
        if(du1%3==0&&du2%3==1)
        {
            gothelp[su]=sud[du1+1][du2-1];
            su=su+1;
            gothelp[su]=sud[du1+1][du2+1];
            su=su+1;
            gothelp[su]=sud[du1+2][du2-1];
            su=su+1;
            gothelp[su]=sud[du1+2][du2+1];
            su=su+1;
        }
        //case 3: element 0,2..
        if(du1%3==0&&du2%3==2)
        {
            gothelp[su]=sud[du1+1][du2-2];
            su=su+1;
            gothelp[su]=sud[du1+1][du2-1];
            su=su+1;
            gothelp[su]=sud[du1+2][du2-2];
            su=su+1;
            gothelp[su]=sud[du1+2][du2-1];
            su=su+1;
        }
        if(du1%3==1&&du2%3==0)
        {
            gothelp[su]=sud[du1-1][du2+1];
            su=su+1;
            gothelp[su]=sud[du1-1][du2+2];
            su=su+1;
            gothelp[su]=sud[du1+1][du2+1];
            su=su+1;
            gothelp[su]=sud[du1+1][du2+2];
            su=su+1;
        }
        //case 5: element 1,1..
        if(du1%3==1&&du2%3==1)
        {
            gothelp[su]=sud[du1-1][du2-1];
            su=su+1;
            gothelp[su]=sud[du1-1][du2+1];
            su=su+1;
            gothelp[su]=sud[du1+1][du2-1];
            su=su+1;
            gothelp[su]=sud[du1+1][du2+1];
            su=su+1;
        }
        //case 6: element 1,2..
        if(du1%3==1&&du2%3==2)
        {
            gothelp[su]=sud[du1-1][du2-2];
            su=su+1;
            gothelp[su]=sud[du1-1][du2-1];
            su=su+1;
            gothelp[su]=sud[du1+1][du2-2];
            su=su+1;
            gothelp[su]=sud[du1+1][du2-1];
            su=su+1;
        }
        //case 7: element 2,0..
        if(du1%3==2&&du2%3==0)
        {
            gothelp[su]=sud[du1-2][du2+1];
            su=su+1;
            gothelp[su]=sud[du1-2][du2+2];
            su=su+1;
            gothelp[su]=sud[du1-1][du2+1]; su=su+1;
            su=su+1;
            gothelp[su]=sud[du1-1][du2+2];
            su=su+1;
            gothelp[su]=sud[du1][du2];
            su=su+1;
        }
        //case 8: element 2,1..
        if(du1%3==2&&du2%3==1)
        {
            gothelp[su]=sud[du1-2][du2-1];
            su=su+1;
            gothelp[su]=sud[du1-2][du2+1];
            su=su+1;
            gothelp[su]=sud[du1-1][du2-1];
            su=su+1;
            gothelp[su]=sud[du1-1][du2+1];
            su=su+1;
        }
        if(du1%3==2&&du2%3==2)
        {
            gothelp[su]=sud[du1-2][du2-2];
            su=su+1;
            gothelp[su]=sud[du1-2][du2-1];
            su=su+1;
            gothelp[su]=sud[du1-1][du2-2];
            su=su+1;
            gothelp[su]=sud[du1-1][du2-1];
            su=su+1;
        }
        //box checking completed
        
        
        
        for(b=0;b<9;b++)
            for(l=0;l<27;l++)
            {if(gothelp[l]!=0)
            {if(checker[b]==gothelp[l])
            {checker[b]=0;
                gothelp[l]=0; }}
            }
        printf("\nyou have got following choices:\n");
        for(b=0;b<9;b++)
        {if(checker[b]!=0)
            printf("%d ",checker[b]);}
        for(b=0;b<9;b++)
            checker[b]=b+1;
        for(b=0;b<27;b++)
            gothelp[b]=0;
        printf("\npress any key to resume...\n");
        r=getch();
        if(r==224||r==0)
            getch();
        if(choice-48==2)
            goto helpend;
        if(choice-48==3)
            goto helpend2;
        if(choice-48==4)
            goto helpend3;
    }
    
    
    
    
    
    
    
    
    
    //checking part started
    //horizontal checking
    for(h=0;h<9;h++)
    {for(i=0;i<9;i++)
    {for(j=(i+1);j<9;j++) //j from i+1 because to avoid self comparision
    {if(sud[h][i]==sud[h][j])
        chk=chk+1;}
    }
    }
    //vertical checking
    for(h=0;h<9;h++)
    {for(i=0;i<9;i++)
    {for(j=(i+1);j<9;j++) //j from i+1 because to avoid self comparision
    {if(sud[i][h]==sud[j][h])
        chk=chk+1;}
    }
    }
    
    
    //box checking ie. checking each box
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            //case 1: when elment is 0,0 ...
            if((i+1)%3==1&&(j+1)%3==1)
            {
                if(sud[i][j]==sud[i+1][j+1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+1][j+2])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+2][j+1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+2][j+2])
                {chk=chk+1;}
            }
            //case 2: element 0,1..
            if(i%3==0&&j%3==1)
            {
                if(sud[i][j]==sud[i+1][j-1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+1][j+1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+2][j-1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+2][j+1])
                {chk=chk+1;}
            }
            //case 3: element 0,2..
            if(i%3==0&&j%3==2)
            {
                if(sud[i][j]==sud[i+1][j-2])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+1][j-1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+2][j-2])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+2][j-1])
                {chk=chk+1;}
            }
            if(i%3==1&&j%3==0)
            {
                if(sud[i][j]==sud[i-1][j+1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-1][j+2])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+1][j+1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+1][j+2])
                {chk=chk+1;}
            }
            //case 5: element 1,1..
            if(i%3==1&&j%3==1)
            {
                if(sud[i][j]==sud[i-1][j-1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-1][j+1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+1][j-1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+1][j+1])
                {chk=chk+1;}
            }
            //case 6: element 1,2..
            if(i%3==1&&j%3==2)
            {
                if(sud[i][j]==sud[i-1][j-2])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-1][j-1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+1][j-2])
                {chk=chk+1;}
                if(sud[i][j]==sud[i+1][j-1])
                {chk=chk+1;}
            }
            //case 7: element 2,0..
            if(i%3==2&&j%3==0)
            {
                if(sud[i][j]==sud[i-2][j+1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-2][j+2])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-1][j+1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-1][j+2])
                {chk=chk+1;}
            }
            //case 8: element 2,1..
            if(i%3==2&&j%3==1)
            {
                if(sud[i][j]==sud[i-2][j-1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-2][j+1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-1][j-1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-1][j+1])
                {chk=chk+1;}
            }
            if(i%3==2&&j%3==2)
            {
                if(sud[i][j]==sud[i-2][j-2])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-2][j-1])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-1][j-2])
                {chk=chk+1;}
                if(sud[i][j]==sud[i-1][j-1])
                {chk=chk+1;}
            }
            //box checking completed
        }
    }
    
    clrscr();
    printf("\n\n\n\n");
    printf("\t\t +-----------------------+\n");
    for(i=0;i<9;i++)
    {for(j=0;j<9;j++)
    {if(j%9==0)
        printf("\t\t | ");
        printf("%d ",sud[i][j]);
        if((j+1)%3==0)
            printf("| ");}
        printf("\n");
        if((i+1)%3==0)
            printf("\t\t +-----------------------+\n");}
    if(chk==0)
        printf("yes!! bingo your solution is absolutly correct");
    else printf("no!! I am so sorry , your solution of sudoku os not correct");
    getch();
    return 0;
}