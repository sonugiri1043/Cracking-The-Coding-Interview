## Chess Test
We have the following method used in a chess game: boolean canMoveTo( int x, int y).
This method is part of the Piece class and returns whether or not the piece can move
to position (x, y) . Explain how you would test this method.

## Solution
Two primary types of testing: extreme case validation (ensuring that the program doesn't
crash on bad input), and general case testing.

### Testing Type 1: Extreme Case Validation
We need to ensure that the program handles bad or unusual input gracefully. This means checking the
following conditions:
- Test with negative numbers for x and y
- Test with x larger than the width
- Test with y larger than the height
- Test with a completely full board
- Test with an empty or nearly empty board
- Test with far more white pieces than black
- Test with far more black pieces than white

### Testing Type 2: General Testing
There are 6 pieces in chess, so we can test each piece against every other piece, in every possible direction.
This would look something like the below code:
```python
for each piece a:
   for each other type of piece b (6 types + empty space)
     for each direction d
         Create a board with piece a.
         Place piece b in direction d.
         Try to move - check return value.
```