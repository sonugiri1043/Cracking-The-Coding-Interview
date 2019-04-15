/*
  How does Bi-directional BFS work?
  Simultaneously run two BFS's from both source and target vertices, terminating once
  a vertex common to both runs is discovered. This vertex will be halfway between the
  source and the target.

  Why is it better than BFS?
  Bi-directional BFS will yield much better results than simple BFS in most cases.
  Assume the distance between source and target is k, and the branching factor is B
  (every vertex has on average B edges).

  BFS will traverse 1 + B + B^2 + ... + B^k vertices.
  Bi-directional BFS will traverse 2 + 2B^2 + ... + 2B^(k/2) vertices.

  For large B and k, the second is obviously much faster the the first.
*/
