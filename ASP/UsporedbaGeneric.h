#pragma once

template <typename T>
bool IsVece(T a, T b)
{
	return (a > b);
}
template <typename T>
bool IsVece(T* a, T* b)
{
	return (*a > *b);
}



template <typename T>
bool IsJednako(T a, T b)
{
	return (a == b);
}
template <typename T>
bool IsJednako(T* a, T* b)
{
	return (a == b);
}



template <typename T>
bool IsManje(T a, T b)
{
	return (a < b);
}
template <typename T>
bool IsManje(T* a, T* b)
{
	return (a < b);
}