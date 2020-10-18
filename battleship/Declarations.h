#pragma once
#include <Windows.h>
struct Player;
struct Coordinate;
struct Board;
struct Settings;
enum GAMEMODE
{
	SINGLEPLAYER = 1, MULTIPLAYER
};

enum DIFFICULTY
{
	VeryEasy = 1, Easy, Normal, Hard
};
enum ELEMENTIDS
{
	MISSED = -1, SPACE, HIT, DESTROYER, SUBMARINE, CRUISER, BATTLESHIP, CARRIER
};

enum ARROWKEYS {
	KEY_UP = 72, KEY_DOWN = 80
};

enum SOUNDS
{
	MISS_SOUND, HIT_SOUND
};


#define GREEN 2
#define RED 4
#define YELLOW 6
#define WHITE 7
#define LIGHTRED 12
#define MENU_ITEM_SIZE 15

short GameSettingsScreen(bool inputDevices);
void Wait();
void GetCoordinatesWithMouse(Coordinate& coordinate);
bool CheckAndSet(int** board, int ship_blocks, int ship_id, char orientation, Coordinate coordinate);
COORD GetConsoleCaretPosition(HANDLE hConsoleOutput);
void ClearConsoleArea(COORD pos1, COORD pos2);
void GameSettings(Settings &GS);
short MainScreen(bool inputDevices);
short SoundSettings(bool inputDevices);
short InputDevicesSettings(bool inputDevices);
short MenuInputWithKeyboard(char** options, short size);
short MenuInputWithMouse(char** options, int size);
short GetDiff(bool inputDevices);
void SetShip(int** board, int x, int y, int ship_id);
void ResetAIData(bool gameOver = false);
void ClearStates();
bool  AI(Player* human, Player* computer, short diff, bool sound);
void CopyCoordinate(Coordinate& coo1, Coordinate& coo2);
void RandomCoordinate(int** board, Coordinate& coordinate);
void TypingEffect(const char* text);
void StartScreen();
short GameModeScreen(bool inputDevices);
void PrintMenu(char** options, int size, int selected);
void SoundEffects(short id);
Player* CreatePlayer();
void Game(Settings gs);
void GetCoordinates(Coordinate & coordinate);
void GetOrientation(char& orientation);
void GetValidCoordinates(Board defender_board, Coordinate& attacker_move, bool inputDevice);
void PlacePlayerShip(Board board, int ship_blocks, int ship_id, bool inputDevices);
void GetShipCoordinate(Board board, char& orient, Coordinate& coordinate, short ship_blocks, short ship_id);
bool CheckOverlap(int** board, char orientation, Coordinate coordinate, int ship_blocks);
bool Draw();
bool AttackToOpponent(Player*& defender, Player*& attacker);
void Start(Player* player1, Player* player2, Settings gs);
bool GameOverScreen(bool inputDevices);
void PlaceAIShip(int** board, int ship_blocks, int ship_id);
Player* AISettings();
bool CheckCoordinates(int** board, Coordinate player_move, bool ai = false, bool sides = false,bool orientation = false, bool direction = false);
void PrintWinner(Player* player);
char* InputName();
void ResetPlayersData(Player* player1, Player* player2, bool is_computer, bool inputDevices);
void DeletePlayersData(Player*& player1, Player*& player2);
void PrintBoards(Player* defender, Player* attacker, bool gameMode = false);
void PrintScores(Player* player1, Player* player2);