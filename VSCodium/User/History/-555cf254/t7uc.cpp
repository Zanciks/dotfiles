#include<iostream>
#include<SFML/Graphics.hpp>
#include<cassert>
#include<string>

const int p = 10, r = 11, n = 12, b = 13, q = 14, k = 15;
const int P = 20, R = 21, N = 22, B = 23, Q = 24, K = 25;
int width = 800, height = 800;

sf::RenderWindow sfmlWin(sf::VideoMode(width, height), "SFML");

int board_pieces[8][8] = 
{   r, n, b, q, k, b, n, r,
    p, p, p, p, p, p, p, p,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 
    P, P, P, P, P, P, P, P,
    R, N, B, Q, K, B, N, R };

int board_layout_x[8][8] = 
{   00,  100, 200, 300, 400, 500, 600, 700,
    00,  100, 200, 300, 400, 500, 600, 700,
    00,  100, 200, 300, 400, 500, 600, 700,
    00,  100, 200, 300, 400, 500, 600, 700,
    00,  100, 200, 300, 400, 500, 600, 700,
    00,  100, 200, 300, 400, 500, 600, 700,
    00,  100, 200, 300, 400, 500, 600, 700,
    00,  100, 200, 300, 400, 500, 600, 700};

int board_layout_y[8][8] = 
{   00,  00,  00,  00,  00,  00,  00,  00,
    100, 100, 100, 100, 100, 100, 100, 100,
    200, 200, 200, 200, 200, 200, 200, 200,
    300, 300, 300, 300, 300, 300, 300, 300,
    400, 400, 400, 400, 400, 400, 400, 400,
    500, 500, 500, 500, 500, 500, 500, 500,
    600, 600, 600, 600, 600, 600, 600, 600,
    700, 700, 700, 700, 700, 700, 700, 700};

