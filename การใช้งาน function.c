#include <stdio.h>

// ใช้ pointer เข้ามาช่วยในการรับส่ง array (ฟังก์ชันโดยปกติจะไม่สามารถรับส่งค่า array ได้)
// อ้างอิง https://codeforwin.org/c-programming/pass-return-array-function-c
int *sortNumber(int array[], int amount) {
    int temp;
    for(int i = 0; i < amount; i++) {
        for(int j = i + 1; j < amount; j++) {
            if(array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}

void duplicateNumber(int array[], int amount) {
    int temp;
    int count = 1;
    printf("duplicate number:\n");
    for(int i = 0; i < amount; i++) {
        if(temp == array[i]) {
            continue;
        }
        for(int j = i + 1; j < amount; j++) {
            if(array[i] == array[j]) {
                count++;
            }
        }
        printf("%d -> %d\n", array[i], count);
        count = 1;
        temp = array[i];
    }
}

int main() {
    // รับค่าจำนวนความจุของ array
    int amount;
    printf("input amount of array: ");
    scanf("%d", &amount);
    
    // รับค่าจำนวนต่างๆใน array
    int array[amount];
    for(int i = 0; i < amount; i++) {
        printf("input value in array[%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    // ใช้ pointer เข้ามาช่วยในการรับส่ง array (ฟังก์ชันโดยปกติจะไม่สามารถรับส่งค่า array ได้)
    // อ้างอิง https://codeforwin.org/c-programming/pass-return-array-function-c
    int *sortArray = sortNumber(array, amount);

    // แสดงค่าใน array
    printf("sorted array: ");
    for(int i = 0; i < amount; i++) {
        printf("%d ", sortArray[i]);
    }
    printf("\n");

    duplicateNumber(sortArray, amount);
}