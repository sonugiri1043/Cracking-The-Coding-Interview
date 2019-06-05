## Sparse Similarity: 
  The similarity of two documents (each with distinct words) is defined to be the
  size of the intersection divided by the size of the union. For example, if the documents consist of
  integers, the similarity of {1, 5, 3} and {1, 7, 2, 3} is 0.4, because the intersection has size
  2 and the union has size 5.

  We have a long list of documents (with distinct values and each with an associated ID) where the
  similarity is believed to be "sparse". That is, any two arbitrarily selected documents are very likely to
  have similarity O. Design an algorithm that returns a list of pairs of document IDs and the associated
  similarity.

  Print only the pairs with similarity greater than O. Empty documents should not be printed at all. For
  simplicity, you may assume each document is represented as an array of distinct integers.

```bash
  EXAMPLE
  Input:
  13: {14, 15, 100, 9, 3}
  16: {32, 1, 9, 3, 5}
  19: {15, 29, 2, 6, 8, 7}
  24: {7, 10}

  Output:
  ID1, ID2 SIMILARITY
  13, 19  : 0.1
  13, 16  : 0.25
  19, 24  : 0.14285714285714285
```

## Solution

### Brute Force:
  The intersection means the number of elements in common. Therefore, we can just iterate
  through the first array (A) and check if each element is in the second array (B). If it is,
  increment an intersection variable.

  union( A, B ) = A + B - intersection( A, B )

  Intersection would take O(|A|.|B|). We need to do this for all pairs of D documents. If we
  assume each document has at most W words then the runtime is O(D^2 W^2).


### Slightly Better Brute Force
  We can throw all of A's elements into a hash table. Then we iterate through B, incrementing
  intersection every time we find an element in A.
  This takes O(A + B) time. If each array has size W and we do this for D arrays, then this takes O(D^2 W).

  We'll need to return a list of document pairs and their similarities. We'll use a DocPair class for this.

  ```C++
  // In C++, To be able to use std::unordered_map with a user-defined key-type, you need to define two things:
  // 1. A hash function: a class that overrides operator() and calculates the hash value given an object of
  //                     the key-type
  // 2. A comparison function for equality: overloading operator==()

  #include <unordered_map>
  
  class DocPair {
     int doc1;
     int doc2;

     public:
     DocPair( int doc1, int doc2 ) {
        this->doc1 = doc1;
      	this->doc2 = doc2;
     }
  
     bool operator==( const DocPair &docPair ) const {
        return( docPair.doc1 == this->doc1 &&docPair.doc2 ==this->doc2 );
     }

     size_t hash() const {
        return (doc1 * 31 ) ^ doc2; 
     }
   };

   class Hasher {
      public:
      size_t operator()( const DocPair & doc ) const {
         return doc.hash();
      }
    };

    class EqualFn {
       public:
       bool operator() ( const DocPair & d1, const DocPair & d2) const {
          return d1 == d2;
       }
    };
    std::unordered_map<DocPair, double, Hasher, EqualFn> docPairToScoreMap;
```

### Slightly Better Brute Force (Alternate)
  If the documents were sorted, you could compute the intersection between two documents by walking
  through them in sorted order, much like you would when doing a sorted merge of two arrays.
  This would take O(A + B) time. This is the same time as our current algorithm, but less space. Doing this
  on D documents with W words each would take O(D^2 W) time.

  Since we don't know that the arrays are sorted, we could first sort them. This would take O(D * W log W)
  time. The full runtime then is O(D * W log W + D^2 W).

### Optimized( Somewhat )
  At first, we might try various techniques that allow us to more quickly eliminate potential comparisons.
  For example, could we compute the min and max values in each array? If we did that, then we'd know that
  arrays with no overlap in ranges don't need to be compared.
  The problem is that this doesn't really fix our runtime issue. Our best runtime thus far is O(D^2 W). With this
  change, we're still going to be comparing all O(D^2) pairs, but the O(W) part might go to O( 1) sometimes.
  That O(D^2) part is going to be a really big problem when D gets large.
  Therefore, let's focus on reducing that O(D^2) factor. That is the "bottleneck" in our solution.
  
  Suppose docA is {14, 15, 100, 9, 3}. For a document to have similarity > 0, it needs to have a 14, a 15,
  a 100, a 9, or a 3. How can we quickly gather a list of all documents with one of those elements?
  The slow (and, really, only way) is to read every single word from every single document to find the documents
  that contain a 14, a 15, a 100, a 9, or a 3. That will take O(DW) time. Not good.
  However, note that we're doing this repeatedly. We can reuse the work from one call to the next.

  If we build a hash table that maps from a word to all documents that contain that word, we can very quickly
  know the documents that overlap with docA.
```bash
  1 -> 16
  2 -> 19
  3 -> 13 , 16, 24
  5 -> 16
  6 -> 19
  7 -> 19, 24
  8 -> 19
  9 -> 13, 16
  ...
```

  When we want to know all the documents that overlap with docA, we just look up each of docNs items in
  this hash table. We'll then get a list of all documents with some overlap. Now, all we have to do is compare
  docA to each of those documents.

  If there are P pairs with similarity > 0, and each document has W words, then this will take O(PW) time (plus
  O(DW) time to create and read this hash table). Since we expect P to be much less than D^2, this is much
  better than before.

### Optimized( Better ):
  If we consider the runtime O(PW + DW) - we probably can't get rid of the O(DW) factor. We have to touch each word
  at least once, and there are O( DW ) words. Therefore, if there's an optimization to be made, it's probably in
  the O( PW) term.
  It would be difficult to eliminate the P part in O(PW) because we have to at least print all P pairs (which
  takes 0 (P) time).

  One way to tackle this is to analyze what information the hash table gives us. Consider this list of documents:
  12: {1, 5, 9}
  13: {5, 3, 1, 8}
  14: {4, 3, 2}
  15: {1, 5, 9, 8}
  17: {1, 6}

  If we look up document 12's elements in a hash table for this document, we'll get:
  1 -> {12, 13, 15, 17}
  5 -> {12, 13, 15}
  9 -> {12, 15}

  This tells us that documents 13, 15, and 17 have some similarity. Under our current algorithm, we would
  now need to compare document 12 to documents 13, 15, and 17 to see the number of elements document
  12 has in common with each (that is, the size of the intersection). The union can be computed from the
  document sizes and the intersection, as we did before.

  Observe, though, that document 13 appeared twice in the hash table, document 15 appeared three times,
  and document 17 appeared once. We discarded that information. But can we use it instead? What does it
  indicate that some documents appeared multiple times and others didn't?

  Document 13 appeared twice because it has two elements (1 and 5) in common. Document 17 appeared
  once because it has only one element (1) in common. Document 15 appeared three times because it has
  three elements (1, 5, and 9) in common. This information can actually directly give us the size of the intersection.

  We could go through each document, look up the items in the hash table, and then count how many times
  each document appears in each item's lists. There's a more direct way to do it.

  - 1. As before, build a hash table for a list of documents.
  - 2. Create a new hash table that maps from a document pair to an integer (which will indicate the size of
  the intersection).
  - 3. Read the first hash table by iterating through each list of documents.
  - 4. For each list of documents, iterate through the pairs in that list. Increment the intersection count for
  each pair.