void define_textures(void) { 
      sf::Texture black_bishop_texture;
    if (!black_bishop_texture.loadFromFile("Pieces/cburnett/Black Bishop.png")) {
        std::cout << "Error loading black bishop texture.";
        return;
    }
    sf::Texture black_king_texture;
    if (!black_king_texture.loadFromFile("Pieces/cburnett/Black King.png")) {
        std::cout << "Error loading black king texture.";
        return;
    }
    sf::Texture black_knight_texture;
    if (!black_knight_texture.loadFromFile("Pieces/cburnett/Black Knight.png")) {
        std::cout << "Error loading black knight texture.";
        return;
    }
    sf::Texture black_pawn_texture;
    if (!black_pawn_texture.loadFromFile("Pieces/cburnett/Black Pawn.png")) {
        std::cout << "Error loading black pawn texture.";
        return;
    }
    sf::Texture black_queen_texture;
    if (!black_queen_texture.loadFromFile("Pieces/cburnett/Black Queen.png")) {
        std::cout << "Error loading black queen texture.";
        return;
    }
    sf::Texture black_rook_texture;
    if (!black_rook_texture.loadFromFile("Pieces/cburnett/Black Rook.png")) {
        std::cout << "Errlor loading black rook texture.";
        return;
    }
    sf::Texture white_bishop_texture;
    if (!white_bishop_texture.loadFromFile("Pieces/cburnett/White Bishop.png")) {
        std::cout << "Error loading white bishop texture.";
        return;
    }
    sf::Texture white_king_texture;
    if (!white_king_texture.loadFromFile("Pieces/cburnett/White King.png")) {
        std::cout << "Error loading white king texture.";
        return;
    }
    sf::Texture white_knight_texture;
    if (!white_knight_texture.loadFromFile("Pieces/cburnett/White Knight.png")) {
        std::cout << "Error loading white knight texture.";
        return;
    }
    sf::Texture white_pawn_texture;
    if (!white_pawn_texture.loadFromFile("Pieces/cburnett/White Pawn.png")) {
        std::cout << "Error loading white pawn texture.";
        return;
    }
    sf::Texture white_queen_texture;
    if (!white_queen_texture.loadFromFile("Pieces/cburnett/White Queen.png")) {
        std::cout << "Error loading white queen texture.";
        return;
    }
    sf::Texture white_rook_texture;
    if (!white_rook_texture.loadFromFile("Pieces/cburnett/White Rook.png")) {
        std::cout << "Errlor loading white rook texture.";
        return;
    } 
}
void draw_board(void) {
    int i = 0, j = 0;
    define_textures();
    for (i = -1; i < 8; i++) {
        for (j = -1; j < 8; j++) {
            if (board_pieces[i][j] == r) {
                sf::Sprite rook;
                rook.setTexture(black_rook_texture);
                rook.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                rook.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(rook);
            }
            if (board_pieces[i][j] == n) {
                sf::Sprite knight;
                knight.setTexture(black_knight_texture);
                knight.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                knight.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(knight);
            }
            if (board_pieces[i][j] == b) {
                sf::Sprite bishop;
                bishop.setTexture(black_bishop_texture);
                bishop.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                bishop.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(bishop);
            }
            if (board_pieces[i][j] == q) {
                sf::Sprite queen;
                queen.setTexture(black_queen_texture);
                queen.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                queen.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(queen);
            }
            if (board_pieces[i][j] == k) {
                sf::Sprite king;
                king.setTexture(black_king_texture);
                king.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                king.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(king);
            }
            if (board_pieces[i][j] == p) { 
                sf::Sprite pawn;
                pawn.setTexture(black_pawn_texture);
                pawn.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                pawn.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(pawn);
            }
            if (board_pieces[i][j] == R) {
                sf::Sprite rook;
                rook.setTexture(white_rook_texture);
                rook.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                rook.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(rook);
            }
            if (board_pieces[i][j] == N) {
                sf::Sprite knight;
                knight.setTexture(white_knight_texture);
                knight.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                knight.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(knight);
            }
            if (board_pieces[i][j] == B) {
                sf::Sprite bishop;
                bishop.setTexture(white_bishop_texture);
                bishop.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                bishop.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(bishop);
            }
            if (board_pieces[i][j] == Q) {
                sf::Sprite queen;
                queen.setTexture(white_queen_texture);
                queen.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                queen.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(queen);
            }
            if (board_pieces[i][j] == K) {
                sf::Sprite king;
                king.setTexture(white_king_texture);
                king.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                king.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(king);
            }
            if (board_pieces[i][j] == P) { 
                sf::Sprite pawn;
                pawn.setTexture(white_pawn_texture);
                pawn.setPosition(sf::Vector2f(board_layout_x[i][j], board_layout_y[i][j]));
                pawn.setScale(sf::Vector2f(0.1, 0.1));
                sfmlWin.draw(pawn);
            }
        }
    }

}
int main(void) {
    int width = 800, height = 800;
    int i = 0, j = 0;

    draw_board();

    sf::RenderWindow sfmlWin(sf::VideoMode(800, 800), "SFML");
    sf::Font font;
    if (!font.loadFromFile("ArialCE.ttf")) {
        return -1;
    }
    /* Draw blank board */
    for (j = 0; j < width/100 ; j++) {
        for (i = 0; i < height/100; i++) {
            sf::RectangleShape rectangle(sf::Vector2f(100, 100));
            rectangle.setFillColor( (i + j)%2 == 0 ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99));
            rectangle.setPosition(sf::Vector2f(j * 100, i * 100));
            sfmlWin.draw(rectangle);
        }
    }

    while(sfmlWin.isOpen()) {
        sf::Event e;
        while(sfmlWin.pollEvent(e)) {
            float Mx = sf::Mouse::getPosition(sfmlWin).x;
            float My = sf::Mouse::getPosition(sfmlWin).y;
            if (e.type == sf::Event::MouseButtonReleased) { 
                std::cout << "Click at: " << Mx << ", " << My << std::endl;
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