#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int techniques[4]={2,2,2,2};
int current;


DWORD WINAPI ThreadFun(LPVOID lpparam){
    int curr,i;
    curr=current; 
    

    techniques[curr-1]--;
    
    Sleep(5);
    techniques[curr-1]++;
    
    return 0;
}

void radar_jamming(int *arr,int len){
    /*
This function takes the radar permutation and treats each element as a radar and
the value as radar jamming technique.
For each radar, the function will check if respective jamming technique has any TG
free or not.
If free, then a thread is created which engages the technique generator for 'Pulse
Width' interval of time.
Else no thread will be created
With every event happening, a log will be printed.
*/
    int i,j;
    HANDLE *freeArray;
    
    DWORD id;
    
    freeArray = (HANDLE*)malloc(sizeof(HANDLE)*len);
    for(i=0;i<len;++i){
        if(techniques[arr[i]-1>0]){
            current=arr[i];
            
            freeArray[i]=CreateThread(NULL,0,ThreadFun,0,0,&id);
        }
        else{
               printf("T%d radar techniques not free for radar #(%d)\n",arr[i],i+1);
        }
    }
    

    for(i=0;i<len;++i){
        CloseHandle(freeArray[i]);
    }
}