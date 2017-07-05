#include <engine.core.h>

using engine::utils::Color;

Object* Color::_DEFAULT = nullptr;
Object* Color::_SAVE = new Object;
int Color::_SAVE_SIZE = 0;
Object* Color::_COLOR_MAP = nullptr; //{"white":'#FFFFFF',"red":'#FF0000',"green":'#00FF00',"blue":'#0000FF',"black":'#000000',"yellow":'#FFFF00','gray':'#AAAAAA'};
//Object* Color::_DEFAULT = Color::_initDefault();
int Color::_COLODID = 1;

#define ArrayCount(a) (sizeof a/ sizeof a[0])

void Color::initColorMap(){
	if(Color::_COLOR_MAP)return;
	Color::_COLOR_MAP = new Object;

	struct  
	{
		char const* color_name;
		char const* color_value;
	}cm[] = {
		{"white","#FFFFFF"},
		{"red","#FF0000"},
		{"green","#00FF00"},
		{"blue","#0000FF"},
		{"black","#000000"},
		{"yellow","#FFFF00"},
		{"gray","#AAAAAA"},
	};
	for (int i = 0; i < ArrayCount(cm); ++i)
	{
		Color::_COLOR_MAP->set_(cm[i].color_name, new String(cm[i].color_value));
	}
}

Color::Color(String const* str){
	//this.strColor=null;
	//this.numColor=0;
	
	strColor= *str;
	if(str->charCodeAt(0)=='#') (str=str->substr(1)); 
	int color=numColor=parseInt(str,16);
	bool flag=(str->get_length() == 8);
	if (flag){
		//_color=[parseInt(*str->substr(0,2), double(16))/ 255,((0x00FF0000 & color)>> 16)/ 255,((0x0000FF00 & color)>> 8)/ 255,(0x000000FF & color)/ 255];
		_color.R = parseInt(*str->substr(0,2), double(16))/ 255; _color.G = ((0x00FF0000 & color)>> 16)/ 255; _color.B= ((0x0000FF00 & color)>> 8)/ 255; _color.A = (0x000000FF & color)/ 255;
		return;
	}
	// RGBA
	//_color=[((0xFF0000 & color)>> 16)/ 255,((0xFF00 & color)>> 8)/ 255,(0xFF & color)/ 255,1];
	_color.R = ((0xFF0000 & color)>> 16)/ 255; _color.G = ((0xFF00 & color)>> 8)/ 255; _color.B = (0xFF & color)/ 255; _color.A = 1;
	_color.__id=++Color::_COLODID;
}

Color::Color(int str){
	//this.strColor=null;
	//this.numColor=0;
	
	int	color=numColor=str;
	//strColor=Utils.toHexColor(color);
	// RGBA
	//_color=[((0xFF0000 & color)>> 16)/ 255,((0xFF00 & color)>> 8)/ 255,(0xFF & color)/ 255,1];
	_color.R = ((0xFF0000 & color)>> 16)/ 255; _color.G = ((0xFF00 & color)>> 8)/ 255; _color.B = (0xFF & color)/ 255; _color.A = 1;
	_color.__id=++Color::_COLODID;
}

Object* Color::_initDefault(){
	Color::_DEFAULT = new Object;
	//for (var i in Color::_COLOR_MAP)Color::_SAVE[i]=Color._DEFAULT[i]=new Color(Color::_COLOR_MAP[i]);
	return Color::_DEFAULT;
}

void Color::_initSaveMap(){
	Color::_SAVE_SIZE=0;
	Color::_SAVE=new Object;
	//for (var i in Color._DEFAULT)Color::_SAVE[i]=Color._DEFAULT[i];	// 默认的加进去
}

Color* Color::create(String const& str){
	Color* color = nullptr;/* &(Color&)(Color::_SAVE[str]);*/ // 这行链接不过
	if (color)return color;
	if(Color::_SAVE_SIZE >= 1000) Color::_initSaveMap();
	color = new Color(str);
	Color::_SAVE->set_(str, color);	// 新建的也存进去
	
	return color;
}
