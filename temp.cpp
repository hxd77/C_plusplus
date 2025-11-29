for(int i=0;i<11;i++)
{
	for(int j=0;j<4;j++)
	{
		for(int k=0;k<4;k++)
		{
			tempState[j+i*4].wordKey[k]=w[k+i*4].wordKey[j];
		}
	}
}