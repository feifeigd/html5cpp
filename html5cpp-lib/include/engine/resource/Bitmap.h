#pragma once

#include "Resource.h"

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
			void* _source;

		public:

			/// 宽度
			int width(){return _w;}

			// 高度
			int height(){return _h;}

			/***
			 * HTMLImage>FileBitmap>Bitmap 或 HTMLCanvas>Bitmap 或 WebGL Texture 。
			 */
			void* source(){return _source;}

			/**
			 * 将此对象的成员（资源、宽、高）属性值复制给指定的 Bitmap 对象。
			 * @param    dec 一个 Bitmap 对象。
			 */
			void copyTo(Bitmap& dec);

			/**
			 * 彻底清理资源。
			 */
			void dispose();
		};
	}
}
