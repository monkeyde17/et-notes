#include "Iterator.h"
#include "Aggregate.h"

#include <iostream>

using namespace std;

Iterator::Iterator() { }

Iterator::~Iterator() { }

ConcreateIterator::ConcreateIterator(Aggregate *ag, int idx)
{
	_ag = ag;
	_idx = idx;
}

ConcreateIterator::~ConcreateIterator() {}

Object ConcreateIterator::CurrentItem()
{
	return _ag->GetItem(_idx);
}

void ConcreateIterator::First()
{
	_idx = 0;
}

void ConcreateIterator::Next()
{
	if (_idx < _ag->GetSize())
	{
		_idx++;
	}
}

bool ConcreateIterator::IsDone()
{
	return _idx == _ag->GetSize();
}

