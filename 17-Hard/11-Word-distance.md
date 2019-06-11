## Word Distance:
  You have a large text file containing words. Given any two words, find the shortest
  distance (in terms of number of words) between them in the file. If the operation will
  be repeated many times for the same file (but different pairs of words), can you optimize
  your solution?

## Solution
we can traverse the file just once. We remember throughout our traversal where we've last
seen word1 and word2, storing the locations in location1 and location2. If the current
locations are better than our best known location, we update the best locations.


If we need to repeat the operation for other pairs of words, we can create a hash table that
maps from each word to the locations where it occurs. We'll only need to read through the list
of words once. After that point, we can do a very similar algorithm but just iterate through the
locations directly.

Consider the following lists of locations.
listA: {1, 2, 9, 15, 25}
listB: {4, 10, 19}

Picture pointers pA and pB that point to the beginning of each list. Our goal is to make pA and pB
point to values as close together as possible.
The first potential pair is (1, 4) .

If we moved pB, then the distance would definitely get larger. If we moved pA, though, we might get
a better pair. Let's do that.
The second potential pair is (2, 4). This is better than the previous pair, so let's record this as
the best pair.
We move pA again and get (9, 4) . This is worse than we had before.
Now, since the value at pA is bigger than the one at pB, we move pB. We get (9, 10).
Next we get (15, 10), then (15, 19),then (25, 19) .

```c++
include <unordered_map>
#include <vector>
#include <string>
#include <climits>

using std::unordered_map;
using std::vector;
using std::string;

void doScanWord( unordered_map<string, vector<int> > &wordLocationMap, vector<string> words ) {
  for( int i=0; i< words.size(); ++i ) {
    if( wordLocationMap.find( words[i] ) != wordLocationMap.end() ) {
      wordLocationMap[ words[i] ].push_back( i );
    } else {
      vector<int> locations;
      locations.push_back( i );
      wordLocationMap.insert( std::make_pair( words[i], locations ) );
    }
  }
}

int getClosestDistance( vector<int> posWord1, vector<int> posWord2 ) {
  int minDistance = INT_MAX;
  int diff;
  int i = 0;
  int j = 0;
  while( i < posWord1.size() && j < posWord2.size() ) {
    diff = posWord1[i] > posWord2[j] ? posWord1[i] - posWord2[j] : posWord2[j] - posWord1[i];
    if( diff < minDistance ) {
      minDistance = diff;
    }
    if( posWord1[i] < posWord2[j] ) {
      ++i;
    } else {
      ++j;
    }
  }
  return minDistance;
}

int wordDistance( vector<string> words, string word1, string word2 ) {
  unordered_map<string, vector<int> > wordLocationMap;
  doScanWord( wordLocationMap, words );
  vector<int> posWord1 = wordLocationMap[ word1 ];
  vector<int> posWord2 = wordLocationMap[ word2 ];
  return getClosestDistance( posWord1, posWord2 );
}
```
