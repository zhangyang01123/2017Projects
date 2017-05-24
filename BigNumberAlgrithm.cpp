// big number algorithm

#include <stdio.h>  
#include <string.h>  

void plus(char *a, char *b, char *c);
void minus(char *a, char *b, char *c);
void multiply(char *a, char *b, char *c);
void reverse(char *a, int n);

int StrToInt(char *a)
{
	int result = 0;
	bool minus = false;
	char * p = a;
	if (*p == '-')
	{
		minus = true;
		p++;
	}
	
	while (*p)
	{
		result = result * 10 + (*p - '0');
		p++;
	}

	if (minus)
		result = result * -1;

	return result;
}

int main()
{
	char a[1000];
	char b[1000];
	char c[1000];
	char s[2];

	while (scanf("%s %s %s", a, s, b) == 3) {
		if (s[0] == '+') {
			plus(a, b, c);
		}
		else if (s[0] == '-') {
			minus(a, b, c);
		}
		else if (s[0] == '*') {
			multiply(a, b, c);
		}
		
		printf("%s\n", c);
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			//a[] = i, b[] = j
			memset(a, 0, sizeof(char)*1000);
			memset(b, 0, sizeof(char) * 1000);
			int aVal = i;
			int bVal = j;
			int index = 0;
			if (aVal == 0)
			{
				a[0] = '0';
			}
			else
			{
				while (aVal)
				{
					a[index++] = aVal % 10 + '0';
					aVal = aVal / 10;
				}
				reverse(a, index);
			}
			
			index = 0;
			if (bVal == 0)
			{
				b[0] = '0';
			}
			else
			{
				while (bVal)
				{
					b[index++] = bVal % 10 + '0';
					bVal = bVal / 10;
				}
				reverse(b, index);
			}
			
			memset(c, 0, 1000 * sizeof(char));
			plus(a, b, c);
			
			int aResult = StrToInt(a);
			int bResult = StrToInt(b);
			int cResult = StrToInt(c);
			printf("%d + %d = %d\n", aResult, bResult, cResult);
			if (cResult != i + j)
			{
				printf("PLUS: assessment failed (a=%d, b=%d, c=%d)  press any key to continue.\n", i, j, cResult);
				char ch = 0;
				scanf("%c", ch);
			}

			memset(c, 0, 1000 * sizeof(char));
			minus(a, b, c);
			aResult = StrToInt(a);
			bResult = StrToInt(b);
			cResult = StrToInt(c);
			printf("%d - %d = %d\n", aResult, bResult, cResult);
			if (cResult != i - j)
			{
				printf("MINUS: assessment failed (a=%d, b=%d, c=%d)  press any key to continue.\n", i, j, cResult);
				char ch = 0;
				scanf("%c", ch);
			}

			memset(c, 0, 1000 * sizeof(char));
			multiply(a, b, c);
			aResult = StrToInt(a);
			bResult = StrToInt(b);
			cResult = StrToInt(c);
			printf("%d * %d = %d\n", aResult, bResult, cResult);
			if (cResult != i * j)
			{
				printf("MULTIPLY: assessment failed (a=%d, b=%d, c=%d)  press any key to continue.\n", i, j, cResult);
				char ch = 0;
				scanf("%c", ch);
			}
		}
	}

	/*memset(a, 0, 1000 * sizeof(char));
	memset(b, 0, 1000 * sizeof(char));
	memset(c, 0, 1000 * sizeof(char));

	for (int i = 0; i < 50; i++)
	{
		a[i] = '9';
	}
	for (int i = 0; i < 49; i++)
	{
		b[i] = '9';
	}
	multiply(a, b, c);

	printf("%s\n", c);
	printf("***************************************************************");
	printf("***************************************************************");
	printf("***************************************************************");
	printf("***************************************************************");
	printf("***************************************************************");
	printf("***************************************************************");
	printf("***************************************************************");
	printf("\n");
	for (int i = 0; i < 1000; i++)
		printf("%c", c[i]);
	printf("\n");*/


	return 0;
}

