#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int** createMasive(int, int);
void printMassive(int**, int, int);
void enterMasiveValue(int**, bool, int, int);
void deleteMasive(int**, int, int);


int main()
{
	printf("Программа для работы с массивом\n\n");

	int** array = NULL;			 /// Объявление пустого указателя на указатель, который будет использоваться для объявления динамического массива
	int lenght = 0;              /// Переменная хранящая длинну массива
	int height = 0;              /// Переменная хранящая ширину массива
	bool wasEntered = false;     /// Переменная отвечающая за проверку наличия массива

	int menu = 0;				 /// Переменная выбора пункта меню
	do
	{
		printf("\n1. Ввод элементов массива\n");
		printf("2. Обработка элементов массива\n");
		printf("3. Вывод массива на экран\n");
		printf("0. Выход\n\n");
		printf("Выберите пункт меню:");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
		{
			printf("Для заполнения массива случайными значениями - 1\n");
			printf("Для ввода значения с клавиатуры - 2\n");
			printf("Для отмены - 0\n");

			int podmenu = 0;
			scanf("%d", &podmenu);/// Дополнительное меню с выбором способа ввода массива
			switch (podmenu)
			{
			case 1:
			{
				if (wasEntered)	                                                /// Освобождение памяти перед создание нового массива
				{
					deleteMasive(array, height, lenght);
				}

				printf("Введите длинну масива: ");
				scanf("%d", &lenght);                                    /// Ввод длинны массива
				printf("\nВведите ширину массива: ");
				scanf("%d", &height);                                    /// Ввод ширины массива

				array = createMasive(height, lenght);

				enterMasiveValue(array, false, height, lenght);

				break;
			}
			case 2:																/// Заполнение массива с клавиатуры
			{
				if (wasEntered)	                                                /// Освобождение памяти перед создание нового массива
				{
					deleteMasive(array, height, lenght);
				}

				printf("Введите длинну масива: ");
				scanf("%d", &lenght);  										/// Ввод длинны массива
				printf("\nВведите ширину массива: ");
				scanf("%d", &height);

				array = createMasive(height, lenght);

				enterMasiveValue(array, true, height, lenght);

				break;
			}
			case 0: break;
			default: printf("Неизвестный пункт меню\n");
			}
			wasEntered = true;							/// После заполнения массива, присвыиваем переменной, отвечающей за проверку ввода массива, значение true
			break;
		}
		case 2:
		{
			if (wasEntered)
			{
				int minValue = array[0][0];				/// Переменная хранящее наибольшее найденное значение элемента массива, для поиска наибольшего значеня
				int heightMin = 0;                      /// Переменная, хранящая номер строки, в которой находится минимальное значение
				int lenghtMin = 0;      				/// Переменная, хранящая номер столбца в котором находится минимальное значение

				for (int h = 0; h < height; h++)
				{
					for (int l = 0; l < lenght; l++)
					{
						if (array[h][l] < minValue)
						{
							minValue = array[h][l];
							heightMin = h;
							lenghtMin = l;
						}
					}
				}

				if ((heightMin == 0) && (lenghtMin == 0))
				{
					printf("Ничего менять не нужно\n");
					printMassive(array, height, lenght);
					break;
				}
				else
				{
					printMassive(array, height, lenght);
					if (heightMin != 0)
					{
						printf("Меняем местами строку %d и строку 1\n", heightMin + 1);
						for (int i = 0; i < lenght; i++)
						{
							int tempValue = array[heightMin][i];
							array[heightMin][i] = array[0][i];
							array[0][i] = tempValue;
						}
						printMassive(array, height, lenght);
					}
					if (lenghtMin != 0)
					{
						printf("Меняем местами столбец %d и столбец 1\n", lenghtMin + 1);
						for (int i = 0; i < height; i++)
						{
							int tempValue = array[i][lenghtMin];
							array[i][lenghtMin] = array[i][0];
							array[i][0] = tempValue;
						}
						printMassive(array, height, lenght);
					}
				}
			}
			else
			{
				printf("Сначала нужно создать массив\n");
			}
			break;
		}
		case 3:
		{
			if (wasEntered)
			{
				printMassive(array, height, lenght);
			}
			else
			{
				printf("Сначала нужно создать массив\n");
			}
			break;
		}
		case 0:
		{
			void deleteMasive(array, height, lenght);

			break;
		}
		default: printf("Неизвестный пункт меню\n");
		}
	} while (menu != 0);
	return 0;
}


void printMassive(int** masive, int height, int lenght)
{
	for (int h = 0; h < height; h++)
	{
		for (int l = 0; l < lenght; l++)
		{
			printf("  Arr[%d][%d]=%d  ", h + 1, l + 1, masive[h][l]);
		}
		printf("\n");
	}
	printf("\n\n");
}

int** createMasive(int height, int lenght)
{
	int** masive = (int**)malloc(height * sizeof(int*));
	for (int i = 0; i < height; i++)
	{
		masive[i] = (int*)malloc(lenght * sizeof(int));
	}

	return(masive);
}

void enterMasiveValue(int** masive, bool userEnter, int height, int lenght)
{
	if (userEnter)
	{
		printf("Ввод значений масива: \n");
		for (int h = 0; h < height; h++)
		{
			for (int l = 0; l < lenght; l++)
			{
				printf("Arr[%d][%d]= ", h + 1, l + 1);
				scanf("%d", &masive[h][l]);
			}
		}
	}
	else
	{
		for (int h = 0; h < height; h++)
		{
			for (int l = 0; l < lenght; l++)
			{
				masive[h][l] = rand();
			}
		}
	}
}

void deleteMasive(int** masive, int height, int lenght)
{
	for (int i = 0; i < height; i++)
	{
		free(masive[i]);
	}
	free(masive);
	masive = NULL;
}


