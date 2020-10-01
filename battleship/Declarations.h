#pragma once

#define SetCenterY() std::cout << "\n\n\n\n\n\n\n\n";
#define SetCenterX() std::cout << "\t\t\t\t\t";
struct Player;
struct Coordinate;
struct Board;

enum GAMEMODE
{
	SINGLEPLAYER = 1, MULTIPLAYER
};

enum DIFFICULTY
{
	Easy = 1, Normal, Legend
};
enum SHIPS
{
	DESTROYER = 2, SUBMARINE, CRUISER, BATTLESHIP, CARRIER
};

enum ARROWKEYS {
	KEY_UP = 72, KEY_DOWN = 80
};


void ControlMenu(char** options, short size, short& selected);
short GetDiff();
void HardMode(Player* human, Player* computer, bool& AI_WIN);
void CopyCoordinate(Coordinate& coo1, Coordinate& coo2);
Coordinate RandomCoordinate(Board board);
void TypingEffect(const char* text);
void StartScreen();
int GameModeScreen();
int PrintMenu(char** menu, const int size, const int selected_index);
Player* CreatePlayer();
void Game(short difficulty = 0);
void GetCoordinates(int& x, int& y);
void GetOrientation(char& orientation);
void PlaceTheShip(int** board, int ship_blocks, int ship_id);
bool CheckOverlap(int** board, char orientation, int x, int y, int ship_blocks);
bool Draw();
bool AttackToOpponent(Player*& defender, Player*& attacker);
int Start(Player* player1, Player* player2, int difficulty = 0);
bool GameOverScreen();
void PlaceAIShips(int** board, int ship_blocks, int ship_id);
Player* AISettings();
bool CheckCoordinates(Board& player_board, Coordinate& player_move);
void PrintWinner(Player* player);
char* InputName();
void GetValidCoordinates(Board defender_board, Coordinate& attacker_move);
void ResetPlayersData(Player* player1, Player* player2);
void DeletePlayersData(Player*& player1, Player*& player2);
void PrintBoards(Player* defender, Player* attacker);
void PrintScores(Player* player1, Player* player2);
void EasyMode(Player* human, Player* computer, bool& AI_WIN);