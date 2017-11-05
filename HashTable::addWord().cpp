void HashTable::addWord(std::string word)
{
    bool isStopWord = false;
    
    for (int c = 0; c < STOPWORD_LIST_SIZE; c++)
    {
        if (vecIgnoreWords[c] == word)
            isStopWord = true;
    }
    
    if (!isStopWord)
    {
        int hashNum = getHash(word);
        wordItem* wordPtr = nullptr;
        wordPtr = searchTable(word);
        
        if (wordPtr != nullptr)
        {
            wordPtr->count ++;
            numCollisions ++;
        }
        
        else
        {
            wordItem* locator = hashTable[hashNum];
        }
    }
}
