/*
  Deck of Cards:

  Design the data structures for a generic deck of cards. Explain how you would
  subclass the data structures to implement blackjack.
 */

#include <iostream>    // std::cout, std::endl
#include <string>      // std::string
#include <vector>      // std::vector
#include <algorithm>   // std::random_shuffle, std::sort

using namespace std;

/* Rank for cards */
enum Rank { ACE = 1,
	    TWO,
	    THREE,
	    FOUR,
	    FIVE,
	    SIX,
	    SEVEN,
	    EIGHT,
	    NINE,
	    TEN,
	    JACK,
	    QUEEN,
	    KING,
	    INVALID_RANK,
};

/* Card Type */
enum Suit {
  CLUB = 1,
  DIAMOND,
  HEART,
  SPADE,
  INVALID_SUIT,
};

/* Represents a Card */
class Card {
  Suit _suit;
  Rank _rank;
public:
  Card( Suit suit_, Rank rank_ ): _suit( suit_ ), _rank( rank_ ) {}

  Suit suit() {
    return _suit;
  }

  Rank rank() {
    return _rank;
  }
};

struct CardComparator {
  static bool before( Card *card1, Card *card2 ) {
    if( card1->suit() < card2->suit() ) {
      return true;
    }
    if( card1->suit() == card2->suit() ) {
      if( card1->rank() < card2->rank()) {
	return true;
      }
    }
    return false;
  }
};

class CardFactory {
public:
  static Card* createCard( int cardNum ) {
    Suit suit = getSuit( ( cardNum / 13 ) + 1 );
    Rank rank = getRank( ( cardNum % 13 ) + 1 );
    Card *card = new Card( suit, rank );
    return card;
  }
  
  static Rank getRank( int rankNum ) {
    switch( rankNum ) {
    case 1 : return Rank::ACE;
    case 2 : return Rank::TWO;
    case 3 : return Rank::THREE;
    case 4 : return Rank::FOUR;
    case 5 : return Rank::FIVE;
    case 6 : return Rank::SIX;
    case 7 : return Rank::SEVEN;
    case 8 : return Rank::EIGHT;
    case 9 : return Rank::NINE;
    case 10 : return Rank::TEN;
    case 11 : return Rank::JACK;
    case 12 : return Rank::QUEEN;
    case 13 : return Rank::KING;
    }
    return Rank::INVALID_RANK;
  }

  static Suit getSuit( int suitNum ) {
    switch( suitNum ) {
    case 1 : return Suit::CLUB;
    case 2 : return Suit::DIAMOND;
    case 3 : return Suit::HEART;
    case 4 : return Suit::SPADE;
    }
    return Suit::INVALID_SUIT;
  }
};

class Deck {
  vector< Card *> deckOfCards;
  CardFactory cardFactory;

public:
  Deck() {}

  Deck( int numOfCards ) {
    for( int i = 0; i < numOfCards; i++ ) {
      deckOfCards.push_back( cardFactory.createCard( i ) );
    }
  }

  void shuffleCards() {
    // using built-in random generator
    random_shuffle( deckOfCards.begin(), deckOfCards.end() );
  }
  
  void sortCards() {
    // sort in non-decreasing order
    sort( deckOfCards.begin(), deckOfCards.end(), CardComparator::before );
  }
  
  Card * getTopCard() {
    Card *card = deckOfCards.back();
    deckOfCards.pop_back();
    return card;
  }
  
  void addCard( Card *c ) {
    deckOfCards.push_back( c );
  }

  void showDeck() {
    vector< Card *>::iterator it;
    for( it = deckOfCards.begin(); it != deckOfCards.end(); it++ )
      cout<< (*it)->suit() << " " << (*it)->rank() << endl;
  }
};

class Player {
  string name;
  Deck *deck;
public:
  Player( string playerName ) {
    name = playerName;
    deck = new Deck();
  }

  void addCard( Card *c ) {
    deck->addCard( c );
  }
};

class Dealer {
  Deck *deck;
public:
  Dealer( int deckSize ) {
    deck = new Deck( deckSize );
    deck->shuffleCards();
  }

  void deal( vector< Player * > &players, int numOfCards ) {
    for( Player* player : players ) {
      for( int i = 0; i < numOfCards; i++ ) {
	player->addCard( deck->getTopCard() );
      }
    }
  }
};

int main() {
  /* Test code for Deck 
  Deck deck( 52 );
  cout << "Deck of cards" << endl;
  deck.showDeck();
  cout << "Deck of cards after shuffling" << endl;
  deck.shuffleCards();
  deck.showDeck();
  deck.sortCards();
  cout << "Deck of cards after sorting" << endl;
  deck.showDeck();
  */

  int numOfPlayers = 4;
  int numOfCards = 52;
  vector< Player *> players;
  players.push_back( new Player( "Vijay" ) );
  players.push_back( new Player( "Ravi" ) );
  players.push_back( new Player( "Nikhil" ) );
  players.push_back( new Player( "Sonu" ) );
  
  Dealer* dealer = new Dealer( numOfCards );
  dealer->deal( players, numOfPlayers );
  return 0;
}
