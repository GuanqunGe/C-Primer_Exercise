If we use a vector instread of a set to hold the line numbers, then:
1. duplicate line numbers will be saved to the vector
2. when printing out line content, we need to skip elements in the line number vector
to avoid printing out the same line more than once.

Personally I like vector, (or multiset) better, even though this means save duplicate 
information. Because in this way, I don't need to go deep into the file content again 
just to count the frequency of the word. 
