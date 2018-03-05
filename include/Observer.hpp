#ifndef _OBSERVER_HPP
#define _OBSERVER_HPP

class Observer
{
	public:
		virtual ~Observer();
		virtual void onNotify() = 0;
};
#endif //_OBSERVER_HPP
