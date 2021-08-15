#pragma once
#include "Depends.hpp"

void load_textures()
{
	box.loadFromFile("Resources/Images/window.png");
	box_2.loadFromFile("Resources/Images/window_2.png");
	arrow.loadFromFile("Resources/Images/arrow.png");
	add.loadFromFile("Resources/Images/add_button.png");
	Outer_box.setTexture(box);
	Add.setTexture(add);
	Arrow.setTexture(arrow);
	Arrow.setTextureRect(IntRect(0, 0, 260, 393));
	Arrow.setScale(0.1, 0.1);
}

void init_buttons()
{
	font.loadFromFile("my_font.ttf");
	button_text[0].setString("Add Vertex");
	button_text[1].setString("Add Edge");
	button_text[2].setString("Get adj_matrix");
	button_text[3].setString("Done");
	for (int i = 0; i < 4; i++)
	{
		buttons[i].setSize(Vector2f(200, 40));
		buttons[i].setPosition(window_width - buttons[i].getSize().x - 20, i * 50 + 20);

		button_text[i].setFont(font);
		button_text[i].setFillColor(Color::Black);
		button_text[i].setCharacterSize(30);
		if (i == 2)
			button_text[i].setCharacterSize(27);
		button_text[i].setPosition((buttons[i].getPosition().x + buttons[i].getSize().x / 2)
			- button_text[i].getGlobalBounds().width / 2, buttons[i].getPosition().y);
	}

	Outer_box.setPosition(window_width - Outer_box.getGlobalBounds().width - 20, 240);
	Add.setPosition(Outer_box.getPosition().x + Outer_box.getGlobalBounds().width / 2 - Add.getGlobalBounds().width / 2, 400);

	text_box_1.setSize(Vector2f(70, 40));
	text_box_1.setFillColor(Color(96, 96, 96, 255));
	text_box_1.setPosition(Outer_box.getPosition().x + Outer_box.getGlobalBounds().width / 4 - text_box_1.getSize().x / 2, 290);
	text_box_2.setSize(Vector2f(70, 40));
	text_box_2.setFillColor(Color(96, 96, 96, 255));
	text_box_2.setPosition(Outer_box.getPosition().x + Outer_box.getGlobalBounds().width / 2 + Outer_box.getGlobalBounds().width / 4
		- text_box_2.getSize().x / 2, 290);
	text_box_3.setSize(Vector2f(70, 40));
	text_box_3.setFillColor(Color(96, 96, 96, 255));
	text_box_3.setPosition(Outer_box.getPosition().x + Outer_box.getGlobalBounds().width / 2 + Outer_box.getGlobalBounds().width / 4
		- text_box_3.getSize().x / 2 - 20, 340);

	//text box textes
	text1.setFont(font);
	text1.setCharacterSize(25);
	text1.setPosition(text_box_1.getPosition().x + 5, text_box_1.getPosition().y + 2);
	text2.setFont(font);
	text2.setCharacterSize(25);
	text2.setPosition(text_box_2.getPosition().x + 5, text_box_2.getPosition().y + 2);
	text3.setFont(font);
	text3.setCharacterSize(25);
	text3.setPosition(text_box_3.getPosition().x + 5, text_box_3.getPosition().y + 2);

	//checkbox
	check_box.setSize(Vector2f(15, 15));
	check_box.setFillColor(Color(96, 96, 96, 255));
	check_box.setOutlineThickness(5.f);
	check_box.setOutlineColor(Color::Black);
	check_box.setPosition(window_width - 110, 396);

	check_box_2.setSize(Vector2f(15, 15));
	check_box_2.setFillColor(Color(96, 96, 96, 255));
	check_box_2.setOutlineThickness(5.f);
	check_box_2.setOutlineColor(Color::Black);
	check_box_2.setPosition(window_width - 110, 432);
}


void clear_memory()
{
	directed_graph = false;
	show_weights = false;
	vertices.clear();
	edges.clear();
	copy_w = 1;
	current_vertices = e1 = e2 = 0;

	for (int i = 1; i <= max; i++)
		for (int j = 1; j <= max; j++)
			adj_matrix[i][j] = 0;
	system("cls");

}