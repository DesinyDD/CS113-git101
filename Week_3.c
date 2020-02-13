1. Function Definition (การนิยามฟังก์ชัน)
รูปแบบของการนิยามฟังก์ชัน
    return-value-type function-name (parameter-list)
    {
       declarations
   
       statement
       statement
       :
    }
Function header and Function body
C compiler เป็น One-pass compiler
2. Function Prototypes
รูปแบบของฟังก์ชัน prototype
    return-value-type function-name (parameter-list);
มีลักษณะเหมือน function header ของ function definition
สามารถละชื่อตัวแปรได้ แต่ละประเภทข้อมูลไม่ได้
ทำไมเราต้องมีการใช้ function prototypes
3. Standard Library Functions and Math Library Functions
ฟังก์ชัน printf, scanf และ getchar เป็นตัวอย่างของฟังก์ชันที่อยู่ใน standard library functions
ฟังก์ชัน sqrt, exp และ log เป็นตัวอย่างของฟังก์ชันที่อยู่ใน math library functions
หากโปรแกรมของเรามีการใช้ฟังก์ชันเหล่านี้ เวลาคอมไพล์โปรแกรม เราจำเป็นต้องคอมไพล์ (link) โปรแกรมของเราเข้ารวมกับโค้ดของฟังก์ชันเหล่านี้ (gcc มีโค้ดของฟังก์ชันกลุ่มนี้อยู่ในไลบรารีที่ถูกติดตั้งไว้แล้วตอนที่เรารัน pacman -S gcc-libs)
โค้ดของ standard library functions ถูกเก็บอยู่ใน /usr/lib/libc.a
โค้ดของ math library functions ถูกเก็บอยู่ใน /usr/lib/libm.a
ลองใช้คำสั่ง nm /usr/lib/libc.a | grep "T _"
ปกติ gcc จะ link ฟังก์ชันใน standard library ให้เราเองโดยอัตโนมัติ โดยที่เราไม่ต้องระบุ option ใน gcc เพิ่มเติม
แต่ฟังก์ชันใน math library จะไม่ได้ถูก link ในอัตโนมัติ โดยเราต้องระบุ -lm เพิ่มเข้าไปตอนเรียกใช้ gcc 
หากเราต้องการใช้ฟังก์ชันใน math library เราควรต้อง #include <math.h> ด้วย
ฟังก์ชัน sin(), cos(), sqrt(), log(), pow(), exp(), floor(), ceil(), fmod()
   #include <math.h>
   main ()
   {  float c, d, f;

      c = 13.0;
      d = 3.0;
      f = 4.0;

      printf("c + d * f         = %.2f\n", c + d * f);
      printf("sqrt of c + d * f = %.2f\n", sqrt(c + d * f));
   }
4. Return Values
ฟังก์ชันจะต้องส่งค่ากลับ หรือไม่ก็ส่งกลับในรูปของ void
เราใช้ void เพื่อบอกคอมไพเลอร์ว่าฟังก์ชันนี้ไม่มีการส่งค่าใดๆ กลับไปยังผู้เรียก
ต.ย.
    return 5;
    return (x > 5);
    return (myFunction());
ต.ย.
    int isOdd(int val)
    {
       return val % 2;
    }
 
    int isEven(int val)
    {
       return !isOdd(val);
    }

    main ()
    {  int value;

       printf("Enter an Integer Value: ");
       scanf("%d", &value);

       if (isEven(value))
          printf("%d is an even number\n", value);
       else
          printf("%d is not an even number\n", value);
    }
เมื่อโปรแกรมทำงานจนไปเจอคำสั่ง return ที่ผู้ในฟังก์ชัน การทำงานของโปรแกรมจะกลับไปทำงานต่อจากจุดที่ฟังก์ชันถูกเรียกใช้
5. Using Functions as Parameters to Functions
ค่าที่ได้จากการเรียกใช้ฟังก์ชันสามารถส่งผ่านไปเป็นพารามิเตอร์ของอีกฟังก์ชันได้
ต.ย.
    long triple(long val)
    {
       return 3 * val;
    }
 
    long square(long val)
    {
       return val * val;
    }
 
    long cube(long val)
    {
       return val * val * val;
    }
 
    main ()
    {  long answer, my_value;
 
       my_value = 2l;
       answer   = triple(square(cube(my_value)));
       printf("Answer = %ld\n", answer);
    }
