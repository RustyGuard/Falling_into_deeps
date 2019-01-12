#include "Log.h"
int main()
{
	sgt::Log::Init();

	SGT_CORE_INFO("Project compiled succesfuly");
	SGT_WARN("Who touch my spagett?");

	while (true);
}
