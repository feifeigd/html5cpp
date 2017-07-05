
#include <engine.core.h>

using engine::resource::Resource;
using engine::resource::ResourceManager;

bool Resource::_isLoadedResourcesSorted = false;

std::vector<Resource*> Resource::_loadedResources;

client::Object Resource::animationCache;
client::Object Resource::meshCache;
int Resource::_uniqueIDCounter=0;

Resource::Resource()
	: lock(false), _lastUseFrameCount(0), _memorySize(0), _released(false)
{
	_$1__id = ++_uniqueIDCounter;
	//this._id=0;
	/*this._name=null;
	this._resourceManager=null;
	Resource.__super.call(this);
	_loadedResources.push_back(this);
	Resource._isLoadedResourcesSorted=false;
	this._released=true;
	this.lock=false;
	this._memorySize=0;
	this._lastUseFrameCount=-1;
	(ResourceManager.currentResourceManager)&& (ResourceManager.currentResourceManager.addResource(this));
	*/
}

void Resource::recreateResource(){
	startCreate();
	compoleteCreate();
}

void Resource::detoryResource(){}

void Resource::activeResource(bool force){
	/*this._lastUseFrameCount=Stat.loopCount;
	if (this._released || force){
		recreateResource();
	}*/
}

bool Resource::releaseResource(bool force){
	if (!force && lock)
		return false;
	if (!_released || force){
		detoryResource();
		_released=true;
		_lastUseFrameCount=-1;
		//this.event(/*laya.events.Event.RELEASED*/"released",this);
		return true;
	}else {
		return false;
	}
}

void Resource::setUniqueName(std::string const& newName){
	bool isUnique = true;
	/*for (var i=0;i < Resource._loadedResources.length;i++){
		if (Resource._loadedResources[i]._name!==newName || Resource._loadedResources[i]===this)
			continue ;
		isUnique=false;
		return;
	}
	if (isUnique){
		if (this.name !=newName){
			this.name=newName;
			Resource._isLoadedResourcesSorted=false;
		}
	}else{
		setUniqueName(newName + ("-copy"));
	}*/
}

void Resource::dispose(){
	/*if (this._resourceManager!==null)
		throw new Error("附属于resourceManager的资源不能独立释放！");
	this.lock=false;
	this.releaseResource();
	var index=Resource._loadedResources.indexOf(this);
	if (index!==-1){
		Resource._loadedResources.splice(index,1);
		Resource._isLoadedResourcesSorted=false;
	}*/
}

void Resource::startCreate(){
	//event(/*laya.events.Event.RECOVERING*/"recovering",this);
}

void Resource::compoleteCreate(){
	_released=false;
	//event(/*laya.events.Event.RECOVERED*/"recovered",this);
}

int Resource::id()const{
	return _$1__id;
}

int Resource::lastUseFrameCount(){
	return _lastUseFrameCount;
}

String const& Resource::name(){
	return _name;
}
void Resource::name(std::string const& value){
	/*if ((value || value!=="")&& this.name!==value){
		this._name=value;
		Resource._isLoadedResourcesSorted=false;
	}*/
}

ResourceManager* Resource::resourceManager(){
	return _resourceManager;
}

int Resource::memorySize()const{
	return _memorySize;
}
void Resource::memorySize(int value){
	int offsetValue=value - _memorySize;
	_memorySize=value;
	//this.event(/*laya.events.Event.MEMORY_CHANGED*/"memorychanged",offsetValue);
}

bool Resource::released()const{
	return _released;
}

/**
*本类型排序后的已载入资源。
*/
std::vector<Resource *>& Resource::sortedLoadedResourcesByName(){
	/*if (!Resource._isLoadedResourcesSorted){
		Resource._isLoadedResourcesSorted=true;
		Resource._loadedResources.sort(Resource.compareResourcesByName);
	}*/
	return _loadedResources;
}
void sortedLoadedResourcesByName(std::vector<Resource *> const& loadedResources){
	//EventDispatcher::_$SET_sortedLoadedResourcesByName(loadedResources);
}

Resource* Resource::getLoadedResourceByIndex(int index){
	return Resource::_loadedResources[index];
}

size_t Resource::getLoadedResourcesCount(){
	return _loadedResources.size();
}

int Resource::compareResourcesByName(Resource const& left, Resource const& right){
	if (&left == &right)
		return 0;
	/*std::string const& x=left.name();
	std::string y=right.name();
	if (x.empty()){
		if (y.empty())
			return 0;	// ==
		else
			return-1;	// <
	}else {
		if (y.empty())
			return 1;	// >
		else {
			int retval=x.localeCompare(y);
			if (retval !=0)
				return retval;
			else {
				right.setUniqueName(y);
				y=right.name();
				return x.localeCompare(y);
			}
		}
	}*/
}