//this header file is made by puneet singh batch b6 6103571
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#if !defined(__COLORS)
#define __COLORS

enum COLORS {
    BLACK,  //0        /* dark colors */
    BLUE,//1
    GREEN,//2
    CYAN,//3
    RED,//4
    MAGENTA,//5
    BROWN,//6
    LIGHTGRAY,//7
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE,
    RESET
};
#endif
#if !defined(__TYPE)
#define __TYPE

enum TYPE {
    SIMPLE,
    BOLD,
    DARK,//2
    UNDERLINE,//3
    HIGHLIGHT,//4
    STRIKETHROUGH
    
};
#endif
void gotoxy(int x, int y)
{    printf("%c[%d;%df",0x1B,y,x);
}
int getch( ) {
    struct termios oldt,
    newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
void clrscr(void)
{system("clear");}

int delay(int a)
{
    int i;
    for(i=0;i<a*150;i++)
    {
        printf("\33\b");
    }
    return 0;
    
}

char *inttostring(int i)
{
    char *ret,temp[10];
    ret=(char*)malloc(10);
    int s,j=0;
    while(i>0)
    {
        s=i%10;
        temp[j]=s+48;
        i=i/10;
        j++;
    }
    temp[j]='\0';
    j=strlen(temp);
    s=j-1;
    j=0;
    for(;s>=0;s--)
    {
        ret[j]=temp[s];
        j++;
    }
    ret[j]='\0';
    return ret;
}
void textbackground(int bcol)
{
    char *command,ofchar[7]="\033[4";
    command=(char*)malloc(30);
    strcat(command,ofchar);
    switch(bcol)
    {
        case 0:
            strcat(command,"0m");//black
            break;
        case 1:
            strcat(command,"4m");//blue
            break;
        case 2:
            strcat(command,"2m");//green
            break;
        case 3:
            strcat(command,"6m");//cyan
            break;
        case 4:
            strcat(command,"1m");//red
            break;
        case 5:
            strcat(command,"5m");//magenta
            break;
        case 6:
            strcat(command,"3m");//brown
            break;
        case 7:
            strcat(command,"7m");//lightgray almost white
            break;
        default:
            strcat(command,"0m");//black
            break;
    }
    printf(command);
}
void textattr(int type)
{
    char *command,ofchar[7]="\033[";
    command=(char*)malloc(30);
    strcat(command,ofchar);
    switch(type)
    {
        case 0:
            strcat(command,inttostring(0));
            break;
        case 1:
            strcat(command,inttostring(1));
            break;
        case 2:
            strcat(command,inttostring(2));
            break;
        case 3:
            strcat(command,inttostring(4));
            break;
        case 4:
            strcat(command,inttostring(7));
            break;
        case 5:
            strcat(command,inttostring(9));
            break;
        default:
            strcat(command,inttostring(0));
            break;
    }
    strcat(command,"m");
    printf(command);
}
void textattrib(int col,int type)
{
    char *command,ofchar[7]="\033[0";
    command=(char*)malloc(30);
    strcat(command,ofchar);
    switch(type)
    {
        case 0:
            strcat(command,inttostring(0));
            break;
        case 1:
            strcat(command,inttostring(1));
            break;
        case 2:
            strcat(command,inttostring(2));
            break;
        case 3:
            strcat(command,inttostring(4));
            break;
        case 4:
            strcat(command,inttostring(7));
            break;
        case 5:
            strcat(command,inttostring(9));
            break;
        default:
            strcat(command,inttostring(0));
            break;
    }
    strcat(command,";");
    switch(col)
    {
        case 0:
            strcat(command,"21m");//black
            break;
        case 1:
            strcat(command,"34m");//blue
            break;
        case 2:
            strcat(command,"32m");//green
            break;
        case 3:
            strcat(command,"36m");//cyan
            break;
        case 4:
            strcat(command,"31m");//red
            break;
        case 5:
            strcat(command,"35m");//magenta
            break;
        case 6:
            strcat(command,"33m");//brown
            break;
        case 7:
            strcat(command,"30m");//gray
            break;
        default:
            strcat(command,"37m");//white
            break;
    }
    
    printf(command);
}
void textcolor(int col)
{
    
    switch(col)
    {
        case 0:
            printf("\033[02;21m");//black
            break;
        case 1:
            printf("\033[02;34m");//blue
            break;
        case 2:
            printf("\033[02;32m");//green
            break;
        case 3:
            printf("\033[02;36m");//cyan
            break;
        case 4:
            printf("\033[02;31m");//red
            break;
        case 5:
            printf("\033[02;35m");//magenta
            break;
        case 6:
            printf("\033[02;33m");//brown
            break;
        case 7:
            printf("\033[01;30m");//gray
            break;
        case 8:
            printf("\033[02;30m");//dark gray
            break;
            //light colors
        case 9:
            printf("\033[00;34m");//blue
            break;
        case 10:
            printf("\033[00;32m");//green
            break;
        case 11:
            printf("\033[00;36m");//cyan
            break;
        case 12:
            printf("\033[00;31m");//red
            break;
        case 13:
            printf("\033[00;35m");//magenta
            break;
        case 14:
            printf("\033[00;33m");//brown
            break;
        default:
            printf("\033[00;37m");//white
            break;
    }
}
