// 2048 Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

bool operation(bool continueLoop, char answer, int (&matrix)[4][4]);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int matrix[4][4];
	//int k;
	int rand1, rand2;
	int count;
	//int rowSize, columnSize;
	char answer;
	bool check = true;
	bool continueLoop;

	std::cout << "Welcome to the game!" << std::endl << std::endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = 0;
		}
	}

	matrix[rand() % 4][rand() % 4] = 2;
	while (check) {
		rand1 = rand() % 4;
		rand2 = rand() % 4;
		if (matrix[rand1][rand2] == 0) {
			matrix[rand1][rand2] = 2;
			check = false;
		}
	}

	//srand(time(NULL));

	//matrix[2][3] = 2;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl << std::endl;
	}

	do {
		std::cout << "Enter direction (L for left, R for right, U for up, D for down): " << std::endl;

		std::cin >> answer;

		count = 0;
		continueLoop = false;
		check = true;
		continueLoop = operation(continueLoop, answer, matrix);
		while (check) {
			rand1 = rand() % 4;
			rand2 = rand() % 4;
			if (matrix[rand1][rand2] == 0) {
				matrix[rand1][rand2] = 2;
				check = false;
			}
			else {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (matrix[i][j] != 0) {
							count++;
						}
					}
				}
			}
			if (count >= 16) {
				check = false;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				std::cout << matrix[i][j] << "  ";
			}
			std::cout << std::endl << std::endl;
		}
		// random generator and switch statement goes here
	} while (continueLoop == true);

	return 0;
}

bool operation(bool continueLoop, char answer, int(&matrix)[4][4])
{
	int k;

	switch (answer) {
	case 'L':
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (matrix[i][j] != 0) {
					k = j;
					while (k > 0) {
						k--;
						if (matrix[i][k] != 0 && matrix[i][k] == matrix[i][j]) {
							matrix[i][k] += matrix[i][j];
							matrix[i][j] = 0;
							k = 0;
							continueLoop = true;
						}
						else if (matrix[i][k] == 0 && k == 0) {
							matrix[i][k] = matrix[i][j];
							matrix[i][j] = 0;
						}
						else if (matrix[i][k] != 0) {
							while (k < 3) {
								if (matrix[i][k + 1] == 0) {
									matrix[i][k + 1] = matrix[i][j];
									matrix[i][j] = 0;
								}
								k++;
							}
							k = 0;
						}
					}
				}
				else {
					continueLoop = true;
				}
				//std::cout << matrix[i][j] << "  ";
			}
			//std::cout << std::endl << std::endl;
		}

		break;

	case 'R':
		for (int i = 3; i >= 0; i--) {
			for (int j = 3; j >= 0; j--) {
				if (matrix[i][j] != 0) {
					k = j;
					while (k < 3) {
						k++;
						if (matrix[i][k] != 0 && matrix[i][k] == matrix[i][j]) {
							matrix[i][k] += matrix[i][j];
							matrix[i][j] = 0;
							k = 3;
							continueLoop = true;
						}
						else if (matrix[i][k] == 0 && k == 3) {
							matrix[i][k] = matrix[i][j];
							matrix[i][j] = 0;
						}
						else if (matrix[i][k] != 0) {
							while (k > 0) {
								if (matrix[i][k - 1] == 0) {
									matrix[i][k - 1] = matrix[i][j];
									matrix[i][j] = 0;
								}
								k--;
							}
							k = 3;
						}
					}
				}
				else {
					continueLoop = true;
				}
				//std::cout << matrix[i][j] << "  ";
			}
			//std::cout << std::endl << std::endl;
		}

		break;

	case 'U':
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (matrix[j][i] != 0) {
					k = j;
					while (k > 0) {
						k--;
						if (matrix[k][i] != 0 && matrix[k][i] == matrix[j][i]) {
							matrix[k][i] += matrix[j][i];
							matrix[j][i] = 0;
							k = 0;
							continueLoop = true;
						}
						else if (matrix[k][i] == 0 && k == 0) {
							matrix[k][i] = matrix[j][i];
							matrix[j][i] = 0;
						}
						else if (matrix[k][i] != 0) {
							while (k < 3) {
								if (matrix[k + 1][i] == 0) {
									matrix[k + 1][i] = matrix[j][i];
									matrix[j][i] = 0;
								}
								k++;
							}
							k = 0;
						}
					}
				}
				else {
					continueLoop = true;
				}
				//std::cout << matrix[i][j] << "  ";
			}
			//std::cout << std::endl << std::endl;
		}

		break;

	case 'D':
		for (int i = 3; i >= 0; i--) {
			for (int j = 3; j >= 0; j--) {
				if (matrix[j][i] != 0) {
					k = j;
					while (k < 3) {
						k++;
						if (matrix[k][i] != 0 && matrix[k][i] == matrix[j][i]) {
							matrix[k][i] += matrix[j][i];
							matrix[j][i] = 0;
							k = 3;
							continueLoop = true;
						}
						else if (matrix[k][i] == 0 && k == 3) {
							matrix[k][i] = matrix[j][i];
							matrix[j][i] = 0;
						}
						else if (matrix[k][i] != 0) {
							while (k > 0) {
								if (matrix[k - 1][i] == 0) {
									matrix[k - 1][i] = matrix[j][i];
									matrix[j][i] = 0;
								}
								k--;
							}
							k = 3;
						}
					}
				}
				else {
					continueLoop = true;
				}
				//std::cout << matrix[i][j] << "  ";
			}
			//std::cout << std::endl << std::endl;
		}

		break;

	default:
		std::cout << "Not a valid direction!" << std::endl;
		continueLoop = true;
		break;

	}

	return continueLoop;
}
