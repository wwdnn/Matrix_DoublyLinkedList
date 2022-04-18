/* Nama				: Wildan Setya Nugraha */
/* NIM				: 211511032 */
/* Kelas 			: D3-1A */
/* Tanggal			: 19 Maret 2022 */
/* Tanggal Update	: 20 Maret 2022 */

#include "DBLMatrix.h"


/*-------------------------------------------------------------------------------------------------------------------*/
void tambahMatrix(matrix *M1, matrix *M2){
	int maxBaris = getMaxBaris(*M1);
	int maxKolom = getMaxKolom(*M1); 
	data baris, kolom;
	data hasil;
	
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t HASIL TAMBAH MATRIX \n");
	printf("\t\t\t\t\t---------------------\n");
	if(isEmptyMatrix(*M1) || isEmptyMatrix(*M2)){
		printf("\n				TIDAK BISA DITAMBAH, PERIKSA ISI MATRIX\n");
	} else {
		for(baris=1; baris<=maxBaris; baris++){
			printf("\t\t\t\t\t      ");
			for(kolom=1; kolom<=maxKolom; kolom++){
				hasil = getDataMatrix(M1, baris, kolom) + getDataMatrix(M2, baris, kolom);
				printf("%2d ", hasil);
			}
			printf("\n"); 
		}
	}
	printf("\n\n\t\t\t\t");
	system("pause");

}

void kurangMatrix(matrix *M1, matrix *M2){
	int maxBaris = getMaxBaris(*M1);
	int maxKolom = getMaxKolom(*M1);
	
	data baris, kolom, hasil;
	
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t HASIL KURANG MATRIX \n");
	printf("\t\t\t\t\t---------------------\n");
	if(isEmptyMatrix(*M1) || isEmptyMatrix(*M2)){
		printf("\n				TIDAK BISA DIKURANG, PERIKSA ISI MATRIX\n");
	} else {
		for(baris=1; baris<=maxBaris; baris++){
			printf("\t\t\t\t\t      ");
			for(kolom=1; kolom<=maxKolom; kolom++){
				hasil = getDataMatrix(M1, baris, kolom) - getDataMatrix(M2, baris, kolom);
				printf("%2d ", hasil);
			}
			printf("\n"); 
		}
	}
	printf("\n\n\t\t\t\t");
	system("pause");
}

void kaliMatrix(matrix *M1, matrix *M2){
	int maxBaris = getMaxBaris(*M1);
	int maxKolom = getMaxKolom(*M1);
	
	data i, j, k, hasil;
	
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t HASIL KALI MATRIX \n");
	printf("\t\t\t\t\t---------------------\n");
	if(isEmptyMatrix(*M1) || isEmptyMatrix(*M2)){
		printf("\n				TIDAK BISA DIKALI, PERIKSA ISI MATRIX\n");
	} else {
		for(i=1; i<=maxBaris; i++){
			printf("\t\t\t\t\t      ");
			for(j=1; j<=maxKolom; j++){
				hasil = 0;
				for(k=1; k<=maxKolom; k++){
					hasil = hasil + (getDataMatrix(M1, i, k) * getDataMatrix(M2, k, j)); 
				}
			printf("%2d ", hasil);
			}
		printf("\n");
		}
	}
	printf("\n\n\t\t\t\t");
	system("pause");

}


/*-------------------------------------------------------------------------------------------------------------------*/
void display(matrix *M, char* s){
	int baris, kolom;

	if(First(*M) == Nil){
		printf("\n\n\t\t\t\t\t MATRIX KOSONG\n");
		
	} else {
		printf("\n\n");
		printf("\t\t\t\t\t    MATRIX %s\n", s);
		printf("\t\t\t\t\t---------------\n");
		
		for(baris=1; baris<=MaxBaris(*M); baris++){
			printf("\t\t\t\t\t    ");
			for(kolom=1; kolom<=MaxKolom(*M); kolom++){
				printf("%2d ", getDataMatrix(M, baris, kolom));
			}
		printf("\n");
		}
	}
	
	printf("\n\n\t\t\t\t");
	system("pause");
}



