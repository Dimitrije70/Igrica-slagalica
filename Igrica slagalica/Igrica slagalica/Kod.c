#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VELICINA 3

void mesaj(int tabla[VELICINA][VELICINA]);
void inicijalizacija_table(int tabla[VELICINA][VELICINA]);
void prikazi_tablu(int tabla[VELICINA][VELICINA]);
int jeLi_resena(int tabla[VELICINA][VELICINA]);
int pomeri_plocicu(int tabla[VELICINA][VELICINA], int smer);

int main() {
	int tabla[VELICINA][VELICINA];
	char komanda;
	srand(time(NULL));
	inicijalizacija_table(tabla);

	while (!jeLi_resena(tabla))
	{
		system("cls");
		prikazi_tablu(tabla);
		printf("Koristite 'w', 'a', 's', 'd' za pomeranje plocica:");
		scanf(" %c", &komanda);
		pomeri_plocicu(tabla, komanda);
	}

	printf("Cestitamo! Resili ste slagalicu!\n");

	system("pause");
	return 0;
}

//Функција за мешање плочица на табли
void mesaj(int tabla[VELICINA][VELICINA])
{
	int i, j, temp, rand_indeks;
	for (int i = VELICINA * VELICINA - 1; i > 0; i--)
	{
		j = rand() % (i + 1);
		temp = tabla[i / VELICINA][i % VELICINA];
		tabla[i / VELICINA][i % VELICINA] = tabla[j / VELICINA][j % VELICINA];
		tabla[j / VELICINA][j % VELICINA] = temp;
	}
}

 //Функција за иницијализацију табле са бројевима
void inicijalizacija_table(int tabla[VELICINA][VELICINA])
{
	int broj = 1;
	for (int i = 0; i < VELICINA; i++)
	{
		for (int j = 0; j < VELICINA; j++)
		{
			if (i == VELICINA - 1 && j == VELICINA - 1) {
				tabla[i][j] = 0; //Празно поље
			}
			else
			{
				tabla[i][j] = broj++;
			}
		}
	}
	mesaj(tabla);
}

//Функција за приказивање табле
void prikazi_tablu(int tabla[VELICINA][VELICINA])
{
	for (int i = 0; i < VELICINA; i++)
	{
		for (int j = 0; j < VELICINA; j++)
		{
			if (tabla[i][j] == 0) {
				printf("   ");
			}
			else
			{
				printf("%2d ", tabla[i][j]);
			}
		}
		printf("\n");
	}
}

//Функција за проверу да ли је слагалица решена
int jeLi_resena(int tabla[VELICINA][VELICINA])
{
	int broj = 1;
	for (int i = 0; i < VELICINA; i++)
	{
		for (int j = 0; j < VELICINA; j++)
		{
			if (i == VELICINA - 1 == j == VELICINA - 1) {
				return tabla[i][j] = 0;
			}
			if (tabla[i][j] != broj++) {
				return 0;
			}
		}
	}
	return 1;
}

//Функција за пометање плочица
int pomeri_plocicu(int tabla[VELICINA][VELICINA], int smer)
{
	int i, j, temp;
	int prazno_i, prazno_j;
	for (int i = 0; i < VELICINA; i++)
	{
		for (int j = 0; j < VELICINA; j++)
		{
			if (tabla[i][j] == 0) {
				prazno_i = i;
				prazno_j = j;
			}
		}
	}

	switch (smer)
	{
	case 'w': //Горе
		if (prazno_i < VELICINA - 1) {
			temp = tabla[prazno_i][prazno_j];
			tabla[prazno_i][prazno_j] = tabla[prazno_i + 1][prazno_j];
			tabla[prazno_i + 1][prazno_j] = temp;
			return 1;
		}
		break;
	case 's': //Доле
		if (prazno_i > 0)
		{
			temp = tabla[prazno_i][prazno_j];
			tabla[prazno_i][prazno_j] = tabla[prazno_i - 1][prazno_j];
			tabla[prazno_i - 1][prazno_j] = temp;
			return 1;
		}
		break;
	case 'a': //Лево
		if (prazno_j < VELICINA - 1) {
			temp = tabla[prazno_i][prazno_j];
			tabla[prazno_i][prazno_j] = tabla[prazno_i][prazno_j + 1];
			tabla[prazno_i][prazno_j + 1] = temp;
			return 1;
		}
		break;
	case 'd': //Десно
		if (prazno_j > 0) {
			temp = tabla[prazno_i][prazno_j];
			tabla[prazno_i][prazno_j] = tabla[prazno_i][prazno_j - 1];
			tabla[prazno_i][prazno_j - 1] = temp;
			return 1;
		}
		break;
	}
	return 0;
}
