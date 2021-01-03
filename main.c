#include <stdio.h>
#include "QueueString.h"
#include <stdlib.h>
#include <string.h>
#include "myconio.h"
#include <conio.h>

void semaf()
{
    gotoxy(10,1);
    printf("%c",196);// -
    gotoxy(9,2);
    printf("%c",179);// |
    gotoxy(9,3);
    printf("%c",179);// |
    gotoxy(9,4);
    printf("%c",179);// |
    gotoxy(10,5);
    printf("%c",238);// -
    gotoxy(11,2);
    printf("%c",179);// |
    gotoxy(11,3);
    printf("%c",179);// |
    gotoxy(11,4);
    printf("%c",179);// |
}

int main (void)
{
    Queue *queue;
    Initialize(&queue);
    int i = 0, t=51;

    char elem[5] = {169,223,223,169};
    char aux[5];
    getch();
    semaf();

    while(t!=0)
    {
        for(i=6; i>0; i--)
        {
            textcolor(4);//RED
            gotoxy(10, 2);
            printf("%c",178);
            gotoxy(15,6);
            textcolor(15);//WHITE
            fflush(stdin);
            enqueue(&queue,elem);
            viewQueue(queue);
            Sleep(1000);
        }
        system("cls");
        semaf();
        for(i=3; i>0; i--)
        {
            if(!isEmpty(queue))
            {
                textcolor(2); //GREEN
                gotoxy(10, 4);
                printf("%c",178);
                gotoxy(15,6);
                textcolor(15); //WHITE
                strcpy(aux,dequeue(&queue));
                viewQueue(queue);
                Sleep(1000);
                system("cls");
                semaf();
            }
            else
            {
                i=0;
                system("cls");
            }
        }
        system("cls");
        semaf();
        for(i=2; i>0; i--)
        {
            if(!isEmpty(queue))
            {
                textcolor(14); //YELLOW
                gotoxy(10, 3);
                printf("%c",178);
                gotoxy(15,6);
                textcolor(15); //WHITE
                strcpy(aux,dequeue(&queue));
                viewQueue(queue);
                Sleep(1000);
                system("cls");
                semaf();
            }
            else
            {
                i=0;
                system("cls");
            }
        }
    }
}

