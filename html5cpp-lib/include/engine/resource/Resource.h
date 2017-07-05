#pragma once

#include "../events/EventDispatcher.h"
#include "IDispose.h"
#include <vector>

namespace engine{
	namespace resource{

		class ResourceManager;

		/**
		 *<code>Resource</code> 是一个资源存取类。
		 */
		class Resource : public events::EventDispatcher
			, public IDispose
		{
		public:
			Resource();

			static client::Object animationCache;
			static client::Object meshCache;

		private:
			static int _uniqueIDCounter;	///< 用于分配资源的id
			// 所有Resource对象的集合
			static std::vector<Resource*> _loadedResources;
			static bool _isLoadedResourcesSorted;

		public:

        /**
         * 通过索引返回本类型已载入资源。
         * @param index 索引。
         * @return 资源 <code>Resource</code> 对象。
         */
        static Resource* getLoadedResourceByIndex(int index);

        /**
         * 本类型已载入资源个数。
         */
        static size_t getLoadedResourcesCount();

        /**
         * 本类型排序后的已载入资源。
         */
        static std::vector<Resource *>& sortedLoadedResourcesByName();
		static void sortedLoadedResourcesByName(std::vector<Resource*> const& loadedResources);

		private:
        /** @private
         * 所属资源管理器，通常禁止修改，如果为null则不受资源管理器，可能受大图合集资源管理。
         * */
        ResourceManager* _resourceManager;

        /**是否加锁，true为不能使用自动释放机制。*/
		bool lock;

		int _$1__id;
        /**
         * 获取唯一标识ID(通常用于优化或识别)。
         */
		int id()const;

		String _name;
        /**
         * 获取名字。
         */
        /**
         * 设置名字
         */
		String const& name();
		void name(std::string const& value);

        /**
         * 资源管理员。
         */
        ResourceManager* resourceManager();

		int _lastUseFrameCount;
        /**
         * 距离上次使用帧率。
         */
        int lastUseFrameCount();

		int _memorySize;
        /**
         * 占用内存尺寸。
         */
        int memorySize()const;
		void memorySize(int value);

		bool _released;
        /**
         * 是否已释放。
         */
        bool released()const;
		
		protected:
			/**重新创建资源。override it，同时修改memorySize属性、处理startCreate()和compoleteCreate()方法。*/
			void recreateResource();

			/**销毁资源，override it,同时修改memorySize属性。*/
			void detoryResource();

        /**
         * 激活资源，使用资源前应先调用此函数激活。
         * @param force 是否强制创建。
         */
        void activeResource(bool force = false);

        /**
         * 释放资源。
         * @param force 是否强制释放。
         * @return 是否成功释放。
         */
        bool releaseResource(bool force = false);

        /**
         * 设置唯一名字,如果名字重复则自动加上“-copy”。
         * @param newName 名字。
         */
        void setUniqueName(std::string const& newName);

        /**
         * <p>彻底清理资源。</p>
         * <p><b>注意：</b>会强制解锁清理。</p>
         */
        void dispose();

		protected:
			/**开始资源激活。*/
			void startCreate();
			/**完成资源激活。*/
			void compoleteCreate();
		public:
			int compareResourcesByName(Resource const& left, Resource const& right);
		};
	}
}
