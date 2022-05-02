#include<iostream>
#include<SFML/Graphics.hpp>
#include<cassert>

const int p = 10, r = 11, n = 12, b = 13, q = 14, k = 15;
const int P = 20, R = 21, N = 22, B = 23, Q = 24, K = 25;
int width = 800, height = 800;

/* DEFINE ALL POSITIONS OF THE BOARD, IN TERMS OF HEIGHT + WIDTH */
int A8[2] = {50, 50}, A7[2] = {50, 150}, A6[2] = {50, 250}, A5[2] = {50, 350}, A4[2] = {50, 450}, A3[2] = {50, 550}, A2[2] = {50, 650}, A1[2] = {50, 750};
int B8[2] = {50, 50}, B7[2] = {50, 150}, B6[2] = {50, 250}, B5[2] = {50, 350}, B4[2] = {50, 450}, B3[2] = {50, 550}, B2[2] = {50, 650}, B1[2] = {50, 750};
int C8[2] = {50, 50}, C7[2] = {50, 150}, C6[2] = {50, 250}, C5[2] = {50, 350}, C4[2] = {50, 450}, C3[2] = {50, 550}, C2[2] = {50, 650}, C1[2] = {50, 750};
int D8[2] = {50, 50}, D7[2] = {50, 150}, D6[2] = {50, 250}, D5[2] = {50, 350}, D4[2] = {50, 450}, D3[2] = {50, 550}, D2[2] = {50, 650}, D1[2] = {50, 750};
int E8[2] = {50, 50}, E7[2] = {50, 150}, E6[2] = {50, 250}, E5[2] = {50, 350}, E4[2] = {50, 450}, E3[2] = {50, 550}, E2[2] = {50, 650}, E1[2] = {50, 750};
int F8[2] = {50, 50}, F7[2] = {50, 150}, F6[2] = {50, 250}, F5[2] = {50, 350}, F4[2] = {50, 450}, F3[2] = {50, 550}, F2[2] = {50, 650}, F1[2] = {50, 750};
int G8[2] = {50, 50}, G7[2] = {50, 150}, G6[2] = {50, 250}, G5[2] = {50, 350}, G4[2] = {50, 450}, G3[2] = {50, 550}, G2[2] = {50, 650}, G1[2] = {50, 750};
int H8[2] = {50, 50}, H7[2] = {50, 150}, H6[2] = {50, 250}, H5[2] = {50, 350}, H4[2] = {50, 450}, H3[2] = {50, 550}, H2[2] = {50, 650}, H1[2] = {50, 750};


int board_pieces[8][8] = 
{   r, n, b, q, k, b, n, r,
    p, p, p, p, p, p, p, p,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 
    P, P, P, P, P, P, P, P,
    R, N, B, Q, K, B, N, R };

int main(void) {
    int width = 800, height = 800;
    int i = 0, j = 0;

    sf::RenderWindow sfmlWin(sf::VideoMode(800, 800), "SFML");
    
    sf::Font font;
    if (!font.loadFromFile("ArialCE.ttf")) {
        return -1;
    }

    for (j = 0; j < width/100 ; j++) {
        for (i = 0; i < height/100; i++) {
            sf::RectangleShape rectangle(sf::Vector2f(100, 100));
            rectangle.setFillColor( (i + j)%2 == 0 ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99));
            rectangle.setPosition(sf::Vector2f(j * 100, i * 100));
            sfmlWin.draw(rectangle);
        }
    }

    sf::RectangleShape piece(sf::Vector2f(50,50));
    piece.setFillColor(sf::Color(255,255,255));
    piece.setPosition(sf::Vector2f(A1[0],A1[1]));
    sfmlWin.draw(piece);

    sf::Texture knight_texture;
    if (!knight_texture.loadFromFile("White Knight.png")) {
        std::cout << "Error loading pieces texture.";
    }
    sf::Sprite knight_piece;
    knight_piece.setTexture(knight_texture);
    knight_piece.setPosition(sf::Vector2f(A2[0], A2[1]));
    knight_piece.setScale(sf::Vector2f(1.5, 1.5));
    sfmlWin.draw(knight_piece);


    while(sfmlWin.isOpen()) {
        sf::Event e;
        while(sfmlWin.pollEvent(e)) {
            float Mx = sf::Mouse::getPosition(sfmlWin).x;
            float My = sf::Mouse::getPosition(sfmlWin).y;
            if (e.type == Event::MouseButtonReleased) { 
                std::cout << Mx << My << std::endl;
            }
            switch(e.type) {
                case sf::Event::EventType::Closed:
                    sfmlWin.close();
                    sfmlWin.display();
                    break;
            }
        }
        sfmlWin.display();
    }
    return 0;
}