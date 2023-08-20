// รวม array
// เรียงตัวเลข
// นับเลขซ้ำ

#include <stdio.h>
// dict
// 1. array อาเรย์ = ชุดข้อมูล
// 2. %d คือการจองพืนที่ชนิดตัวเลข (integer) เพื่อรับค่า(&ตัวแปร) หรือแสดงผล(ตัวแปร)
// 3. printf("hello world %d", ตัวแปร) แสดงค่าในแท๊กข้อความและตัวแปร
// 4. scanf("%d", &ตัวแปร) รับค่าชนิด integer แล้วเก็บค่านั้นไว้ใน ตัวแปร

int main() { 
    // ประกาศตัวแปรเก็บค่าจำนวนในอาเรย์
    int amount_array_1, amount_array_2;

    // รับค่าจำนวนความจุของอาเรย์ 1 (เก็บได้กี่ค่า)
    printf("input element of array1: ");
    scanf("%d", &amount_array_1);

    // ประกาศตัวเเปรที่ชื่อว่า array1 ที่เก็บค่าได้จำนวน amount_array_1 ค่า
    int array1[amount_array_1];

    // รับค่าจำนวนของ array1 ทั้งหมดโดยใช้ for loop ตั้งแต่ตัวแรก (i = 0) จนถึงตัวสุดท้าย (i = amount_array_1 - 1 )
    // note. การเขียนโปรแกรมโดยทั่วไปการนับเลขจะเริ่มต้นที่ 0 แล้วสิ้นสุดที่ ตัวสุดท้าย - 1 แต่จำนวนยังคงเท่ากับการนับเลขปกติ
    for(int i = 0; i < amount_array_1; i++) {
        printf("Array1[%d]: ", i);
        scanf("%d", &array1[i]);
    }

    // รับค่า array2
    printf("input element of array2: ");
    scanf("%d", &amount_array_2);
    int array2[amount_array_2];
    for(int i = 0; i < amount_array_2; i++) {
        printf("Array2[%d]: ", i);
        scanf("%d", &array2[i]);
    }
    printf("-------------\n");

    // ประกาศตัวแปรความจุของ array3 = ความจุ array1 + ความจุ array2
    int amount_array_3 = amount_array_1 + amount_array_2;
    int array3[amount_array_3];
 
    // note. การนำ array1 และ array2 ไปใส่ไว้ใน array3 สามารถทำได้หลายวิธีแล้วแต่แนวคิด (คำตอบจะได้เหมือนกันแต่วิธีการอาจต่างกัน)
    // ทำ for loop ตั้งแต่เริ่มจนถึง amount_array_1
    for(int i = 0; i < amount_array_1; i++) {
        // นำค่า array1 ไปใส่ไว้ใน array3
        // note. ตัวที่เราต้องการให้เกิดการเปลี่ยนแปลงจะต้องอยู่ด้านซ้ายเสมอ
        array3[i] = array1[i];
    }

    // ทำ for loop ตั้งแต่เริ่ม(ความจุใน array1) จนถึงสุดท้าย(ความจุ array3)
    for(int i = amount_array_1; i < amount_array_3; i++) {
        // นำค่า array2 ไปใส่ไว้ใน array3
        // note. ตัวเลขเริ่มต้นที่จำนวนความจุของ array1 แต่ array2 ต้องเริ่มที่ 0 ดังนั้น array2 ต้องเริ่มที่ i - ความจุของ array1
        array3[i] = array2[i-amount_array_1];
    }

    // ประกาศตัวแปรเพื่อเก็บค่า
    int temp;

    // ตัวแปรใช้สำหรับการ debug (debug Trigger)
    // int debugState = 0;

    // เรียงตัวเลข
    for(int i = 0; i < amount_array_3; i++) {
        for(int j = i + 1; j < amount_array_3; j++) {
            // ถ้าเลขด้านหลังน้อยกว่าเลขด้านหน้า ให้สลับตัวเลขกัน
            if(array3[j] < array3[i]) {
                // สลับตัวเลข
                temp = array3[i];
                array3[i] = array3[j];
                array3[j] = temp;

                // // debug Trigger
                // debugState = 1;
            }
            // // ใช้ debug ตามข้อความที่ส่งให้
            // printf("[%d] = %d, [%d] = %d |", i, array3[i], j, array3[j]);
            // for(int k = 0; k < amount_array_3; k++) {
            //     printf(" %d", array3[k]);
            // }
            // if( debugState == 1 ) {
            //     printf(" Switch %d and %d", array3[j], array3[i]);
            //     debugState = 0;
            // }
            // printf("\n");
        }
        // printf("\n");
    }
    printf("number in array after sorted\nArray3:");
    for(int i = 0; i < amount_array_3; i++) {
        printf(" %d", array3[i]);
    }
    printf("\n");

    // ตัวนับเลขซ้ำเริ่มที่ 1
    int count = 1;

    // หาเลขซ้ำ
    for(int i = 0; i < amount_array_3; i++) {
        // ให้นับค่าแค่ตัวเดียว
        if(temp == array3[i] && i > 0){
            // // debug การข้าม
            // // ค่าในตำแหน่งปัจจุบันซ้ำกับค่าในตำแหน่งก่อนหน้านี้
            // printf("[%d] = %d | ", i, array3[i]);
            // for(int k = 0; k < amount_array_3; k++) {
            //     printf(" %d", array3[k]);
            // }
            // printf(" continue\n\n");

            // ข้าม
            continue;
        }

        // นับค่าซ้ำ
        for(int j = i + 1; j < amount_array_3; j++) {
            if(array3[i] == array3[j]) {
                // count เพิ่มทีละ 1
                count++;

                // // debug trigger
                // debugState = 1;
            }
            // // debug การวนลูปของ i และ j
            // printf("[%d] = %d, [%d] = %d |", i, array3[i], j, array3[j]);
            // for(int k = 0; k < amount_array_3; k++) {
            //     printf(" %d", array3[k]);
            // }
            // if( debugState == 1 ) {
            //     printf(" count number %d amount %d", array3[i], count);
            //     debugState = 0;
            // }
            // printf("\n");
        }
        // printf("\n");

        // แสดงตัวเลขที่ซ้ำ
        printf("%d -> %d\n", array3[i], count);

        // ตั้งค่าเริ่มต้น
        temp = array3[i];
        count = 1;
    }
}
