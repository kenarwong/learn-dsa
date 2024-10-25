	const int N = some value;
	bool isFriend[N][N];
	...
	int numMutualFriends[N][N];
	for (int i = 0; i < N; i++)
	{
	    numMutualFriends[i][i] = -1;  // the concept of mutual friend
				          // makes no sense in this case
	    for (int j = 0; j < N; j++)
	    {
	        if (i == j)
	            continue;
	        numMutualFriends[i][j] = 0;
	        for (int k = 0; k < N; k++)
	        {
	            if (k == i  ||  k == j)
	                continue;
		    if (isFriend[i][k]  &&  isFriend[k][j])
	        	numMutualFriends[i][j]++;
	        }
	    }
	}

	const int N = some value;
	bool isFriend[N][N];
	...
	int numMutualFriends[N][N];
	for (int i = 0; i < N; i++)
	{
	    numMutualFriends[i][i] = -1;  // the concept of mutual friend
				          // makes no sense in this case
	    for (int j = 0; j < i; j++)  // loop limit is now i, not N
	    {
	        numMutualFriends[i][j] = 0;
	        for (int k = 0; k < N; k++)
	        {
	            if (k == i  ||  k == j)
	                continue;
		    if (isFriend[i][k]  &&  isFriend[k][j])
	        	numMutualFriends[i][j]++;
	        }
	        numMutualFriends[j][i] = numMutualFriends[i][j];
	    }
	}

  const int N = some value;
	bool isFriend[N][N];
	...
	int numMutualFriends[N][N];
	for (int i = 0; i < N; i++)
	{
	    numMutualFriends[i][i] = -1;  // the concept of mutual friend
				          // makes no sense in this case
	    for (int j = 0; j < i; j++)  // loop limit is now i, not N
	    {
	        numMutualFriends[i][j] = 0;
	        for (int k = 0; k < N; k++)
	        {
	            if (k == i  ||  k == j)
	                continue;
		    if (isFriend[i][k]  &&  isFriend[k][j])
	        	numMutualFriends[i][j]++;
	        }
	        numMutualFriends[j][i] = numMutualFriends[i][j];
	    }
	}