6. Recursion (การเรียกซ้ำ)
ฟังก์ชันสามารถเรียกใช้ตนเองได้ ซึ่งเรียกว่า recursion
การเรียกตนเองสามารถอยู่ในรูป direct และ indirect
สิ่งที่ควรรู้คือ เมื่อฟังก์ชันเรียกตนเอง การเรียกจะสำเนาฟังก์ชัน (เช่น ตัวแปร local) ขึ้นมาอีกชุด โดยเป็นอิสระจากการถูกเรียกในครั้งแรก 
ต.ย.
Factorial ของเลขจำนวนเต็มบวก n ซึ่งปกติเขียนอยู่ในรูป n! (อ่านว่า "n factorial") เป็นผลคูณของ 
    n * (n-1) * (n-2) * ... * 1

    long factorial(long n)
    {
       if (n == 0)
          return 1;
       else
          return n * factorial(n-1);
    }

    int main()
    {  long n;

       do {
          printf("Enter n: ");
          scanf("%ld", &n);
          if (n < 0)
             printf("n is a negative value, please re-enter\n");
       } while (n < 0);
       printf("%ld! = %ld\n", n, factorial(n)); 
    }
Fibonacci Series 
    1, 1, 2, 3, 5, 8, 13, 21, 34 ...

    long Fib(long n)
    {
       if (n <= 2)
          return 1;
       else
          return Fib(n-1) + Fib(n-2);
    }
ลองปรับโค้ดให้ปราศจากการเรียกซ้ำ แต่ใช้การวนซ้ำแทน
sum.c, triangle.c, hi5.c
7. Scope Rules (ขอบเขตและช่วงชีวิตของตัวแปร)
ในบางบริเวณของโปรแกรม ตัวแปรที่ถูกกำหนดขึ้นอาจถูกเข้าถึงได้ และเมื่อออกนอกบริเวณดังกล่าว ตัวแปรนั้นอาจไม่สามารถถูกเข้าถึงได้


7.1 Local Variables 

ตัวแปรที่ถูกประกาศไว้อยู่ภายในตัวฟังก์ชัน รวมถึงตัวแปรพารามิเตอร์ของฟังก์ชัน จะเป็นตัวแปร local ซึ่งสามารถถูกใช้งานได้เพียงภายในฟังก์ชันที่ถูกประกาศไว้
ต.ย.
    float func_1(int param1, float param2)
    {
       float result;

       result = param1 * param2;
       return result;
    }

    int main()
    {  int cnt;
 
       for (cnt=1; cnt <= 10; cnt++) {
          int sum=0;

          sum += cnt;
          printf("%2d) %d\n", cnt, sum);
       }
    }


7.2 Global Variables 

ตัวแปรที่ถูกประกาศไว้นอกฟังก์ชันเป็นตัวแปร global ซึ่งสามารถถูกเข้าถึงได้จากฟังก์ชันต่างๆ รวมถึงฟังก์ชัน main ได้
หากตัวแปร local มีชื่อซ้ำกับตัวแปร global แล้ว การแก้ไขค่าในตัวแปร local จะไม่ได้มีผลกระทบกับค่าของตัวแปร global
    int value = 10;
 
    void func_1(int value)
    {
       value *= 2;
       printf("value = %d\n", value);
    }


 7.3 Storage Classes 

จากที่ผ่านมา นอกจากการที่ตัวแปรมี ชื่อ ประเภท และค่า ได้แล้ว  ภาษา C ยังกำหนดให้ผู้ใช้สามารถกำหนด storage class ให้กับตัวแปร ใน 4 ลักษณะ ผ่านการใช้ keyword auto, register, extern, และ static เพื่อช่วยกำหนดช่วงชีวิตในการเก็บข้อมูลของตัวแปรใน memory
storage class 4 ประเภทนี้ สามารถแบ่งออกเป็น 2 storage duration ซึ่งคือ automatic storage duration และ static storage duration
auto และ register ใช้กำหนดตัวแปรที่เป็น automatic storage duration  ซึ่งก็คือ ตัวแปรเหล่านี้จะถูกกำหนดขึ้นมาใน memory เมื่อโปรแกรมเข้าไปทำงานใน block ที่ถูกแปรเหล่านี้ถูกประกาศขึ้น และเมื่อโปรแกรมออกจาก block ตัวแปรเหล่านี้จะไม่อยู่ใน memory อีกต่อไป
ตัวแปร local เป็นตัวแปรที่อยู่ใน automatic storage duration โดย default ดังนั้นการใช้ keyword auto จึงไม่เป็นการจำเป็น ซึ่งเรามักจะไม่ค่อยเห็น auto ปรากฏอยู่ในโค้ดโปรแกรม
ส่วน register เป็นการแจ้งให้คอมไพเลอร์ได้ทราบว่าเราต้องการเก็บค่าตัวแปรนี้ไว้ใน register เพื่อความเร็วในการเข้าถึงตัวแปร ดังนั้นหากระบบมี register เหลือใช้ คอมไพเลอร์ก็จะจัดสรร register ให้กับโปรแกรมได้ใช้งาน
    int main()
    {  auto int i;
       int j;   /* local variables have automatic storage by default */
       register int k;
 
       for (i=j=k=0; k < 500000000; k++) {
          double l=0;

          l += k;
       }
    }
