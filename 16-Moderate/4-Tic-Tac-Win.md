## Tic Tac Win
Design an algorithm to figure out if someone has won a game of tic-tac-toe.

## Solution
The problem is a bit more complex, and there is no single "perfect" answer. The optimal
solution depends on your preferences.

There are a few major design decisions to consider:
- Will hasWon be called just once or many times ( for instance, as part of a tic-tac-toe website )?
  If the latter is the case, we may want to add pre-processing time to optimize the runtime of hasWon.
- Do we know the last move that was made?
- Tic-tac-toe is usually on a 3x3 board. Do we want to design for just that or do we want to implement
  it as an NxN solution?

### Solution 1: If hasWon is called many times
There are only 3^9, or about 20000, tic-tac-toe boards (assuming a 3x3 board). Therefore, we can represent
our tic-tac-toe board as an int, with each digit representing a piece (0 -> Empty, 1 -> Red, 2 -> Blue).
We set up a hash table or array in advance with all possible boards as keys and the value indicating who has
won.

```c++
enum Piece { Empty, Red, Blue };

Piece hasWon( int board ) {
   return winnerMap[ board ];
}

/* Using base 3 representation */
int convertBoardToInt( vector< vector< Piece > > board ) {
   int sum = 0;
   for( int i = 0; i < board.size(); ++i ) {
      for( int j = 0; j < board[i].size(); ++j ) {
         sum = sum*3 + board[i][j];
      }
   }
   return sum;
}
```

### Solution 2: If we know the last move
If we know the very last move that was made (and we've been checking for a winner up until now), then we
only need to check the row, column, and diagonal that overlaps with this position.

```c++
Piece hasWon( vector< vector< Piece> > board, int row, int column ) {
   if( board.size() != board[0].size() )
       return Piece.Empty;

   Piece piece = vector[ row ][ column ];
   if( piece == Piece.Empty )
      return Piece.Empty;
   
   if( hasWonRow( board, row ) || hasWonColumn( board, column ) ) {
      return Piece;
   }
   if( row == column && hasWonDiagonal( board, 1 ) ) ) {
      return Piece;
   }
   if( row == ( board.size() - column - 1 ) && hasWonDiagonal( board, -1 ) ) {
      return Piece;
   }
   return Piece.Empty;
}

bool hasWonRow( vector< vector< Piece> > board, int row ) {
   for( int i=1; i < board[row].size(); ++i ) {
      if( board[row][0] != board[row][i] ) {
         return false;
      }
   }
   return true;
}

bool hasWonColumn( vector< vector<Piece> > board, int col ) {
   for( int j=1; j< board.size(); ++j ) {
     if( board[0][col] != board[j][col] ) {
     	return false;
     }
   }
   return true;
}

bool hasWonDiagonal( vector< vector<Piece> > board, int direction ) {
   /* direction is 1 or -1 */
   int row = 0;
   int column = direction == 1 ? 0 : board.size() - 1;
   Piece first = board[row][column]
   for( int i = 0; i < board.size; ++i ) {
      if( first != board[ row ][ column ] ) {
      }
      row += 1;
      column += direction;
   }
   return true;
}
```

### Solution 3: Designing for just a 3x3 board
If we really only want to implement a solution for a 3x3 board, the code is relatively short and simple. The
only complex part is trying to be clean and organized, without writing too much duplicated code.
The code below checks each row, column, and diagonal to see if there is a winner.

### Solution 4: Designing for an NxN board
There are a number of ways to implement this on an NxN board.
### Nested For-Loops
The most obvious way is through a series of nested for-loops.
