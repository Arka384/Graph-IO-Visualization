#pragma once
#include "Depends.hpp"

void update_buttons()
{
	vertex v;
	for (int i = 0; i < 4; i++)
	{
		buttons[i].setFillColor(Color(184, 134, 11, 255));
		int hot = mousePos.x > buttons[i].getPosition().x && mousePos.x < buttons[i].getPosition().x + buttons[i].getSize().x
			&& mousePos.y > buttons[i].getPosition().y && mousePos.y < buttons[i].getPosition().y + buttons[i].getSize().y;
		if (hot) {
			buttons[i].setFillColor(Color(189, 183, 107, 255));
		}

		if (hot && mousePressed && i == 0) {
			mousePressed = false;
			//this is basically the part for adding new vertices
			current_vertices++;
			std::stringstream ss;
			ss << current_vertices;
			v.name.setFont(font);
			v.name.setCharacterSize(30);
			v.name.setString(ss.str());
			v.name.setOrigin(v.name.getGlobalBounds().width / 2, v.name.getGlobalBounds().height / 2);
			v.shape.setRadius(v_size / 2);
			v.shape.setFillColor(Color::Red);
			v.shape.setOrigin(v_size / 2, v_size / 2);
			v.shape.setPosition(v_size, v_size);
			v.numbering = current_vertices;
			vertices.push_back(v);
		}

		if (hot && mousePressed && i == 1) {
			mousePressed = false;
			s1.clear();
			s2.clear();
			s3.clear();
			if (edge_window_active)
				edge_window_active = false;
			else
				edge_window_active = true;
		}

		if (hot && mousePressed && i == 2) {
			mousePressed = false;

			std::ifstream input("input.txt");
			if (!input.is_open())	//if failed to open input file
				std::cout << "failed\n";

			input >> current_vertices;
			int number = 0, i = 1, j = 1;
			while (input >> number)
			{
				adj_matrix[i][j] = number;
				if (j == current_vertices) {
					j = 1;
					i++;
				}
				else j++;
			}
			input.close();
			construct_graph();

		}

		if (hot && mousePressed && i == 3) {
			mousePressed = false;
			create_adj_matrix();
			display_adj_matrix();
		}


	}
}

void update_edgeWindow()
{
	//add button
	Add.setScale(1, 1);
	Add.setPosition(Outer_box.getPosition().x + Outer_box.getGlobalBounds().width / 2 - Add.getGlobalBounds().width / 2, 465);
	int hot = mousePos.x > Add.getPosition().x && mousePos.x < Add.getPosition().x + Add.getGlobalBounds().width &&
		mousePos.y > Add.getPosition().y && mousePos.y < Add.getPosition().y + Add.getGlobalBounds().height;
	if (hot) {
		Add.setPosition(Outer_box.getPosition().x + Outer_box.getGlobalBounds().width / 2 - Add.getGlobalBounds().width / 2 - 5, 460);
		Add.setScale(1.1, 1.1);
	}
	if (hot && mousePressed && s1.empty() != 1 && s2.empty() != 1) {
		mousePressed = false;
		e1 = std::stoi(s1);
		e2 = std::stoi(s2);
		if (s3.length() == 0)
			copy_w = 1;
		else
			copy_w = std::stoi(s3);
		s1.clear();
		s2.clear();
		s3.clear();
		add_edges();
	}

	//check_box button
	int n_hot = mousePos.x > check_box.getPosition().x && mousePos.x < check_box.getPosition().x + check_box.getGlobalBounds().width &&
		mousePos.y > check_box.getPosition().y && mousePos.y < check_box.getPosition().y + check_box.getGlobalBounds().height;
	if (n_hot && mousePressed) {
		mousePressed = false;
		if (check_box.getFillColor() == Color(96, 96, 96, 255)) {
			check_box.setFillColor(Color::White);
			show_weights = true;
		}
		else {
			check_box.setFillColor(Color(96, 96, 96, 255));
			show_weights = false;
		}
	}
	//check_box_2
	int n_hot_2 = mousePos.x > check_box_2.getPosition().x && mousePos.x < check_box_2.getPosition().x + check_box_2.getGlobalBounds().width &&
		mousePos.y > check_box_2.getPosition().y && mousePos.y < check_box_2.getPosition().y + check_box_2.getGlobalBounds().height;
	if (n_hot_2 && mousePressed) {
		mousePressed = false;
		if (check_box_2.getFillColor() == Color(96, 96, 96, 255)) {
			check_box_2.setFillColor(Color::White);
			directed_graph = true;
			Outer_box.setTexture(box_2);
		}
		else {
			check_box_2.setFillColor(Color(96, 96, 96, 255));
			directed_graph = false;
			Outer_box.setTexture(box);
		}
	}


	//for text boxes - selection and input
		//for text box 1
	if (mousePos.x > text_box_1.getPosition().x && mousePos.x < text_box_1.getPosition().x + text_box_1.getSize().x
		&& mousePos.y > text_box_1.getPosition().y && mousePos.y < text_box_1.getPosition().y + text_box_1.getSize().y &&
		Mouse::isButtonPressed(Mouse::Button::Left))
		box1_active = true;
	else if (Mouse::isButtonPressed(Mouse::Button::Left))
		box1_active = false;
	//for text box 2
	if (mousePos.x > text_box_2.getPosition().x && mousePos.x < text_box_2.getPosition().x + text_box_2.getSize().x
		&& mousePos.y > text_box_2.getPosition().y && mousePos.y < text_box_2.getPosition().y + text_box_2.getSize().y &&
		Mouse::isButtonPressed(Mouse::Button::Left))
		box2_active = true;
	else if (Mouse::isButtonPressed(Mouse::Button::Left))
		box2_active = false;
	//for text box 3
	if (mousePos.x > text_box_3.getPosition().x && mousePos.x < text_box_3.getPosition().x + text_box_3.getSize().x
		&& mousePos.y > text_box_3.getPosition().y && mousePos.y < text_box_3.getPosition().y + text_box_3.getSize().y &&
		Mouse::isButtonPressed(Mouse::Button::Left))
		box3_active = true;
	else if (Mouse::isButtonPressed(Mouse::Button::Left))
		box3_active = false;


	//text updation 
	text1.setString(s1);
	text2.setString(s2);
	text3.setString(s3);

}

