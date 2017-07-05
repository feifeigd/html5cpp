#pragma once

namespace engine{

	namespace utils{class Color;}

	namespace display{
		namespace css{
			/**
			 * <code>Font</code> 类是字体显示定义类。
			 */
			class Font {
				/**
				 * 一个默认字体 <code>Font</code> 对象。
				 */
				static Font* EMPTY;
				/**
				 * 默认的颜色。
				 */
				static String defaultColor;
				/**
				 * 默认字体大小。
				 */
				static int defaultSize;
				/**
				 * 默认字体名称系列。
				 */
				static String defaultFamily;
				/**
				 * 默认字体属性。
				 */
				static String defaultFont;
				//static _STROKE:Array<any>;
			public:
				static void __init__();

			private:
				/**
				 * 字体名称系列。
				 */
				String family;
				/**
				 * 描边宽度（以像素为单位）列表。
				 */
				//stroke:Array<any>;
				/**
				 * 首行缩进 （以像素为单位）。
				 */
				int indent;
				/**
				 * 字体大小。
				 */
				int size;
				int _type;
				String _text;

				/**
				 * 创建一个新的 <code>Font</code> 类实例。
				 * @param    src 将此 Font 的成员属性值复制给当前 Font 对象。
				 */
				Font(Font const* src);

				enum{
					_ITALIC		=0x200,
					_PASSWORD	=0x400,
					_BOLD		=0x800,
				};

				/**
				 * 字体样式字符串。
				 */
				void set(String const& value);

				utils::Color* _color;
				/**
				 * 表示颜色字符串。
				 */
				String const& color()const;
				void color(String const& value);
				/**
				 * 表示是否为斜体。
				 */
				bool italic()const;
				void italic(bool value);
				/**
				 * 表示是否为粗体。
				 */
				bool bold()const;
				void bold(bool value);
				/**
				 * 表示是否为密码格式。
				 */
				bool password()const;
				void password(bool value);

				/**
				 * 返回字体样式字符串。
				 * @return 字体样式字符串。
				 */
				String const& toString();

				/**
				 * 文本的粗细。
				 */
				int _weight;
				String const* weight()const;
				void weight(String const& value);
				/**
				 * 规定添加到文本的修饰。
				 */
				String const& decoration()const;
				void decoration(String const& value);

				/**
				 * 将当前的属性值复制到传入的 <code>Font</code> 对象。
				 * @param    dec  一个 Font 对象。
				 */
				void copyTo(Font& dec)const;

				Object* _decoration;
			};
		}
	}
}
