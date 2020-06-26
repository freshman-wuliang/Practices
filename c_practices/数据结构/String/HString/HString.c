#include"HString.h"

Status StrAssign(pHString pH,char array[])
{
	int i;

	//if(pH->ch)
		//free(pH->ch);

	pH->ch = (char*)malloc((strlen(array)+1)*sizeof(char));
	if(!pH->ch)
		exit(OVERFLOW);

	i = 0;
	while(array[i] != '\0')
	{
		pH->ch[i] = array[i];
		i++;
	}

	pH->ch[i] = '\0';
	pH->length = strlen(array);

	return OK;
}

int StrLength(HString S)
{
	return S.length;
}

int StrCompare(HString S,HString T)
{
	int i = 0,j = 0;

	while(S.ch[i] != '\0' && T.ch[j] != '\0')
	{
		if(S.ch[i] > T.ch[i])
			return 1;
		else if(S.ch[i] < T.ch[i])
			return -1;
		else
		{
			i++;
			j++;
		}
	}
	if(S.ch[i] == '\0' && T.ch[j] == '\0')
		return 0;
	else if(S.ch[i]  == '\0' && T.ch[j] != '\0')
		return -1;
	else if(S.ch[i] != '\0' && T.ch[j] == '\0')
		return 1;
}

Status ClearString(pHString pH)
{
	if(!pH->ch)
		return FALSE;
	free(pH->ch);
	pH->ch = NULL;
	pH->length = 0;

	return OK;
}

Status ConCat(pHString pH,HString S1,HString S2)
{
	int i = 0;
	int j = 0;

	if(pH->ch)
		free(pH->ch);

	pH->ch = (char*)malloc((S1.length+S2.length+1)*sizeof(char));
	if(!pH->ch)
		exit(OVERFLOW);

	while(S1.ch[i] != '\0')
	{
		pH->ch[i] = S1.ch[i];
		i++;
	}
	while(S2.ch[j] != '\0')
	{
		pH->ch[i+j] = S2.ch[j];
		j++;
	}

	pH->ch[i+j] = '\0';
	pH->length = S1.length + S2.length;

	return OK;
}

Status SubString(pHString psub,HString S,int pos,int len)
{
	int i;

	if(pos < 1 || pos > S.length)
		return FALSE;
	if(len < 0 || len > S.length-pos+1)
		return FALSE;

	if(psub->ch)
		free(psub->ch);

	if(!len)
	{
		psub->ch = NULL;
		psub->length = 0;
	}
	else
	{
		psub->ch = (char*)malloc((len+1)*sizeof(char));
		if(!psub->ch)
			exit(OVERFLOW);

		for(i=0;i<len;i++)
		{
			psub->ch[i] = S.ch[pos-1+i];
		}
		psub->ch[i] = '\0';
		psub->length = len;
	}
}

void PrintString(HString S)
{
	printf("%s\n",S.ch);
}
