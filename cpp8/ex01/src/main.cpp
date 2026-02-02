
template <typename T>
Array<T>::Array(void): _size(0)
{
	arr = new	T[0];
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	arr = new	T[n];
}

template <typename T>
Array<T>::Array(Array &og): _size(og.size())
{
	arr = new T[og.size()];
	for (unsigned int i = 0; i < og.size() ; i++)
		arr[i] = og[i];
}

//DESTRUCTOR

template <typename T>
Array<T>::~Array(void)
{
	delete[] arr;
}

//OVERLOADS

template <typename T>
Array<T>	&Array<T>::operator=(Array &og)
{
	arr = new T[og.size()];
	for (unsigned int i = 0; i < og.size() ; i++)
		arr[i] = og[i];
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int n)
{
	if (n >= size())
		throw (std::exception());
	return (arr[n]);
}

template <typename T>
unsigned int	Array<T>::size(void)
{
	return (this->_size);
}

#endif
