/*
  Deck of Cards:
  Design the data structures for a generic deck of cards. Explain how you would
  subclass the data structures to implement blackjack.
 */

#include <iostream>
#include <vector>       // std::vector
#include <algorithm>    // std::random_shuffle, std::sort

using namespace std;

/* Rank for cards */
enum Rank { ONE = 1,
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
	    ACE,
};

/* Card Type */
enum Suit {
  CLUB = 1,
  DIAMOND,
  HEART,
  SPADE,
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
  
  // Return 0 when equal
  int compareTo( Card *card2 ) {
    if( card2 == NULL ) {
      return 1;
    }
    if( card2->suit() != this->suit() ) {
      return card2->suit() - this->suit();
    }
    if( card2->rank() != this->rank() ) {
      return card2->rank() - this->rank();
    }
    return 0;
  }
};

class Deck {
  vector< Card *> deckOfCards;

public:
  Deck() {}

  void suffleCards() {
    // using built-in random generator
    random_shuffle( deckOfCards.begin(), deckOfCards.end() );
  }
  
  void sortCards() {
    // sort in non-decreasing order
    sort( deckOfCards.begin(), deckOfCards.end() );
  }
};

int main() {
  return 0;
}
