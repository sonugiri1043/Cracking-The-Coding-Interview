## System Design And Scalability

# TinyURL example
Step 1: Scope the problem
If you're asked something such as "Design TinyURL: You'll want to understand what exactly
you need to implement. Will people be able to specify their own short URLs? Or will it all
be auto-generated? Will you need to keep track of any stats on the clicks? Should the URLs
stay alive forever, or do they have a timeout?

These are questions that must be answered before going further.

Make a list of the major features or use cases. For example, for TinyURL, it might be:
- Shortening a URL to a TinyURL.
- Analytics for a URL.
- Retrieving the URL associated with a TinyURL.
- User accounts and links management.

Step 2: Make Reasonable Assumptions
It's okay to make some assumptions (when necessary), but they should be reasonable.
For example, it would not be reasonable to assume that your system only needs to process 100
users per day, or to assume that you have infinite memory available. However, it might be reasonable
to design for a max of one million new URLs per day. Making this assumption can help you calculate
how much data your system might need to store.

Step 3: Draw the Major Components
Draw a diagram of the major components. You might have something like a frontend server
(or set of servers) that pull data from the backend's data store. You might have another
set of servers that crawl the internet for some data, and another set that process analytics.
Draw a picture of what this system might look like.
Walk through your system from end-to-end to provide a flow. A user enters a new URL. Then what?

Step 4: Identify the Key Issues
Once you have a basic design in mind, focus on the key issues. What will be the bottlenecks or
major challenges in the system?
For example, if you were designing TinyURL, one situation you might consider is that while some
URLs will be infrequently accessed, others can suddenly peak. This might happen if a URL is posted
on Reddit or another popular forum. You don't necessarily want to constantly hit the database.

Step 5: Redesign for the Key Issues
Once you have identified the key issues, it's time to adjust your design for it. You might find that
it involves a major redesign or just some minor tweaking (like using a cache). Stay up at the whiteboard
here and update your diagram as your design changes.