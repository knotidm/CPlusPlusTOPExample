#include "TOP_CPlusPlusBase.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CPlusPlusTOPExample : public TOP_CPlusPlusBase, AppNative
{
public:
	CPlusPlusTOPExample(const TOP_NodeInfo *info);
	virtual ~CPlusPlusTOPExample();
	virtual void		getGeneralInfo(TOP_GeneralInfo *);
	virtual bool		getOutputFormat(TOP_OutputFormat*);
	virtual void		execute(const TOP_OutputFormatSpecs*, const TOP_InputArrays*, void* reserved);
	virtual int			getNumInfoCHOPChans();
	virtual void		getInfoCHOPChan(int index, TOP_InfoCHOPChan *chan);
	virtual bool		getInfoDATSize(TOP_InfoDATSize *infoSize);
	virtual void		getInfoDATEntries(int index, int nEntries, TOP_InfoDATEntries *entries);
private:
	const TOP_NodeInfo		*myNodeInfo;
	int						 myExecuteCount;
};