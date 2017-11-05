void HashTable::getStopWords(char *ignoreWordFileName)
{
    ifstream input;
    string text;
    int counter = 0;
    input.open(ignoreWordFileName);
    
    while (getline(input, text))
    {
        vecIgnoreWords[counter] = text;
        counter ++;
    }
    
    input.close();
}
