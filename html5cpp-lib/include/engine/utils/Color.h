#pragma once

namespace engine{
	namespace utils{
		/**
		 * <code>Color</code> 是一个颜色值处理类。
		 */
		class Color : public Object {
			static Object* _SAVE;
			static int _SAVE_SIZE;
		private:
			static Object* _COLOR_MAP;
			static Object* _DEFAULT;
			static int _COLODID;

			struct {				
				double R,G,B,A;
				int __id;
			}_color;
		public:
			/** 字符串型颜色值。*/
			String strColor;
		private:
			/** uint 型颜色值。*/
			int numColor;

			/**
			* 根据指定的属性值，创建一个 <code>Color</code> 类的实例。
			* @param    str 颜色值。
			*/
			Color(String const* str = new String("#000000"));
			Color(int str);

			static Object* _initDefault();

			static void _initSaveMap();
			static void initColorMap();
		public:
			/**
			* 根据指定的属性值，创建并返回一个 <code>Color</code> 类的实例。
			* @param    str 颜色值。
			* @return 一个 <code>Color</code> 类的实例。
			*/
			static Color* create(String const& str);
		};
	}
}