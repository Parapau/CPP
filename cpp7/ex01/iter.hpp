

template <typename T1, typename T2> void iter (T1 &array, T2 &len, void (*func)(const T1*))
{
	int		i;

	i = 0;
	while (i < len)
	{
		func(array[i]);
		i++;
	}
}
