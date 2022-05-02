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
            rectangle.setFillColor((i+j)%2 == 0 ? sf::Color(DarkSquare[0], DarkSquare[1], DarkSquare[2]) : sf::Color(LightSquare[0], LightSquare[1], LightSquare[2]));
            rectangle.setPosition(sf::Vector2f(((i * (width / 8)), j * (height / 8)));
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
                piece.setScale(sf::Vector2f(width / 8000.0, height / 8000.0));
                window.draw(piece);
            }
        }
    }
}

int main(void) {

    int window_width = 1600, window_height = 900;
    int board_width = 800, board_height = 800;
    int LightSquare[3] = {181, 136, 99}, DarkSquare[3] = {240, 217, 181};
    int currentBoard[8][8];

    int board_layout_x[8] = 
    {   0 * board_width  / 8, 1 * board_width  / 8, 2 * board_width  / 8, 3 * board_width  / 8, 4 * board_width  / 8, 5 * board_width  / 8, 6 * board_width  / 8, 7 * board_width  / 8};
    int board_layout_y[8] = 
    {   1 * board_height / 8, 2 * board_height / 8, 3 * board_height / 8, 4 * board_height / 8, 5 * board_height / 8, 6 * board_height / 8, 7 * board_height / 8, 8 * board_height / 8};

    sf::RenderWindow sfmlWin(sf::VideoMode(window_width, window_height), "SFML");
    sfmlWin.clear();
    sf::Font font;
    if (!font.loadFromFile("ArialCE.ttf")) {
        return -1;
    }

    // draw the board
    drawBoard(LightSquare, DarkSquare, board_width, board_height, sfmlWin);

    // set inital board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            currentBoard[i][j] = initialBoard[i][j];
        }
    }

    // draw the pieces
    sf::Texture black_bishop;
    createPiece(black_bishop, "pieces/cburnett/Black Bishop.png", b, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture black_king;
    createPiece(black_king, "pieces/cburnett/Black King.png", k, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture black_knight;
    createPiece(black_knight, "pieces/cburnett/Black Knight.png", n, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture black_pawn;
    createPiece(black_pawn, "pieces/cburnett/Black Pawn.png", p, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture black_queen;
    createPiece(black_queen, "pieces/cburnett/Black Queen.png", q, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture black_rook;
    createPiece(black_rook, "pieces/cburnett/Black Rook.png", r, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture white_bishop;
    createPiece(white_bishop, "pieces/cburnett/White Bishop.png", B, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture white_king;
    createPiece(white_king, "pieces/cburnett/White King.png", K, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture white_knight;
    createPiece(white_knight, "pieces/cburnett/White Knight.png", N, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture white_pawn;
    createPiece(white_pawn, "pieces/cburnett/White Pawn.png", P, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture white_queen;
    createPiece(white_queen, "pieces/cburnett/White Queen.png", Q, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);
    sf::Texture white_rook;
    createPiece(white_rook, "pieces/cburnett/White Rook.png", R, currentBoard, board_layout_x, board_layout_y, board_width, board_height, sfmlWin);

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