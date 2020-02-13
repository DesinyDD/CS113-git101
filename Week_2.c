#include <stdio.h>
#include <stdlib.h>
char name[5];
int main()
{

    // printf("%s\n", name);
    // int i;
    // scanf("%s %d", name, &i);


    // printf("Enter name :");
    // gets(name);                     // WINDOW PROMT ไม่มีปัญหา
    // printf("name = %s\n", name);    // bash รับ input ก่อน - แล้วค่อยแสดงมาที่เดียว (ทำให้ดูเหมือนว่าผิด!) 


    // gets(name);                     // รับทุกอย่าง กำหนดอะไรไม่ได้ รับข้อมูลจนกว่าจะพบ "\n"
    // fgets(name, 20, stdin);         // กำหนดได้ว่ารับจากไหน รับเท่าไหร่


    char number[5];                    
    // [5] คือ array ขนาด 5 และจองช่องสุดท้ายไว้ให้ "\0" หรือ NULL - แปลว่าเก็บได้แค่ 4
    // Enter เป็นหนึ่งใน Ascii จะถูกจัดเก็บใน Array ด้วย 


    // fgets(number, 5, stdin);        // fgets = file get string
    // int i = atoi(number);           // atoi  = Array to Integer
    // ถ้า i แปลงค่าไม่ได้ จะให้ค่าเป็น 0


    // printf("number = %s, i = %d\n", number, i);


    // char a = getchar();
    // getchar();  //เผื่อหลีกเลี่ยงการรับ Ascii ของ Enter
    // char b = getchar();


    // long l = atol(number);
    // double d = atof(number);


    // puts(number);  //Put String
    // putchar(100); putchar('a');


    // undeclared คือยังไม่ได้ประกาศตัวแปร
    

    int found = 0;          // FALSE
    float isExist = 0.0;    // FALSE
    char isOnline = '\0';   // FALSE
    // แค่ 3 ค่านี้เท่านั้นที่เป็น FALSE - ที่เหลือเป็น TRUE


    // fgets(number, 5, stdin);
    // int i = atoi(number);

    
    // () ใส่เงื่อนไข
    // if (i >= 0 && i <= 10)
    // {
    //     printf("if = %d", i >= 0 && i <= 10);
    // }
    // else if (i <= 50 || !found)
    // {
    //     printf("else");
    // }


    // count++;    // เพิ่มค่าทีหลังคำนวณในบรรทัด
    // ++count;    // เพิ่มค่าก่อนคำนวณในบรรทัด
    fgets(number, 5, stdin);
    int i = atoi(number);
    // int count = 0;
    // while (count < i)
    // {
    //     printf("%d\n", count);
    //     count++;
    // }
    

    // "infinite loop"
    // while (1){}
    // for(;;){}


    for (int j = 0; j < i; j++)
    // ส่วนใหญ่จะทำแบบนี้     
    // stagement 1 - ถูกเรียกครั้งแรก ครั้งเดียว
    // stagement 2 - เงื่อนไข
    // stagement 3 - ต่อจากไม่เข้าเงื่อนไข stagement 2
    {
        printf("%d\n", j);
    }


    // "10%" ใช้แบบนี้ 10.0/100.0
    // คิด 10% จากการคูณด้วย 0.1 มีโอกาสพลาดสูง
}