// dinos.cpp

// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  Then get Valley::display going.  That gives
// you more flexibility in the order you tackle the rest of the functionality.
// As you finish implementing each TODO: item, remove its TODO: comment.

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;

///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////

const int MAXROWS = 20;        // max number of rows in a valley
const int MAXCOLS = 40;        // max number of columns in a valley
const int MAXDINOSAURS = 170;  // max number of dinosaurs allowed

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int NUMDIRS = 4;

///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class Valley;  // This is needed to let the compiler know that Valley is a
			   // type name, since it's mentioned in the Dinosaur declaration.

class Dinosaur
{
public:
	// Constructor
	Dinosaur(Valley* vp, int r, int c);

	// Accessors
	int  row() const;
	int  col() const;

	// Mutators
	void move();

private:
	Valley * m_valley;
	int     m_row;
	int     m_col;
};

class Player
{
public:
	// Constructor
	Player(Valley *vp, int r, int c);

	// Accessors
	int  row() const;
	int  col() const;
	int  age() const;
	bool isDead() const;

	// Mutators
	void   stand();
	void   move(int dir);
	bool   shoot(int dir);
	void   setDead();

private:
	Valley * m_valley;
	int     m_row;
	int     m_col;
	int     m_age;
	bool    m_dead;
};

class Valley
{
public:
	// Constructor/destructor
	Valley(int nRows, int nCols);
	~Valley();

	// Accessors
	int     rows() const;
	int     cols() const;
	Player* player() const;
	int     dinosaurCount() const;
	int     numDinosaursAt(int r, int c) const;
	void    display(string msg) const;

	// Mutators
	bool    addDinosaur(int r, int c);
	bool    addPlayer(int r, int c);
	bool    destroyDinosaur(int r, int c);
	bool    moveDinosaurs();

private:
	int        m_rows;
	int        m_cols;
	Player*    m_player;
	Dinosaur*  m_dinos[MAXDINOSAURS];
	int        m_nDinos;
};

class Game
{
public:
	// Constructor/destructor
	Game(int rows, int cols, int nDinos);
	~Game();

	// Mutators
	void play();

private:
	Valley * m_valley;
};

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir);
int randInt(int min, int max);
void clearScreen();

///////////////////////////////////////////////////////////////////////////
//  Dinosaur implementation
///////////////////////////////////////////////////////////////////////////

Dinosaur::Dinosaur(Valley* vp, int r, int c)
{
	if (vp == nullptr)
	{
		cout << "***** A dinosaur must be created in some Valley!" << endl;
		exit(1);
	}
	if (r < 1 || r > vp->rows() || c < 1 || c > vp->cols())
	{
		cout << "***** Dinosaur created with invalid coordinates (" << r << ","
			<< c << ")!" << endl;
		exit(1);
	}
	m_valley = vp;
	m_row = r;
	m_col = c;
}

int Dinosaur::row() const
{
	return m_row;
}

int Dinosaur::col() const
{
	// TODO: TRIVIAL:  Return the number of the column the Dinosaur is at.
	return m_col;  // Replace this incorrect line "return 1" with the correct code.
}

void Dinosaur::move()
{
	// Attempt to move in a random direction; if we can't move, don't move
	//int j = randInt(0, NUMDIRS - 1);
	//cout << "j = " << j << endl;

	switch (randInt(0, NUMDIRS - 1))
	{
		case UP:
			// TODO:  Move the dinosaur up one row if possible.
			if (m_row >= 2) {
				m_row--;
				//cout << "a dinosaur moved up" << endl;
			}
			break;
		case DOWN:
			if (m_row < m_valley->rows()) {
				m_row++;
				//cout << "a dinosaur moved down" << endl;
			}
			break;
		case LEFT:
			if (m_col >= 2) {
				m_col--;
				//cout << "a dinosaur moved left" << endl;
			}
			break;
		case RIGHT:
			if (m_col < m_valley->cols()) {
				m_col++;
				//cout << "a dinosaur moved right" << endl;
			}
			break;
		default:
		{
			//cerr << "dino movement not recognized" << endl;
			break;
		}
		// TODO:  Implement the other movements.

	}
}

///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

