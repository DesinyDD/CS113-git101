#include <stdio.h>
int addTen(int x)       // method signature , function phototype
{
    x += 10;
    return x;
}
int addTwenty();        // ประกาศแค่ fuction phototype , โดยประกาศคล้ายตัวแปร
int main()
{
    int x = 90;
    int y = addTen(x);      
    printf("addTen in main = %d\n", y);
    printf("addTwenty in main = %d\n", addTwenty());
}
int x = 2000;           // ตัวแปร local ต้องห้ามลืม ประกาศค่าเริ่มต้น , ตัวแปร global หากลืมประกาศตัวแปรเริ่มต้น คอมพิวเตอร์จะให้ = 0 อัตโนมัต
int addTwenty()         // จากบรรทัดที่ 7 , มาเรียกใช้จากตรงนี้ , pass by value ก็อปค่า x มา , โดยค่า x ไม่เกี่ยวข้องกับตัวที่ส่งมา
{
    x += 20;            // ภาษาซี - ถ้าหาตัวแปร ในฟังก์ชันไม่เจอ จะไปหาจาก global , โดยตัวแปร global ต้องประกาศก่อนฟังก์ชัน , ค่า global x จะกลายเป็น 2020
    return x;
}


int fac(int i)          // function แบบ recursive
{
    if (i == 1)         // return constant , ตัวหยุด
        return 1;
    return i*fac(i-1);  // ตัว loop
}

// bitwise oparater
// 5        => 0101         = 5
// 5 >> 2   => 01           = 1
// 5 << 2   => 010100       = 20
// 5 & 1    => 0101 & 0001  = 1