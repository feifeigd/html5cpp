#pragma once

namespace engine{
	namespace resource{

		/**
		 *<code>Bitmap</code> 是图片资源类。
		 */
		class Bitmap : public Resource{
		public:
			Bitmap();

		protected:
			int _w, _h;

		public:

			/// 宽度
			int width(){return _w;}

			// 高度
			int height(){return _h;}
		};
	}
}

