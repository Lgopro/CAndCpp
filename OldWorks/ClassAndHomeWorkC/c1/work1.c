#include <stdio.h>
#include <stdlib.h>

void Pir1(int _soog,int _basis, char _madpis)
{
    int i,j;
    for(i=1;i<=_basis;i++)
    {
   
    for(j=1;j<=i;j++)
    {
    printf("%c", _madpis);


	} 
    printf("\n");
	}
}

 void Pir2(int _soog,int _basis, char _madpis)
 {
    int i,j;
    for(i=_basis;i>=1;i--)
    {
    for(j=1;j<=i;j++)
    {
    printf("%c", _madpis);

    }
    printf("\n");
    }
}

void Pir3(int _soog,int _basis, char _madpis)
{
    int i,j,k=0;
    for(i=0;i<_basis;i++){
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

void Pir4(int _soog,int _basis, char _madpis)
{
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
    
void Pir5(int _soog,int _basis, char _madpis)
{
	int i,j,k;
	if(_basis%2==0){
	Pir1(1,_basis/2,_madpis);
	Pir2(2,_basis/2,_madpis);
	}
	if(_basis%2!=0){
	Pir1(1,_basis/2+1,_madpis);
	Pir2(2,_basis/2,_madpis);
	}
	
    /*if(_basis%2!=0){
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
    }*/
}

int main()
{
        int i,soog,basis;
        char madpis;
        printf("please enter the type of piramide\n");
        scanf("%d", &soog);
        printf("please enter the basis godel\n");
         scanf("%d", &basis);
        getchar();
         printf("please enter the char you want to print\n");
          scanf("%c", &madpis);
          printf("\n");

      if(soog==1){
      Pir1(soog,basis,madpis);

      }
      if(soog==2){
      Pir2(soog,basis,madpis);

      }
      if(soog==3){
      Pir3(soog,basis,madpis);

      }
      if(soog==4){
      Pir4(soog,basis,madpis);

      }
      if(soog==5){
      Pir5(soog,basis,madpis);

      }

        return 0;
}
