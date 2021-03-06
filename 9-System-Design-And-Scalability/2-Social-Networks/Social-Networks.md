## Social Network
How would you design the data structures for a very large social network like Facebook or LinkedIn?
Describe how you would design an algorithm to show the shortest path between two people
(e.g., Me -> Bob -> Susan -> Jason -> You).

## Solution
A good way to approach this problem is to remove some of the constraints and solve it for that situation
first.
### Step 1: Simplify the Problem-Forget About the Millions of Users
First, let's forget that we're dealing with millions of users. Design this for the simple case.

We can construct a graph by treating each person as a node and letting an edge between two nodes indicate
that the two users are friends. If I wanted to find the path between two people, I could start with one
person and do a simple breadth-first search.

**Why wouldn't a depth-first search work well?** First, depth-first search would just find a path. It wouldn't
necessarily find the shortest path. Second, even if we just needed any path, it would be very inefficient. Two
users might be only one degree of separation apart, but I could search millions of nodes in their "subtrees"
before finding this relatively immediate connection.

Alternatively, I could do what's called a bidirectional breadth-first search. This means doing two breadth first
searches, one from the source and one from the destination. When the searches collide, we know we've found a path.

In the implementation, we'll use two classes to help us. BFSData holds the data we need for a breadth-first
search, such as the isVisited hash table and the toVisit queue. PathNode will represent the path as
we're searching it, storing each Person and the previousNode we visited in this path.

```c++
/* Look at code in this directory for shortest distance between 2 nodes in a graph */
class BFSData {
  public:
    queue<PathNode *> toVisit;
    unordered_map< int, PathNode *> visited;
      
    bool isFinished() {
       return toVisit.isEmpty();
    }
};
```

### Step 2: Handle the Millions of Users
When we deal with a service the size of Linkedln or Facebook, we cannot possibly keep all of our data on
one machine. That means that our simple Person data structure doesn't quite work-our friends may not live on
the same machine as we do. Instead, we can replace our list of friends with a list of their IDs, and traverse.

- Optimization: Reduce machine jumps
Jumping from one machine to another is expensive. Instead of randomly jumping from machine to machine
with each friend, try to batch these jumps- e.g., if five of my friends live on one machine, I should look them
up all at once.
- Optimization: Smart division of people and machines
People are much more likely to be friends with people who live in the same country as they do. Rather than
randomly dividing people across machines, try to divide them by country, city, state, and so on. This will
reduce the number of jumps.

**Question: Breadth-first search usually requires "marking" a node as visited. How do you do that in
this case?**
Usually, in BFS, we mark a node as visited by setting a visited flag in its node class. Here, we don't want to
do that. There could be multiple searches going on at the same time, so it's a bad idea to just edit our data.
Instead, we could mimic the marking of nodes with a hash table to look up a node id and determine whether it's
been visited.