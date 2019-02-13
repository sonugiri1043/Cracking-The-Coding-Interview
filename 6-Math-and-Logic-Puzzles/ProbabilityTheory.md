## gcd
gcd * lcm = x * y

## Checking for Primality
Iterate only up through the square root of n when checking for divisibility.

## Generating a List of Primes: The Sieve of Eratosthenes
We start with a list of all the numbers up through some value max. First, we
cross off all numbers divisible by 2. Then, we look for the next prime ( the
next non-crossed off number ) and cross off all numbers divisible by it. By
crossing off all numbers divisible by 2, 3, 5, 7, 11, and so on, we wind up
with a list of prime numbers from 2 through max.

## Probability:
Probability of A and B
P( A and B ) = P( B given A ) . P(A)

**example**:
What's the probability of picking an even number and a number between 1 and 5.
The odds of picking a number between 1 and 5 is 50%, and the odds of a number
between 1 and 5 being even is 40%. So, the odds of doing both are:

P( x is even and x <= 5 ) = P( x is even given x <= 5 ). P( x <= 5 )
 = ( 2/5 ) * ( 1/2 )
 = 1/5

Observe that since 'P( A and B ) = P( B given A ) P(A)' the probability of A given B
in terms of the reverse:
P( A given B ) = P( B given A ).P(A) / P(B)
The above equation is called Bayes'Theorem.

### Probability of A or B
P( A or B ) = P(A) + P(B) - P( A and B )

### Independence
If A and B are independent ( that is, one happening tells you nothing about the other
happening ), then
P( A and B ) = P(A).P(B)

This rule simply comes from recognizing that P( B given A ) = P(B), since A indicates
nothing about B.

### Mutual Exclusivity
If A and B are mutually exclusive ( that is, if one happens, then the other cannot happen ), then
P( A or B ) = P(A) + P(B)

This is because P( A and B ) = 0, so this term is removed from the earlier 
P(A or B) equation.

Many people, strangely, mix up the concepts of independence and mutual exclusivity. They are
entirely different. In fact, two events cannot be both independent and mutually exclusive
( provided both have probabilities greater than 0 ). Why? Because mutual exclusivity means
that if one happens then the other cannot. Independence, however, says that one event happening
means absolutely nothing about the other event. Thus, as long as two events have non-zero probabilities,
they will never be both mutually exclusive and independent.