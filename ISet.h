#ifndef __ISET_H
#define __ISET_H	

#include <iostream> 
#include <clocale>
#include <stdlib.h>


using namespace std;    

template < class T > class ISet
{
public:
	// добавить элемент
	virtual void add(const T& elem) = 0;
	// удалить элемент
	virtual void remove(const T& elem) = 0;
	// содержится ли элемент
	virtual bool contains(const T& elem) const = 0;
	// узнать размер множества
	virtual int size() const = 0;

};


template < class T > class MySet : public ISet < T >
{
protected:

	T *set;  // Множество
	T *temp; // Временный массив
	unsigned int sizeset;  // Размер множества

public:
	MySet()	//Конструктор
	{
		set = new (nothrow)T[0];
		sizeset = 0;
	}

	void add(const T& elem) // Добавить элемент 
	{
		T element = elem;


		for (int i = 0; i<sizeset; i++)
			if (element == set[i])
			{

				cout << "\n Element already in set \n";
				return;
			}


		temp = new (nothrow)T[sizeset];

		for (int i = 0; i<sizeset; i++)
			temp[i] = set[i];

		delete[] set;

		sizeset++;

		set = new (nothrow)T[sizeset];

		for (int i = 0; i < sizeset; i++)
			set[i] = temp[i];

		delete[] temp;

		set[sizeset - 1] = element;



	};

	void remove(const T& elem)	// Удалить элемент
	{
		T element = elem;
		bool flag = true;

		temp = new (nothrow)T[sizeset - 1];

		for (int i = 0; i < sizeset; i++)
		{
			
			if (element == set[i])
			{
				flag = false;

				int k = 0;

				for (int j = 0; j< sizeset; j++)
				{
					if (set[i] != element)
					{
						temp[k] = set[i];
						k++;
					}
				}

			}

		}
		if (flag == true)
		{
			cout << "\n Element is not found\n";
			return;
		}



	};

	bool contains(const T& elem) const	// Cодержится ли элемент
	{

		T element = elem;

		bool flag = false;

		for (int i = 0; i<sizeset; i++)
			if (element == set[i])
			{
				flag = true;
			}
		return flag;

	};

	int size() const // Узнать размер множества
	{
		return sizeset;
	};
	};

#endif