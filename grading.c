#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// declaring the main fucntion that performs the grade
int text_analyzer(string someText);
int main(void)
{
// getting the text to analyze
    string textToAnalyze = get_string("Enter the text: \n");

// calling the function
    text_analyzer(textToAnalyze);
}

// main function definition
int text_analyzer(string someText)
{
    int index = 0;
    int l;
    int s;
    int letters = 0;
    int sentences = 0;
    int words = 1;
    int lengthOfString = strlen(someText);
// iterating through the text to get the letters, words, sentences 
    for (int i = 0; i < lengthOfString; i++)
    {
// if the n character is alphabet
        if (isalpha(someText[i]))
        {
// grammar understanding: the difference between I'm ( 2 words ) and Dmitrii's ( 1 word )
            if (someText[i + 1] == '\'' && (someText[i] == 'e' || someText[i] == 'E' || someText[i] == 'I' || someText[i] == 'i'))
            {
                words++;
                letters++;
            }
// grammar understanding: complex sentence and if the following n character is not alphabetic and there is space after
            else if (someText[i + 1] == ':')
            {
                words++;
            }
            else
            { 
                letters++;
            }
        }
// if the current element is character and the next is space
        if (someText[i] == ' ' && isalpha(someText[i + 1]))
        {
            words++;
        }
// understanding the end of the sentence
        if ((someText[i] == '.' || someText[i] == '!' || someText[i] == '?') && someText[i - 1] != '\"')
        {
            sentences++;
        }
    }
// grading formula
    l = (float)letters / (float)words * 100;
    s = (float)sentences / (float)words * 100;
    index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %d\n", index);
        return 0;
    }

}

