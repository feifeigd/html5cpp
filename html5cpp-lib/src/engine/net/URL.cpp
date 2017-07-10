#include <engine.core.h>

using namespace engine;

String net::URL::basePath("");
String const* net::URL::rootPath = new String("");
Object* net::URL::version = nullptr;


//URL.customFormat=null;

net::URL::URL(String const& url){
	_url=URL::formatURL(url);
	_path=URL::getPath(url);
}

String const& net::URL::url()const{
	return *_url;
}

String const& net::URL::path()const{
	return *_path;
}

String const* net::URL::formatURL(String const& url, String const* _basePath){
	/*if (URL::customFormat !=null)url=URL::customFormat(url,_basePath);*/
	if (!url)return new String("null path");
	/*if (Render.isConchApp==false){
		URL.version[url] && (url+="?v="+URL.version[url]);
	}*/
	if (url.charCodeAt(0)=='~')	
		return URL::rootPath->concat(*url.substring(1));
	if (URL::isAbsolute(url))
		return &url;
	
	return (_basePath ? *_basePath : URL::basePath).concat(url);
}

bool net::URL::isAbsolute(String const& url){
	return url.indexOf(":")> 0 || url.charCodeAt(0)=='/'; 
}

String const* net::URL::getPath(String const& url){
	int ofs=url.lastIndexOf("/");
	return ofs > 0 ? url.substr(0,ofs+1) : new String("");
}

String const& net::URL::getName(String const& url){
	int ofs=url.lastIndexOf("/");
	return ofs > 0 ? *url.substr(ofs+1):url;
}
