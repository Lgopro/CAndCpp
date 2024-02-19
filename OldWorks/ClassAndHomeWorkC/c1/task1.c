#include <stdio.h>
#include <stdlib.h>
/*
* Description: prints piramide from this type: *
                                               **
                                               ***
* Input: Type of piramide. size of basis and character that will be printed
* Return: nothing.
* output: piramide.
*/
void Pir1(int _soog,int _basis, char _madpis){
    int i,j;
    for(i=1;i<=_basis;i++){
    for(j=1;j<=i;j++){
    printf("%c", _madpis);
    }
    printf("\n");
    }
}
/*
* Description: prints piramide from this type: ***
                                               **
                                               *
* Input: Type of piramide. size of basis and character that will be printed
* Return: nothing.
* output: piramide.
*/

 void Pir2(int _soog,int _basis, char _madpis){
    int i,j;
    for(i=_basis;i>=1;i--){
    for(j=1;j<=i;j++){
    printf("%c", _madpis);
    }
    printf("\n");
    }
    }
    /*
* Description: prints piramide from this type: ***
                                                *
* Input: Type of piramide. size of basis and character that will be printed
* Return: nothing.
* output: piramide.
*/
void Pir3(int _soog,int _basis, char _madpis){
    int i,j,k=0;
    for(i=0;i<_basis/2+1;i++){
    for(j=0;j<_basis;j++){
    if(j<i)
    printf(" ");
    else if(_basis-j<=i)
    printf(" ");
    else
    printf("%c", _madpis);
    }
    printf("\n");
    }
    }
/*
* Description: prints piramide from this type:  *
                                               ***
* Input: Type of piramide. size of basis and character that will be printed
* Return: nothing.
* output: piramide.
*/
void Pir4(int _soog,int _basis, char _madpis){
    int i,j,k;
    if(_basis%2!=0){
    for(i=0;i<_basis/2+1;i++){
    for(j=1;j<=_basis;j++){
    k=_basis/2+1;
        if(j>=k-i && j<=k+i)
    printf("%c", _madpis);

    else printf(" ");
    }
    printf("\n");
    }
    }
    if(_basis%2==0){
     for(i=0;i<_basis/2;i++){
    for(j=1;j<=_basis;j++){
    k=_basis/2;
        if(j>=k-i && j<=k+1+i)
    printf("%c", _madpis);
    else printf(" ");
    }
    printf("\n");
     }
    }
    }
/*
* Description: prints piramide from this type: *
                                               **
                                               *
* Input: Type of piramide. size of basis and character that will be printed
* Return: nothing.
* output: piramide.
*/
void Pir5(int _soog,int _basis, char _madpis){
int i,j,k;
    if(_basis%2!=0){
    k=_basis/2+1;
     for(i=1;i<=k;i++){
    for(j=1;j<=i;j++){
    printf("%c", _madpis);
    }
    printf("\n");
    }
    for(i=k-1;i>=1;i--){
    for(j=1;j<=i;j++){
    printf("%c", _madpis);
    }
    printf("\n");
    }
    }
    if(_basis%2==0){
   k=_basis/2;
     for(i=1;i<=k;i++){
    for(j=1;j<=i;j++){
    printf("%c", _madpis);
    }
    printf("\n");
    }
    for(i=k;i>=1;i--){
    for(j=1;j<=i;j++){
    printf("%c", _madpis);
    }
    printf("\n");
    }
    }
    }


void Soog(int _soog, int _basis,char _madpis)
{
    if(_soog==1)
      {
      Pir1(_soog,_basis,_madpis);
      }
      if(_soog==2)
      {
      Pir2(_soog,_basis,_madpis);
      }
      if(_soog==3)
      {
      Pir3(_soog,_basis,_madpis);
      }
      if(_soog==4)
      {
      Pir4(_soog,_basis,_madpis);
      }
      if(_soog==5)
      {
      Pir5(_soog,_basis,_madpis);
      }
     printf("\n");
}

void Menu(int _num)
{
int i,soog,basis;
    char madpis;
    do{
    printf("Please enter the type of pyramid from 1 to 5. Enter 0 if you want to exit\n");
    printf("Pyramid 1 type:\n*\n**\n***\n");
      printf("Pyramid 2 type:\n***\n**\n*\n");
      printf("Pyramid 3 trype:\n***\n *\n");
        printf("Pyramid 4 trype:\n *\n***\n");
         printf("Pyramid 5 type:\n*\n**\n*\n");
         printf("Please enter your choise:\n");
    scanf("%d", &soog);
    if(soog<0 || soog>5)
        {
             printf("Wrong input.. please try again\n");
            continue;
        }
    if(soog==0)
        {
            break;
        }
    printf("Please enter the basis godel\n");
    scanf("%d", &basis);
    getchar();
    printf("Please enter the char you want to print\n");
    scanf("%c", &madpis);
    printf("\n");
    Soog(soog,basis,madpis);
    }
     while(soog!=0);
}
int main()
{
    Menu(10);
        return 0;
}
