/* Nama		: Wildan Setya Nugraha */
/* NIM		: 211511032 */
/* Kelas	: D3-1A */
/* Tanggal	: 17 Maret 2022 */

#include "DBLMatrix.h"

int main(){
	/* Kamus Data */
	matrix M1, M2;
	int pilihan, pilihan2;
	
	/* Proses */
	loadingScreen();
	setOrdo(&M1, &M2);
	CreateListMatrix(&M1);
	CreateListMatrix(&M2);


	while(1){
		
		menu:
		system("cls");
		
		printf("\t\t\t\t\t---------------\n");
		printf("\t\t\t\t\t ORDO : %d * %d\n", getMaxBaris(M1), getMaxKolom(M1));
		printf("\t\t\t\t\t---------------\n");
		printf("\t\t\t\t1. INSERT VALUE PADA MATRIX PERTAMA\n");
		printf("\t\t\t\t2. INSERT VALUE PADA MATRIX KEDUA\n");
		printf("\t\t\t\t3. DISPLAY MATRIX\n");
		printf("\t\t\t\t4. TAMBAH KEDUA MATRIX\n");
		printf("\t\t\t\t5. KURANGI KEDUA MATRIX\n");
		printf("\t\t\t\t6. KALI KEDUA MATRIX\n");
		printf("\t\t\t\t7. EXIT\n");
		printf("\t\t\t\t-----------------------------------\n");
		printf("\t\t\t\tPILIHAN : ");
		scanf("%d", &pilihan);
	
		switch(pilihan){
			case 1:
				inputElemenMatrix(&M1);
				break;
			case 2:
				inputElemenMatrix(&M2);
				break;
			case 3:
				while(1){
					system("cls");
					printf("\t\t\t\t\t---------------\n");
					printf("\t\t\t\t1. TAMPILKAN MATRIX PERTAMA\n");
					printf("\t\t\t\t2. TAMPILKAN MATRIX KEDUA\n");
					printf("\t\t\t\t3. KEMBALI KE MENU\n");
					printf("\t\t\t\t-----------------------------------\n");
					printf("\t\t\t\tPILIHAN : ");
					scanf("%d", &pilihan2); 
					
					switch(pilihan2){
						case 1:
							display(&M1, "1");
							break;
						case 2:
							display(&M2, "2");
							break;
						case 3:
							goto menu;
							break;
						default:
							printf("\t\t\t\t\tPILIHAN TIDAK ADA\n");
					}
				}				
				break;
				
			case 4:
				tambahMatrix(&M1, &M2);
				
				break;
			case 5:
				kurangMatrix(&M1, &M2);
				break;	
			case 6:
				kaliMatrix(&M1, &M2);				
				break;	
			case 7:
				exitScreen();
				exit(1);
				break;
			default:
				printf("\t\t\t\t\tPILIHAN TIDAK ADA\n");
		}
	}	
	return 0;
}


























