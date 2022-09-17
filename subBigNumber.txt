void swapPointer(char** a, char** b)
{
	char* temp = *a;
	*a = *b;
	*b = temp;
}

char* subBigNumber(char* number1, char* number2)
{
	bool sign = false, remember = false;

	if (strlen(number1) < strlen(number2))
	{
		sign = true;
		swapPointer(&number1, &number2);
	}
	else if (strlen(number1) == strlen(number2))
	{
		for (int i = strlen(number1) - 1; i >= 0; i--)
		{
			if (number1[i] < number2[i])
			{
				swapPointer(&number1, &number2);
				sign = true;
			}
		}
	}
	size_t number1Len = strlen(number1);
	size_t number2Len = strlen(number2);
	char* result = new char [number1Len + 2];
	memset(result, '0', number1Len + 2);

	for (int i = 0; i < number2Len; i++)
	{
		int temp = number1[number1Len - i - 1] - number2[number2Len - i - 1];

		if (remember)
			temp--;
		if (temp < 0)
		{
			temp += 10;
			remember = true;
		}
		else
			remember = false;

		result[number1Len - i] = temp + '0';
	}

	for (int i = 0; i < number1Len - number2Len; i++)
	{
		int temp = number1[number1Len - number2Len - i - 1] - '0';

		if (remember == true)
			temp--;
		if (temp < 0)
		{
			temp += 10;
			remember = true;
		}
		else
			remember = false;

		result[number1Len - number2Len - i] = temp + '0';	
	}

	while (result[0] == '0')
	{
		if (result[1] != '0' && sign == true)
		{
			result[0] = '-';
			result[number1Len + 1] = '\0';
			break;
		}

		for (int i = 0; i < number1Len; i++)
		{
			result[i] = result[i + 1];
		}
		result[number1Len] = '\0';
	}

	return result;
}