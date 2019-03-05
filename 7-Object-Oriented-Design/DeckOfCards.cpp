/*
  Deck of Cards:
  Design the data structures for a generic deck of cards. Explain how you would
  subclass the data structures to implement blackjack.
 */

#include <iostream>

using namespace std;

/* Rank for cards */
enum Rank {
  ONE,
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
  CLUB,
  DIAMOND,
  HEART,
  SPADE,
};

/* Represents a single Card */
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

int main() {
  return 0;
}