void update_vertices()
{
	int x = 0;
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		for (auto i = vertices.begin(); i != vertices.end(); i++) {
			i->name.setPosition(i->shape.getPosition().x - 5, i->shape.getPosition().y - 5);
			if (mousePos.x > i->shape.getPosition().x - v_size / 2 && mousePos.x < i->shape.getPosition().x + v_size / 2 &&
				mousePos.y > i->shape.getPosition().y - v_size / 2 && mousePos.y < i->shape.getPosition().y + v_size / 2)
				x = i->numbering;
		}

		for (auto i = vertices.begin(); i != vertices.end(); i++) {
			if (i->numbering == x)
			{
				i->shape.setPosition(mousePos);
			}
		}
	}
}

void update_edges()
{
	for (auto k = edges.begin(); k != edges.end(); k++) {
		for (auto i = vertices.begin(); i != vertices.end(); i++) {
			if (i->numbering == k->v1) {
				for (auto j = vertices.begin(); j != vertices.end(); j++) {
					if (j->numbering == k->v2)
					{
						float dx = j->shape.getPosition().x - i->shape.getPosition().x;
						float dy = j->shape.getPosition().y - i->shape.getPosition().y;
						float dist = (dx*dx + dy * dy);
						dist = sqrt(dist);	//this is the distance between the two balls in which the edge is
						float angle = atan2(dy, dx);	//this is the angle of rotation for the edge to be inside the balls
						angle = angle * (180 / pi);

						k->shape.setRotation(angle);
						k->shape.setPosition(i->shape.getPosition());	//I make the edge permanently connected to one vertex and free form to another
						k->shape.setSize(Vector2f(dist, 10));	//this makes the size of the edges dynamic
						k->direction.setRotation(angle);	//this makes the direction sprite to rotate dynamically

						float x = (j->shape.getPosition().x + i->shape.getPosition().x) / 2;
						float y = (j->shape.getPosition().y + i->shape.getPosition().y) / 2;
						k->weight_text.setPosition(x, y);
						x = (x + i->shape.getPosition().x) / 2;
						y = (y + i->shape.getPosition().y) / 2;
						k->direction.setPosition(x, y);
					}
				}
			}
		}
	}
}

