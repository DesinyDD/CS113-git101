#include <stdio.h>
int main()
{
    int x = 100;
    // int q = 0144;       // 0144 ฐานแปด {%o}  = 100
    // int w = 0x64;       // 0x64 ฐานสิบหก {%x} = 100
    // printf("x = %d\n", x);
    // printf("reference of x = %lu\n", &x);     // %lu - unsign long
    // printf("reference of x = %p\n", &x);      // %p แสดงเลขฐาน 16

    // int number[] = {1, 2, 3, 4, 5, 6};
    // // int number[100];
    // // int number[100] = {1, 2, 3, 4, 5, 6};

    // number[100000] = 200;
    // printf("index 1 = %d\n", number[100000]);
    // printf("reference of &number[1] = %p\n", &number[1000]);
    // printf("reference of &number[0] = %p\n", &number[0]);   // number ตัวนี้ เป็น array เก็บ address
    // printf("reference of number = %p\n", number+1);         // บวก 1 ที่ pointer - จะบวกไปเท่ากับขนาดของตัวแปร

    // int number[] = {1, 2, 3, 4, 5, 6};
    // int *ptr = &x;
    // int *arrPtr;
    // arrPtr = number;    // 0x00
    // arrPtr += 3;
    // *arrPtr += 3;
    // printf("arrPtr = %p, *arrPtr = %d\n", arrPtr, *arrPtr);

    // int number[] = {1, 2, 3, 4, 5, 6};
    // for (int *ptr = number; ptr <= &number[5]; ptr++){
    //     printf("[%p] = %d\n", ptr, *ptr);
    // }
    // int *ptr2 = number;
    // for (int i = 0; i < 5; i++){
    //     printf("[%p] = %d\n", ptr2 + i, *(ptr2+i));
    // }

    // char input[100];
    // int count = 0;
    // char c;
    // while ( (c = getchar()) != '\n' )
    // {
    //     input[count] = c;
    //     ++count;
    // }
    // input[count] = '\0';
    // for (char *cPtr = input ; *cPtr != '\0' ; cPtr++)
    // {
    //     printf("%c\n", *cPtr);
    // }
    
    char s[100];
    int i;
    char c;
    scanf("%d=%c=%s", &i, &c, s);
    printf("%d--%c--%s", i, c, s);

}