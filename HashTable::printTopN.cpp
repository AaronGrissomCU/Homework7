void HashTable::printTopN(int n)
{
	wordItem* topList = new wordItem[n];
	
	for (int c = 0; c < n; c++)
	{
		topList[c].word = "NULL";
		topList[c].count = -1;
		topList[c].next = nullptr;
	}
	
	wordItem* search = nullptr;
	
	for (int c = 0; c < STOPWORD_LIST_SIZE; c++)
	{
		search = hashTable[c];
		
		while (search != nullptr)
		{
			int location = 0;
			for (int x = 0; x <= n; x++)
			{
				if (topList[x].count > search->count)
				{
					location ++;
				}
			}
			
			wordItem insert, temp;
			insert.word = search->word;
			insert.count = search->count;
			insert.next = nullptr;
			temp.word = "NULL";
			temp.count = -1;
			temp.next = nullptr;
			
			for (int x = location; x < n; x++)
			{
				temp.word = topList[x].word;
				temp.count = topList[x].count;
				
				topList[x].word = insert.word;
				topList[x].count = insert.count;
				
				insert.word = temp.word;
				insert.count = temp.count;
			}
			
			search = search->next;
		}
	}
	
	for (int c = 0; c < n; c++)
	{
		std::cout << topList[c].count << " - " << topList[c].word << std::endl;
	}
	
	delete [] topList;
}
