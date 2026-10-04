#include<stdio.h>
//fuction to calculate square of a number
int calSquare(int n);

int main(){
    int n;
    printf("enter no : ");
    scanf("%d",&n);
    printf("square is : %d",calSquare(n));
    return 0;

}
int calSquare(int n){
    return n*n;
}