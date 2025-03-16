#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int *set){ // print all value of the set
    for(int i = 0 ; i < 20; i++)
        printf("%d ", set[i]);
    printf("\n");
}

void all(int *set){ // S = { 1, 2, ... , 20}
    for(int i = 0; i < 20; i++ ){
        set[i] = i + 1;
    }
}

void empty(int *set){ // set all value to 0

    for(int i = 0; i<20; i++){
        set[i] = 0;
    }
}

void add(int *set, int num){ // add a value to set

    int have = 0;
    
    for(int i = 0; i < 20; i++){ // check whether num is in the set
        if(set[i] == num){
            have = 1;
            break;
        }
    }

    if(have == 0){ // num is not in the set
        for(int i = 0; i < 20; i++){
            if(set[i] == 0){
                set[i] = num; // add num to set
                break;
            }
        }
    }
}

void remove_func(int *set, int num){ // remove num in the set
    for(int i = 0 ; i < 20; i++){
        if(set[i] == num){
            set[i] = 0;
            break;
        }
    }
}

void check(int *set, int num){ // check whether num is in the set
    int have = 0;

    for(int i = 0 ; i < 20; i++){
        if(set[i] == num){
            have = 1;
            break;
        }
    }

    if(have == 1) printf("1\n");
    else printf("0\n");    
}

void toggle(int *set, int num){ // check and remove or add num in the set
    int have = -1;

    for(int i = 0 ; i < 20; i++){
        if(set[i] == num){
            have = i; // store index in 'have'
            break;
        }
    }

    if(have > -1){ // if num is in the set
        set[have] = 0;
    }
    else{ // if num is not in the set
        for(int i = 0 ; i < 20; i++){
            if(set[i] == 0){
                set[i] = num;
                break;
            }
        }
    }
}
    
int main(void)
{
    int calNum;
    scanf("%d", &calNum);

    int S[20] = {0};

    for(int i=0; i<calNum; i++){
        char array[10];
        int num;
        scanf("%s", array);
        if(strcmp(array, "all") == 0){
            all(S);
            continue;
        }
        else if(strcmp(array, "empty") == 0){
            empty(S);
            continue;
        }

        scanf("%d", &num);

        if(strcmp(array, "add") == 0){
            add(S, num);
            continue;
        }

        else if(strcmp(array, "check") == 0){
            check(S, num);
            continue;
        }

        else if(strcmp(array, "remove") == 0){
            remove_func(S, num);
            continue;
        }

        else if(strcmp(array, "toggle") == 0){
            toggle(S, num);
            continue;
        }
    }

    return 0;
}