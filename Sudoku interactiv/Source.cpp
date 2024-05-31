#include <iostream>
#include <ctime>
#include <algorithm>

class Sudoku
{
private:
	int** matrice;
	int vector[10] = { 0 };
	int** solutie;
public:
	void vectorul()
	{
		/*std::cout << "Da ti valori de la 1 la 9 aleator\n";
		for (int i = 1; i <= 9; i++)
			std::cin >> vector[i];*/
		for (int i = 1; i <= 9; ++i)
		{
			vector[i] = i;
		}
		std::random_shuffle(vector + 1, vector + 10);
	}
	void alocareMatrice()
	{
		matrice = new int* [9];
		for (int i = 0; i < 9; i++)
		{
			matrice[i] = new int[9];
			for (int j = 0; j < 9; j++)
				matrice[i][j] = 0;
		}
	}
	void afisareSudoku()
	{
		for (int i = 0; i < 9; i++)
		{
			if (i == 3 || i == 6)
				std::cout << "-------------------" << '\n';
			for (int j = 0; j < 9; j++)
			{
				if (j == 3 || j == 6)
					std::cout << "|";
				std::cout << matrice[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	void afisareSolutie()
	{
		for (int i = 0; i < 9; i++)
		{
			if (i == 3 || i == 6)
				std::cout << "-------------------" << '\n';
			for (int j = 0; j < 9; j++)
			{
				if (j == 3 || j == 6)
					std::cout << "|";
				std::cout << solutie[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	bool verificare(int n, int m, int numar)
	{
		for (int i = 0; i < n; i++)
			if (numar == matrice[i][m])
				return false;
		for (int i = 0; i < m; i++)
			if (numar == matrice[n][i])
				return false;
		int startLinie = n - n % 3;
		int startColoana = m - m % 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (numar == matrice[startLinie + i][startColoana + j])
					return false;
			}
		}
		return true;
	}
	bool findEmptyCell(int& i, int& j)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (matrice[i][j] == 0)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool solveSudoku()
	{
		int i, j;
		if (!findEmptyCell(i, j))
		{
			return true;
		}
		for (int k = 1; k <= 9; k++)
		{
			if (verificare(i, j, vector[k]))
			{
				matrice[i][j] = vector[k];
				if (solveSudoku())
				{
					return true;
				}
				else
					matrice[i][j] = 0;
			}
		}
		return false;
	}
	void eliminare()
	{
		solutie = new int* [9];
		for (int i = 0; i < 9; i++)
		{
			solutie[i] = new int[9];
			for (int j = 0; j < 9; j++)
				solutie[i][j] = matrice[i][j];
		}
		int alegere;
		std::cout << "Alege nivelul e dificultate: 1.usor, 2. mediu, 3. greu\n";
		std::cin >> alegere;
		switch (alegere)
		{
		case 1:
		{
			int eliminare = rand() % 6 + 43;
			for (int i = 0; i < eliminare; i++)
			{
				int row = rand() % 9;
				int coloana = rand() % 9;
				solutie[row][coloana] = 0;
			}
			break;
		}
		case 2:
		{
			int eliminare = rand() % 5 + 50;
			for (int i = 0; i < eliminare; i++)
			{
				int row = rand() % 9;
				int coloana = rand() % 9;
				solutie[row][coloana] = 0;
			}
			break;
		}
		case 3:
		{
			int eliminare = rand() % 3 + 56;
			for (int i = 0; i < eliminare; i++)
			{
				int row = rand() % 9;
				int coloana = rand() % 9;
				solutie[row][coloana] = 0;
			}
			break;
		}
		default:
			std::cout << "Valoare invalida\n";
			eliminare();
		}
	}
	void completare()
	{
		int greseli = 0;
		while (matrice != solutie)
		{
			int i, j, val;
			std::cout << "Introduceti valoarea ";
			std::cin >> val;
			std::cout << "Pe linia ";
			std::cin >> i;
			std::cout << "Pe coloana ";
			std::cin >> j;
			if (matrice[i - 1][j - 1] == val)
			{
				solutie[i - 1][j - 1] = val;
				afisareSolutie();
			}
			else
			{
				std::cout << "Ai gresit! Incearca iar\n";
				greseli++;
			}
		}
		std::cout << "Felicitari! Ai rezolvat Sudokul! Numarul de greseli:";
		std::cin >> greseli;
	}
};
int main()
{
	srand(time(NULL));
	Sudoku sudoku;
	sudoku.alocareMatrice();
	sudoku.vectorul();
	sudoku.solveSudoku();
	sudoku.eliminare();
	sudoku.afisareSolutie();
	sudoku.completare();
}