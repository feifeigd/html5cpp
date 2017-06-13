
#pragma once

namespace engine{
	namespace utils{

		/// 
		class Browser{
		public:
			/** 浏览器原生 window 对象的引用。*/
			static client::Window& window();

			static resource::HTMLCanvas* canvas;
			/** 全局画布上绘图的环境。 */
			static resource::Context* ctx;
		private:
			static void* _pixelRatio;

		public:
			static void __init__();

			/**
			 * 创建浏览器原生节点。
			 * @param    type 节点类型。
			 * @return    创建的节点对象的引用。
			 */
			static client::Object* createElement(std::string const&type);


			/** 浏览器物理高度。*/
			static int height();
		};
	}
}
