#include <xmlConfig/xmlConfig2.hpp>

void XMLConfigurator2::EnableDebug() {
	if ( profilePool ) profilePool->EnableDebug();
	debugClass::EnableDebug();
}
void XMLConfigurator2::DisableDebug() {
	if ( profilePool ) profilePool->DisableDebug();
	debugClass::DisableDebug();
}

void XMLConfigurator2::Dump() {
	if ( this->profilePool != 0 )
	{
		if ( this->GetDebugFlagLevel4() )
			this->profilePool->Dump();
	}
}