Player::Player(Valley* vp, int r, int c)
{
	if (vp == nullptr)
	{
		cout << "***** The player must be created in some Valley!" << endl;
		exit(1);
	}
	if (r < 1 || r > vp->rows() || c < 1 || c > vp->cols())
	{
		cout << "**** Player created with invalid coordinates (" << r
			<< "," << c << ")!" << endl;
		exit(1);
	}
	m_valley = vp;
	m_row = r;
	m_col = c;
	m_age = 0;
	m_dead = false;
}

int Player::row() const
{
	// TODO: TRIVIAL:  Return the number of the row the player is at.
	return m_row;  // Replace this incorrect line "return 1" with the correct code.
}

int Player::col() const
{
	// TODO: TRIVIAL:  Return the number of the column the player is at.
	return m_col;  // Replace this incorrect line "return 1;" with the correct code.
}

int Player::age() const
{
	// TODO: TRIVIAL:  Return the player's age.
	return m_age;  // Replace this incorrect line "return 0;" with the correct code.
}

void Player::stand()
{
	m_age++;
}

void Player::move(int dir)
{
	m_age++;

	// Attempt to move in the indicated direction; if we can't move, don't move
	switch (dir)
	{
	case UP:	// UP
				// TODO:  Move the player up one row if possible.
		if (m_row >= 2) {
			m_row--;
			return;
		}
		else return;
	case DOWN:
		if (m_row < m_valley->rows()) {
			m_row++;
			return;
		}
		else return;
	case LEFT:
		if (m_col >= 2) {
			m_col--;
			return;
		}
		else
			return;
	case RIGHT:
		if (m_col < m_valley->cols()) {
			m_col++;
			return;
		}
		else
			return;
		// TODO:  Implement the other movements.
	default:
		return;
	}
}

bool Player::shoot(int dir)
{
	m_age++;

	if (randInt(1, 3) > 1) { // miss with 2/3 probability
		cerr << "You missed!" << endl;
		return false;
	}
	// TODO:  Destroy the nearest dinosaur in direction dir
	else {
		if (dir == RIGHT) {
			//cout << "You shot right" << endl;
			for (int k = 1; m_col + k <= m_valley->cols(); k++) {	// loop through positions to the right as long as we are in the valley
				if (m_valley->numDinosaursAt(m_row, m_col + k) > 0) {	// if there is a D at the current position
					//cout << "There are " << (m_valley->numDinosaursAt(m_row, m_col + k)) << " dinosaurs at row and column: " << m_row << m_col + k << endl;
					m_valley->destroyDinosaur(m_row, m_col + k);		// destroy the first D that we find in the loop
					return true;
				}
			}
		}
		else if (dir == LEFT) {
			//cout << "You shot left" << endl;
			for (int k = 1; m_col - k >= 1; k++) {
				if (m_valley->numDinosaursAt(m_row, m_col - k) > 0) {
					//cout << "There are " << (m_valley->numDinosaursAt(m_row, m_col - k)) << " dinosaurs at row and column: " << m_row << m_col - k << endl;
					m_valley->destroyDinosaur(m_row, m_col - k);
					return true;
				}
			}
		}
		else if (dir == UP) {
			//cout << "You shot up" << endl;
			for (int k = 1; m_row - k >= 1; k++) {
				if (m_valley->numDinosaursAt(m_row - k, m_col) > 0) {
					//cout << "There are " << (m_valley->numDinosaursAt(m_row - k, m_col)) << " dinosaurs at row and column: " << m_row - k << m_col << endl;
					m_valley->destroyDinosaur(m_row - k, m_col);
					return true;
				}
			}
		}
		else if (dir == DOWN) {
			//cout << "You shot down" << endl;
			for (int k = 1; m_row + k <= m_valley->rows(); k++) {
				if (m_valley->numDinosaursAt(m_row + k, m_col) > 0) {
					//cout << "There are " << (m_valley->numDinosaursAt(m_row + k, m_col)) << " dinosaurs at row and column: " << m_row + k << m_col << endl;
					m_valley->destroyDinosaur(m_row + k, m_col);
					return true;
				}
			}
		}

	}
	return false;  // Replace this line "return false;" with the correct code.  true???
}

