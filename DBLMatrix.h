/* Nama				: Wildan Setya Nugraha */
/* NIM				: 211511032 */
/* Kelas			: D3-1A */
/* Tanggal			: 18 - 19 Maret 2022 */
/* Tanggal Update	: 20 Maret 2022 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define Nil NULL
#define Info(P) (P)->Info
#define Baris(P) (P)->Baris
#define Kolom(P) (P)->Kolom
#define Kanan(P) (P)->Kanan
#define Bawah(P) (P)->Bawah
#define First(L) (L).First
#define Last(L) (L).Last
#define MaxBaris(L) (L).MaxBaris
#define MaxKolom(L) (L).MaxKolom
#define MaxMatrix 100
#define MinMatrix 1


typedef int data;
typedef struct tElmtList *address;
typedef struct tElmtList{
	data Info;
	data Baris;
	data Kolom;
	address Kanan;
	address Bawah;
} ElmtList;

typedef struct matrix{
	address First;
	address Last;
	int MaxBaris;
	int MaxKolom;
} matrix;

address Head[MaxMatrix];


/*-----------------------------------------------OPERASI-OPERASI MATRIX-------------------------------------------------------*/
void tambahMatrix(matrix *M1, matrix *M2);
void kurangMatrix(matrix *M1, matrix *M2);
void kaliMatrix(matrix *M1, matrix *M2);

/*---------------------------------MENGAMBIL ISI DATA MATRIX DALAM DOUBLE LINKED LIST----------------------------------------*/
int getDataMatrix(matrix *M, data baris, data kolom);

/*-------------------------------------------------DOUBLE LINKED LIST--------------------------------------------------------*/
void CreateListMatrix(matrix *M);
bool isEmptyMatrix(matrix M);
address Alokasi(data X, int baris, int kolom);
void buatElemenMatrix(matrix *M, data X, data baris, data kolom);
void inputElemenMatrix(matrix *M);

/*------------------------------------MEMBUAT / MENGAMBIL NILAI MAXBARIS ATAU MAXKOLOM---------------------------------------*/
void setOrdo(matrix *M1, matrix *M2);
int getMaxBaris(matrix M);
int getMaxKolom(matrix M);

/*------------------------------------------------TAMPILAN KE LAYAR----------------------------------------------------------*/
void display(matrix *M, char* s);
void exitScreen();
void loadingScreen();












