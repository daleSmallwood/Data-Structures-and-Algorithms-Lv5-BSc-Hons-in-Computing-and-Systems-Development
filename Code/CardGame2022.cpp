#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <string>
#define MAX 52
using namespace std;
using std::vector;
using std::string;


enum Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
string cards[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
int CardPoints[13] = { 11,2,3,4,5,6,7,8,9,10,10,10,10 };
enum Suit { Spades, Hearts, Diamonds, Clubs };
int UserCardPoint;
string UserCard;
int DealerCardPoint;
string DealerCard;

struct Card 
{
	Rank rank;
	Suit suit;
	int num_suits = 4;
	int num_ranks = 13;
};


struct Deck 
{
	vector<Card> cards;
	int max_deck_size = 52;
};

struct Player 
{
	vector<Card> hand;
	string name;
};


struct Game
{
	vector<Player> players;
	Deck deck;
	int num_players = 2;
	int num_cards_per_hand = 1;
};





/*
class card {
public:
	char face;
	string suit;

	void printcard() {
		cout << face << " of " << suit;
	}

};
card deck[52], temp;
*/

/*
class cardDeck {

public:
 void Deck() {

		srand(time(0));
		char face[]{ 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
		string suit[]{ "Hearts","Diamonds","Clubs","Spades" };

		int cardSuit, cardNumber, fullCard{};

		for (cardSuit = 0; cardSuit < 4; cardSuit++) 
		{
			for (cardNumber = 0; cardNumber < 13; cardNumber++)
			{
				deck[fullCard].face = face[cardNumber];
				deck[fullCard].suit = suit[cardSuit];
				fullCard++;
				//generateCardNumber();
			}
		}


	}


};
*/

/*     
public class linearQueue
	
{
   
	void queue() 
	{
		private int front, back;
		private int[] nums;

		public linearQueue(int size) 
		{
			this.front = this.back = -1;
			this.nums = new int[size];
		}
	}
	
};

int queue[MAX], front= -1, rear = -1, cardNumber = 52;

void enqueue(int queue[], int cardNumber)
{
	if (rear == -1)
	{
		front = rear = 0;
		queue[rear] = cardNumber;
	}
	else if (rear == MAX - 1)
	{
		printf("\n too many cards \n");
		return;
	}
	else
	{
		rear++;
		queue[rear] = cardNumber;
	}
	printf("card added\n");
	
}
void generateCardNumber ()
{
	cardNumber = cardNumber + 1;
	enqueue(queue, cardNumber);

}
void showCardQueue(int queue[])
{
	if (rear == -1)
	{
		printf("\n card pile is empty.\n");
		return;
	}
	printf("\nCards in deck\n");
	for (int i = front; i <= rear; i++)
	{
		printf("%i\n", queue[i]);
	}
	printf("\n");

}

void update(int queue[])
{
	if (front == -1)
	{
		printf("\n Card pile is empty.");
		printf("\n\n");
		return;
	}
	else if (front == rear)
	{
		cardNumber = queue[front];
		front = rear = -1;
	}
	else
	{
		cardNumber = queue[front];
		front++;
	}
	printf("\n next card is: %i", cardNumber);
	printf("\n\n");
}

*/

/*
class cardQueue
{
	public:
		void cardQueue();
		{
			queue<int> cardQueue;
			for(int deck = 0; deck <51; deck++ ) 
			{
				cout << "enqueueing" << deck << endl;
				cardQueue.push(deck);
			}
			cout << "size of queue" << cardQueue.size() << endl;
			cout << "back of queue" << cardQueue.back() << endl;


		}
			

};
	
*/

//cardDeck theDeck;
//theDeck.Deck();


void bubbleSort(string array[], int size) 
{
	for (int step = 0; step < size; ++step) 
	{
		for (int CardPostion = 0; i < size - step; ++CardPostion)
		{
			if (array[CardPostion] > array[CardPostion + 1])
			{
				string temp = array[CardPostion];
				array[CardPostion] = array[CardPostion + 1];
				array[CardPostion + 1] = temp;
			}
		}
	}
}
void bubbleSortpoints(int array[], int size) 
{
	for (int step = 0; step < size; ++step) 
	{
		for (int CardPostion = 0; CardPostion < size - step; ++CardPostion)
		{
			if (array[CardPostion] > array[CardPostion + 1])
			{
				int temp = array[CardPostion];
				array[CardPostion] = array[CardPostion + 1];
				array[CardPostion + 1] = temp;
			}
		}
	}
}


void initialize(Deck&);
void print_deck(const Deck&);
void print_card(const Card&);
void shuffle(Deck&);
bool deal_cards(Game&);
void print_hand(const vector<Card>&);
void initialize(Game&);
void add_players(Game&);
void print_game(const Game&);
bool quit = false;
void menu();



	
int main()
{

	Game game;
	
	//initialize(game);
	//deal_cards(game);
	//print_game(game);

	do
	{
		menu();
	} while (!quit);
	system("cls");
}
		

void initialize(Deck& deck)
{

	Card card;
	for (int suit = 0; suit < card.num_suits; suit++)
	{
		for (int rank = 0; rank < card.num_ranks; rank++)
		{
			card.suit = Suit(suit);
			card.rank = Rank(rank);
			deck.cards.push_back(card);
		}
	}
}
void print_deck(const Deck& deck)
{
	for (Card c : deck.cards)
	{
		print_card(c);
	}
}
void print_card(const Card& card) 
{
	std::cout << "Rank =" << card.rank << "  "
		<< "Suit = " << card.suit << 'n';
}
bool deal_cards(Game& game)
{
	if (game.deck.cards.size() < game.num_players * game.num_cards_per_hand) 
	{
		return false;
	}

	for (int card = 0; card <game.num_cards_per_hand; card++)
	{
		for (int player = 0; player < game.num_players; player++)
		{
			game.players[player].hand.push_back(game.deck.cards[0]);
			game.deck.cards.erase(game.deck.cards.begin());
		}

	}
	return true;
}
void print_hand(const vector<Card>& hand)
{
	for (Card c : hand)
	{
		print_card(c);
	}
}
void initialize(Game& game)
{
	initialize(game.deck);
	shuffle(game.deck);
	add_players(game);
}
void add_players(Game& game)
{
	for (int player = 0; player < game.num_players; player++);
	{
		Player new_player;
		game.players.push_back(new_player);
	}
}
void print_game(const Game& game)
{

	for (int player = 0; player < game.num_players; player++)
	{
		print_hand(game.players[player].hand);
		std::cout << "\n";
		
	}

	print_deck(game.deck);
}



void menu() {
	
	system("cls");
	int input;
	cout << "\n                              Dale's Highest card wins!\n";
	cout << "Shuffle the deck 1.\n";
	cout << "Order the deck   2.\n";
	cout << "Show the deck    3.\n";
	cout << "Draw a card      4.\n";
	cout << "Exit             5.\n";
	cout << "Please input a corresponding number:"; cin >> input;
	if (input == 1) 
	{
		void shuffle(Deck & deck);
	}
	
	else if (input == 2) 
	{
		//order();
	}
	
	else if (input == 3) 
	{
		system("cls");
		void print_deck(const Deck & deck);
		{
			cout << "\nReturn to menu   1.\n";
			cout << "Exit             2.\n";
			cout << "Please input a corresponding number:"; cin >> input;
			if (input == 1)
			{
				menu();
			}
			else if (input == 2)
			{
				quit = true;
			}

		}
		
	}
	else if (input == 4) {
		void print_card(const Deck&);
		{
			cout << "\n                                       Highest card wins!\n\n";
			cout << "\n Players card:"; 

			cout << "\n\n\n what would you like to do?";
			cout << "\n Swap it!                      1.";
			cout << "\n Keep it!                      2.";
			cout << "\n Please input a corresponding number:"; cin >> input;
			if (input == 1)
			{
				menu();
			}
			else if (input == 2)
			{
				quit = true;
			}


		}
	}
	else if (input == 5) {
		quit = true;
	}

}


/*
	attempted index 
void shuffle(shuffledDeck& deck)
{
	system("cls");
	int input;
	Deck shuffled;
	while (!deck.card.empty())
	{
		size_t rand_index = rand() % deck.cards.size();
		shuffled.cards.push_back(deck.cards[rand_index]);
		deck.cards.erase(deck.card.begin() + rand_index);

	}
	deck = shuffled;
	cout << "                        Deck has been shuffled.\n";
	cout << "\nReturn to menu 1.";
	cout << "\nShow deck      2.";
	cout << "\nExit           3.";
	cout << "Please input a corosponding number:"; cin >> input;
	if (input == 1) {
		menu();
	}
	else if (input == 2) {
		printDeck();
		{
			cout << "\nReturn to menu   1.\n";
			cout << "Exit               2.\n";
			cout << "Please input a corresponding number:"; cin >> input;
			if (input == 1)
			{
				menu();
			}
			else if (input == 2)
			{
				quit = true;
			}
		}
	}
	else if (input == 3) {
		quit = true;
	}


} 

	 current working shuffle 

	int input;
	int numberOfCards, shuffleCards;
	for (numberOfCards = 0; numberOfCards < 52; numberOfCards++) {
	shuffleCards = rand() % 52;
	temp = deck[numberOfCards];
	deck[numberOfCards] = deck[shuffleCards];
	deck[shuffleCards] = temp;

}
*/


// this shuffles the cards.
void shuffle(Deck& deck)
{ 
	Deck shuffled;
	int input;
	
	while (!deck.cards.empty())
	{
		size_t rand_index = rand() % deck.cards.size();
		shuffled.cards.push_back(deck.cards[rand_index]);
		deck.cards.erase(deck.cards.begin() + rand_index);
	}
	deck = shuffled;

	system("cls");
	
	
	cout << "                        Deck has been shuffled.\n";
	cout << "\nReturn to menu 1.";
	cout << "\nShow deck      2.";
	cout << "\nExit           3.";
	cout << "Please input a corosponding number:"; cin >> input;
		
	if (input == 1)
	{
		menu();
	}
	else if (input == 2) {
		void print_deck(Deck & deck);
		{
			cout << "\nReturn to menu   1.\n";
			cout << "Exit               2.\n";
			cout << "Please input a corresponding number:"; cin >> input;
			if (input == 1)
			{
				menu();
			}
			else if (input == 2)
			{
				quit = true;
			}
		}
	}
	else if (input == 3) {
		quit = true;
	}


}

void order() 
{

}

/*
void printDeck(game.deck)
{
	int Card;
	for (Card = 0; Card < 52; Card++) {
		deck[Card].printcard();
		cout << "\n";


	}
}
*/

void draw() 
{
	//deck[0].printcard();
	//update(queue);
	//view(queue);
}

void swap() 
{

}

void playAgain()
{

}
void cardqueue()
{
	//view(queue);
}










// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
