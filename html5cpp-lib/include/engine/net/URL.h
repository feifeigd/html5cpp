#pragma once

namespace engine{
	namespace net{
		/**
		* <p> <code>URL</code> 类用于定义地址信息。</p>
		*/
		class URL {
			/**
			* 版本号。
			*/
			static Object* version;

			/**
			* 创建一个新的 <code>URL</code> 实例。
			*/
			URL(String const& url);

			/**
			* 格式化后的地址。
			*/
			String const* _url;
			String const& url()const;
			/**
			* 地址的路径。
			*/
			String const* _path;
			String const& path()const;
			/**
			* 基础路径。
			*/
			static String basePath;
		public:
			/**
			* 根路径。
			*/
			static String const* rootPath;
			/** 自定义url格式化。例如： customFormat=function(url:string,basePath:string):string
			public static var customFormat:Function;
			/**
			* 格式化指定的地址并返回。
			* @param    url 地址。
			* @param    _basePath 路径。
			* @return 格式化处理后的地址。
			*/
			static String const* formatURL(String const& url, String const* _basePath = nullptr);

			/**
			* 获取指定 URL 的路径。
			* <p><b>注意：</b>末尾有斜杠（/）。</p>
			* @param    url 地址。
			* @return  url 的路径。
			*/
			static String const* getPath(String const& url);

			/**
			* 获取指定 URL 的文件名。
			* @param    url 地址。
			* @return url 的文件名。
			*/
			static String const& getName(String const& url);
			static bool isAbsolute(String const& url);
		};
	}
}
