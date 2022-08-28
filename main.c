/*
    PROJECT NAME : To develop radar warning jamming techniques

                            Project Discription
                    -----------------------------------
    1. A pilot is flying a aircraft and suddenly saw there are some unknown radar is
       trying to approach aircraft and pilot is scaring with this then pilot have 
       to deside to share imformation or misguide them. 
    2. Pilot have four radar techniques and each technique has a certain amount of
       techniques available .
    3. We will create a non uniform random array according to weightage of techniques
       and iterate one by one index of random array and create a thread for each technique
       for fixed and constant pulse width.
    4. If specific technique is using we will do techniques number minus 1 and if techniques 
        will come within time interval then we will do techniques number plus 1.
    5. In all process we have to maintain two list one is used list and other is free list.
        If a technique no is completely used at any interval then we have to  print which 
        techniques will not available at which index of random array.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"radar.c"

void swap(int *a,int *b);// swap two number
void nonUniformRandomizationArray(int *arr,int N);/* allocates memory to the arrays and calls the 
                                                      nextPermutation function*/
void createArray(int *it,int n,int N);// makes original array with calculated data frequency
int minimum(int a,int b);

void swap(int *a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void nonUniformRandomizationArray(int *arr,int N){
    /*
PROCEDURE:
Swaping elements after selecting two random indices random number of times
Random number will always be less than size of the list
*/
    int first,second,third,fourth,i,j;
    srand(time(NULL));
    for(i=0;i<N;++i){
        first=rand()%N;
        second=rand()%N;
        third=rand()%N;
        fourth=rand()%N;
        swap(&arr[first],&arr[second]);
        swap(&arr[second],&arr[third]);
        swap(&arr[third],&arr[fourth]);
    }
    for(j=0;j<N;++j){
        printf("%d ",arr[j]);
    }
    printf("\n\n");
    printf("Radar Jamming Technique Start");
     Sleep(1000);
    for(i=0;i<5;++i){
        printf(".");
        Sleep(200);
    }
    printf("\n");
    radar_jamming(arr,N);
}

void createArray(int *it,int n,int N){
    /*
PROCEDURE:
Makes a list of same size as of permutated array and initializes it with ‐1.
Iterates over the original array and find a random position in the newly created list for each
index
of original array and places the element there and finally prints the list after shuffling.
*/
    int *arr=(int*)malloc(sizeof(int)*N);
    int i,j,k=0;
    for(i=0;i<n;++i){
        for(j=0;j<((it[i]*N)/100);++j){
            arr[k++]=i+1;

        }
    }
    printf("\n");
    free(it);
    printf("Non Uniform Random Permutation Of Technique: \n");
     nonUniformRandomizationArray(arr,N);
    free (arr);
}

int minimum(int a,int b){
    if(a>b) return b;
    else return a;
}

int main(){
    int n,N,i,min=100,sum1=0,sum2=0;
    int *it;
    printf("\nEnter the no of techniques : ");
    scanf("%d",&n);
    printf("Enter the Range of permutated array : ");
    scanf("%d",&N);
    it=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;++i){
        printf("Weightage of Technique T%d : ",i+1);
        scanf("%d",it+i);
    }
    for(i=0;i<n;++i){
        if(it[i]!=0){
            min=minimum(min,it[i]);
        }
    }
    for(i=0;i<n;++i){
        sum1+=it[i]/min;
        sum2+=it[i]/10;
    }
    if(sum1==N || sum2==N || N%sum2==0 || N%sum1==0)
        createArray(it,n,N);
    else
        printf("Not Possible");
    return 0;
}