void add_edges()
{
	int case1 = 0, case2 = 0;

	for (auto i = edges.begin(); i != edges.end(); i++) {
		case1 = (i->v1 == e1 && i->v2 == e2);
		case2 = (i->v1 == e2 && i->v2 == e1);
		if (case1 || case2)
			if (directed_graph == false)
				return;
	}


	for (auto i = vertices.begin(); i != vertices.end(); i++) {
		if (i->numbering == e1) {
			for (auto j = vertices.begin(); j != vertices.end(); j++) {
				if (j->numbering == e2)
				{
					float dx = j->shape.getPosition().x - i->shape.getPosition().x;
					float dy = j->shape.getPosition().y - i->shape.getPosition().y;
					float dist = (dx*dx + dy * dy);
					dist = sqrt(dist);	//this is the distance between the two balls in which the edge is
					float angle = atan2(dy, dx);	//this is the angle of rotation for the edge to be inside the balls
					angle = angle * (180 / pi);

					edge temp;
					std::stringstream ss;
					ss << copy_w;
					temp.weight_text.setFont(font);
					temp.weight_text.setCharacterSize(30);
					temp.weight_text.setFillColor(Color::Red);
					temp.weight_text.setStyle(Text::Bold);
					temp.weight_text.setString(ss.str());
					temp.weight_text.setOrigin(temp.weight_text.getGlobalBounds().width / 2, temp.weight_text.getGlobalBounds().height / 2);

					temp.direction = Arrow;
					temp.direction.setRotation(angle);
					temp.direction.setOrigin(temp.direction.getGlobalBounds().width / 2, temp.direction.getGlobalBounds().height / 2 + 130);

					temp.shape.setSize(Vector2f(100, 10));
					temp.shape.setRotation(angle);
					temp.shape.setPosition(i->shape.getPosition());	//I make the edge permanently connected to one vertex and free form to another
					temp.shape.setSize(Vector2f(dist, 10));	//this makes the size of the edges dynamic
					temp.v1 = e1;
					temp.v2 = e2;
					temp.weight = copy_w;

					edges.push_back(temp);

					/*
					for (auto i = edges.begin(); i != edges.end(); i++) {
						if (directed_graph)
							adj_matrix[i->v1][i->v2] = i->weight;
						else {
							adj_matrix[i->v1][i->v2] = i->weight;
							adj_matrix[i->v2][i->v1] = i->weight;
						}
					}
					*/

				}
			}
		}
	}
}

void construct_graph()
{
	for (int i = 1; i <= current_vertices; i++)
	{
		vertex v;
		std::stringstream ss;
		ss << i;
		v.name.setFont(font);
		v.name.setCharacterSize(30);
		v.name.setString(ss.str());
		v.name.setOrigin(v.name.getGlobalBounds().width / 2, v.name.getGlobalBounds().height / 2);
		v.shape.setRadius(v_size / 2);
		v.shape.setFillColor(Color::Red);
		v.shape.setOrigin(v_size / 2, v_size / 2);
		v.shape.setPosition(rand() % (window_width - 300), rand() % window_height);
		//v.shape.setPosition(window_width / 2, window_height / 2);
		v.numbering = i;
		vertices.push_back(v);
	}

	if (directed_graph) {
		for (int i = 1; i <= current_vertices; i++) {
			for (int j = 1; j <= current_vertices; j++) {
				if (adj_matrix[i][j] != 0) {
					e1 = i;
					e2 = j;
					copy_w = adj_matrix[i][j];
					add_edges();
				}
				if (adj_matrix[j][i] != 0) {
					e1 = j;
					e2 = i;
					copy_w = adj_matrix[i][j];
					add_edges();
				}
			}
		}
	}
	else {
		for (int i = 1; i <= current_vertices; i++) {
			for (int j = 1; j <= current_vertices; j++) {
				if (adj_matrix[i][j] != 0) {
					e1 = i;
					e2 = j;
					copy_w = adj_matrix[i][j];
					adj_matrix[i][j] = 0;
					adj_matrix[j][i] = 0;
					add_edges();
				}
			}
		}
	}

}



void create_adj_matrix()
{
	for (auto i = edges.begin(); i != edges.end(); i++) {
		if (directed_graph)
			adj_matrix[i->v1][i->v2] = i->weight;
		else {
			adj_matrix[i->v1][i->v2] = i->weight;
			adj_matrix[i->v2][i->v1] = i->weight;
		}
	}
}

void display_adj_matrix()
{
	for (int i = 1; i <= current_vertices; i++)
	{
		for (int j = 1; j <= current_vertices; j++)
			std::cout << adj_matrix[i][j] << " ";
		std::cout << "\n";
	}
}
