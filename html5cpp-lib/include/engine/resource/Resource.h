#pragma once

#include "../events/EventDispatcher.h"

namespace engine{
	namespace resource{

		/**
		 *<code>Resource</code> 是一个资源存取类。
		 */
		class Resource : public events::EventDispatcher{
		public:
			Resource();
		};
	}
}
