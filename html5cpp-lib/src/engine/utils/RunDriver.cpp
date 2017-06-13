#include <engine.core.h>

using engine::utils::RunDriver;

double RunDriver::now(){
	return client::Date::now();
}
