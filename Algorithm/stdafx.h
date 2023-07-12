#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <map>
#include <set>
#include <utility>

typedef int DataType;

using namespace std;

#define Clear system("cls");
#define Pause system("Pause")

#define endll endl << endl

enum DS
{
	LINKED_LIST,
	STACK,
	QUEUE,
	TREE
};

enum AL
{
	SELECTION_SORT = 1,
	INSERTION_SORT,
	BUBBLE_SORT,
	QUICK_SORT,
	MERGE_SORT,
	BINARY_SEARCH
};