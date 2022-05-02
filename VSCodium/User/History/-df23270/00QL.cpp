// $ g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system 

#include<iostream>
#include<SFML/Graphics.hpp>
#include<cassert>
#include<string>

const int r = 10, b = 11, n = 12, q = 13, k = 14, p = 15;
const int R = 20, B = 21, N = 22, Q = 23, K = 24, P = 25;  

int initialBoard[8][8] =
{   r, n, b, q, k, b, n, r, 
    p, p, p, p, p, p, p, p,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0,
    P, P, P, P, P, P, P, P, 
    R, N, B, Q, K, B, N, R};

void drawBoard(int LightSquare[3], int DarkSquare[3], int width, int height,  sf::RenderWindow& window) {
    int i, j;
    window.clear();
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            sf::RectangleShape rectangle(sf::Vector2f(width/8, height/8));
            rectangle.setFillColor((i+j)%2 == 0 ? sf::Color(LightSquare[0], LightSquare[1], LightSquare[2]) : sf::Color(DarkSquare[0], DarkSquare[1], DarkSquare[2]));
            rectangle.setPosition(sf::Vector2f(i * (width / 8), j * (height / 8)));
            window.draw(rectangle);
        }
    }
}

void createPiece(sf::Texture texture, std::string textureLocation, int pieceType, int currentBoard[8][8], int board_layout_x[8], int board_layout_y[8], int width, int height, sf::RenderWindow& window) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pieceType == currentBoard[i][j]) {
                sf::Sprite piece;
                texture.loadFromFile(textureLocation);
                piece.setTexture(texture);
                piece.setPosition(sf::Vector2f(board_layout_x[j], board_layout_y[i]));
                //piece.setPosition(sf::Vector2f(100, 100));
                int size_x = width/8000, size_y = height/8000;
                std::cout << size_x << size_y << std::endl;
                piece.setScale(sf::Vector2f((width/8000), (0.1)));
                //piece.setScale(sf::Vector2f(0.1, 0.1));
                window.draw(piece);
                std::cout << "Piece displayed." << std::endl;
            }
        }
    }
}

int main(void) {

    int width = 400, height = 400;
    int LightSquare[3] = {181, 136, 99}, DarkSquare[3] = {240, 217, 181};
    int currentBoard[8][8];

    int board_layout_x[8] = 
    {   0 * width  / 8, 1 * width  / 8, 2 * width  / 8, 3 * width  / 8, 4 * width  / 8, 5 * width  / 8, 6 * width  / 8, 7 * width  / 8};
    int board_layout_y[8] = 
    {   0 * height / 8, 1 * height / 8, 2 * height / 8, 3 * height / 8, 4 * height / 8, 5 * height / 8, 6 * height / 8, 7 * height / 8};

    sf::RenderWindow sfmlWin(sf::VideoMode(width, height), "SFML");
    sfmlWin.clear();
    sf::Font font;
    if (!font.loadFromFile("ArialCE.ttf")) {
        return -1;
    }

    // draw the board
    drawBoard(LightSquare, DarkSquare, width, height, sfmlWin);
    // set inital board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currentBoard[i][j] = initialBoard[i][j];
            std::cout << currentBoard[i][j] << std::endl;
        }
    }
    // draw the pieces
    sf::Texture black_bishop;
    createPiece(black_bishop, "pieces/cburnett/Black Bishop.png", b, currentBoard, board_layout_x, board_layout_y, width = 800, height = 800, sfmlWin);


    while (sfmlWin.isOpen()) {
        sf::Event e;
        while(sfmlWin.pollEvent(e)) {
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