## Web Crawler
**If you were designing a web crawler, how would you avoid getting into infinite loops?**


## Solution
If we picture the web as a graph of links, an infinite loop will occur when a cycle occurs.
To prevent infinite loops, we just need to detect cycles. One way to do this is to create a
hash table where we set hash [ v ] to true after we visit page v.

We can crawl the web using breadth-first search. Each time we visit a page, we gather all its
links and insert them at the end of a queue. If we've already visited a page, we ignore it.

**This is great but what does it mean to visit page v? Is page v defined based on its content or its URL?**
If it's defined based on its URL, we must recognize that URL parameters might indicate a completely
different page. For example, the page www.github.com/Microsoft is totally different from the page
www.github.com/Google. But, we can also append URL parameters arbitrarily to any URL without truly
changing the page, provided it's not a parameter that the web application recognizes and handles.
The page www.careercup.com?foobar=hello is same a swww.careercup.com.

Identifying page based on contest also doesn't work. Suppose I have some randomly generated content
on the xyz.com home page. Is it a different page each time you visit it? Not really.

The reality is that there is probably no perfect way to define a "different" page, and this is where
this problem gets tricky.

One way to tackle this is to have some sort of estimation for degree of similarity. If, based on the
content and the URL, a page is deemed to be sufficiently similar to other pages, we deprioritize crawling
its children. For each page, we would come up with some sort of signature based on snippets of the content
and the page's URL.

Let's see how this would work.

We have a database which stores a list of items we need to crawl. On each iteration, we select the highest
priority page to crawl. We then do the following:
- 1. Open up the page and create a signature of the page based on specific subsections of the page and its
URL.
- 2. Query the database to see whether anything with this signature has been crawled recently.
- 3. If something with this signature has been recently crawled, insert this page back into the database at a	
low priority.
- 4. If not, crawl the page and insert its links into the database.

Under the above implementation, we never "complete" crawling the web, but we will avoid getting stuck
in a loop of pages. If we want to allow for the possibility of "finishing" crawling the web ( which would
clearly happen only if the "web" were actually a smaller system, like an intranet ), then we can set a minimum
priority that a page must have to be crawled.

**Bot Traps**
A bot trap is a section of a page that keeps generating new links with unique URLs and you will essentially
get trapped in an "infinite loop" by following the links that are being served by that page. This is not exactly
a loop, because a loop would be the result of visiting the same URL, but it's an infinite chain of URLs which
you should avoid crawling.