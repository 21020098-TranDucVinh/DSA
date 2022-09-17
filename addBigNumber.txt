string addBigNumbers(string number1, string number2) {
   if (number1.length() > number2.length())
    swap(number1, number2);
   string sum = "";
   int len1 = number1.length();
   int len2 = number2.length();
   int digitDiff = len2 - len1;
   int carry = 0;
   int intSum;
   for (int i=len1-1; i>=0; i--) {
      intSum = ((number1[i]-'0') + (number2[i+digitDiff]- '0') + carry);
      sum.push_back(intSum%10 + '0');
      carry = intSum/10;
   }
   for (int i=digitDiff-1; i>=0; i--) {
      intSum = ((number2[i]-'0')+carry);
      sum.push_back(intSum%10 + '0');
      carry = intSum/10;
   }
   if (carry)
    sum.push_back(carry+'0');
   reverse(sum.begin(), sum.end());
   return sum;
}

// C2
void swapPointer(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}

char* addBigNumber(char* number1, char* number2)
{
	if (strlen(number1) < strlen(number2))
	{
		swapPointer(&number1, &number2);
	}

	size_t number1Len = strlen(number1), number2Len = strlen(number2);
	char* result = new char[number1Len + 2];
	memset(result, '0', number1Len);
	bool remember = false;

	for (int i = 0; i < number2Len; i++)
	{
		int temp = number2[number2Len - i - 1] - '0' + number1[number1Len - i - 1] - '0';

		if (remember)
			temp++;

		remember = temp > 9;

		temp = temp % 10;

		result[number1Len - i] = temp + '0';
	}

	for (int i = 0; i < number1Len - number2Len; i++)
	{
		int temp = number1[number1Len - number2Len - i - 1] - '0';

		if (remember)
			temp++;

		remember = temp > 9;
	
		temp = temp % 10;

		result[number1Len - number2Len - i] = temp + '0';
	}

	result[number1Len + 1] = '\0';

	if (remember)
	{
		result[0] = '1';
	}
	else
	{
		for (int i = 0; i <= number1Len; i++)
			result[i] = result[i + 1];
	}

	return result;
}