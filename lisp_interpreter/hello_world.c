#include <stdio.h>

void hello_while();

int main(int argc, char** argv) {
    for (int i=0; i<6; i++){
        puts("Hello big world!");
    }
    int n = 3;
    hello_while(n);
    return 0;
}

void hello_while(int n){
    int i = 0;
    while (i < n) {
        puts("while loop");
        i++;
    }
}
