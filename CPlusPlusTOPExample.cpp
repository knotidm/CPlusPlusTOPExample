#include "CPlusPlusTOPExample.h"

extern "C"
{
	DLLEXPORT
		int	GetTOPAPIVersion(void)
	{
		return TOP_CPLUSPLUS_API_VERSION;
	}
	DLLEXPORT
		TOP_CPlusPlusBase* CreateTOPInstance(const TOP_NodeInfo *info)
	{
		return new CPlusPlusTOPExample(info);
	}
	DLLEXPORT
		void DestroyTOPInstance(TOP_CPlusPlusBase *instance)
	{
		delete (CPlusPlusTOPExample*)instance;
	}
};

CPlusPlusTOPExample::CPlusPlusTOPExample(const TOP_NodeInfo *info) : myNodeInfo(info)
{
	myExecuteCount = 0;
}

CPlusPlusTOPExample::~CPlusPlusTOPExample(){}

void CPlusPlusTOPExample::getGeneralInfo(TOP_GeneralInfo *ginfo)
{
	ginfo->cookEveryFrame = true;
}

bool CPlusPlusTOPExample::getOutputFormat(TOP_OutputFormat *format)
{
	return false;
}

void CPlusPlusTOPExample::execute(const TOP_OutputFormatSpecs* outputFormat, const TOP_InputArrays* arrays, void* reserved)
{
	myExecuteCount++;

	gl::clear(Color::black());
	float red = sin(myExecuteCount++ * 0.05);
	float green = sin(myExecuteCount++ * 0.02);
	float blue = sin(myExecuteCount++ * 0.03);
	gl::color(red, green, blue, 1);

	gl::translate(outputFormat->width / 2, outputFormat->height / 2, 0);

	glPushMatrix();
	gl::rotate(Vec3f(0, green * 50, blue * 100));
	gl::drawCube(Vec3f::zero(), Vec3f(100, 100, 100));
	glPopMatrix();

	/*glPushMatrix();
	gl::rotate(Vec3f(red * 50, 0, blue * 50));
	gl::drawSphere(Vec3f(0, 0, 0), 200, 6);
	glPopMatrix();

	glPushMatrix();
	gl::rotate(Vec3f(red * 50, green * 100, 0));
	gl::drawStrokedEllipse(Vec2f(0, 0), 300, 300, 12);
	glPopMatrix();*/
}

int CPlusPlusTOPExample::getNumInfoCHOPChans()
{
	return 1;
}

void CPlusPlusTOPExample::getInfoCHOPChan(int index, TOP_InfoCHOPChan *chan)
{
	if (index == 0)
	{
		chan->name = "executeCount";
		chan->value = myExecuteCount;
	}
}

bool CPlusPlusTOPExample::getInfoDATSize(TOP_InfoDATSize *infoSize)
{
	infoSize->rows = 1;
	infoSize->cols = 2;
	infoSize->byColumn = false;
	return true;
}

void CPlusPlusTOPExample::getInfoDATEntries(int index, int nEntries, TOP_InfoDATEntries *entries)
{
	if (index == 0)
	{
		static char tempBuffer1[4096];
		static char tempBuffer2[4096];		
		strcpy(tempBuffer1, "executeCount");
		entries->values[0] = tempBuffer1;
		sprintf(tempBuffer2, "%d", myExecuteCount);
		entries->values[1] = tempBuffer2;
	}
}