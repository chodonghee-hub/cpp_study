#include <iostream>
#include <list>

using namespace std;

class Event
{
public : 
	int duration;
	int elapse;

	virtual void Update() = 0;
	bool IsDone()
	{
		return elapse >= duration;
	}
};

class CallFunc;
class EventManager
{
public : 
	list<Event*> _events;
	
	void Instance(CallFunc* func)
	{
		_events.emplace_back(func);
	}

	void Update()
	{
		for (list<Event*>::iterator it = _events.begin(); it != _events.end();)
		{
			(*it)->Update();
			if ((*it)->IsDone())
			{
				_events.erase(it++);
			}
		}
	}
};

class CallFunc : public Event
{
public :
	void(*_func)();
	
	CallFunc(void(*func)(), int _duration);

	virtual void Update() override
	{
		_func();
		elapse += 1;
		return;
	}
};

CallFunc::CallFunc(void(*func)(), int _duration)
{
	_func = func;
	duration = _duration;
}

void AAA()
{
	cout << "AAA hi" << endl;
}

void BBB()
{
	cout << "BBB hi" << endl;
}

void CCC()
{
	cout << "CCC hi" << endl;
}

int main(void)
{
	EventManager* mgr = new EventManager();
	mgr->Instance(new CallFunc(AAA, 3));
	mgr->Instance(new CallFunc(BBB, 1));
	mgr->Instance(new CallFunc(CCC, 2));

	for (int i = 0; i < 100; i++)
	{
		mgr->Update();
	}
	return EXIT_SUCCESS;
}