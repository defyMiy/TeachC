#include <stdio.h>

void primeNumber(int value) { // function หาจำนวนเฉพาะ รับค่ามาเป็นจำนวณสุดท้ายที่ใช้หาจำนวณเฉพาะ
    int arrayOfPrimeNumber[value]; // สร้าง array สำหรับเก็บจำนวนเฉพาะ
    int positionToInsert = 0; // กำหนดตำแหน่งเริ่มเก็บใน array เท่ากับ 0
    int valueIsPrime = 1; // ตัวแปรที่บอกว่าเป็นจำนวนเฉพาะมั้ย
    for(int i = 2; i < value; i++) { // ลูปวนตัวเลขตั้งแต่ 2 ถึงจำนวนที่รับค่ามาเป็นจำนวณสุดท้ายที่ใช้หาจำนวณเฉพาะ
        for(int j = 2; j < i; j++) { // ลูปหาจำนวณเพาะ
            if(i % j == 0) { // ถ้าตัวตั้ง (i) หารด้วยตัวหารที่เป็นลูปตั้งแต่ (2) ถึง (i-1) ลงตัว
                valueIsPrime = 0; // กำหนดตัวแปรที่บอกว่าเป็นจำนวนนี้เป็นเฉพาะให้เป็น ไม่จริง หรือ 0
                break; // ในเมื่อมันไม่เป็นจำนวนเฉพาะเเล้วจึงไม่มีความจำเป็นต้องหาต่อเลยสั่งหยุด
            }
        }
        if(valueIsPrime == 1) { // จากบรรทัด 9 ถ้าไม่มีตัวเลขไหนหารลงตัวแล้วแสดงว่าตัวเลขนั้นดป็นจำนวนเฉพาะ
            arrayOfPrimeNumber[positionToInsert++] = i; // นำเลขที่เป็นจำนวนเฉพาะเก็บค่าไว้ใน array แล้วตำแหน่ง = ตำแหน่ง + 1
        }
        valueIsPrime = 1; // ตั้งค่าเริ่มต้นให้ตัวต่อไปที่บอกว่าเป็นจำนวนเฉพาะไหมดป็นจริง หรือ 1
    }

    // แสดงค่าทั้งหมดใน array
    printf("prime number from 2 to %d is :", value); 
    for(int i = 0; i < positionToInsert; i++) {
        printf(" %d", arrayOfPrimeNumber[i]);
    }
}

int main() {
    printf("program find prime from 2 to input number");
    printf("\nenter input number: ");
    int num;
    scanf("%d", &num); //รับค่่าตัวเลข
    if(num < 2) { // จำนวนเฉพาะไม่สามารถมีค่าน้อยกว่า 2 ได้
        printf("prime number cannot be less than 2");
    } else {
        primeNumber(num);
    }
}
