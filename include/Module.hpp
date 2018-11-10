#ifndef _MODULE_HPP_
#define _MODULE_HPP_

#include <vector>

class Module
{
	private:
		std::vector<Module> ObserverModules;
		std::bool running;
		virtual Module();
		virtual ~Module();
		virtual void Shutdown();
		virtual void Configure();
		virtual void Init();
	protected:
		virtual void notify();
	public:
		virtual void onNotify();
		virtual void addObserver();
		virtual void removeObserver();
};

#endif //_MODULE_HPP_
