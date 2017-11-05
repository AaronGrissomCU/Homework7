int HashTable::getTotalNumberNonStopWords()
{
    wordItem* scout = nullptr;
    int numNonStopWords = 0;
    
    for (int c = 0; c < STOPWORD_LIST_SIZE; c++)
    {
        scout = hashTable[c];
        
        while (scout != nullptr)
        {
            numNonStopWords += scout->count;
            scout = scout->next;
        }
    }
    
    return numNonStopWords;
}
