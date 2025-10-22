#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 500, 500 }), "title");
	window.clear();

	const int cellSize = 50;
	const int gridSize = 10;

	sf::RectangleShape matrix[gridSize][gridSize];
	//int numGreenCells = 10;

	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			matrix[i][j].setSize(sf::Vector2f(cellSize - 2, cellSize - 2)); // ������ ������
			matrix[i][j].setPosition(i * cellSize, j * cellSize); // ������� ������
			// if (i % 2 != 0 && j <= numGreenCells)
			if (i % 2 != 0 && j <= 10 - i)
			{
				matrix[i][j].setFillColor(sf::Color::Green);
			}
			else
			{
				matrix[i][j].setFillColor(sf::Color::White); // ���� ������� �����
			}
			matrix[i][j].setOutlineColor(sf::Color::Black); // ���� �������
			matrix[i][j].setOutlineThickness(1); //������� �������
		}
		//numGreenCells--; //��������� �� 1(=>���������� �� 2)
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		for (int i = 0; i < gridSize; ++i)
		{
			for (int j = 0; j < gridSize; ++j)
			{
				window.draw(matrix[i][j]);
			}
		}
		window.display();
	}
	
}