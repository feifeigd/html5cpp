
#pragma once

namespace engine{
	namespace utils{

		/// 
		class Browser{
		public:
			static void __init__();
			static client::Window& window();

			static resource::HTMLCanvas* canvas;
		};
	}
}
