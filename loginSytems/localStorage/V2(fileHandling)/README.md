# So i am trying to make it as string and store it (JSON.stringify, JSON.parse) and do file handling .(NODE JS WAY)

# Link - https://nodejs.dev/learn/nodejs-streams#an-example-of-a-stream

Difference between stream and streams:
- Streams basically provide two major advantages over using other data handling methods:

Memory efficiency: you don't need to load large amounts of data in memory before you are able to process it
Time efficiency: it takes way less time to start processing data, since you can start processing as soon as you have it, rather than waiting till the whole data payload is available

- For example, in the traditional way, when you tell the program to read a file, the file is read into memory, from start to finish, and then you process it.

Using streams you read it piece by piece, processing its content without keeping it all in memory.


