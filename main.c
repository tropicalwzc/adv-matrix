//thanks for inspiration of my linear algebra teacher
//so,it is much easier get the answer of most calculation
#include <stdio.h>
#include <float.h>
#include "zero.h"

int main()
{

typedef double F ;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ data enter part
    int spider[1]={};
    int RN,CN;
    double determinants ;
    GH: printf("welcome to matrix calculate \n") ;
    printf("enter total row number: \n")  ;
    scanf("%d",&RN) ;//ÐÐ

    printf("\n enter total column number: \n") ;
     scanf("%d",&CN);//ÁÐ

    printf("\n please enter your number from left to right,up to down \n ") ;

    int couter=0;

    int B ;
    B=RN-1 ;

    F square[10][11]={} ;
    F fakes[10][11]={} ;

    int row,column ;
    int rowworker ;
    F *jpointer;
    int *hpointer ;
    int hh ;
    for(row=0;row<RN;row++)
    {
        for (column=0;column<CN;column++)
           {

         hh= scanf("%lg",&square[row][column])  ;// copy to two document space
            jpointer=&fakes[row][column] ;
            *jpointer=square[row][column];

           }
           printf("\n") ;
    }
    row=0;
    column=0;
    printf(" \n ////////////////////////////////////////////////////////////////////////////////////////// \n " );
 for(row=0;row<RN;row++)
    {

        for (column=0;column<CN;column++)
          {
              printf("< %1.3lg >",fakes[row][column])  ;
          }
printf("\n") ;

    }
printf(" \n ////////////////////////////////////////////////////////////////////////////////////////// \n " );
    //**********************************************************************************//first line

    int i,k ;
for(row=0;row<RN;row++)
{
    if(square[row][0]==0)//confirm the first line
    {
        rowworker=row;
        for(i=0;i<CN;i++)
        {
            jpointer=&fakes[B][i];
            *jpointer=square[rowworker][i];
            jpointer=&fakes[rowworker][i];
            *jpointer=square[B][i];
        }

        i=0;
        B--;
    }
}
  for(row=0;row<RN;row++)
    {

        for (column=0;column<CN;column++)
          {
              printf("< %1.3lg >",fakes[row][column])  ;
          }
printf("\n") ;

    }
printf(" \n ////////////////////////////////////////////////////////////////////////////////////////// \n " );
//**************************************************************************************//second cut zero
F getr(double ad,double bd ,double xd);
F x,a,b;
a=fakes[0][0];
for (i=1;i<RN;i++)//i is number of row
{
    b=fakes[i][0];
   if  (b!=0)
  {
   x=(-b)/a ;
   jpointer=&fakes[i][0];
   *jpointer=0 ;
   for(k=1;k<CN;k++)//k is number of column
   {
       jpointer=&fakes[i][k];
       *jpointer=getr(fakes[0][k],fakes[i][k],x);
   }
   if (b==0)
    continue ;
  }

}
zero(fakes,spider);
//_____________________________________________________________________________
  for(row=0;row<RN;row++)
    {

        for (column=0;column<CN;column++)
          {
              printf("< %1.3lg >",fakes[row][column])  ;
          }
printf("\n") ;

    }
printf(" \n ////////////////////////////////////////////////////////////////////////////////////////// \n " );
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//part three pivot founder
 for(row=0;row<RN;row++)
    {
        for (column=0;column<CN;column++)
           {

            jpointer=&square[row][column] ;
            *jpointer=fakes[row][column];

           }
          printf("\n");
    }
//copy fakes !
int m,iu,kh ;

for (k=1;k<CN;k++)
{
    couter =0 ;
    for(i=k;i<RN;i++)
    {
        if (fakes[i][k]==0)
            couter++ ;
        if (fakes[i][k]!=0)// according to the theory that whether the number is zero from k to i
        {
          zero(fakes,spider);


// change other member
            a=fakes[i][k];//a is pivot
for (iu=i+1;iu<RN;iu++)//i is number of row
{
    b=fakes[iu][k];
   if  (b!=0)
  {
   x=(-b)/a ;
   jpointer=&fakes[iu][k];
   *jpointer=0 ;
   for(kh=i+1;kh<CN;kh++)//k is number of column
   {
       jpointer=&fakes[iu][kh];
       *jpointer=getr(fakes[i][kh],fakes[iu][kh],x);
   }

  }
else
    continue ;
         }

        }

    }
}

 for(row=0;row<RN;row++)
    {

        for (column=0;column<CN;column++)
          {
              printf("< %1.3lg >",fakes[row][column])  ;
          }
printf("\n") ;

    }
printf(" \n ////////////////////////////////////////////////////////////////////////////////////////// \n " );
// put all zero line to the end
 for(row=0;row<RN;row++)
    {
        for (column=0;column<CN;column++)
           {

            jpointer=&square[row][column] ;
            *jpointer=fakes[row][column];

           }
           printf("\n") ;
    }
    // copy fakes again
couter=0;
B=RN-1 ;
for(row=0;row<RN;row++)
{
    for(k=0;k<CN;k++)
{
    if (fakes[row][k]!=0)
        couter++ ;
}
    if(couter==0)//confirm the all 0 line
    {
        rowworker=row;
        for(i=0;i<=RN;i++)
        {
            jpointer=&fakes[B][i];
            *jpointer=square[rowworker][i];
            jpointer=&fakes[rowworker][i];
            *jpointer=square[B][i];
        }

        i=0;
        B--;
    }
    couter=0 ;
}
for(row=0;row<RN;row++)
    {
        for (column=0;column<CN;column++)
           {

            jpointer=&square[row][column] ;
            *jpointer=fakes[row][column];

           }
           printf("\n") ;
    }
    // copy fakes
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

B=RN-1 ;
int top[10]={} ;
F container[10]={};
for(i=0;i<RN;i++)
{couter =0;
    for(k=0;k<CN;k++)
    {
        if(fakes[i][k]==0)
           {
              couter++ ;
           }
            else
                break ;
            }
            jpointer=&container[i];
            *jpointer=couter ;

            }
    //  how many zero are there in each row

for (i=0;i<RN;i++)
{couter=0;
    for(k=0;k<RN;k++)
    {
        if (container[i]-container[k]>0)
        {
            couter++ ;// the more zero the bigger couter will be
        }
    }
    hpointer=&top[i];
    *hpointer =couter ;
    if(i==0)
        continue ;
    if(top[i]-top[i-1]==0)
    {
        hpointer=&top[i];
        *hpointer =couter+1 ;
    }




}
// each row zero quantities order in top
for(i=0;i<RN;i++)
{
    printf("  %d  ",top[i]);
}
//
int gn ;
for(i=0;i<RN;i++)
{    gn=top[i];
    for(k=0;k<CN;k++)
      {
           jpointer = &fakes[gn][k];
           *jpointer= square[i][k];
      }
}
determinants=1 ;

if(CN==RN)
{
    for(i=0;i<CN;i++)
 {
   determinants*=fakes[i][i];
 }
 if(spider[0]%4==2)
    determinants=-determinants ;

 printf("\ndeterminants is : %lf  spider is : %d\n",determinants,spider[0]);
}

printf("complex form of matrix is : \n")  ;
 for(row=0;row<RN;row++)
    {

        for (column=0;column<CN;column++)
          {
              printf("< %1.3lg >",fakes[row][column])  ;
          }
printf("\n") ;

    }
printf(" \n ////////////////////////////////////////////////////////////////////////////////////////// \n " );
//###########################################################################
for(row=0;row<RN;row++)
    {
        for (column=0;column<CN;column++)
           {

            jpointer=&square[row][column] ;
            *jpointer=fakes[row][column];

           }
           printf("\n") ;
    }
    // copy new
    F a1,b1;
    int h,s;
    for(i=RN;i>0;i--)
    {

        for(k=1;k<CN;k++)
        {
            if(fakes[i][k]==0)// 1
            continue ;
              a1=fakes[i][k];
              couter=1 ;

          if (couter==1)
           {

            for(h=i-1;h>=0;h--)// 2
            {
                if(fakes[h][k]!=0)
               {
                  b1=fakes[h][k];
                   x=-b1/a1;
                   for (s=CN-1;s>0;s--)// (  )  (h,s)
                   {
                       jpointer=&fakes[h][s];
                       *jpointer=getr(fakes[i][s],fakes[h][s],x);
                   }
                   }
            }

           }
           break ;

    }
    }
// back finish
 for(row=0;row<RN;row++)
    {

        for (column=0;column<CN;column++)
          {
              printf("< %1.3lg >",fakes[row][column])  ;
          }
printf("\n") ;

    }
printf(" \n ////////////////////////////////////////////////////////////////////////////////////////// \n " );
// become the simplest number
 for(row=0;row<RN;row++)
    {
        for (column=0;column<CN;column++)
           {

            jpointer=&square[row][column] ;
            *jpointer=fakes[row][column];

           }
            printf("\n");
    }
    //copy
couter=0 ;
int z,v,po ;
F y ;
int n ;

for(n=0;n<RN;n++)
{
    for(m=0;m<CN;m++)
    {
        y=(int)fakes[n][m];
        if (fakes[n][m]- y !=0)
        { goto ASD ;}

    }
}


for(i=0;i<RN;i++)

{


    for (z=30;z>2;z--)
    {
     for (v=0;v<CN;v++)
    {
            if ((int)fakes[i][v]%z==0)
            {couter++ ;}
                }
if (couter==CN)
{
    for(po=0;po<CN;po++)
    {
        jpointer=&fakes[i][po];
        *jpointer=square[i][po]/z;
            }
}
couter=0;
    }


}


ASD:


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// data export part
zero(fakes,spider);
      for(row=0;row<RN;row++)
    {

        for (column=0;column<CN;column++)
            printf( "[ %2.3lf ]",fakes[row][column] ) ;
printf("\n") ;
    }
printf("\n \n");
printf(" copyright belongs to tropical wzc");
printf("\n please enter any number more than 1 to continue,less than 1 to quit \n ") ;
printf("enter the next matrix's quantities of row now \n");
int en1 ;
scanf("%d ",&en1) ;
if(en1==1)
   {
      return 0;
   }

goto GH ;

}




