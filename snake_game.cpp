#include <iostream>
#include <conio.h> // For _kbhit() and _getch()
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int GRID_SIZE = 20;
const char SNAKE_HEAD = 'O';
const char SNAKE_BODY = 'o';
const char FOOD = '*';
const char EMPTY = ' ';

struct Position {
    int x, y;
};

class SnakeGame {
private:
    vector<Position> snake;
    Position food;
    char direction;
    bool gameOver;
    int score;

public:
    SnakeGame() : direction('D'), gameOver(false), score(0) {
        snake.push_back({GRID_SIZE / 2, GRID_SIZE / 2});
        snake.push_back({GRID_SIZE / 2, GRID_SIZE / 2 - 1});
        snake.push_back({GRID_SIZE / 2, GRID_SIZE / 2 - 2});
        placeFood();
    }

    void placeFood() {
        srand(time(0));
        while (true) {
            food.x = rand() % GRID_SIZE;
            food.y = rand() % GRID_SIZE;
            bool onSnake = false;
            for (auto &segment : snake) {
                if (segment.x == food.x && segment.y == food.y) {
                    onSnake = true;
                    break;
                }
            }
            if (!onSnake) break;
        }
    }

    void draw() {
        system("cls");
        for (int i = 0; i < GRID_SIZE + 2; i++) cout << "#";
        cout << endl;
        
        for (int i = 0; i < GRID_SIZE; i++) {
            cout << "#";
            for (int j = 0; j < GRID_SIZE; j++) {
                bool printed = false;
                if (i == food.x && j == food.y) {
                    cout << FOOD;
                    printed = true;
                }
                for (size_t k = 0; k < snake.size(); k++) {
                    if (snake[k].x == i && snake[k].y == j) {
                        cout << (k == 0 ? SNAKE_HEAD : SNAKE_BODY);
                        printed = true;
                        break;
                    }
                }
                if (!printed) cout << EMPTY;
            }
            cout << "#" << endl;
        }
        for (int i = 0; i < GRID_SIZE + 2; i++) cout << "#";
        cout << "\nScore: " << score << endl;
    }

    void input() {
        if (_kbhit()) {
            char key = _getch();
            if ((key == 'W' || key == 'w') && direction != 'S') direction = 'W';
            else if ((key == 'A' || key == 'a') && direction != 'D') direction = 'A';
            else if ((key == 'S' || key == 's') && direction != 'W') direction = 'S';
            else if ((key == 'D' || key == 'd') && direction != 'A') direction = 'D';
        }
    }

    void logic() {
        Position newHead = snake.front();
        if (direction == 'W') newHead.x--;
        else if (direction == 'S') newHead.x++;
        else if (direction == 'A') newHead.y--;
        else if (direction == 'D') newHead.y++;

        if (newHead.x < 0 || newHead.x >= GRID_SIZE || newHead.y < 0 || newHead.y >= GRID_SIZE) {
            gameOver = true;
            return;
        }
        for (size_t i = 1; i < snake.size(); i++) {
            if (snake[i].x == newHead.x && snake[i].y == newHead.y) {
                gameOver = true;
                return;
            }
        }
        snake.insert(snake.begin(), newHead);
        if (newHead.x == food.x && newHead.y == food.y) {
            score += 10;
            placeFood();
        } else {
            snake.pop_back();
        }
    }

    void run() {
        while (!gameOver) {
            draw();
            input();
            logic();
            _sleep(100);
        }
        cout << "Game Over! Final Score: " << score << endl;
    }
};

int main() {
    SnakeGame game;
    game.run();
    return 0;
}