extern และ static ใช้กำหนดตัวแปรที่เป็น static storage duration  ซึ่งก็คือ ตัวแปรเหล่านี้จะถูกกำหนดขึ้นมาใน memory ตั้งแต่เมื่อโปรแกรมเริ่มทำงาน และจะอยู่ใน memory จนกว่าโปรแกรมจะสิ้นสุดการทำงาน ดังนั้นเมื่อโปรแกรมเริ่มต้นทำงานตัวแปรจะเริ่มเก็บค่าข้อมูล และเก็บต่อไปจนกว่าโปรแกรมจะทำงานสิ้นสุด
ตัวแปร global และชื่อฟังก์ชันถูกกำหนดให้เป็น extern โดย default
    int result;
 
    void func_1(int result)
    {  extern float another_global_var;
 
       result *= 2;
       printf("inside func_1: result = %d\n", result);
       printf("%f\n", another_global_var);
    }
 
    float another_global_var = 0.5;
 
    int main ()
    {  
       result = 10;
       func_1(2);
       printf("inside main: result = %d\n", result);
    }
หากตัวแปร local ถูกประกาศโดยใช้ static ซึ่งอยู่ภายในฟังก์ชัน ตัวแปรนั้นจะถูกเข้าถึงได้จากภายในฟังก์ชันเท่านั้น แต่ตัวแปรนั้นจะยังคงค่าและอยู่ใน memory แม้ว่าการทำงานของโปรแกรมจะออกจากฟังก์ชันนั้นไปแล้ว
7.4 Dynamic Storage Duration

พื้นที่เก็บข้อมูล (ตัวแปร?) สำหรับ dynamic storage duration สามารถถูก allocate ขึ้นมาได้ตามความต้องการของโปรแกรมขณะที่โปรแกรมกำลังทำงานอยู่
7.5 รายละเอียดที่น่าสนใจ 

เรื่องตัวแปร global เก็บไว้ที่ไหน
เรื่อง stack และ heap 1   เรื่อง stack และ heap 2
8. Separate Compilation (การคอมไพล์แยกส่วน)
ส่วนของการนิยามฟังก์ชันและการเรียกใช้ไม่จำเป็นต้องถูกคอมไพล์ในเวลาเดียวกัน และสามารถแยกอยูู่่กันคนละไฟล์ได้ รวมถึงตัวแปร global และการเข้าถึงค่าตัวแปรนั้นด้วย
โค้ดของโปรแกรม main.c:
     int global = 10;
 
     int main()
     {  extern int my_sqr(int);
 
        printf("value returned from my_sqr = %d\n", my_sqr(5));
     }
โค้ดของโปรแกรม func.c:
     int my_sqr(int arg)
     {  extern int global;
 
        printf("inside my_sqr(): global = %d\n", global);
 
        return arg * arg;
     }
วิธีการคอมไพล์
$ gcc -c main.c                   # คำสั่งนี้จะสร้าง main.o 
$ gcc -c func.c                   # คำสั่งนี้จะสร้าง func.o 
$ gcc main.o func.o -o main.exe   # คำสั่งนี้จะลิงก์ main.o และ func.o เข้าด้วยกัน
9. การใช้ make
ไฟล์ Makefile จะบรรจุกฎต่างๆ ที่ใช้ในการสร้าง อาทิ object file หรือ executable file
การสร้างกฎ
   target: dependency
   -->tab-->คำสั่งที่ใช้ในการสร้าง target
10. Random Number Generator
rand () เป็นฟังก์ชันใน C standard library ที่ใช้ในการสร้างเลขสุ่มที่เป็นจำนวนเต็มที่อยู่ระหว่าง 0 และ RAND_MAX  ซึ่ง RAND_MAX เป็นค่าคงที่ที่ถูกกำหนดไว้ให้แล้วใน <stdlib.h>
ในโปรแกรม เวลามีการเรียกใช้ rand () หลายๆ ครั้ง ค่าที่ฟังก์ชันนี้ส่งกลับมาจะได้ตัวเลขจำนวนเต็มที่แตกต่างกันออกไป
โดยปกติแล้ว ในการรันโปรแกรมในแต่ละครั้ง ชุดเลขสุ่มที่โปรแกรมได้รับจากฟังก์ชันจะเป็นชุดเลขสุ่มที่เหมือนกัน แต่ถ้าหากเราต้องการชุดเลขสุ่มที่แตกต่างกันออกไป เราจำเป็นต้องเรียก srand() หนึ่งครั้งเพื่อกำหนดค่า seed ให้กับ random number generator ก่อนที่เราจะเรียกใช้ rand() ต่อไป
     #include <stdio.h>
     #include <stdlib.h>
 
     int main()
     {  int i;
 
        srand(10);
 
        for (i=0; i < 10; i++)
           printf("%d\n", rand()%6+1);
     }