bool Player::isDead() const
{
	// TODO: TRIVIAL:  Return whether the player is dead.
	return m_dead;  // Replace this incorrect line "return false;" with the correct code.
}

void Player::setDead()
{
	m_dead = true;
}

///////////////////////////////////////////////////////////////////////////
//  Valley implementations
///////////////////////////////////////////////////////////////////////////

Valley::Valley(int nRows, int nCols)
{
	if (nRows <= 0 || nCols <= 0 || nRows > MAXROWS || nCols > MAXCOLS)
	{
		cout << "***** Valley created with invalid size " << nRows << " by "
			<< nCols << "!" << endl;
		exit(1);
	}
	m_rows = nRows;
	m_cols = nCols;
	m_player = nullptr;
	m_nDinos = 0;
}

Valley::~Valley()
{
	// TODO:  Delete the player and all remaining dynamically allocated dinosaurs.
	delete m_player;
	for (int k = 0; k < m_nDinos; k++) {
		delete m_dinos[k];
	}
}

int Valley::rows() const
{
	// TODO: TRIVIAL:  Return the number of rows in the valley.
	return m_rows;  // Replace this incorrect line "return 1;" with the correct code.
}

int Valley::cols() const
{
	// TODO: TRIVIAL:  Return the number of columns in the valley.
	return m_cols;  // Replace this incorrect line "return 1;" with the correct code.
}

Player* Valley::player() const
{
	return m_player;
}

int Valley::dinosaurCount() const
{
	return m_nDinos;
}

int Valley::numDinosaursAt(int r, int c) const
{
	// TODO:  Return the number of dinosaurs at row r, column c.
	int sum = 0;
	for (int k = 0; k < m_nDinos && m_dinos[k] != nullptr; k++) {
		if (m_dinos[k]->row() == r && m_dinos[k]->col() == c)
			sum++;
	}
	return sum;  // Replace this incorrect line "return 0;" with the correct code.
}

void Valley::display(string msg) const
{
	// Position (row,col) in the valley coordinate system is represented in
	// the array element grid[row-1][col-1]
	char grid[MAXROWS][MAXCOLS];
	int r, c;

	// Fill the grid with dots
	for (r = 0; r < rows(); r++)
		for (c = 0; c < cols(); c++)
			grid[r][c] = '.';

	// Indicate each dinosaur's position
	// TODO:  If one dinosaur is at some position, set the char to 'D'.
	//        If it's 2 through 8, set it to '2' through '8'.
	//        For 9 or more, set it to '9'.
	for (int k = 0; k < m_nDinos; k++) {
		if (m_dinos[k] != nullptr) {
			int num = numDinosaursAt(m_dinos[k]->row(), m_dinos[k]->col());

			switch (num) {
			case 0:
				break;
			case 1:
				grid[m_dinos[k]->row() - 1][m_dinos[k]->col() - 1] = 'D';
				continue;
			case 2:
				grid[m_dinos[k]->row() - 1][m_dinos[k]->col() - 1] = '2';
				continue;
			case 3:
				grid[m_dinos[k]->row() - 1][m_dinos[k]->col() - 1] = '3';
				continue;
			case 4:
				grid[m_dinos[k]->row() - 1][m_dinos[k]->col() - 1] = '4';
				continue;
			case 5:
				grid[m_dinos[k]->row() - 1][m_dinos[k]->col() - 1] = '5';
				continue;
			case 6:
				grid[m_dinos[k]->row() - 1][m_dinos[k]->col() - 1] = '6';
				continue;
			case 7:
				grid[m_dinos[k]->row() - 1][m_dinos[k]->col() - 1] = '7';
				continue;
			case 8:
				grid[m_dinos[k]->row() - 1][m_dinos[k]->col() - 1] = '8';
				continue;
			default:
				grid[m_dinos[k]->row() - 1][m_dinos[k]->col() - 1] = '9';
				continue;
			}
		}
	}

	// Indicate player's position
	if (m_player != nullptr)
	{
		// Set the char to '@', unless there's also a dinosaur there,
		// in which case set it to '*'.
		char& gridChar = grid[m_player->row() - 1][m_player->col() - 1];
		if (gridChar == '.')
			gridChar = '@';
		else
			gridChar = '*';
	}

	// Draw the grid
	clearScreen();
	for (r = 0; r < rows(); r++)
	{
		for (c = 0; c < cols(); c++)
			cout << grid[r][c];
		cout << endl;
	}
	cout << endl;

	// Write message, dinosaur, and player info
	cout << endl;
	if (msg != "")
		cout << msg << endl;
	cout << "There are " << dinosaurCount() << " dinosaurs remaining." << endl;
	if (m_player == nullptr)
		cout << "There is no player." << endl;
	else
	{
		if (m_player->age() > 0)
			cout << "The player has lasted " << m_player->age() << " steps." << endl;
		if (m_player->isDead())
			cout << "The player is dead." << endl;
	}
}

