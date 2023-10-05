#include <stdio.h>

int main() {
    //We use an unsigned int because the count cannot be negative
    unsigned int sentenceCount;
    //Get an an unsigned int for input
    scanf("%u", &sentenceCount);
    //Create the array of strings (sentences)
    char sentences[1000000][101];
    //Add one to the sentence count so that the following loop statement works properly (convert from 0-start to 1-start
    sentenceCount++;

    //Loop for the count, (the amount of sentences)
    for(size_t i=0; i<sentenceCount; ++i) {
        //input the sentence at sentence -1
        fgets(sentences[i], 101, stdin);
    }

    //Make variables to count s/S and t/T
    unsigned int tCount = 0;
    unsigned int sCount = 0;

    //Loop through all the sentences
    for(size_t i=0; i<sentenceCount; ++i) {
        //get the length of the stream.
        size_t strLen = 0;
        //Make a for loop that increments the strLen variables until it hits the end of string char '\0', which gives us the length of the string
        for(;sentences[i][strLen] != '\0'; ++strLen);
        //We iterate through each letter of the string at i
        for(size_t j=0; j<strLen; ++j) {
            //If the letter == t or T add to tCount
            if(sentences[i][j] == 't' || sentences[i][j] == 'T') {
                tCount++;
            }
            //If the letter == s or S add to sCount
            if(sentences[i][j] == 's' || sentences[i][j] == 'S') {
                sCount++;
            }
        }

    }

    //Check with the conditions stated on the Problem, and print English or French
    if(tCount > sCount) {
        printf("English");
    } else if (tCount < sCount) {
        printf("French");
    } else if(tCount == sCount) {
        printf("French");
    } else {
        printf("Error");
        return 1;
    }

    return 0;
}