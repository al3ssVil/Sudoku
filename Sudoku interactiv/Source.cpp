#include <iostream>
#include <ctime>
#include <algorithm>

class Sudoku
{
private:
	int** m_matrix;
	int vector[10] = { 0 };
	int** solution;
public:
	void InitializeVector()
	{
		for (int i = 1; i <= 9; ++i)
		{
			vector[i] = i;
		}
		std::random_shuffle(vector + 1, vector + 10);
	}
	void MatrixAllocation()
	{
		m_matrix = new int* [9];
		for (int i = 0; i < 9; i++)
		{
			m_matrix[i] = new int[9];
			for (int j = 0; j < 9; j++)
				m_matrix[i][j] = 0;
		}
	}
	void DisplaySudoku()
	{
		for (int i = 0; i < 9; i++)
		{
			if (i == 3 || i == 6)
				std::cout << "-------------------" << '\n';
			for (int j = 0; j < 9; j++)
			{
				if (j == 3 || j == 6)
					std::cout << "|";
				std::cout << m_matrix[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	void DisplaySolution()
	{
		for (int i = 0; i < 9; i++)
		{
			if (i == 3 || i == 6)
				std::cout << "-------------------" << '\n';
			for (int j = 0; j < 9; j++)
			{
				if (j == 3 || j == 6)
					std::cout << "|";
				std::cout << solution[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	bool Check(int n, int m, int number)
	{
		for (int i = 0; i < n; i++)
			if (number == m_matrix[i][m])
				return false;
		for (int i = 0; i < m; i++)
			if (number == m_matrix[n][i])
				return false;
		int startRow = n - n % 3;
		int startColumn = m - m % 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (number == m_matrix[startRow + i][startColumn + j])
					return false;
			}
		}
		return true;
	}
	bool FindEmptyCell(int& i, int& j)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (m_matrix[i][j] == 0)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool SolveSudoku()
	{
		int i, j;
		if (!FindEmptyCell(i, j))
		{
			return true;
		}
		for (int k = 1; k <= 9; k++)
		{
			if (Check(i, j, vector[k]))
			{
				m_matrix[i][j] = vector[k];
				if (SolveSudoku())
				{
					return true;
				}
				else
					m_matrix[i][j] = 0;
			}
		}
		return false;
	}
	void Remove()
	{
		solution = new int* [9];
		for (int i = 0; i < 9; i++)
		{
			solution[i] = new int[9];
			for (int j = 0; j < 9; j++)
				solution[i][j] = m_matrix[i][j];
		}
		int choice;
		std::cout << "Choose the difficulty level:\n 1. Easy\n 2. Medium\n 3. Hard\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int remove = rand() % 6 + 43;
			for (int i = 0; i < remove; i++)
			{
				int row = rand() % 9;
				int coloana = rand() % 9;
				solution[row][coloana] = 0;
			}
			break;
		}
		case 2:
		{
			int remove = rand() % 5 + 50;
			for (int i = 0; i < remove; i++)
			{
				int row = rand() % 9;
				int coloana = rand() % 9;
				solution[row][coloana] = 0;
			}
			break;
		}
		case 3:
		{
			int remove = rand() % 3 + 56;
			for (int i = 0; i < remove; i++)
			{
				int row = rand() % 9;
				int coloana = rand() % 9;
				solution[row][coloana] = 0;
			}
			break;
		}
		default:
			std::cout << "Invalid value\n";
			Remove();
		}
	}
	void Filling()
	{
		int mistakes = 0;
		while (m_matrix != solution)
		{
			int i, j, val;
			std::cout << "Enter the value: ";
			std::cin >> val;
			std::cout << "On the line: ";
			std::cin >> i;
			std::cout << "On the column: ";
			std::cin >> j;
			if (m_matrix[i - 1][j - 1] == val)
			{
				solution[i - 1][j - 1] = val;
				DisplaySolution();
			}
			else
			{
				std::cout << "You made a mistake! Try again.\n";
				mistakes++;
			}
		}
		std::cout << "Congratulations! You solved the Sudoku!\n Number of mistakes:";
		std::cin >> mistakes;
	}
};
int main()
{
	srand(time(NULL));
	Sudoku sudoku;
	sudoku.MatrixAllocation();
	sudoku.InitializeVector();
	sudoku.SolveSudoku();
	sudoku.Remove();
	sudoku.DisplaySolution();
	sudoku.Filling();
}