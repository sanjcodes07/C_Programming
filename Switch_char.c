#include<stdio.h>
int main(){
    char day = 'f';
    switch(day){
        case 'a' : printf("monday\n");
        break;
        case 'b' : printf("tueday\n");
        break;
        case 'c' : printf("wednesday\n");
        break;
        case 'd' : printf("thrusday\n");
        break;
        case 'e' : printf("friday\n");
        break;
        case 'f' : printf("saturday\n");
        break;
        case 'g' : printf("sunday\n");
        break;
    }
    return 0;
}