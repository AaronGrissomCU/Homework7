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
            wordPtr = hashTable[hashNum];
           
            if (wordPtr == nullptr)
            {
                wordPtr = new wordItem;
                hashTable[hashNum] = wordPtr;
                wordPtr->word = word;
                wordPtr->count = 1;
                wordPtr->next = nullptr;
            }
            else
            {
                while (wordPtr->next != nullptr)
                {
                   wordPtr = wordPtr->next;
                }
                wordPtr->next = new wordItem;
                wordPtr = wordPtr->next;
                wordPtr->word = word;
                wordPtr->count = 1;
                wordPtr->next = nullptr;
            }
        }
    }
}