/*-------------------------------------------------------------------------------------------------------------------*/
int getDataMatrix(matrix *M, data baris, data kolom){
	address Temp1, Temp2;
	
	Temp1 = First(*M);
	Temp2 = Temp1;
	while(Temp1 != Nil){
		if(Baris(Temp1) == baris && Kolom(Temp1) == kolom){
			return Info(Temp1);
		} else {
			Temp1 = Kanan(Temp1);
		}
		
		if (Temp1 == Nil){
			Temp2 = Bawah(Temp2);
			Temp1 = Temp2;
		}
	}
}


/*-------------------------------------------------------------------------------------------------------------------*/
void CreateListMatrix(matrix *M){
	First(*M) = Nil;
	Last(*M) = Nil;
}

bool isEmptyMatrix(matrix M){
	return ((First(M)==Nil) && (Last(M)==Nil));
}

address Alokasi(data X, int baris, int kolom){
	address nodeMatrix;
	
	nodeMatrix = (address) malloc (sizeof(ElmtList));
	
	if(nodeMatrix != Nil){
		Info(nodeMatrix) = X;
		Baris(nodeMatrix) = baris;
		Kolom(nodeMatrix) = kolom;
		Kanan(nodeMatrix) = Nil;
		Bawah(nodeMatrix) = Nil;
		return nodeMatrix;
	} else {
		return Nil;
	}
}


void buatElemenMatrix(matrix *M, data X, data baris, data kolom){
	
	address nodeMatrix;
	data maxBaris = getMaxBaris(*M);

	nodeMatrix = Alokasi(X, baris, kolom);
	
	if(First(*M) == Nil){
		First(*M) = nodeMatrix;
	}	
	if(Head[baris] == Nil){
		Head[baris] = nodeMatrix;
	} else {
		Kanan(Last(*M)) = nodeMatrix; 
	}
	Last(*M) = nodeMatrix;
	
	
	address temp1 = Head[baris-1];
	address temp2 = Head[baris];
	while(temp1 != Nil && temp2 != Nil){
		Bawah(temp1) = temp2;
		temp1 = Kanan(temp1);
		temp2 = Kanan(temp2);
	}
	
}

void inputElemenMatrix(matrix *M){
	data maxBaris = getMaxBaris(*M);
	data maxKolom = getMaxKolom(*M);
	data baris, kolom, X;
				
	printf("\n");
	for(baris=1; baris<=maxBaris; baris++){
		Head[baris]= Nil; 
		for(kolom=1; kolom<=maxKolom; kolom++){
			printf("\t\t\t\tINPUT DATA BARIS KE-%d, KOLOM KE-%d : ",baris, kolom);
			scanf("%d", &X);
			buatElemenMatrix(M, X, baris, kolom);
		}
		printf("\t\t\t\t--------------------------------------\n");
	}
}


/*-------------------------------------------------------------------------------------------------------------------*/
void setOrdo(matrix *M1, matrix *M2){
	int baris, kolom;
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t---------------\n");
	printf("\t\t\t\t\tTENTUIN ORDONYA\n");
	printf("\t\t\t\t\t    DULU YA\n");
	printf("\t\t\t\t\t---------------\n");
	printf("\t\t\t\t\tMAX BARIS : ");
	scanf("%d", &baris);
	printf("\t\t\t\t\tMAX KOLOM : ");
	scanf("%d", &kolom);
	
	if(baris == MinMatrix || baris > MaxMatrix || kolom > MaxMatrix){
		setOrdo(M1, M2);
	} else {
		MaxBaris(*M1) = baris;
		MaxKolom(*M1) = kolom;
	
		MaxBaris(*M2) = baris;
		MaxKolom(*M2) = kolom;
	}
}

int getMaxBaris(matrix M){
	return M.MaxBaris;
}

int getMaxKolom(matrix M){
	return M.MaxKolom;
}



/*-------------------------------------------------------------------------------------------------------------------*/
void exitScreen(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t--------------------\n");
	printf("\t\t\t\t\t TERIMAKASIH BANYAK\n");
	printf("\t\t\t\t\t        YA:))\n");
	printf("\t\t\t\t\t--------------------\n");	

	Sleep(500);
	printf("\t\t\t\t\t      . ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	
}

void loadingScreen(){
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t-----------------------\n");
	printf("\t\t\t\t\t MOHON TUNGGU SEBENTAR\n");
	printf("\t\t\t\t\t          YA:))\n");
	printf("\t\t\t\t\t-----------------------\n");	

	Sleep(500);
	printf("\t\t\t\t\t        . ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
}
