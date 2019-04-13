# Stock Data
Imagine you are building some sort of service that will be called by up to 1000 client
applications to get simple end-of-day stock price information (open, close, high, low). You may
assume that you already have the data, and you can store it in any format you wish. How would you
design the client-facing service that provides the information to client applications? You are responsible
for the development, rollout, and ongoing monitoring and maintenance of the feed. Describe
the different methods you considered and why you would recommend your approach. Your service
can use any technologies you wish, and can distribute the information to the client applications in
any mechanism you choose.

## Solution
Focus on how we actually distribute the information to clients. Assume that we have some scripts that
magically collect the information. Different aspects we should consider in a given proposal
are:
- Client Ease of Use
- Ease for Ourselves
- Cost of maintenance
- Flexibility for Future Demands
- Scalability and Efficiency

### Proposal 1
One option is that we could keep the data in simple text files and let clients download the data through
some sort of FTP server. This would be easy to maintain in some sense, since files can be easily viewed and
backed up, but it would require more complex parsing to do any sort of query. And, if additional data were
added to our text file, it might break the clients' parsing mechanism.

### Proposal 2
We could use a standard SQL database, and let the clients plug directly into that. This would provide the
following benefits:
- Facilitates an easy way for the clients to do query processing over the data, in case there are additional
features we need to support. For example, we could easily and efficiently perform a query such as "return
all stocks having an open price greater than N and a closing price less than M:'
- Rolling back, backing up data, and security could be provided using standard database features. We
don't have to "reinvent the wheel," so it's easy for us to implement.
- Reasonably easy for the clients to integrate into existing applications. SQL integration is a standard
feature in software development environments.

What are the disadvantages of using a SQL database?
- It's much heavier weight than we really need. We don't necessarily need all the complexity of a SQL
backend to support a feed of a few bits of information.
- It's difficult for humans to be able to read it, so we'll likely need to implement an additional layer to view
and maintain the data. This increases our implementation costs.
- Security: While a SQL database offers pretty well defined security levels, we would still need to be very
careful to not give clients access that they shouldn't have. Additionally, even if clients aren't doing
anything "malicious:' they might perform expensive and inefficient queries, and our servers would bear
the costs of that.

These disadvantages don't mean that we shouldn't provide SQL access. Rather, they mean that we should
be aware of the disadvantages.

### Proposal 3
XML is another great option for distributing the information. Our data has fixed format and fixed size:
company_name, open, high, low, closing price. The XML could look like this:
```python
 <root>
 <date value="200S-10-12">
 <company name="foo">
 <open>126.23</open>
 <high>130.27</high>
 <low>122.S3</low>
 <closingPrice>127.30</closingPrice>
 </company>
 <company name="bar">
 <open>s2.73</open>
 <high>66.27</high>
 <low>s0.29</low>
 <closingPrice>s4.91</closingPrice>
 </company>
 </date>
 <date value="2668-10-11"> . • • </date>
 </root>
```

The advantages of this approach include the following:
- It's very easy to distribute, and it can also be easily read by both machines and humans. This is one
reason that XML is a standard data model to share and distribute data. Most languages have a library to
perform XML parsing, so it's reasonably easy for clients to implement.
- We can add new data to the XML file by adding additional nodes. This would not break the client's parser
(provided they have implemented their parser in a reasonable way). Since the data is being stored as XML
 files, we can use existing tools for backing up the data. We don't need to implement our own backup tool.

The disadvantages may include:
- This solution sends the clients all the information, even if they only want part of it. It is inefficient in that
way. 
- Performing any queries on the data requires parsing the entire file.

Regardless of which solution we use for data storage, we could provide a web service for client
data access. This adds a layer to our work, but it can provide additional security, and it may even make it
easier for clients to integrate the system.
However - and this is a pro and a con - clients will be limited to grabbing the data only how we expect or
want them to. By contrast, in a pure SQL implementation, clients could query for the highest stock price,
even if this wasn't a procedure we "expected" them to need.

So which one of these would we use? There's no clear answer. The pure text file solution is probably a
bad choice, but you can make a compelling argument for the SQL or XML solution, with or without a web
service.