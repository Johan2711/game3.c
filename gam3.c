/*
 * Game Hitung - versi sederhana
 * Operator : + - x /
 * Soal 1-10  : operand maks 10, skor +5
 * Soal 11-20 : operand maks 30, skor +10
 * Soal 21-30 : operand maks 60, skor +15
 * Game berakhir jika salah 3 kali atau 30 soal selesai.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int skor = 0;
    int salah = 0;
    int i;
    int batas, poin;
    int a, b, hasil, jawaban;
    int pilih;
    int ok;
    int c;
    char op;

    srand(time(NULL));

    printf("=== GAME HITUNG ===\n");
    printf("30 soal, kesempatan salah maksimal 3 kali.\n");
    printf("Jawab pembagian dengan bilangan bulat.\n\n");

    for (i = 1; i <= 30 && salah < 3; i++) {

       
        if (i <= 10) {
            batas = 10;
            poin = 5;
        } else if (i <= 20) {
            batas = 30;
            poin = 10;
        } else {
            batas = 60;
            poin = 15;
        }

        
        pilih = rand() % 4;

        
        a = rand() % batas + 1;
        b = rand() % batas + 1;

        if (pilih == 0) {
            op = '+';
            hasil = a + b;
        } else if (pilih == 1) {
            op = '-';
            if (a < b) {         
                int temp = a;
                a = b;
                b = temp;
            }
            hasil = a - b;
        } else if (pilih == 2) {
            op = 'x';
            hasil = a * b;
        } else {
            op = '/';
            
            hasil = rand() % 10 + 1;      
            b = rand() % (batas / hasil) + 1;
            a = hasil * b;
        }

        printf("Soal %d: %d %c %d = ", i, a, op, b);
        ok = scanf("%d", &jawaban);

     
        while ((c = getchar()) != '\n' && c != EOF) {
        }

        if (ok == 1 && jawaban == hasil) {
            skor = skor + poin;
            printf("Benar! Skor: %d\n\n", skor);
        } else {
            salah = salah + 1;
            printf("Salah! Jawaban benar: %d. Salah: %d/3\n\n", hasil, salah);
        }
    }

    if (salah >= 3) {
        printf("GAME OVER, kesempatan salah habis.\n");
    } else {
        printf("Selamat, semua soal selesai!\n");
    }
    printf("Skor akhir: %d\n", skor);

    return 0;
}