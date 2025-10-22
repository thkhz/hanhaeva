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
			matrix[i][j].setSize(sf::Vector2f(cellSize - 2, cellSize - 2)); // Размер ячейки
			matrix[i][j].setPosition(i * cellSize, j * cellSize); // Позиция ячейки
			// if (i % 2 != 0 && j <= numGreenCells)
			if (i % 2 != 0 && j <= 10 - i)
			{
				matrix[i][j].setFillColor(sf::Color::Green);
			}
			else
			{
				matrix[i][j].setFillColor(sf::Color::White); // Цвет заливки ячеек
			}
			matrix[i][j].setOutlineColor(sf::Color::Black); // Цвет границы
			matrix[i][j].setOutlineThickness(1); //Толщина границы
		}
		//numGreenCells--; //уменьшаем на 1(=>уменьшится на 2)
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