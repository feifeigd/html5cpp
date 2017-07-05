#include <engine.core.h>

using engine::display::css::Font;
using engine::utils::Color;

Font* Font::EMPTY = nullptr;


String Font::defaultColor("#000000");
int Font::defaultSize=12;
String Font::defaultFamily("Arial");
String Font::defaultFont("12px Arial");
//Font._STROKE=[0,"#000000"];

Font::Font(Font const* src) : _type(0), _weight(0), size(Font::defaultSize), _decoration(nullptr)
{
	_text="";
	indent=0;
	_color=Color::create(Font::defaultColor);
	family = Font::defaultFamily;
	//this.stroke = Font::_STROKE;	
	if(src && src != Font::EMPTY)src->copyTo(*this);
}

void Font::__init__(){
	Font::EMPTY = new Font(nullptr);
}

void Font::set(String const& value){
	_text= "";
	TArray<String>& strs= *value.split(' ');
	for (int i=0,n=strs.get_length();i < n;i++){
		String& str = *strs[i];
		if(str == String("italic")){
			italic(true);
			continue ;
		}else if(str == String("bold")){
			bold(true);
			continue ;
		}
		if (str.indexOf("px") > 0){
			size= parseInt(str);
			family = strs[i+1];
			i++;
			continue;
		}
	}
}

String const& Font::toString(){
	_text="";
	if(italic()) _text.concat("italic ");
	if(bold()) _text.concat("bold ");
	_text.concat(size)->concat("px ")->concat(family);
	return _text;
}

void Font::copyTo(Font& dec)const{
	dec._type	= _type;
	dec._text	= _text;
	dec._weight	= _weight;
	dec._color	= _color;
	dec.family	= family;
	//dec.stroke	= stroke !=Font._STROKE ? this.stroke.slice():Font._STROKE;
	dec.indent	= indent;
	dec.size	= size;
}

String const& Font::color()const{
	return _color->strColor;
}
void Font::color(String const& value){
	_color=Color::create(value);
}

String const& Font::decoration()const{
	static String none("none");
	if(_decoration) return *(String*)(*_decoration)[String("value")];
	else return none;
}
void Font::decoration(String const& value){
	TArray<String>& strs= *value.split(' ');
	if(!_decoration)_decoration=new Object;
	String& str0 = *strs[0];
	
	if(str0 == String("_"))
		_decoration->set_("type", new String("underline"));
		//this._decoration.type='underline'		
	if(str0 == String("-"))
		_decoration->set_("type", new String("line-through"));
		//this._decoration.type='line-through'	
	if(str0 == String("overline"))
		_decoration->set_("type", new String("overline"));
		//this._decoration.type='overline'
	else
		_decoration->set_("type", &str0);
	
	if(strs[1]) _decoration->set_("color", Color::create(strs[1]));
	//_decoration.value=value;
	_decoration->set_("value", (Object*)&value);
}

bool Font::italic()const{
	return (_type & _ITALIC)!=0;
}
void Font::italic(bool value){
	value ? (_type |=_ITALIC):(_type &=~_ITALIC);
}

bool Font::bold()const{
	return (_type & _BOLD)!=0;
}
void Font::bold(bool value){
	value ? (_type |=_BOLD):(_type &=~_BOLD);
}

bool Font::password()const{
	return (_type & _PASSWORD)!=0;
}
void Font::password(bool value){
	value ? (_type |=_PASSWORD):(_type &=~_PASSWORD);
}

String const* Font::weight()const{	
	return new String(_weight);
}

void Font::weight(String const& value){
	int weight=0;	
	if(value == String("normal"))
		;
	else if(value == String("bold")){
		bold(true);
		weight=700;
	}
	else if(value == String("bolder"))
		weight=800;	
	else if(value == String("lighter"))
		weight=100;
	else
		weight = parseInt(value);
	
	_weight = weight;
	_text="";
}
