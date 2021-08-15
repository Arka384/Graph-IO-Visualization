#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
using namespace sf;

constexpr float pi = 3.14159;
constexpr int window_width = 1280;
constexpr int window_height = 720;
constexpr int max = 20;

Vector2f mousePos;
bool mousePressed = false;
bool show_weights = false;
bool directed_graph = false;
bool edge_window_active = false;
bool box1_active = false, box2_active = false, box3_active = false;
int adj_matrix[max][max] = { 0 };

//vertex
int current_vertices = 0;
float v_size = 40.f;
typedef struct vertex {
	CircleShape shape;
	Text name;
	int numbering;
	char alpha_numbering;
}vertex;
std::list<vertex> vertices;

//edges
int e1 = 0, e2 = 0;	//incedent edges
int copy_w = 1;
typedef struct edge {
	RectangleShape shape;
	Sprite direction;
	Text weight_text;
	int weight;
	int v1, v2;
}edge;
std::list<edge>edges;

//buttons
RectangleShape buttons[4], check_box, check_box_2;
RectangleShape text_box_1, text_box_2, text_box_3;
std::string s1, s2, s3;
Sprite Outer_box, Add, Arrow;
Texture box, box_2, add, arrow;
Text button_text[4];
Text text1, text2, text3;
Font font;


//functions
void init_buttons(void);
void load_textures(void);
void update_buttons(void);
void update_vertices(void);
void update_edgeWindow(void);
void add_edges(void);
void update_edges(void);
void create_adj_matrix(void);
void display_adj_matrix(void);
void construct_graph(void);
void clear_memory(void);