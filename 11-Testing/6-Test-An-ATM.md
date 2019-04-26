## Test an ATM
How would you test an ATM in a distributed banking system?

## Solution
The first thing to do on this question is to clarify assumptions. Ask the following questions:
- Who is going to use the ATM? Answers might be "anyone", or it might be "blind people" or any number
of other answers.
- What are they going to use it for? Answers might be "withdrawing money," "transferring money",
"checking their balance", or many other answers.
- What tools do we have to test? Do we have access to the code, or just to the ATM?

Remember: a good tester makes sure he knows what he's testing!

Once we understand what the system looks like, we'll want to break down the problem into different testable
components. These components include:
- Logging in
- Withdrawing money
- Depositing money
- Checking balance
- Transferring money
We would probably want to use a mix of manual and automated testing.

Manual testing would involve going through the steps above, making sure to check for all the error cases
(low balance, new account, nonexistent account, and so on).

Automated testing is a bit more complex. We'll want to automate all the standard scenarios, as shown
above, and we also want to look for some very specific issues, such as race conditions. Ideally, we would be
able to set up a closed system with fake accounts and ensure that, even if someone withdraws and deposits
money rapidly from different locations, he never gets money or loses money that he shouldn't.

Above all, we need to prioritize security and reliability. People's accounts must always be protected, and we
must make sure that money is always properly accounted for. No one wants to unexpectedly lose money! A
good tester understands the system priorities.