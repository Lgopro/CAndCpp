



void Swap(int *var1, int *var2)
{
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

void BitSwap(int *var1, int *var2)
{
	*var1 = *var1 ^ *var2;
	*var2 = *var2 ^ *var1;
	*var1 = *var1 ^ *var2;
}

void InPlaceSwap(int *var1, int *var2)
{
	*var1 = *var1 + *var2;
	*var2 = *var1 - *var2;
	*var1 = *var1 - *var2;
}