void plus(char *a, char *b, char *c)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (k < 1000)
	{
		c[k++] = 0;
	}

	char * p1 = a;
	while (*p1 == '0') p1++;
	int nonzeroA = p1 - a;
	i = nonzeroA;
	while (a[i]) i++;
	i = i - nonzeroA;

	char * p2 = b;
	while (*p2 == '0') p2++;
	int nonzeroB = p2 - b;
	j = nonzeroB;
	while (b[j]) j++;
	j = j - nonzeroB;

	if (i == j && i == 0)
	{
		c[0] = '0';
		return;
	}
	else if (i == 0)
	{
		for (int index = 0; index < j; index++)
		{
			c[index] = b[index + nonzeroB];
		}
		return;
	}
	else if (j == 0)
	{
		for (int index = 0; index < i; index++)
		{
			c[index] = a[index + nonzeroA];
		}
		return;
	}

	k = i > j ? i + 1: j + 1;

	i--;
	j--;
	int cIndex = k - 1;
	int carry = 0;
	while (k > 0)
	{
		int aVal = i < 0 ? 0 : a[i + nonzeroA] - '0';
		int bVal = j < 0 ? 0 : b[j + nonzeroB] - '0';
		int tmpSum = (carry + aVal + bVal) % 10;
		carry = (carry + aVal + bVal) / 10;
		i--;
		j--;
		k--;
		c[k] = tmpSum + '0';
	}

	k = 0;
	while (c[k] == '0') k++;
	if (k > 0)
	{
		int index = 0;
		while (k <= cIndex)
		{
			c[index] = c[k];
			index++;
			k++;
		}
		c[index] = 0;
	}
}
void minus(char *a, char *b, char *c)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int positive = 0;

	while (k < 1000)
	{
		c[k++] = 0;
	}
	char * p1 = a;
	while (*p1 == '0') p1++;
	int nonzeroA = p1 - a;
	i = nonzeroA;
	while (a[i]) i++;
	i = i - nonzeroA;

	char * p2 = b;
	while (*p2 == '0') p2++;
	int nonzeroB = p2 - b;
	j = nonzeroB;
	while (b[j]) j++;
	j = j - nonzeroB;

	k = i > j ? i: j;

	if (i > j)
	{
		positive = 1;
	}
	else if (j > i)
	{
		positive = 0;
	}
	else
	{
		int index = 0;
		for (index = 0; index < k; index++)
		{
			if (a[nonzeroA + index] > b[nonzeroB + index])
			{
				positive = 1;
				break;
			}
			else if (a[nonzeroA + index] < b[nonzeroB + index])
			{
				positive = 0;
				break;
			}
			else
				continue;
		}
		if (index == k)
		{
			c[0] = '0';
			return;
		}
	}

	i--;
	j--;
	int cIndex = k - 1;
	int borrow = 0;
	while (k > 0)
	{
		int aVal = i < 0 ? 0 : a[nonzeroA + i] - '0';
		int bVal = j < 0 ? 0 : b[nonzeroB + j] - '0';
		int tmpSub = 0;
		if (positive)
		{
			tmpSub = aVal - bVal - borrow;
		}
		else
		{
			tmpSub = bVal - aVal - borrow;
		}
		 
		if (tmpSub < 0)
		{
			borrow = 1;
			tmpSub += 10;
		}
		else
			borrow = 0;

		i--;
		j--;
		k--;
		c[k] = tmpSub + '0';
	}

	k = 0;
	while (c[k] == '0') k++;
	if (positive == 0)
	{
		if (k)
		{
			c[k - 1] = '-';
		}
		else
		{
			k = cIndex;
			while (k >= 0)
			{
				c[k + 1] = c[k];
				k--;
			}
			c[0] = '-';
			return;
		}
	}
	
	k = 0;
	while (c[k] == '0') k++;
	if (k > 0)
	{
		int index = 0;
		while (k <= cIndex)
		{
			c[index] = c[k];
			index++;
			k++;
		}
		c[index] = 0;
	}
}
void multiply(char *a, char *b, char *c)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (k < 1000)
	{
		c[k++] = 0;
	}

	char * p1 = a;
	while (*p1 == '0') p1++;
	int nonzeroA = p1 - a;
	i = nonzeroA;
	while (a[i]) i++;
	i = i - nonzeroA;

	char * p2 = b;
	while (*p2 == '0') p2++;
	int nonzeroB = p2 - b;
	j = nonzeroB;
	while (b[j]) j++;
	j = j - nonzeroB;

	if (i == 0 || j == 0)
	{
		c[0] = '0';
		return;
	}

	k = i + j;
	int cIndex = k - 1;
	i--;
	j--;
	int tmpC[1000] = { 0 };
	
	for (int indexI = i + nonzeroA; indexI >= nonzeroA; --indexI)
	{
		for (int indexJ = j + nonzeroB; indexJ >= nonzeroB; --indexJ)
		{
			tmpC[indexI - nonzeroA + indexJ - nonzeroB + 1] = tmpC[indexI - nonzeroA + indexJ - nonzeroB + 1] + (a[indexI] - '0')*(b[indexJ] - '0');
		}
	}

	for (int index = i + j + 1; index >= 0; --index)
	{
		if (tmpC[index] >= 10)
		{
			tmpC[index - 1] += tmpC[index] / 10;
			tmpC[index] %= 10;
		}
	}

	for (int index = 0; index < k; index++)
	{
		c[index] = tmpC[index] + '0';
	}

	if (c[0] == '0')
	{
		for (int index = 0; index < k - 1; index++)
		{
			c[index] = c[index + 1];
		}
		c[k - 1] = 0;
	}

	k = 0;
	while (c[k] == '0') k++;
	if (k > 0)
	{
		int index = 0;
		while (k <= cIndex)
		{
			c[index] = c[k];
			index++;
			k++;
		}
		c[index] = 0;
	}

}

void reverse(char * a, int n)
{
	int begin = 0;
	int end = n - 1;
	
	while (begin < end)
	{
		char tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;
		begin++;
		end--;
	}
}
