#include "Depends.hpp"
#include "Init.hpp"
#include "Updates.hpp"

//add edge overlapping

int main()
{
	srand(time(NULL));
	RenderWindow window(sf::VideoMode(window_width, window_height), "Test");

	load_textures();
	init_buttons();

	while (window.isOpen())
	{
		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
			case Event::MouseButtonPressed:
				if (evnt.mouseButton.button == Mouse::Button::Left)
					mousePressed = true;
				break;
			case Event::MouseButtonReleased:
				if (evnt.mouseButton.button == Mouse::Button::Left)
					mousePressed = false;
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::R))
					;	// clear_memory();
				break;
			case Event::TextEntered:
				if (evnt.text.unicode >= 48 && evnt.text.unicode <= 57)
					if (box1_active && s1.length() <= 1)
						s1 += static_cast<char>(evnt.text.unicode);
					else if (box2_active && s2.length() <= 1)
						s2 += static_cast<char>(evnt.text.unicode);
					else if (box3_active && s3.length() <= 2)
						s3 += static_cast<char>(evnt.text.unicode);

				if (evnt.text.unicode == 8)
					if (box1_active && s1.length() > 0)
						s1.pop_back();
					else if (box2_active && s2.length() > 0)
						s2.pop_back();
					else if (box3_active && s3.length() > 0)
						s3.pop_back();
				break;
			default:
				break;
			}
		}

		//updates
		mousePos = Vector2f(Mouse::getPosition(window));

		update_buttons();
		update_vertices();
		update_edges();
		if (edge_window_active)
			update_edgeWindow();


		// draw
		window.clear();

		for (int i = 0; i < 4; i++) {
			window.draw(buttons[i]);
			window.draw(button_text[i]);
		}

		for (auto i = edges.begin(); i != edges.end(); i++) {
			window.draw(i->shape);
			if (directed_graph)
				window.draw(i->direction);
			if (show_weights)
				window.draw(i->weight_text);
		}

		for (auto i = vertices.begin(); i != vertices.end(); i++) {
			window.draw(i->shape);
			window.draw(i->name);
		}

		if (edge_window_active) {
			window.draw(Outer_box);
			window.draw(Add);
			window.draw(text_box_1);
			window.draw(text_box_2);
			window.draw(text_box_3);
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);
			window.draw(check_box);
			window.draw(check_box_2);
		}

		window.display();
	}
}
