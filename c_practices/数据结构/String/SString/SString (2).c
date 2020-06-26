#include"SString.h"

void StrAssign(SString T,char array[])
{
	int count = 0;
	char *p;

	if(strlen(array) > MAXSTRLEN)
		array[MAXSTRLEN] = '\0';

	p = array;
	while(*p != '\0')
	{
		T[count] = *p;
		count++;
		p++;
	}
	T[count] = '\0';
}

void StrCopy(SString T,SString S)
{
	int count = 0;
	char *p;

	p = S;
	while(*p != '\0')
	{
		T[count] = *p;
		count++;
		p++;
	}

	T[count] = '\0';
}

int StrEmpty(SString T)
{
	if(T[0] == '\0')
		return 1;
	else
		return 0;
}

int StrCompare(SString S,SString T)
{
	int a = 0;
	int b = 0;

	while(S[a] != '\0' && T[b] != '\0')
	{
		if(S[a] == T[b])
		{
			a++;
			b++;
		}
		else if(S[a] > S[b])
			return 1;
		else
			return -1;
	}
	if(S[a] == '\0' && T[b] == '\0')
		return 0;
	else if(S[a] == '\0' && T[b] != '\0')
		return -1;
	else if(S[a] != '\0' && T[b] == '\0')
		return 1;
}

int StrLength(SString S)
{
	int count = 0;
	char *p;

	p = S;
	while(*p != '\0')
	{
		count++;
		p++;
	}

	return count;
}

void ConCat(SString T,SString S1,SString S2)
{
	int count1 = 0;
	int count2 = 0;

	while(S1[count1] != '\0')
	{
		T[count1] = S1[count1];
		count1++;
	}
	while(S2[count2] != '\0' && count1 < MAXSTRLEN)
	{
		T[count1] = S2[count2];
		count1++;
		count2++;
	}

	T[count1] = '\0';
}

void ClearString(SString S)
{
	S[0] = '\0';
}

Status SubString(SString Sub,SString S,int pos,int len)
{
	int i;

	if(pos < 1 || pos >StrLength(S))
		return ERROR;
	if(len < 0 || len > StrLength(S))
		return ERROR;

	for(i=0;i<len;i++)
	{
		Sub[i] = S[pos-1+i];
	}

	Sub[i] = '\0';

	return OK;
}

int Index(SString S,SString T)
{
	SString sub;
	int i;

	for(i=1;i<=StrLength(S)-StrLength(T)+1;i++)
	{
		SubString(sub,S,i,StrLength(T));
		if(!StrCompare(T,sub))
			return i;
	}

	return 0;
}

int Index_B(SString S,SString T,int pos)
{
	int i = 1;
	int j = 1;
	
	if(pos < 1 || pos > StrLength(S))
		return 0;
	if(S[0] == '\0')
		return 0;
	
	while(i <= StrLength(S)-StrLength(T)+1 && T[j-1] != '\0')
	{
		if(S[i-1] == T[j-1])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	
	if(T[j-1] == '\0')
		return i-j+1;
	else
		return 0;
}

Status StrInsert(SString S,int pos,SString T)
{
	SString sub,sum1,sum2;

	if(pos < 1 || pos >StrLength(S))
		return FALSE;

	SubString(sub,S,pos,StrLength(S)-pos+1);
	S[pos-1] = '\0';
	ConCat(sum1,S,T);
	ConCat(sum2,sum1,sub);
	StrCopy(S,sum2);

	return OK;
}

Status StrDelete(SString S,int pos,int len)
{
	SString sub,sum;

	if(pos < 1 || pos > StrLength(S))
		return FALSE;

	SubString(sub,S,pos+len,StrLength(S)-len-pos+1);
	S[pos-1] = '\0';
	ConCat(sum,S,sub);
	StrCopy(S,sum);

	return OK;
}

Status Replace(SString S,SString T,SString V)
{
	int i,j;
	SString sub;

	if(StrEmpty(S) || StrEmpty(T))
		return FALSE;

	for(i=1;i<=StrLength(S)-StrLength(T)+1;i++)
	{
		SubString(sub,S,i,StrLength(T));
		if(!StrCompare(sub,T))
		{
			StrDelete(S,i,StrLength(T));
			StrInsert(S,i,V);
		}
	}

	return OK;
}

void PrintString(SString S)
{
	printf("%s\n",S);
}