bool Valley::addDinosaur(int r, int c)
{
	// If MAXDINOSAURS have already been added, return false.  Otherwise,
	// dynamically allocate a new dinosaur at coordinates (r,c).  Save the
	// pointer to the newly allocated dinosaur and return true.

	// TODO:  Implement this

	
	// Dinosaur must be inside the valley
	//if (!(r >= 1 && r <= m_rows && c >= 1 && c <= m_cols)); {
	//cout << "Dinosaur out of bounds" << endl;
	//return false;
	//}
	if (r < 1 || c < 1 || r > rows() || c > cols())
		return false;

	// Don't add a dinosaur on top of the player
	if (m_player != nullptr  &&  m_player->row() == r && m_player->col() == c) {
	cerr << "Don't add a dino on top of the player" << endl;
	return false;
	}

	if (m_nDinos > MAXDINOSAURS) {
	cerr << "Too many dinosaurs already" << endl;
	return false;
	}

	else {
	m_dinos[m_nDinos] = new Dinosaur(this, r, c);	// "this" points to the function itself
	m_nDinos++;
	}
	return true;  // Replace this incorrect line with the correct code.
}

bool Valley::addPlayer(int r, int c)
{
	// Don't add a player if one already exists
	if (m_player != nullptr)
		return false;

	if (r < 1 || c < 1 || r > rows() || c > cols())
		return false;

	if (numDinosaursAt(r, c) > 0)
		return false;

	// Dynamically allocate a new Player and add it to the valley
	m_player = new Player(this, r, c);
	//cout << "player is at row and column: " << r << " " << c << endl;
	return true;
}

bool Valley::destroyDinosaur(int r, int c)
{
	// TODO:  Destroy one dinosaur at row r, column c, and return true.
	//        Return false is there is no dinosaur there to destroy.
	for (int k = 0; k < m_nDinos; k++)
	{
		if (m_dinos[k] != nullptr) {
			if (m_dinos[k]->row() == r && m_dinos[k]->col() == c) {
				delete m_dinos[k];
				m_nDinos--;
				for (int i = k; i < m_nDinos; i++) {
					m_dinos[i] = m_dinos[i + 1];
				}
				return true;
			}

		}
	}
	return false;  // Replace this incorrect line "return false;" with the correct code.
}

bool Valley::moveDinosaurs()
{
		// TODO:  Have the k-th dinosaur in the valley make one move.
		//        If that move results in the dinosaur being at the same
		//        position as the player, the player dies.
		for (int k = 0; k < m_nDinos; k++) {
			m_dinos[k]->move();
			if (m_dinos[k]->row() == m_player->row() && m_dinos[k]->col() == m_player->col()) {
				//cout << "Player has position: [row, col] << " << m_player->row() << " " << m_player->col() << endl;
				//cout << "The dinosaur who ate the Player has position [row, col] " << m_dinos[k]->row() << " " << m_dinos[k]->col() << endl;
				m_player->setDead();
			}
		}
	

	// return true if the player is still alive, false otherwise
	return !m_player->isDead();
}

///////////////////////////////////////////////////////////////////////////
//  Game implementations
///////////////////////////////////////////////////////////////////////////

