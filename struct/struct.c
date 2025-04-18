#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int age;
    int roll_no;
    float marks;
};

struct charset {
    char s;
    int i;
};

struct point {
    int x;
    int y;
};

void printPoint(struct point *ponto) {
    printf("%d %d\n", ponto->x, ponto->y);
};

void keyValue(char* s, int* i) {
    scanf("%c %d", s, i);
}

//Podemos passar partes da estrutura como parâmetros de funções

void print(char name[], int age, int roll, float marks) {
    printf("%s %d %d %.2f", name, age, roll, marks);
}

int main (void) {
    struct student s1 = {"Nick", 15, 56, 72.5};
    print(s1.name, s1.age, s1.roll_no, s1.marks);

    // Example 2
    int j;
    struct charset cs;
    keyValue(&cs.s, &cs.i);
    printf("%c %d", cs.s, cs.i);
    return 0;

    // Example 3
    struct point p1 = {21, 45};
    printPoint(&p1);
    return 0;
}