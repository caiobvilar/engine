#ifndef _MESSAGE_BUS_HPP_
#define _MESSAGE_BUS_HPP_

//C++ Basics
#include <pthread.h>
#include <vector>
#include <queue>
///////////////////////////
/////////SYSTEMS///////////
#include "Message.hpp"

class MessageBus
{
	public:
		
		MessageBus();
		~MessageBus();

	private:

		std::queue<Message> MsgQueue;
		bool running; //Holds MessageBus running state
};
#endif // _MESSAGE_BUS_HPP_