Game::Game(int rows, int cols, int nDinos)
{
	if (nDinos < 0)
	{
		cout << "***** Cannot create Game with negative number of Dinosaurs!" << endl;
		exit(1);
	}
	if (nDinos > MAXDINOSAURS)
	{
		cout << "***** Trying to create Game with " << nDinos
			<< " dinosaurs; only " << MAXDINOSAURS << " are allowed!" << endl;
		exit(1);
	}
	if (rows == 1 && cols == 1 && nDinos > 0)
	{
		cout << "***** Cannot create Game with nowhere to place the Dinosaurs!" << endl;
		exit(1);
	}

	// Create valley
	m_valley = new Valley(rows, cols);

	// Add player
	int rPlayer = randInt(1, rows);
	int cPlayer = randInt(1, cols);
	m_valley->addPlayer(rPlayer, cPlayer);

	// Populate with dinosaurs
	while (nDinos > 0)
	{
		int r = randInt(1, rows);
		int c = randInt(1, cols);
		cout << "r: " << r << endl;
		cout << "c: " << c << endl;
		// Don't put a dinosaur where the player is
		if (r == rPlayer && c == cPlayer)
			continue;
		m_valley->addDinosaur(r, c);
		nDinos--;
	}
}

Game::~Game()
{
	delete m_valley;
}

void Game::play()
{
	string msg = "";
	m_valley->display(msg);
	Player* player = m_valley->player();
	if (player == nullptr)
		return;

	while (!m_valley->player()->isDead() && m_valley->dinosaurCount() > 0)
	{
		cout << "Move (u/d/l/r/su/sd/sl/sr/q or nothing): ";
		string action;
		getline(cin, action);
		if (action.size() == 0)
			player->stand();
		else
		{
			switch (action[0])
			{
			default:   // if bad move, nobody moves
				cout << '\a' << endl;  // beep
				continue;
			case 'q':
				return;
			case 'u':
			case 'd':
			case 'l':
			case 'r':
				player->move(decodeDirection(action[0]));
				break;
			case 's':
				if (action.size() < 2)  // if no direction, nobody moves
				{
					cout << '\a' << endl;  // beep
					continue;
				}
				switch (action[1])
				{
				default:   // if bad direction, nobody moves
					cout << '\a' << endl;  // beep
					continue;
				case 'u':
				case 'd':
				case 'l':
				case 'r':
					if (m_valley->player()->shoot(decodeDirection(action[1])))		// Originally this line was: if (player->shoot(decodeDirection(action[1])))
						msg = "Hit!";
					else
						msg = "Missed!";
					break;
				}
				break;
			}
		}
		if (!m_valley->player()->isDead()) {
			m_valley->moveDinosaurs();
		}
		m_valley->display(msg);
		msg = "";
	}
	if (m_valley->player()->isDead()) {
		/*
		for (int r = 1; r <= m_valley->rows(); r++)
		{
			for (int c = 1; c <= m_valley->cols(); c++) {
				cout << "There are " << m_valley->numDinosaursAt(r, c) << " dinosaurs at [row,col] " << r << "," << c << endl;
			}

		}
		*/
		//cout << "The player is at [row,col]: " << m_valley->player()->row() << ", " << m_valley->player()->col() << endl; 
		//cout << "The dino who ate you is at [row,col]: " << m_valley->player()->row() << ", " << m_valley->player()->col() << endl;
		cout << "You lose." << endl;
	}
	else
		cout << "You win." << endl;
}

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function implementations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir)
{
	switch (dir)
	{
	case 'u':  return UP;
	case 'd':  return DOWN;
	case 'l':  return LEFT;
	case 'r':  return RIGHT;
	}
	return -1;  // bad argument passed in!
}

// Return a random int from min to max, inclusive
int randInt(int min, int max)
{
	if (max < min)
		swap(max, min);
	static random_device rd;
	static default_random_engine generator(rd());
	uniform_int_distribution<> distro(min, max);
	return distro(generator);
}

///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////

int main()
{
	// Create a game
	// Use this instead to create a mini-game:   Game g(3, 3, 2);
	Game g(20, 40, 170);
	//Game g(15, 18, 100);

	// Play the game
	g.play();
}

///////////////////////////////////////////////////////////////////////////
//  clearScreen implementation
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.  (The Xcode output window doesn't have the capability
// of being cleared.)

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperLeft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <iostream>
#include <cstring>
#include <cstdlib>

void clearScreen()  // will just write a newline in an Xcode output window
{
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
		cout << endl;
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

#endif

